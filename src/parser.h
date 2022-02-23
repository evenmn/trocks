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


namespace fs = std::filesystem;

std::vector<std::string> txt2vector(std::string filename);
void parser(int argc, char** argv);

