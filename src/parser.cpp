#include <iostream>
#include <fstream>
#include <sstream>
#include <algorithm>
#include <iterator>
#include <string>
#include <vector>
#include <filesystem>

#include "parser.h"
#include "run.h"
#include "help.h"
#include "group.h"


namespace fs = std::filesystem;


/* ----------------------------------------------------------------------------
   Read a text file 'filename' and convert it to a vector of strings where each
   element corresponds to the line in the text file
------------------------------------------------------------------------------- */

std::vector<std::string> txt2string(std::string filename)
{
    std::vector<std::string> lines;
    std::ifstream infile;
    infile.open(filename);
    if (infile.is_open()) {
        std::string line;
        while (std::getline(infile, line)) {
            lines.push_back(line);
        }
        infile.close();
    }
    else {
        std::cout << "File '" + filename + "' cannot be opened" << std::endl;
    }
    return lines;
}


/* ----------------------------------------------------------------------------
   Parsing command line arguments and calling functions defined in 'run.h' or
   'group.h'
------------------------------------------------------------------------------- */

void parser(int argc, char** argv)
{
    // check all groups
    std::string group_dir = "/var/run/trocks";
    std::vector<std::string> groups;
    std::vector<std::vector<std::string>> nodes;
    //string path = std::filesystem::absolute(group_dir);
    for (const auto & entry : fs::directory_iterator(group_dir)){
        std::string group_path = entry.path();

        // get nodes
        nodes.push_back(txt2string(group_path));

        // get group names
        size_t pos = 0;
        while ((pos = group_path.find("/")) != std::string::npos) {
            group_path.erase(0, pos + 1);
        }
        std::string groupname = group_path.substr(0, group_path.find("."));
        groups.push_back(groupname);
    }

    if(argc >= 2) {
        std::string keyword = argv[1];
        if(keyword == "-h" || keyword == "--help"){
           print_help(); 
        }
        else if(keyword == "run"){
            std::string node = argv[2];
            std::string command = argv[3];
            bool background;
            if(argc == 4){
                background = false;
            }
            else{
                std::istringstream(argv[4]) >> std::boolalpha >> background;
            }
            auto it = find(groups.begin(), groups.end(), node);
            if (it != groups.end()){
                int index = it - groups.begin();
                for(auto i : nodes[index]){
                    run(i, command, background);
                }
            }
            else {
                run(node, command, background);
            }
        }
        else if(keyword == "surun"){
            std::string node = argv[2];
            std::string command = argv[3];
            bool background;
            if(argc == 4){
                background = false;
            }
            else{
                std::istringstream(argv[4]) >> std::boolalpha >> background;
            }
            auto it = find(groups.begin(), groups.end(), node);
            if (it != groups.end()){
                int index = it - groups.begin();
                for(auto i : nodes[index]){
                    surun(i, command, background);
                }
            }
            else {
                surun(node, command, background);
            }
        }
        else if(keyword == "add_group"){
            std::string group = argv[2];
            add_group(group, group_dir);
        }
        else if(keyword == "rm_group"){
            std::string group = argv[2];
            rm_group(group, group_dir);
        }
        else if(keyword == "add_node"){
            std::string group = argv[2];
            std::string node = argv[3];
            add_node(group, node, group_dir);
        }
        else if(keyword == "rm_node"){
            std::string group = argv[2];
            std::string node = argv[3];
            rm_node(group, node, group_dir);
        }
        else if(keyword == "list_nodes"){
            std::string group = argv[2];
            auto it = find(groups.begin(), groups.end(), group);
            if (it != groups.end()){
                int index = it - groups.begin();
                list_nodes(nodes[index]);
            }
            else{
                std::cout << "Group '" << group << "' does not exist" << std::endl;
            }
        }
        else if(keyword == "list_groups"){
            list_groups(groups);
        }
        else{
            std::cout << "'" << keyword << "' is not a known keyword!" << std::endl;
        }
    }
    else {
        std::cout << "Trocks version 0.0.2" << std::endl;
        std::cout << "Author: Even M. Nordhagen" << std::endl;
        std::cout << "url: github.com/evenmn/trocks" << std::endl;
    }
}
