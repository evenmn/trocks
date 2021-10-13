#pragma once
#include <iostream>
#include <string>
#include <filesystem>

using namespace std;
namespace fs = std::filesystem;

void run(string node, string command);
void surun(string node, string command);
void add_node(string node);
void rm_node(string node);

//string known_cpu_nodes_file = "txt/known_cpu_nodes.txt";
//string known_gpu_nodes_file = "txt/known_gpu_nodes.txt";
