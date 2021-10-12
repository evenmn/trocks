#include "parser.h"


void parser(string input)
{
    vector<string> splitted = split(input);
    string keyword = splitted.at(0);
    if(keyword == "run"){
        string node = splitted.at(1);
        string command = splitted.at(2)
        if(node == "compute"){
            // read file with node names
            // into a std vector
            for(auto i : known_nodes){
                run(i, command);
            }
        }
        else if(node == "gpu"){
            //
            int i = 1;
        }
        else {
            run(node, command);
        }
    }
    else if(keyword == "surun"){
        string node = splitted.at(1);
        string command = splitted.at(2)
        if(node == "compute"){
            // read file with node names
            // into a std vector
            for(auto i : known_nodes){
                surun(i, command);
            }
        }
        else if(node == "gpu"){
            //
            int i = 1;
        }
        else {
            surun(node, command);
        }
    }
    else if(keyword == "add_node"){
        string node = splitted.at(1);
        if(node == "compute" || node == "gpu"){
            cout << "Node name cannot be 'compute' or 'gpu'" << endl;
            exit(0);
        }
        add_node(node);
    }
    else if(keyword == "rm_node"){
        string node = splitted.at(1);
        rm_node(node);
    }
    else{
        cout << "'" << keyword << "' is not a known keyword!" << endl;
    }
}
