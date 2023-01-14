#include "../include/interact.h"

/*
    helping method create files if not exist
    if created new one return true otherwise return false
*/
bool Interact::create_file_if_not_exist(std::string file_name)
{
    // Structure which would store the metadata
    struct stat sb;

    // create file if not exist
    std::string file_path = environment_dir_name + "/" + file_name;
    // if file not exist
    if (stat(file_path.c_str(), &sb))
    {
        try
        {
            std::fstream input_file(file_path);
            input_file.close();
        }
        catch (...)
        {
            throw std::invalid_argument("couldn't create " + file_name + " file");
        }
        return 1;
    }
    return 0;
}

// helping method: return true if file exist and executable otherwise return false
bool Interact::check_exe_file_path(std::string file_path)
{
    // check if it is .exe file or no extension
    int last_dot_index = file_path.find_last_of('.');
    if (~last_dot_index) // no '.' exist
    {
        int last_slash_index = file_path.find_last_of('/');
        int last_back_slash_index = file_path.find_last_of('\\');
        if (last_dot_index == std::max({last_dot_index, last_slash_index, last_back_slash_index}))
        {
            if (last_dot_index != file_path.size() - 4 or file_path.substr(last_dot_index + 1) != "exe")
            {
                std::cout << "Not .exe file. ";
                return 0;
            }
        }
    }

    // Structure which would store the metadata
    struct stat sb;
    // it file not exist
    if (stat(file_path.c_str(), &sb))
    {
        std::cout << "File not exist. ";
        return 0;
    }

    return 1;
}

// read valid natural integer from user
int Interact::enter_non_negative_integer()
{
    int input_int;
    bool read_again = 1;
    while (read_again)
    {
        read_again = 0;
        std::string input;
        std::cin >> input;
        try
        {
            input_int = stoi(input);
            if (input_int < 0)
                read_again = 1;
        }
        catch (...)
        {
            read_again = 1;
        }

        if (read_again)
            std::cout << "INVALID NON-NEGATIVE INTEGER, please enter non-negative integer number.\n";
    }
    return input_int;
}

// enter path process from user
void Interact::enter_path(std::string required_file_path, std::string &read_in)
{
    while (true)
    {
        std::cout << "Enter the " << required_file_path << "\n";
        if (!is_first_use)
            std::cout << "or enter 1 to use the last used path\n";

        std::string input;
        std::cin >> input;

        if (!is_first_use and input == "1")
        {
            if (check_exe_file_path(read_in))
                return;
        }
        else
        {
            if (check_exe_file_path(input))
            {
                read_in = input;
                return;
            }
        }

        std::cout << "INVALID PATH.\n";
    }
}

// read saved data (last used data) from 'environment_dir/saved_data_file'
void Interact::read_saved_data()
{
    std::string saved_data_file_path = environment_dir_name + "/" + saved_data_file_name;
    // open data file
    std::ifstream data_file(saved_data_file_path);
    std::string line = "";

    // raed
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

    // close data file
    data_file.close();
}

// write current data (class fields) into 'environment_dir/saved_data_file'
void Interact::save_new_data()
{
    std::string saved_data_file_path = environment_dir_name + "/" + saved_data_file_name;
    // open data file
    std::ofstream data_file(saved_data_file_path);
    // write
    data_file << exe_test_file_path << "\n";
    data_file << exe_answer_file_path << "\n";
    data_file << exe_generator_file_path << "\n";
    data_file << number_of_test_cases << "\n";
    // close file
    data_file.close();
}

// show current data (class fields) to user
void Interact::print_saved_data()
{
    std::cout << "_______________________________________________________\n";
    std::cout << "path of the executable test file: " << exe_test_file_path << "\n";
    std::cout << "path of the executable reference file: " << exe_answer_file_path << "\n";
    std::cout << "path of the executable generator file: " << exe_generator_file_path << "\n";
    std::cout << "number of test cases: " << number_of_test_cases << "\n";
    std::cout << "_______________________________________________________\n";
}

/*
    prepare environment (create missing files or dir).
    return false if saved_data_file not existing otherwise return true.
*/
void Interact::init()
{
    // Structure which would store the metadata
    struct stat sb;

    std::string dir_path = environment_dir_name + "/";
    // create environment directory if it doesn't exist
    if (stat(dir_path.c_str(), &sb)) // if not exist
    {
        // call static method of file control class to run command on cmd
        FileControl::runCommand("mkdir " + environment_dir_name, "Exception: couldn't create environment directory");
    }
    // create files if not exist
    // if saved_data_file not exist the program will suppose that it is the first use for the user.
    is_first_use = create_file_if_not_exist(saved_data_file_name);
    create_file_if_not_exist(input_file_name);
    create_file_if_not_exist(test_output_file_name);
    create_file_if_not_exist(answer_output_file_name);

    // after environment is good, read saved data
    read_saved_data();
}

// constructor: manage whole process and interact with user
Interact::Interact()
{
    init();

    int flag = 0;
    if (!is_first_use)
    {
        std::cout << "Last used data ^_^\n";
        print_saved_data();
        std::cout << "Enter 1 for use the last used data or enter 0 to use new data.\n";
        flag = enter_non_negative_integer();
        while (flag > 1)
        {
            std::cout << "INVALID INPUT. only 0 and 1 are valid.\n";
            flag = enter_non_negative_integer();
        }
    }

    if (!flag)
    {
        // enter user data
        enter_path("executable file path you want to test:", exe_test_file_path);
        enter_path("reference executable file path:", exe_answer_file_path);
        enter_path("generator executable file path:", exe_generator_file_path);
        std::cout << "Enter number of tests.\n";
        number_of_test_cases = enter_non_negative_integer();
        
        save_new_data();
        std::cout << "Data updated ^_^\n";
        print_saved_data();
    }

    std::cout << "\nHere we goooooooooooooo\n\n";
}

// getters
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