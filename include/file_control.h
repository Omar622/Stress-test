#ifndef FILECONTROL_H
#define FILECONTROL_H

/**
 * @brief 
 * Definition of the CompareFiles class. it manages running of executable file 
 * and the case of input, output parameters.
 */

class FileControl
{
    std::string exe_file_path, input_file_path, output_file_path;

public:
    static void runCommand(std::string, std::string);

    FileControl(std::string, std::string, std::string);
    // execute exe_file_path and give input, output files if exist
    void run();
};

#include "../src/file_control.cpp"

#endif