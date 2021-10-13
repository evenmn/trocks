#include "parser.h"

vector<string> txt2string(string filename)
{
    vector<string> lines;
    ifstream myReadFile;
    myReadFile.open(filename);
    char output[100];
    if (myReadFile.is_open()) {
        while (!myReadFile.eof()) {
            myReadFile >> output;
            string s;
            stringstream ss;
            ss << output;
            ss >> s;
            lines.push_back(s);
        }
    }
    else {
        cout << "File '" + filename + "' cannot be opened" << endl;
    }
    return lines;
}

void parser(int argc, char** argv)
{
    vector<string> known_cpu_nodes = txt2string(std::filesystem::absolute("txt/known_cpu_nodes.txt"));
    vector<string> known_gpu_nodes = txt2string(std::filesystem::absolute("txt/known_cpu_nodes.txt"));

    if(argc >= 2) {
        string keyword = argv[1];
        if(keyword == "run"){
            string node = argv[2];
            string command = argv[3];
            if(node == "compute" || node == "cpu"){
                for(auto i : known_cpu_nodes){
                    run(i, command);
                }
            }
            else if(node == "gpu"){
                for(auto i : known_gpu_nodes){
                    run(i, command);
                }
            }
            else {
                run(node, command);
            }
        }
        else if(keyword == "surun"){
            string node = argv[2];
            string command = argv[3];
            if(node == "compute" || node == "cpu"){
                for(auto i : known_cpu_nodes){
                    surun(i, command);
            }
        }
        else if(node == "gpu"){
            for(auto i : known_gpu_nodes){
                surun(i, command);
            }
        }
        else {
            surun(node, command);
        }
        }
        else if(keyword == "add_node"){
            string node = argv[2];
            if(node == "compute" || node == "gpu" || node == "cpu"){
                cout << "Node name cannot be 'compute' or 'gpu'" << endl;
                exit(0);
            }
            add_node(node);
        }
        else if(keyword == "rm_node"){
            string node = argv[2];
            rm_node(node);
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
