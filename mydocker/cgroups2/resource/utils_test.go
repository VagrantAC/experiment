package resource

import (
	"testing"

	"github.com/stretchr/testify/assert"
)

func TestFindCgroup2MountPoint(t *testing.T) {
	assert.Equal(t, FindCgroup2Mountpoint(), "/sys/fs/cgroup")
}
