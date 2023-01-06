#include <stdlib.h>
#include <string>
#include <iostream>
#include <algorithm>

#include "file_control.h"

FileControl::FileControl(std::string exe_file_path, std::string input_file_path, std::string output_file_path)
    : exe_file_path(exe_file_path), input_file_path(input_file_path), output_file_path(output_file_path) {}

// excute exe_file
void FileControl::run()
{
    std::string command = exe_file_path;

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
    {
        std::cerr << "Exception: " << error_message << "\n";
        throw;
    }
}
