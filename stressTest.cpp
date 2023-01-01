/*
All you have to do is:
    1) set number of tests you want in "tc" variable in line 110
    2) write code to build only one random test case in function "buildTests" in line 27
    3) set your code in file "myCode.cpp".
    4) set code that generates the refrence answer in file "answer.cpp".

Note: there are some functions like "buildHugeNumber" in line 15, helping you to build random number of n digit.
      also "randll" in line 23, helping to get random long long.
*/

#include <bits/stdc++.h>
#include "Admin/admin.h"
#include "Checker/compare_files.h"
#include "Tools/tools.h"

using namespace std;


void buildTests()
{
    ofstream in("input.in");

    // build here random test case

    int test_case = 1; // number of test cases
    in << test_case << "\n";
    while (test_case--)
    {
        int array_size = rnd(1, 100); // size of array
        in << array_size << "\n";
        int MAX_VALUE = 1e9;
        for (int i = 0; i < array_size; ++i)
        { // printing array
            int x = rndll(1, MAX_VALUE);
            in << x << " ";
        }
        in << "\n";

        int query = rnd(1, 100); // number of queries
        in << query << "\n";
        for (int i = 0; i < query; ++i)
        {
            int l = rnd(0, array_size); // random number from 0 to n-1
            int r = rnd(0, array_size); // random number from 0 to n-1
            if (r < l)
                swap(l, r); // garantee that l < r.
            in << l << " " << r << "\n";
        }
    }
    // Example of code of random test is above.
    in.close(); // close file input.in
}


int main()
{
    // number of test cases
    const int tc = 10;

    // files' names
    const string 
    code_to_test = "myCode",
    ref_code = "answer",
    input_file = "input",
    code_to_test_output_file = "output",
    ref_code_output_file = "answer";

    Admin admin = Admin(code_to_test, ref_code, input_file, code_to_test_output_file, ref_code_output_file);
    // build files of code & answer once
    admin.build();

    CompareFiles cf = CompareFiles(code_to_test_output_file, ref_code_output_file);


    for (int i = 1; i <= tc; ++i)
    {
        cout << "test " << i << ":\n";
        buildTests();
        admin.run();
        if (!cf.compare())
        {
            cout << "failed in test " << i << "\n";
            break;
        }
        else
        {
            cout << "AC\n";
        }
    }

    return 0;
}
