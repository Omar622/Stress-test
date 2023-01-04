#ifndef INTERACT_H
#define INTERACT_H

class Interact
{
    std::string cpp_test_file_path, cpp_answer_file_path, saved_data_file_path;
    int number_of_test_cases;

    void read_file();
    void write_file();
    void read_user_data();
    void print_user_data();

public:
    Interact(std::string);
    static void print_slow(std::string);
    std::string get_test_file_path();
    std::string get_answer_file_path();
    int get_number_of_test_cases();
};

#include "interact.cpp"

#endif