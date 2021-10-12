#include "keywords.h"

void run(string node, string command)
{
   system("ssh " + node + " " + command);
}

void surun(string node, string command)
{
   system("ssh -t " + node + " sudo " + command);
}

void add_node(string node)
{
    cout << "Yes" << endl;
}

void rm_node(string node)
{
    cout << "Hey" << endl;
}
