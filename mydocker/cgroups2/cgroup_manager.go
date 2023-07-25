package cgroups

import (
	"fmt"
	"io/ioutil"
	resource "mydocker/cgroups2/resource"
	"os"
	"path"
	"strconv"

	log "github.com/sirupsen/logrus"
)

type CgroupManager struct {
	CgroupName string
	Resource   resource.ResourceConfig
}

func NewCgroupManager(cgroupName string) *CgroupManager {
	return &CgroupManager{
		CgroupName: cgroupName,
	}
}

func (c *CgroupManager) Apply(pid int) error {
	cgroupPath, err := resource.GetCgroup2Path(c.Hierarchy(), true)
	if err != nil {
		return err
	}
	if err := ioutil.WriteFile(path.Join(cgroupPath, "cgroup.procs"), []byte(strconv.Itoa(pid)), 0644); err != nil {
		return fmt.Errorf("set cgroup proc fail %v", err)
	}
	return nil
}

func (c *CgroupManager) Set(res *resource.ResourceConfig) error {
	cgroupPath, err := resource.GetCgroup2Path(c.Hierarchy(), false)
	if err != nil {
		return err
	}
	for _, subSysIns := range resource.ResourceControllersIns {
		subSysIns.Set(cgroupPath, res)
	}
	return nil
}

func (c *CgroupManager) Destroy() error {
	cgroupPath, err := resource.GetCgroup2Path(c.Hierarchy(), false)
	if err != nil {
		return err
	}
	if err := os.Remove(cgroupPath); err != nil {
		log.Warnf("remove cgroup fail %v", err)
		return err
	}
	return nil
}

func (c *CgroupManager) Hierarchy() string {
	return "mydocker"
}
