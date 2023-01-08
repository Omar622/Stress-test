#include <iostream>
#include <string>

#include "../include/file_control.h"

// constructor read the executable, input and output files' paths
FileControl::FileControl(std::string exe_file_path, std::string input_file_path, std::string output_file_path)
    : exe_file_path(exe_file_path), input_file_path(input_file_path), output_file_path(output_file_path) {}

// execute exe_file
void FileControl::run()
{
    std::string command = exe_file_path;

    // handle the existence of input, output files
    if (input_file_path != "")
        command += " < " + input_file_path;
    if (output_file_path != "")
        command += " > " + output_file_path;

    runCommand(command, "couldn't execute " + exe_file_path);
}

// excute command in cmd
void FileControl::runCommand(std::string command, std::string error_message)
{
    const char *command_cstr = command.c_str();
    if (system(command_cstr))
        throw std::invalid_argument(error_message);
}
