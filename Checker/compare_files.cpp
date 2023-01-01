#include <string>
#include <vector>
#include <iostream>
#include <fstream>

#include "compare_files.h"

CompareFiles::CompareFiles(std::string code_output, std::string answer_output)
    : code_output(code_output), answer_output(answer_output) {}

void CompareFiles::get_files()
{
    output_vec.clear();
    answer_vec.clear();
    std::string temp;

    std::ifstream out_file(code_output + ".out");

    while (getline(out_file, temp))
        output_vec.emplace_back(temp);

    out_file.close();

    std::ifstream ans_file(answer_output + ".out");
    while (getline(ans_file, temp))
        answer_vec.emplace_back(temp);
    ans_file.close();
}

bool CompareFiles::compare()
{
    get_files();

    if (output_vec.size() != answer_vec.size())
    {
        std::cout << "files has no equel sizes\n";
        return false;
    }

    int i = 0;
    for (; i < output_vec.size() and i < answer_vec.size(); ++i)
    {
        if (answer_vec[i] != output_vec[i])
        {
            std::cout << "WA in line " << i + 1 << "\nexpected " << answer_vec[i] << ", but found " << output_vec[i] << "\n";
            return false;
        }
    }

    return true;
}