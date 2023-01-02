#ifndef ADMIN_H
#define ADMIN_H

class FileControl
{
    std::string cpp_file_path, exe_file_path, input_file_path, output_file_path;
    std::string path_to_exe_path(std::string);
    std::string path_to_name(std::string);

public:
    FileControl(std::string, std::string, std::string);
    void build();
    void run();

    static void runCommand(std::string, std::string);
};

#include "file_control.cpp"

#endif