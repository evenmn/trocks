# Trocks
A light-weight C++ code for performing operations (executing commands etc) across the compute nodes of HPC clusters. Can be seen as Rocks' stupid little brother.

## Compile
```bash
make compile
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
trocks list_nodes <groupname>
```

