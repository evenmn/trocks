# Trocks
A light-weight C++ code for performing operations (executing commands etc) across the compute nodes of HPC clusters. Can be seen as Rocks' stupid little brother. Tested on Linux (Ubuntu 20.04) and macOS (Big Sur 11.6).

## Prerequisites
- g++ 9.4 or newer (utilizes std::filesystem in C++17)

## Compile
```bash
make compile
```
In addition, Trocks looks for groups at `/var/run/trocks/`. This directory has to be created manually the first time and given open permissions:
```bash
sudo mkdir /var/run/trocks
sudo chmod 777 /var/run/trocks
```

## How to use
Run command "command" on remote node "nodename":
```bash
trocks run <nodename> <command>
```

Run sudo command "command" on remote node "nodename":
```bash
trocks surun <nodename> <command>
```

## Groups
The nodes can also be categorized in groups, and actions can be performed on all nodes in a group:
```bash
trocks add_group <groupname>
```
```bash
trocks add_node <groupname> <nodename>
```
```bash
trocks rm_group <groupname>
```
```bash
trocks list_groups
```
```bash
trocks list_nodes <groupname>
```

