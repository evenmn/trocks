#pragma once
#include <iostream>
#include <string>
#include <filesystem>

#include "group.h"

using namespace std;
namespace fs = std::filesystem;

void run(string node, string command);
void surun(string node, string command);