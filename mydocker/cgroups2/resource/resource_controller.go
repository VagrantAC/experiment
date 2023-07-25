package resource

type ResourceConfig struct {
	MemoryMax  string
	MemoryHigh string
	CpuWeight  string
	CpuSetCpus string
}

// https://docs.kernel.org/admin-guide/cgroup-v2.html#controllers
type ResourceController interface {
	Name() string
	Set(path string, res *ResourceConfig) error
}

var (
	ResourceControllersIns = []ResourceController{
		&CpusetController{},
		&MemoryController{},
		&CpuController{},
	}
)
