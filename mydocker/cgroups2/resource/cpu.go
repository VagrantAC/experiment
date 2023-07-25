package resource

import (
	"fmt"
	"io/ioutil"
	"path"
)

type CpuController struct {
}

func (s *CpuController) Set(cgroupPath string, res *ResourceConfig) error {
	if res.CpuWeight != "" {
		if err := ioutil.WriteFile(path.Join(cgroupPath, fmt.Sprintf("%s.weight", s.Name())), []byte(res.CpuWeight), 0644); err != nil {
			return fmt.Errorf("set cgroup cpu share fail %v", err)
		}
	}
	return nil
}

func (s *CpuController) Name() string {
	return "cpu"
}
