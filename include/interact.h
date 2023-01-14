#ifndef INTERACT_H
#define INTERACT_H

#include <iostream>
#include <algorithm>
#include <fstream>
#include <string>
#include <sys/stat.h>

#include "../include/file_control.h"

/**
 * @brief 
 * Definition of the Interact class. it manages interaction with user 
 * and get all needed input from user.
 * first it checks the environment and create the non existing files
 * so it detects if it is first use for user or not then
 * offer user to use the last used data or insert new data.
 * (in case first use it will not offer user it will ask him for data directly)
 * that is all it do just preparing.
 * 
 * it also can save current data or retrieve last used one.
 * is saves and read from file ('environment_dir/saved_data_file') in the same order.
 */

class Interact
{
    // names of files and directories of the environment (it will not be created if it is not exist)
    const std::string 
    environment_dir_name = "stress_test_env",
    saved_data_file_name = "data.txt",
    input_file_name = "input.txt",
    test_output_file_name = "output.txt",
    answer_output_file_name = "answer.txt";

    // executable files and number of test cases that will be read from user.
    std::string exe_test_file_path, exe_answer_file_path, exe_generator_file_path;
    int number_of_test_cases;

    // is it first time for user to use this tool?
    bool is_first_use;

    // helping method: creates file if not exist. take file path as parameter
    bool create_file_if_not_exist(std::string);

    // helping method: check if it is exe file and it does exist.
    bool check_exe_file_path(std::string);

    // read integer from user
    int enter_non_negative_integer();

    // enter path process from user
    void enter_path(std::string, std::string&);

    // read last used data from precreated environment into class fields.
    void read_saved_data();
    // save current data (class fields) into environment for the future uses.
    void save_new_data();

    // // read needed input from user
    // void enter_user_data();
    // show current data (class fields)
    void print_saved_data();
    
    /*
        prepare environment (create missing files or dir).
        return false if saved_data_file not existing otherwise return true.
    */
    void init();

public:
    // constructor: manage all the interaction process with user and call all methods.
    Interact();

    // getters
    std::string get_exe_test_file_path();
    std::string get_exe_answer_file_path();
    std::string get_exe_generator_file_path();

    std::string get_input_file_path();

    std::string get_test_output_file_path();
    std::string get_answer_output_file_path();

    int get_number_of_test_cases();
};

#include "../src/interact.cpp"

#endif