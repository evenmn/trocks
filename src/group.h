#pragma once
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <filesystem>

using namespace std;
namespace fs = std::filesystem;

void add_group(string groupname, string group_dir);
void rm_group(string groupname, string group_dir);
void add_node(string groupname, string nodename, string group_dir);
void rm_node(string groupname, string nodename, string group_dir);
void list_nodes(vector<string> nodes);
void list_groups(vector<string> groups);
