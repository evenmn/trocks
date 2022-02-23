#include <iostream>
#include <string>

#include "help.h"


/* ----------------------------------------------------------------------------
   Print out help instructions to terminal when adding '--help' flag
------------------------------------------------------------------------------- */

void print_help()
{
    std::cout << "usage: trocks [option] [arg]" << std::endl;
    std::cout << "Options and arguments:" << std::endl;
    std::cout << "-h or --help   :" << std::endl;
    std::cout << "   Help (you already know this)" << std::endl;
    std::cout << "run <nodename or groupname> <command>:" << std::endl;
    std::cout << "   Run command 'command' on node 'nodename' or group of" << std::endl;
    std::cout << "   nodes 'groupname'" << std::endl;
    std::cout << "surun <nodename or groupname> <command>:" << std::endl;
    std::cout << "   Run sudo command 'command' on node 'nodename' or group" << std::endl;
    std::cout << "   of nodes 'groupname'" << std::endl;
    std::cout << "   You need sudo access on the nodes to perform this action" << std::endl;
    std::cout << "add_group <groupname>:" << std::endl;
    std::cout << "   Add group with name 'groupname'. The group is associated" << std::endl;
    std::cout << "   with the file 'groupname'.txt, which can be manipulated" << std::endl;
    std::cout << "add_node <groupname> <nodename>:" << std::endl;
    std::cout << "   Add node 'nodename' to a group 'groupname'" << std::endl;
    std::cout << "rm_group <groupname>:" << std::endl;
    std::cout << "   Remove group 'groupname'" << std::endl;
    std::cout << "list_nodes <groupname>:" << std::endl;
    std::cout << "   List all nodes belogning to group 'groupname'" << std::endl;
    std::cout << "list_groups:" << std::endl;
    std::cout << "   List all groups" << std::endl;
}
