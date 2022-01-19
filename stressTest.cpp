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
using namespace std;

string buildHugeNumber(int n){ // string of random number of n digit
    string str(n, ' ');
    for(int i = 0; i < n; ++i){
        str[i] = '0' + (rand() % 9);
    }
    return str;
}

long long randll(){ // random long long
    return (long long)rand() * rand() * rand*() * rand();
}

void buildTests(){
    ofstream in("input.in");

    // build here random test case

    int test_case = 1; // number of test cases
    in << test_case << "\n";
    while(test_case--){
        int array_size = rand() % 100 + 1; // size of array
        in << array_size << "\n";
        int MAX_VALUE = 1e9;
        for(int i = 0; i < array_size; ++i){ // printing array
            int x = randll() % MAX_VALUE + 1;
            in << x << " ";
        }
        in << "\n";

        int query = rand() % 100 + 1; // number of queries
        in << query << "\n";
        for(int i = 0; i < query; ++i){
            int l = rand() % array_size; // random number from 0 to n-1
            int r = rand() % array_size; // random number from 0 to n-1
            if(r < l) swap(l, r); // garantee that l < r.
            in << l << " " << r << "\n";
        }
    }
    // Example of code of random test is above.
    in.close(); // close file input.in
}

void build(){ // build myCode.cpp and answer.cpp
    int _;
    _ = system("g++ -o output.exe myCode.cpp");
    _ = system("g++ -o answer.exe answer.cpp");
}

void run(){ // excute answer.exe and output.exe
    int _;
    _ = system("answer.exe < input.in > answer.out");
    _ = system("output.exe < input.in > output.out");
}

void get_files(vector<string>& out_vec, vector<string>& ans_vec){
    string temp;

    ifstream out_file("output.out");
    while(getline(out_file, temp)){
        out_vec.emplace_back(temp);
    }
    out_file.close();

    ifstream ans_file("answer.out");
    while(getline(ans_file, temp)){
        ans_vec.emplace_back(temp);
    }
    ans_file.close();
}

bool check(){
    vector<string> out;
    vector<string> ans;

    get_files(out, ans);

    if((int)out.size() != (int)ans.size()){
        cout << "files has no equel sizes\n";
        return false;
    }

    int i = 0;
    for(; i < (int)out.size() && i < (int)ans.size(); ++i){
        if(ans[i] != out[i]){
            cout << "WA in line " << i+1 << "\nexpected " << ans[i] << ", but found " << out[i] << "\n";
            return false;
        }
    }

    return true;
}

int main(){
    srand(time(0)); // make random values depending on time of running.
    
    build(); // build files of code & answer once
    int tc = 100; // number of test cases
    for(int i = 1; i <= tc; ++i){
        cout << "test " << i << ":\n";
        buildTests();
        run();
        if(!check()){
            cout << "failed in test " << i << "\n";
            break;
        }else{
            cout << "AC\n";
        }
    }
    
    return 0;
}
