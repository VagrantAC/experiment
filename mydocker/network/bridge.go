package network

import (
	"fmt"
	"net"
	"os/exec"
	"strings"

	log "github.com/sirupsen/logrus"
	"github.com/vishvananda/netlink"
)

type BridgeNetworkDriver struct {
}

func createBridgeInterface(bridgeName string) error {
	_, err := net.InterfaceByName(bridgeName)
	if err == nil || !strings.Contains(err.Error(), "no such network interface") {
		return err
	}

	la := netlink.NewLinkAttrs()
	la.Name = bridgeName

	br := &netlink.Bridge{
		LinkAttrs: la,
	}
	if err := netlink.LinkAdd(br); err != nil {
		return fmt.Errorf("bridge creation failed for bridge %s: %v", bridgeName, err)
	}
	return err
}

func setInterfaceIP(name, rawIP string) error {
	iface, err := netlink.LinkByName(name)
	if err != nil {
		return fmt.Errorf("error get interface: %v", err)
	}

	ipNet, err := netlink.ParseIPNet(rawIP)
	if err != nil {
		return err
	}

	addr := &netlink.Addr{
		IPNet: ipNet,
		Label: "",
		Flags: 0,
		Scope: 0,
	}
	return netlink.AddrAdd(iface, addr)
}

func setInterfaceUP(interfaceName string) error {
	iface, err := netlink.LinkByName(interfaceName)
	if err != nil {
		return fmt.Errorf("Error retrieving a link named [ %s ]: %v", iface.Attrs().Name, err)
	}

	if err := netlink.LinkSetUp(iface); err != nil {
		return fmt.Errorf("Error enabling interface for %s: %v", interfaceName, err)
	}
	return nil
}

func setupIPTables(bridgeName string, subnet *net.IPNet) error {
	iptablesCmd := fmt.Sprintf("-t nat -A POSTROUTING -s %s ! -o %s -j MASQUERADE", subnet.String(), bridgeName)
	if output, err := exec.Command("iptables", strings.Split(iptablesCmd, "")...).Output(); err != nil {
		log.Errorf("iptables Output, %v", output)
	}
	return nil
}

func (d *BridgeNetworkDriver) Name() string {
	return "bridge-network-driver"
}

func (d *BridgeNetworkDriver) Create(subnet, name string) (*Network, error) {
	ip, ipRange, _ := net.ParseCIDR(subnet)
	ipRange.IP = ip
	n := &Network{
		Name:    name,
		IpRange: ipRange,
	}

	err := d.initBridge(n)
	if err != nil {
		log.Errorf("error init bridge: %v", err)
	}
	return n, err
}

func (d *BridgeNetworkDriver) initBridge(n *Network) error {
	bridgeName := n.Name

	if err := createBridgeInterface(bridgeName); err != nil {
		return fmt.Errorf("Error add bridge: %s, Error: %v", bridgeName, err)
	}

	ip := *n.IpRange
	ip.IP = n.IpRange.IP
	if err := setInterfaceIP(bridgeName, ip.String()); err != nil {
		return fmt.Errorf("Error assigning address: %s on bridge: %s with an error of: %v", ip, bridgeName, err)
	}

	if err := setInterfaceUP(bridgeName); err != nil {
		return fmt.Errorf("Error set bridge up: %s, Error: %v", bridgeName, err)
	}

	if err := setupIPTables(bridgeName, n.IpRange); err != nil {
		return fmt.Errorf("Error setting iptable for %s: %v", bridgeName, err)
	}
	return nil
}

func (d *BridgeNetworkDriver) deleteBridge(n *Network) error {
	bridgeName := n.Name

	l, err := netlink.LinkByName(bridgeName)
	if err != nil {
		return fmt.Errorf("Getting link with name %s failed: %v", bridgeName, err)
	}

	if err := netlink.LinkDel(l); err != nil {
		return fmt.Errorf("Failed to remove bridge interface %s delete: %v", bridgeName, err)
	}
	return nil
}

func (d *BridgeNetworkDriver) Delete(network Network) error {
	bridgeName := network.Name
	br, err := netlink.LinkByName(bridgeName)
	if err != nil {
		return err
	}
	return netlink.LinkDel(br)
}

func (d *BridgeNetworkDriver) Connect(network *Network, endpoint *Endpoint) error {
	bridgeName := network.Name
	br, err := netlink.LinkByName(bridgeName)
	if err != nil {
		return err
	}

	la := netlink.NewLinkAttrs()
	la.Name = endpoint.ID[:5]
	la.MasterIndex = br.Attrs().Index

	endpoint.Device = netlink.Veth{
		LinkAttrs: la,
		PeerName:  "cif-" + endpoint.ID[:5],
	}

	if err = netlink.LinkAdd(&endpoint.Device); err != nil {
		return fmt.Errorf("Error Add Endpoint Device: %v", err)
	}

	if err = netlink.LinkSetUp(&endpoint.Device); err != nil {
		return fmt.Errorf("Error Add Endpoint Device: %v", err)
	}
	return nil
}

func (d *BridgeNetworkDriver) Disconnect(network *Network, endpoint *Endpoint) error {
	return nil
}
