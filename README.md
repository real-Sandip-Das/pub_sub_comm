# Overview

A package containing two nodes: `publisher` and `subscriber`

`publisher` publishes a dummy string(the parameter `dummy_string`) to a specific topic(the parameter `topic_name`) at a specific rate(`publisher_rate_hz`) \
`subscriber` subscribes to the same topic and has a configurable Queue Size(the parameter `queue_size`)

# Initialization

```bash
cd ~/Tasks
catkin_create_pkg pub_sub_comm roscpp
cd pub_sub_comm
git init
```

Then created a symlink to `~/Tasks/pub_sub_comm/` in the `src` subdirectory of a (to be)Catkin Workspace folder and ran `catkin init`

# Installation

<!-- TODO: Add installation instructions -->

# Instructions

**Caution**: the following instructions will only work if the Workspace environment(i.e. `devel/setup.bash` with respect to the Workspace root folder) is sourced correctly inside the terminal session

It can be used in two ways:

1. Running each node seperately(e.g. if you want to read logs of each node seperately)
2. Using the launch file to run both nodes simultaneously

## 1. Running each node seperately

Terminal command for running the publisher node:

```bash
rosrun pub_sub_comm publisher _topic_name:='/pub_sub_comm' _publisher_rate_hz:=1 _dummy_string:='Some dummy string here' _queue_size:=5
```

Terminal command for running the subscriber node:

```bash
rosrun pub_sub_comm subscriber _topic_name:='/pub_sub_comm' _queue_size:=5
```

## 2. Using the launch file

Terminal command to launch both nodes simultaneously using the launch file:

```bash
roslaunch pub_sub_comm simultaneous_launch.launch
```
