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
