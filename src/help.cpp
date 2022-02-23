#include "help.h"


/* ----------------------------------------------------------------------------
   Print out help instructions to terminal when adding '--help' flag
------------------------------------------------------------------------------- */

void print_help()
{
    cout << "usage: trocks [option] [arg]" << endl;
    cout << "Options and arguments:" << endl;
    cout << "-h or --help   :" << endl;
    cout << "   Help (you already know this)" << endl;
    cout << "run <nodename or groupname> <command>:" << endl;
    cout << "   Run command 'command' on node 'nodename' or group of nodes 'groupname'" << endl;
    cout << "surun <nodename or groupname> <command>:" << endl;
    cout << "   Run sudo command 'command' on node 'nodename' or group of nodes 'groupname'" << endl;
    cout << "   You need sudo access on the nodes to perform this action" << endl;
    cout << "add_group <groupname>:" << endl;
    cout << "   Add group with name 'groupname'. The group is associated" << endl;
    cout << "   with the file 'groupname'.txt, which can be manipulated" << endl;
    cout << "add_node <groupname> <nodename>:" << endl;
    cout << "   Add node 'nodename' to a group 'groupname'" << endl;
    cout << "rm_group <groupname>:" << endl;
    cout << "   Remove group 'groupname'" << endl;
    cout << "list_nodes <groupname>:" << endl;
    cout << "   List all nodes belogning to group 'groupname'" << endl;
    cout << "list_groups:" << endl;
    cout << "   List all groups" << endl;
}
