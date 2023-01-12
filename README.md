# Stress Test

Stress Test is a tool for comparing the output of two executable files given the same random input multiple times. This can be useful for testing the correctness of code or finding the case that cause code to fail.

## Requirements

-   The executable files for the code being tested and the reference code must be in the same format (e.g., both must be Windows executables or both must be Linux executables).
-   The generator code must produce input in a format that is compatible with both the code being tested and the reference code.

## Usage

-   Write code to generate random input for both the code being tested and the reference code.
-   Run the Stress Test program, specifying the paths to the executable files for the code being tested, the reference code, and the generator code.
-   The Stress Test program will then handle the rest, running both executable files with the same random input and comparing their output.

## Overview

Many and many times in competitve programming when you have a solution got WA (wrong answer) and you are suffering and can not find a case fails your code. Now, you have to stress test your code. The idea of stress test is to give random input (test case) to code you know (or feel) it fails at some case and give the same input to code you are sure it is correct then compare the output of both codes and report the status wether it is identical or conflict. In this project you give the both codes and write code to generate suitable random input so the project manages all the rest for you, it will generate multiple test cases and tell you the case that fail your code. Basically, I made this project to help me test my code easily. Especially when I was doing competitive programming most of time.

## How to use project

All you have to do after downlad this project in your device is to:

1. Write code that generates suitable random input in `build_random_test.cpp`.
2. Run `stressTest.cpp` and it will interact with you to complete the stress test process.

## Note

1. The project needs `c++ `compiler (`g++` command should be working).
2. There are some helpful functions pre written for you. They may help in `generating random test code`
   [see](https://github.com/Omar622/Stress-test/blob/main/TOOLS.md)

## Upcoming

Add fetures such as:

1. Test interactive problems.
2. Add more comparators such as:
    - single or more doubles with EPS.
    - single or more int64, ignore whitespaces.
    - compare lines, ignore whitespaces.
