#include "run.h"

void run(string node, string command, bool background)
{
    string exec = "ssh " + node + " " + command;
    if(background){
        exec += " &>/dev/null &";
    }
    system(exec.c_str());
}

void surun(string node, string command, bool background)
{
    string exec = "ssh -t " + node + " sudo " + command;
    if(background){
        exec += " &>/dev/null &";
    }
    system(exec.c_str());
}
