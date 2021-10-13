#pragma once
#include <iostream>
#include <fstream>
#include <sstream>
#include <iterator>
#include <string>
#include <vector>
#include <filesystem>

#include "keywords.h"


using namespace std;
namespace fs = std::filesystem;

vector<string> txt2vector(string filename);
void parser(int argc, char** argv);

//vector<string> known_cpu_nodes;
//vector<string> known_gpu_nodes;
