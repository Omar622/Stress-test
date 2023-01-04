#include <stdlib.h>
#include <string>
#include <iostream>
#include <algorithm>

#include "file_control.h"

FileControl::FileControl(std::string cpp_file_path, std::string input_file_path, std::string output_file_path)
    : cpp_file_path(cpp_file_path), input_file_path(input_file_path), output_file_path(output_file_path)
{
    exe_file_path = path_to_exe_path(cpp_file_path);
}

// build cpp_file
void FileControl::build()
{
    std::string command = "g++ -o \"" + exe_file_path + "\" \"" + cpp_file_path + "\"";
    runCommand(command, "couldn't build " + path_to_name(cpp_file_path));
}

// excute exe_file
void FileControl::run()
{
    std::string command = "\"";

    command += "\"" + exe_file_path + "\"";
    if (input_file_path != "")
        command += " < \"" + input_file_path + "\"";
    if (output_file_path != "")
        command += " > \"" + output_file_path + "\"";

    command += "\"";

    runCommand(command, "couldn't excute " + path_to_name(exe_file_path));
}

// convert ..\..\foo.cpp to excuted_dir_path/foo.exe
std::string FileControl::path_to_exe_path(std::string path)
{
    std::string file_name = path_to_name(path);
    if (file_name.find(".") == -1)
    {
        std::cerr << "Exception: path_to_exe_path parameter is invalid\n";
        throw;
    }
    while (file_name.back() != '.')
        file_name.pop_back();
    file_name += "exe";
    return excuted_dir_path + file_name;
}

// convert ..\..\foo.cpp to foo.cpp
std::string FileControl::path_to_name(std::string path)
{
    std::string name = "";
    while (!path.empty() and path.back() != '\\' and path.back() != '/')
        name.push_back(path.back()), path.pop_back();
    reverse(name.begin(), name.end());
    return name;
}

void FileControl::runCommand(std::string command, std::string error_message)
{
    const char *command_cstr = command.c_str();
    if (system(command_cstr))
    {
        std::cerr << "Exception: " << error_message << "\n";
        throw;
    }
}

std::string FileControl::excuted_dir_path;