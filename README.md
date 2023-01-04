# Stress Test project

## Overview
Many and many times in competitve programming when you have a solution got WA (wrong answer) and you are suffering and can not find a case fails your code. Now, you have to stress test your code. The idea of stress test is to give random input (test case) to code you know (or feel) it fails at some case and give the same input to code you are sure it is correct then compare the output of both codes and report the status wether it is identical or conflict. In this project you give the both codes and write code to generate suitable random input so the project manages all the rest for you, it will generate multiple test cases and tell you the case that fail your code. Basically, I made this project to help me test my code easily. Especially when I was doing competitive programming most of time.

## How to use project
All you have to do after downlad this project in your device is to:
  1. Write code that generates suitable random input in `build_random_test.cpp`.
  2. Run `stressTest.cpp` and it will interact with you to complete the stress test process.

## Note
  1. The project only runs on `windows` and it needs `c++ `compiler (`g++` command should be working).
  2. There are some helpful functions pre written for you. They may help in `generating random test code`
      [see](https://github.com/Omar622/Stress-test/TOOLS.md)

## Upcoming
  Add fetures such as:
   1. Test interactive problems.
   2. Add more comparators such as:
      * single or more doubles with EPS.
      * single or more int64, ignore whitespaces.
      * compare lines, ignore whitespaces.
