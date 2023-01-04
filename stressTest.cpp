#include <bits/stdc++.h>
#include "file-control/file_control.h"
#include "checker/compare_files.h"
#include "interact/interact.h"
#include "tools/tools.h"

int main()
{
    const std::string
        input_file_path = "inp-out/input.in",
        output_test_file_path = "inp-out/output.out",
        output_answer_file_path = "inp-out/answer.out",
        build_random_test_file_path = "build_random_test.cpp",
        saved_data_file_path = "data/interact.txt";
    
    FileControl::excuted_dir_path = "excuted-files/";

    // program interact with user here.
    Interact interact = Interact(saved_data_file_path);

    // get data after end of interaction.
    int number_of_test_cases = interact.get_number_of_test_cases();
    std::string
        cpp_test_file_path = interact.get_test_file_path(),
        cpp_answer_file_path = interact.get_answer_file_path();

    // preparing files for build and run
    FileControl
        fc_test = FileControl(cpp_test_file_path, input_file_path, output_test_file_path),
        fc_answer = FileControl(cpp_answer_file_path, input_file_path, output_answer_file_path),
        fc_build_tests = FileControl(build_random_test_file_path, "", input_file_path);

    // prepare comparator
    CompareFiles cf = CompareFiles(output_test_file_path, output_answer_file_path);

    // building files
    Interact::print_slow("building...");
    fc_test.build();
    fc_answer.build();
    fc_build_tests.build();
    Interact::print_slow("built successfully.");
    std::cout << "\n\n\n";

    // run test cases
    for (int id = 1; id <= number_of_test_cases; ++id)
    {
        std::cout << "test " << id << ":\n";
        // build random test
        fc_build_tests.run();
        // run both test and answer file
        fc_test.run();
        fc_answer.run();

        // compare outputs
        if (cf.compare())
            std::cout << "status: PASSED\n";
        else
            return (std::cout << "status: FAILED in test " << id << "\n", 0);
    }

    return 0;
}
