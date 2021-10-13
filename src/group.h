#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <filesystem>

using namespace std;
namespace fs = std::filesystem;

void add_group(string groupname);
void rm_group(string groupname);
void add_node(string groupname, string nodename);
void rm_node(string groupname, string nodename);
void list_nodes(string groupname, vector<string> nodes);
