#ifndef INTERACT_H
#define INTERACT_H

class Interact
{
    const std::string 
    environment_dir_name = "stress_test_env",
    saved_data_file_name = "data.txt",
    input_file_name = "input.in",
    test_output_file_name = "output.out",
    answer_output_file_name = "answer.out";

    std::string exe_test_file_path, exe_answer_file_path, exe_generator_file_path;
    int number_of_test_cases;

    bool create_file_if_not_exist(std::string);

    void read_saved_data();
    void save_new_data();

    void enter_user_data();
    void print_saved_data();

    bool init();

public:
    Interact();

    std::string get_exe_test_file_path();
    std::string get_exe_answer_file_path();
    std::string get_exe_generator_file_path();
    std::string get_input_file_path();
    std::string get_test_output_file_path();
    std::string get_answer_output_file_path();
    int get_number_of_test_cases();
};

#include "interact.cpp"

#endif