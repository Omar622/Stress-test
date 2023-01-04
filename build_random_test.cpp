#include <bits/stdc++.h>
/*
    include all pre writtn functions
    see: https://github.com/Omar622/Stress-test/TOOLS.md
*/
#include "tools/tools.h"

using namespace std;

// build here random test case
int main()
{
    int test_case = 1; // number of test cases
    cout << test_case << "\n";
    while (test_case--)
    {
        int array_size = rnd(1, 100); // size of array
        cout << array_size << "\n";
        int MAX_VALUE = 1e9;
        for (int i = 0; i < array_size; ++i)
        { // printing array
            int x = rndll(0, MAX_VALUE);
            cout << x << " ";
        }
        cout << "\n";

        int query = rnd(1, 100); // number of queries
        cout << query << "\n";
        for (int i = 0; i < query; ++i)
        {
            int l = rnd(0, array_size-1); // random number from 0 to n-1
            int r = rnd(0, array_size-1); // random number from 0 to n-1
            if (r < l)
                swap(l, r); // garantee that l < r.
            cout << l << " " << r << "\n";
        }
    }

    return 0;
}
