#include <iostream>
#include <fstream>
#include <string>
#include <windows.h>
#include <sys/stat.h>

#include "interact.h"

// if created new one return true otherwise return false
bool Interact::create_file_if_not_exist(std::string file_name)
{
    // Structure which would store the metadata
    struct stat sb;

    // create file if it doesn't exist
    std::string file_path = environment_dir_name + "/" + file_name;
    if (stat(file_path.c_str(), &sb))
    {
        try
        {
            std::fstream input_file(file_path);
            input_file.close();
        }
        catch (...)
        {
            std::cerr << "Exception: couldn't create " << file_name << " file\n";
            throw;
        }
        return 1;
    }
    return 0;
}

void Interact::read_saved_data()
{
    std::string saved_data_file_path = environment_dir_name + "/" + saved_data_file_name;
    std::ifstream data_file(saved_data_file_path);
    std::string line = "";

    data_file >> line;
    exe_test_file_path = line;

    data_file >> line;
    exe_answer_file_path = line;

    data_file >> line;
    exe_generator_file_path = line;

    data_file >> line;
    try
    {
        number_of_test_cases = stoi(line);
    }
    catch (...)
    {
        number_of_test_cases = 0;
    }

    data_file.close();
}

void Interact::save_new_data()
{
    std::string saved_data_file_path = environment_dir_name + "/" + saved_data_file_name;
    std::ofstream data_file(saved_data_file_path);
    data_file << exe_test_file_path << "\n";
    data_file << exe_answer_file_path << "\n";
    data_file << exe_generator_file_path << "\n";
    data_file << number_of_test_cases << "\n";
    data_file.close();
}

void Interact::enter_user_data()
{
    std::cout << "Please, executable file path you want to test. (Expect .exe file):\n";
    std::cin >> exe_test_file_path;

    std::cout << "Enter the refrence executable file path. (Expect .exe file):\n";
    std::cin >> exe_answer_file_path;

    std::cout << "Enter the generator executable file path. (Expect .exe file):\n";
    std::cin >> exe_generator_file_path;

    std::cout << "Enter number of tests.\n";
    std::cin >> number_of_test_cases;
    number_of_test_cases = std::max(number_of_test_cases, 0); // in case user entered negative number.
}

void Interact::print_saved_data()
{
    std::cout << "_______________________________________________________\n";
    std::cout << "path of the executable test file: " << exe_test_file_path << "\n";
    std::cout << "path of the executable refrence file: " << exe_answer_file_path << "\n";
    std::cout << "path of the executable generator file: " << exe_generator_file_path << "\n";
    std::cout << "number of test cases: " << number_of_test_cases << "\n";
    std::cout << "_______________________________________________________\n";
}

// if there is data saved return true otherwise return false
bool Interact::init()
{
    // Structure which would store the metadata
    struct stat sb;

    std::string dir_path = environment_dir_name + "/";
    // create environment directory if it doesn't exist
    if (stat(dir_path.c_str(), &sb))
    {
        if (mkdir(environment_dir_name.c_str()) == -1)
        {
            std::cerr << "Exception: couldn't create environment directory\n";
            throw;
        }
    }

    bool is_there_data_saved = create_file_if_not_exist(saved_data_file_name);
    create_file_if_not_exist(input_file_name);
    create_file_if_not_exist(test_output_file_name);
    create_file_if_not_exist(answer_output_file_name);

    read_saved_data();

    return is_there_data_saved;
}

Interact::Interact()
{
    bool is_first_time = init();

    std::string flag = "0";
    if (!is_first_time)
    {
        std::cout << "Last used data ^_^\n";
        print_saved_data();
        std::cout << "Enter 1 for use the last used data or enter 0 to use new data.\n";
        while (std::cin >> flag)
            if (flag == "1" or flag == "0")
                break;
            else
                std::cout << "INVALID INPUT. only 0 and 1 are valid.\n";
    }

    if (flag == "0")
    {
        enter_user_data();
        save_new_data();
        std::cout << "Data updated ^_^\n";
        print_saved_data();
    }

    std::cout << "\n";
    std::cout << "Here we goooooooooooooo\n";
    std::cout << "\n\n\n";
}

std::string Interact::get_exe_test_file_path()
{
    return exe_test_file_path;
}

std::string Interact::get_exe_answer_file_path()
{
    return exe_answer_file_path;
}

std::string Interact::get_exe_generator_file_path()
{
    return exe_generator_file_path;
}

std::string Interact::get_input_file_path()
{
    return environment_dir_name + "/" + input_file_name;
}

std::string Interact::get_test_output_file_path()
{
    return environment_dir_name + "/" + test_output_file_name;
}

std::string Interact::get_answer_output_file_path()
{
    return environment_dir_name + "/" + answer_output_file_name;
}

int Interact::get_number_of_test_cases()
{
    return number_of_test_cases;
}