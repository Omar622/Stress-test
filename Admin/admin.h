#ifndef ADMIN_H
#define ADMIN_H

class Admin
{
    std::string code, answer;                      // cpp code
    std::string input, code_output, answer_output; // files

    void runCommand(std::string, std::string);

public:
    Admin(std::string, std::string, std::string, std::string, std::string);
    void build();
    void run();
};

#include "admin.cpp"

#endif