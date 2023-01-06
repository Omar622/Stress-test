#ifndef ADMIN_H
#define ADMIN_H

class FileControl
{
    std::string exe_file_path, input_file_path, output_file_path;

public:
    static void runCommand(std::string, std::string);

    FileControl(std::string, std::string, std::string);
    void run();
};

#include "file_control.cpp"

#endif