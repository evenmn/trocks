#pragma once
#include <iostream>
#include <fstream>
#include <sstream>
#include <algorithm>
#include <iterator>
#include <string>
#include <vector>
#include <filesystem>

#include "run.h"
#include "help.h"
#include "group.h"


using namespace std;
namespace fs = std::filesystem;

vector<string> txt2vector(string filename);
void parser(int argc, char** argv);
