#include <iostream>
#include <fstream>
#include <string>
#include <windows.h>

#include "interact.h"

Interact::Interact(std::string saved_data_file_path) : saved_data_file_path(saved_data_file_path)
{
    read_file();
    std::cout << "\n\n";
    print_slow("Hello my friend! I am pleased to help you.");
    std::cout << "\n\n";

    print_slow("Here is the last used data ^_^");
    print_user_data();
    print_slow("If it is your first time to use this program, just IGNORE the last printed data and continue.");
    std::cout << "\n\n";

    std::string flag = "";
    print_slow("would you like to use the last used data ?");
    print_slow("If yes enter 1 otherwise enter 0.");
    print_slow("If it is your first time to use this program, enter 0.");
    while (std::cin >> flag)
        if (flag == "1" or flag == "0")
            break;
        else
            print_slow("INVALID INPUT. Please, if yes enter 1 otherwise enter 0.");

    if (flag == "0")
    {
        read_user_data();
        write_file();
        print_slow("Data updated ^_^");
        print_user_data();
    }

    std::cout << "\n";
    print_slow("Here we goooooooooooooo");
    std::cout << "\n\n\n";
}

void Interact::read_user_data()
{
    print_slow("Please, enter path of the file you want to test. (Expect cpp file):");
    std::cin >> cpp_test_file_path;

    print_slow("Enter path of the refrence file. (Expect cpp file):");
    std::cin >> cpp_answer_file_path;

    print_slow("Enter number of tests.");
    std::cin >> number_of_test_cases;
    number_of_test_cases = std::max(number_of_test_cases, 0); // in case user entered negative number.
}

void Interact::print_user_data()
{
    std::cout << "\n";
    std::cout << "path of the test file: " << cpp_test_file_path << "\n";
    std::cout << "path of the refrence file: " << cpp_answer_file_path << "\n";
    std::cout << "number of test cases: " << number_of_test_cases << "\n";
    std::cout << "___________________________________\n\n\n";
    Sleep(2000);
}

void Interact::read_file()
{
    std::ifstream data_file(saved_data_file_path);
    std::string line = "";

    data_file >> line;
    cpp_test_file_path = line;

    data_file >> line;
    cpp_answer_file_path = line;

    try
    {
        data_file >> line;
        number_of_test_cases = stoi(line);
    }
    catch (...)
    {
        number_of_test_cases = 0;
    }

    data_file.close();
}

void Interact::write_file()
{
    std::ofstream data_file(saved_data_file_path);
    data_file << cpp_test_file_path << "\n";
    data_file << cpp_answer_file_path << "\n";
    data_file << number_of_test_cases << "\n";
    data_file.close();
}

void Interact::print_slow(std::string line)
{
    for (char &c : line)
    {
        std::cout << c;
        Sleep(50);
    }
    std::cout << "\n";
}

std::string Interact::get_test_file_path()
{
    return cpp_test_file_path;
}

std::string Interact::get_answer_file_path()
{
    return cpp_answer_file_path;
}

int Interact::get_number_of_test_cases()
{
    return number_of_test_cases;
}
