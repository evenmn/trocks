#pragma once
#include <string>
#include <vector>


void add_group(std::string groupname, std::string group_dir);
void rm_group(std::string groupname, std::string group_dir);
void add_node(std::string groupname, std::string nodename, std::string group_dir);
void rm_node(std::string groupname, std::string nodename, std::string group_dir);
void list_nodes(std::vector<std::string> nodes);
void list_groups(std::vector<std::string> groups);
