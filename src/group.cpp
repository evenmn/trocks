#include "group.h"

void add_group(string groupname)
{
    /* Add new group. A group exists if the file "txt/<groupname>.txt exists
     */
    auto path = std::filesystem::absolute("txt/" + groupname + ".txt");
    if(std::filesystem::exists(path)){
        cout << "Group '" << groupname << "' already exists" << endl;
        exit(0);
    }
    ofstream output(path);
}

void rm_group(string groupname)
{
    /* Remove group, which means remove file "txt/<groupname>.txt
     */
    auto path = std::filesystem::absolute("txt/" + groupname + ".txt");
    if(remove(path)){
        perror("Error removing group");
    }
}

void add_node(string groupname, string nodename)
{
    /* Add node to group. This means appending line with node name to
     * group file
     */
    auto path = std::filesystem::absolute("txt/" + groupname + ".txt");
    ofstream file(path, std::ios_base::app | std::ios_base::out);
    file << nodename << endl;
}

void rm_node(string groupname, string nodename)
{
    int i = 1;
}

