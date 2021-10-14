#include "parser.h"

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

void parser(int argc, char** argv)
{
    // check all groups
    vector<string> groups;
    vector<vector<string>> nodes;
    string path = std::filesystem::absolute("txt");
    for (const auto & entry : fs::directory_iterator(path)){
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
        if(keyword == "-h" || keyword == "-help" || keyword == "help"){
           print_help(); 
        }
        else if(keyword == "run"){
            string node = argv[2];
            string command = argv[3];
            auto it = find(groups.begin(), groups.end(), node);
            if (it != groups.end()){
                int index = it - groups.begin();
                for(auto i : nodes[index]){
                    run(i, command);
                }
            }
        }
        else if(keyword == "surun"){
            string node = argv[2];
            string command = argv[3];
            auto it = find(groups.begin(), groups.end(), node);
            if (it != groups.end()){
                int index = it - groups.begin();
                for(auto i : nodes[index]){
                    surun(i, command);
                }
            }
        }
        else if(keyword == "add_group"){
            string group = argv[2];
            add_group(group);
        }
        else if(keyword == "rm_group"){
            string group = argv[2];
            rm_group(group);
        }
        else if(keyword == "add_node"){
            string group = argv[2];
            string node = argv[3];
            add_node(group, node);
        }
        else if(keyword == "rm_node"){
            string group = argv[2];
            string node = argv[3];
            rm_node(group, node);
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
        cout << "Trocks version 0.0.1" << endl;
        cout << "Author: Even M. Nordhagen" << endl;
    }
}
