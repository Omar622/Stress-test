#ifndef TOOLS_H
#define TOOLS_H

// full 32-bit unsigned random number
std::mt19937 mt(time(0));

int rnd(int, int);
long long rndll(long long, long long);

std::string random_huge_number(int);

std::string random_string(int);

std::vector<std::pair<int, int>> random_tree(int, int);

#include "tools.cpp"

#endif