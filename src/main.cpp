#include <bits/stdc++.h>
#include "../include/file_control.h"
#include "../include/compare_files.h"
#include "../include/interact.h"

int main()
{
    // program interact with user here and get input and prepare the environment.
    Interact interact = Interact();

    // get data after the end of interaction.
    std::string
        exe_test_file_path = interact.get_exe_test_file_path(),
        exe_answer_file_path = interact.get_exe_answer_file_path(),
        exe_generator_file_path = interact.get_exe_generator_file_path(),
        input_file_path = interact.get_input_file_path(),
        test_output_file_path = interact.get_test_output_file_path(),
        answer_output_file_path = interact.get_answer_output_file_path();
    int number_of_test_cases = interact.get_number_of_test_cases();

    // preparing files for run
    FileControl
        test_file_control = FileControl(exe_test_file_path, input_file_path, test_output_file_path),
        answer_file_control = FileControl(exe_answer_file_path, input_file_path, answer_output_file_path),
        generator_file_control = FileControl(exe_generator_file_path, "", input_file_path);

    // prepare comparator
    CompareFiles test_answer_comparator = CompareFiles(test_output_file_path, answer_output_file_path);


    // run test cases
    for (int id = 1; id <= number_of_test_cases; ++id)
    {
        std::cout << "test " << id << ":\n";
        // build random test using generator
        generator_file_control.run();
        // run both test and answer files
        test_file_control.run();
        answer_file_control.run();

        // compare outputs
        if (test_answer_comparator.compare_lines())
            std::cout << "status: PASSED\n";
        else
            return (std::cout << "status: FAILED in test " << id << "\n", 0); // report failed and return
    }

    return 0;
}
