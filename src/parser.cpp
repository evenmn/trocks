#include "parser.h"


/* ----------------------------------------------------------------------------
   Read a text file 'filename' and convert it to a vector of strings where each
   element corresponds to the line in the text file
------------------------------------------------------------------------------- */

vector<string> txt2string(string filename)
{
    vector<string> lines;
    ifstream infile;
    infile.open(filename);
    if (infile.is_open()) {
        string line;
        while (getline(infile, line)) {
            lines.push_back(line);
        }
        infile.close();
    }
    else {
        cout << "File '" + filename + "' cannot be opened" << endl;
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
    string group_dir = "/var/run/trocks";
    vector<string> groups;
    vector<vector<string>> nodes;
    //string path = std::filesystem::absolute(group_dir);
    for (const auto & entry : fs::directory_iterator(group_dir)){
        string group_path = entry.path();

        // get nodes
        nodes.push_back(txt2string(group_path));

        // get group names
        size_t pos = 0;
        while ((pos = group_path.find("/")) != string::npos) {
            group_path.erase(0, pos + 1);
        }
        string groupname = group_path.substr(0, group_path.find("."));
        groups.push_back(groupname);
    }

    if(argc >= 2) {
        string keyword = argv[1];
        if(keyword == "-h" || keyword == "--help"){
           print_help(); 
        }
        else if(keyword == "run"){
            string node = argv[2];
            string command = argv[3];
            bool background;
            if(argc == 4){
                background = false;
            }
            else{
                istringstream(argv[4]) >> std::boolalpha >> background;
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
            string node = argv[2];
            string command = argv[3];
            bool background;
            if(argc == 4){
                background = false;
            }
            else{
                istringstream(argv[4]) >> std::boolalpha >> background;
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
            string group = argv[2];
            add_group(group, group_dir);
        }
        else if(keyword == "rm_group"){
            string group = argv[2];
            rm_group(group, group_dir);
        }
        else if(keyword == "add_node"){
            string group = argv[2];
            string node = argv[3];
            add_node(group, node, group_dir);
        }
        else if(keyword == "rm_node"){
            string group = argv[2];
            string node = argv[3];
            rm_node(group, node, group_dir);
        }
        else if(keyword == "list_nodes"){
            string group = argv[2];
            auto it = find(groups.begin(), groups.end(), group);
            if (it != groups.end()){
                int index = it - groups.begin();
                list_nodes(nodes[index]);
            }
            else{
                cout << "Group '" << group << "' does not exist" << endl;
            }
        }
        else if(keyword == "list_groups"){
            list_groups(groups);
        }
        else{
            cout << "'" << keyword << "' is not a known keyword!" << endl;
        }
    }
    else {
        cout << "Trocks version 0.0.2" << endl;
        cout << "Author: Even M. Nordhagen" << endl;
        cout << "url: github.com/evenmn/trocks" << endl;
    }
}
