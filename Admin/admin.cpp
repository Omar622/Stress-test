#include <stdlib.h>
#include <string>
#include <iostream>

#include "admin.h"

void Admin::runCommand(std::string command, std::string error_message)
{
    const char *command_cstr = command.c_str();

    int ret = system(command_cstr);
    if (ret)
    {
        std::cerr << "Exception: " << error_message << "\n";
        throw;
    }
}

Admin::Admin(std::string code, std::string answer, std::string input, std::string code_output, std::string answer_output)
    : code(code), answer(answer), input(input), code_output(code_output), answer_output(answer_output) {}

// build myCode.cpp and answer.cpp
void Admin::build()
{
    std::string command1 = "g++ -o output.exe " + code + ".cpp";
    std::string command2 = "g++ -o answer.exe " + answer + ".cpp";
    runCommand(command1, "can not build " + code + ".cpp");
    runCommand(command2, "can not build " + answer + ".cpp");
}

// excute answer.exe and output.exe
void Admin::run()
{
    std::string command1 = "output.exe < " + input + ".in > " + code_output;
    std::string command2 = "answer.exe < " + input + ".in > " + answer_output;
    runCommand(command1, "can not excute output.exe");
    runCommand(command2, "can not excute answer.exe");
}
