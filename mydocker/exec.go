package main

import (
	"encoding/json"
	"fmt"
	"io/ioutil"
	"mydocker/container"
	"os"
	"os/exec"
	"strings"

	log "github.com/sirupsen/logrus"
)

const ENV_EXEC_PID = "mydocker_pid"
const ENV_EXEC_CMD = "mydocker_cmd"

func getContainerPidByName(containerName string) (string, error) {
	dirURL := fmt.Sprintf(container.DefaultInfoLocation, containerName)
	configFilePath := dirURL + container.ConfigName

	contentBytes, err := ioutil.ReadFile(configFilePath)
	if err != nil {
		return "", err
	}
	var containerInfo container.ContainerInfo
	if err := json.Unmarshal(contentBytes, &containerInfo); err != nil {
		return "", err
	}
	return containerInfo.Pid, nil
}

func ExecContainer(containerName string, commandArray []string) {
	pid, err := getContainerPidByName(containerName)
	if err != nil {
		log.Errorf("Exec container getContainerPidByName %s error %v", containerName, err)
		return
	}

	cmdStr := strings.Join(commandArray, " ")
	log.Infof("container pid %s", pid)
	log.Infof("command %s", cmdStr)

	cmd := exec.Command("/proc/self/exe", "exec")
	cmd.Stdin = os.Stdin
	cmd.Stdout = os.Stdout
	cmd.Stderr = os.Stderr

	os.Setenv(ENV_EXEC_PID, pid)
	os.Setenv(ENV_EXEC_CMD, cmdStr)
	containerEnvs := getEnvsByPid(pid)
	cmd.Env = append(cmd.Env, containerEnvs...)

	if err := cmd.Run(); err != nil {
		log.Errorf("Exec container %s error %v", containerName, err)
	}
}

func getEnvsByPid(pid string) []string {
	path := fmt.Sprintf("/proc/%s/environ", pid)
	contentBytes, err := ioutil.ReadFile(path)
	if err != nil {
		log.Errorf("Read file %s error %v", path, err)
		return nil
	}
	envs := strings.Split(string(contentBytes), "\u0000")
	return envs
}
