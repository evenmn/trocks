#include "group.h"


/* ----------------------------------------------------------------------------
   Add new group. A group exists if the file "txt/<groupname>.txt exists
------------------------------------------------------------------------------- */

void add_group(string groupname, string group_dir)
{
    string path = group_dir + "/" + groupname + ".txt";
    if(std::filesystem::exists(path)){
        cout << "Group '" << groupname << "' already exists" << endl;
        exit(0);
    }
    ofstream output(path);
}


/* ----------------------------------------------------------------------------
   Remove group, which means removing file "txt/<groupname>.txt
------------------------------------------------------------------------------- */

void rm_group(string groupname, string group_dir)
{
    auto path = group_dir + "/" + groupname + ".txt";
    if(remove(path.c_str())){
        perror("Error removing group");
    }
}


/* ----------------------------------------------------------------------------
   Add node to group. This means appending line with node name to group file
------------------------------------------------------------------------------- */

void add_node(string groupname, string nodename, string group_dir)
{
    auto path = group_dir + "/" + groupname + ".txt";
    ofstream file(path.c_str(), std::ios_base::app | std::ios_base::out);
    file << nodename << endl;
}


/* ----------------------------------------------------------------------------
   Remove a node from a group. This corresponds to removing a line from one
   of the txt files
------------------------------------------------------------------------------- */

void rm_node(string groupname, string nodename, string group_dir)
{}


/* ----------------------------------------------------------------------------
   List all nodes associated with a group and print them out to terminal
------------------------------------------------------------------------------- */

void list_nodes(vector<string> nodes)
{
    for(auto node : nodes){
        cout << node << endl;
    }
}


/* ----------------------------------------------------------------------------
   List all groups and print them out to terminal
------------------------------------------------------------------------------- */

void list_groups(vector<string> groups)
{
    for(auto group : groups){
        cout << group << endl;
    }
}
