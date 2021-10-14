#include "group.h"

void add_group(string groupname, string group_dir)
{
    /* Add new group. A group exists if the file "txt/<groupname>.txt exists
     */
    string path = group_dir + "/" + groupname + ".txt";
    if(std::filesystem::exists(path)){
        cout << "Group '" << groupname << "' already exists" << endl;
        exit(0);
    }
    ofstream output(path);
}

void rm_group(string groupname, string group_dir)
{
    /* Remove group, which means remove file "txt/<groupname>.txt
     */
    auto path = group_dir + "/" + groupname + ".txt";
    if(remove(path.c_str())){
        perror("Error removing group");
    }
}

void add_node(string groupname, string nodename, string group_dir)
{
    /* Add node to group. This means appending line with node name to
     * group file
     */
    auto path = group_dir + "/" + groupname + ".txt";
    ofstream file(path.c_str(), std::ios_base::app | std::ios_base::out);
    file << nodename << endl;
}

void rm_node(string groupname, string nodename, string group_dir)
{}

void list_nodes(vector<string> nodes)
{
    for(auto node : nodes){
        cout << node << endl;
    }
}

void list_groups(vector<string> groups)
{
    for(auto group : groups){
        cout << group << endl;
    }
}
