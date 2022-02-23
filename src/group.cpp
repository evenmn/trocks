#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <filesystem>

#include "group.h"

namespace fs = std::filesystem;


/* ----------------------------------------------------------------------------
   Add new group. A group exists if the file "txt/<groupname>.txt exists
------------------------------------------------------------------------------- */

void add_group(std::string groupname, std::string group_dir)
{
    std::string path = group_dir + "/" + groupname + ".txt";
    if(fs::exists(path)){
        std::cout << "Group '" << groupname << "' already exists" << std::endl;
        exit(0);
    }
    std::ofstream output(path);
}


/* ----------------------------------------------------------------------------
   Remove group, which means removing file "txt/<groupname>.txt
------------------------------------------------------------------------------- */

void rm_group(std::string groupname, std::string group_dir)
{
    auto path = group_dir + "/" + groupname + ".txt";
    if(remove(path.c_str())){
        perror("Error removing group");
    }
}


/* ----------------------------------------------------------------------------
   Add node to group. This means appending line with node name to group file
------------------------------------------------------------------------------- */

void add_node(std::string groupname, std::string nodename, std::string group_dir)
{
    auto path = group_dir + "/" + groupname + ".txt";
    std::ofstream file(path.c_str(), std::ios_base::app | std::ios_base::out);
    file << nodename << std::endl;
}


/* ----------------------------------------------------------------------------
   Remove a node from a group. This corresponds to removing a line from one
   of the txt files
------------------------------------------------------------------------------- */

void rm_node(std::string groupname, std::string nodename, std::string group_dir)
{}


/* ----------------------------------------------------------------------------
   List all nodes associated with a group and print them out to terminal
------------------------------------------------------------------------------- */

void list_nodes(std::vector<std::string> nodes)
{
    for(auto node : nodes){
        std::cout << node << std::endl;
    }
}


/* ----------------------------------------------------------------------------
   List all groups and print them out to terminal
------------------------------------------------------------------------------- */

void list_groups(std::vector<std::string> groups)
{
    for(auto group : groups){
        std::cout << group << std::endl;
    }
}
