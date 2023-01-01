#include <stdlib.h>
#include <string>
#include <random>
#include <iostream>

#include "tools.h"

int rnd(int a, int b)
{
    if (a > b)
    {
        std::cerr << "Exception: rnd parameters is invalid\n";
        throw;
    }
    return mt() % (b - a + 1) + a;
}

long long rndll(long long a, long long b)
{
    if (a > b)
    {
        std::cerr << "Exception: rndll parameters is invalid\n";
        throw;
    }
    return (1ll * mt() * mt()) % (b - a + 1) + a;
}

// string of random number of n digit
std::string random_huge_number(int n)
{
    std::string str(n, ' ');
    for (int i = 0; i < n; ++i)
        str[i] = '0' + rnd(0, 9);

    return str;
}

// random string of n digit
std::string buildString(int n)
{
    std::string str(n, ' ');
    for (int i = 0; i < n; ++i)
        str[i] = 'a' + rnd(0, 26);

    return str;
}

// rooted at vertex r
std::vector<std::pair<int, int>> random_tree(int n, int r)
{
    std::vector<std::pair<int, int>> edges;
    std::vector<int> nodes = {r};
    int u = 1;
    while (u <= n)
    {
        if (u != r)
        {
            int v = nodes[rand() % (int)(nodes.size())];
            edges.push_back({u, v});
            nodes.emplace_back(u);
        }
        ++u;
    }
    return edges;
}