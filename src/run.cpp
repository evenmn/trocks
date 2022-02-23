#include "run.h"


/* ----------------------------------------------------------------------------
   Run a command 'command' on a node 'node'. Commands can be run in background
   using the 'background' argument.
------------------------------------------------------------------------------- */

void run(string node, string command, bool background)
{
    string exec = "ssh " + node + " " + command;
    if(background){
        exec += " &>/dev/null &";
    }
    system(exec.c_str());
}


/* ----------------------------------------------------------------------------
   Run a command 'command' on a node 'node' in sudo mode. Commands can be run 
   in background using the 'background' argument
------------------------------------------------------------------------------- */
void surun(string node, string command, bool background)
{
    string exec = "ssh -t " + node + " sudo " + command;
    if(background){
        exec += " &>/dev/null &";
    }
    system(exec.c_str());
}
