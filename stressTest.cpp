#include <bits/stdc++.h>
#include "file-control/file_control.h"
#include "checker/compare_files.h"
#include "tools/tools.h"

using namespace std;

int main()
{
    int tc; // number of test cases

    string cpp_test_file_path, cpp_answer_file_path;
    cout << "Hello there!,\n\nenter test file path (expect cpp file): \n";
    cin >> cpp_test_file_path;
    cout << "enter answer file path (expect cpp file): \n";
    cin >> cpp_answer_file_path;
    cout << "enter number of test cases: \n";
    cin >> tc;

    const string
        input_file_path = "input.in",
        output_test_file_path = "output.out",
        output_answer_file_path = "answer.out",
        build_random_test_file_path = "build_random_test.cpp";

    FileControl fc_test = FileControl(cpp_test_file_path, input_file_path, output_test_file_path);
    FileControl fc_answer = FileControl(cpp_answer_file_path, input_file_path, output_answer_file_path);
    FileControl fc_build_tests = FileControl(build_random_test_file_path, "", input_file_path);

    cout << "building...\n";
    fc_test.build();
    fc_answer.build();
    fc_build_tests.build();
    cout << "built successfully.\n\n";

    CompareFiles cf = CompareFiles(output_test_file_path, output_answer_file_path);

    for (int i = 1; i <= tc; ++i)
    {
        cout << "test " << i << ":\n";
        fc_build_tests.run();
        fc_test.run();
        fc_answer.run();

        if (!cf.compare())
            return (cout << "failed in test " << i << "\n", 0);
        else
            cout << "AC\n";
    }

    return 0;
}
