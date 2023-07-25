package resource

import (
	"bufio"
	"fmt"
	"os"
	"path"
	"strings"
)

func FindCgroup2Mountpoint() string {
	f, err := os.Open("/proc/self/mountinfo")
	if err != nil {
		return ""
	}
	defer f.Close()

	scanner := bufio.NewScanner(f)
	for scanner.Scan() {
		txt := scanner.Text()
		fields := strings.Split(txt, " ")
		if fields[len(fields)-2] == "cgroup2" {
			return fields[4]
		}
	}
	if err := scanner.Err(); err != nil {
		return ""
	}
	return ""
}

func GetCgroup2Path(hierarchy string, autoCreate bool) (string, error) {
	cgroupRoot := FindCgroup2Mountpoint()
	if _, err := os.Stat(path.Join(cgroupRoot, hierarchy)); err == nil || (autoCreate && os.IsNotExist(err)) {
		if os.IsNotExist(err) {
			if err := os.Mkdir(path.Join(cgroupRoot, hierarchy), 0755); err != nil {
				return "", fmt.Errorf("error create cgroup %v", err)
			}
		}
		return path.Join(cgroupRoot, hierarchy), nil
	} else {
		return "", fmt.Errorf("cgroup path error %v", err)
	}
}
