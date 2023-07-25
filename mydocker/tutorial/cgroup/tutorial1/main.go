package main

import (
	"flag"
	"fmt"
	"io/ioutil"
	"os/exec"
	"path"
	"strconv"
	"syscall"

	"os"
)

const cgroupMemoryHierarchyMount = "/sys/fs/cgroup/testmemorylimit1"

var isChildren = flag.Bool("isChildren", false, "this is children")

func main() {
	flag.Parse()
	fmt.Printf("main() pid: %d, ppid: %d, gid: %d, isChildren: %v\n", os.Getpid(), os.Getppid(), os.Getgid(), *isChildren)
	if *isChildren {
		cmd := exec.Command("stress", "--vm-bytes", "500m", "--vm-keep", "-m", "1")
		cmd.SysProcAttr = &syscall.SysProcAttr{}
		cmd.Stdin = os.Stdin
		cmd.Stdout = os.Stdout
		cmd.Stderr = os.Stderr
		if err := cmd.Start(); err != nil {
			fmt.Println("ERROR", err)
			os.Exit(1)
		} else {
			fmt.Printf("%v\n", cmd.Process.Pid)
		}
		res := exec.Command("echo $$")
		res.Stdout = os.Stdout
		res.Run()
		cmd.Process.Wait()
		return
	}
	cmd := exec.Command("./main", "--isChildren", "true")
	cmd.SysProcAttr = &syscall.SysProcAttr{
		Cloneflags: syscall.CLONE_NEWUTS | syscall.CLONE_NEWPID | syscall.CLONE_NEWNS,
	}
	cmd.Stdin = os.Stdin
	cmd.Stdout = os.Stdout
	cmd.Stderr = os.Stderr
	os.Mkdir(cgroupMemoryHierarchyMount, 0755)
	ioutil.WriteFile(path.Join(cgroupMemoryHierarchyMount, "cgroup.procs"), []byte(strconv.Itoa(os.Getpid())), 0644)
	ioutil.WriteFile(path.Join(cgroupMemoryHierarchyMount, "memory.high"), []byte("300m"), 0644)
	ioutil.WriteFile(path.Join(cgroupMemoryHierarchyMount, "memory.max"), []byte("300m"), 0644)

	if err := cmd.Start(); err != nil {
		fmt.Println("ERROR", err)
		os.Exit(1)
	}
	cmd.Process.Wait()
}
