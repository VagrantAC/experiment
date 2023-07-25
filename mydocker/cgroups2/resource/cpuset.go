package resource

import (
	"fmt"
	"io/ioutil"
	"path"
)

type CpusetController struct {
}

func (s *CpusetController) Set(cgroupPath string, res *ResourceConfig) error {
	if res.CpuSetCpus != "" {
		if err := ioutil.WriteFile(path.Join(cgroupPath, fmt.Sprintf("%s.cpus", s.Name())), []byte(res.CpuSetCpus), 0644); err != nil {
			return fmt.Errorf("set cgroup memory fail %v", err)
		}
	}
	return nil
}

func (s *CpusetController) Name() string {
	return "cpuset"
}
