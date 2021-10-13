#include "keywords.h"

void run(string node, string command)
{
    string exec = "ssh " + node + " " + command;
    const char *cexec = exec.c_str();
    system(cexec);
}

void surun(string node, string command)
{
    string exec = "ssh -t " + node + " sudo " + command;
    const char *cexec = exec.c_str();
    system(cexec);
}

void add_node(string node)
{
    //std::ofstream file(std::filesystem::absolute(known_cpu_nodes_file), std::ios_base::app | std::ios_base::out);

    //file << node;
}

void rm_node(string node)
{
    cout << "Hey" << endl;
}
