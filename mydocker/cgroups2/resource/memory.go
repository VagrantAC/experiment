package resource

import (
	"fmt"
	"io/ioutil"
	"path"
)

type MemoryController struct {
}

func (s *MemoryController) Set(cgroupPath string, res *ResourceConfig) error {
	if res.MemoryMax != "" {
		if err := ioutil.WriteFile(path.Join(cgroupPath, fmt.Sprintf("%s.max", s.Name())), []byte(res.MemoryMax), 0644); err != nil {
			return fmt.Errorf("set cgroup memory max fail %v", err)
		}
	}
	if res.MemoryHigh != "" {
		if err := ioutil.WriteFile(path.Join(cgroupPath, fmt.Sprintf("%s.high", s.Name())), []byte(res.MemoryHigh), 0644); err != nil {
			return fmt.Errorf("set cgroup memory high fail %v", err)
		}
	}
	return nil
}

func (s *MemoryController) Name() string {
	return "memory"
}
