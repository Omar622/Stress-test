# Stress Test

Stress Test is a tool for comparing the output of two executable files given the same random input multiple times.
This can be useful for testing the correctness of code or finding the case that cause code to fail.

## Idea of stress test

Stress test can check correctness of the code and find a case causes code to fail if exist but how ? I would tell to you..
Imagine you have code you want to test call it `test` and you have also a code that do the same task as `test` do call it `answer`
then you should implement code generates random input every time you run it call it `generator` (assumed `test` and `answer` take same input in the same format).
After that you would give the binary files of `test`, `answer` and `generator` to the stress test tool and it will make the whole test for you.
The tool will run `generator` then run `test` and `answer` reading input form generator output then check if their outputs are identical. The tool will make this process multiple times and if the outputs are identical in all times that means your `test` is correct otherwise it will give you the case that fails `test`.

## Notes

1. The `generator` output is the input of `test` and `answer` and it must be compatible with the way `test` and `answer` reading input.
2. Stress test program is a executable `c++` code.
3. The tool works for windows and linux.

## Features

1. It doesn't matter the programming languages only the executable files are needed.
2. The tool saves the last used executable files' paths.

## How to use

-   Impelement the `generator` file then build it and remember its executable file path.
    -   If you use `c++` this [library](https://github.com/Omar622/Random-generator) will help you a lot to generate random stuff.
-   Build `test` and `answer` and remember their executable files paths.
-   Run the Stress Test program, specifying the paths to `test`, `answer`, and `generator`.
    -   You can get stress test program from releases or by build `src\main.cpp` from the source code.
-   The Stress Test program will then handle the rest, running both executable files with the same random input and comparing their output.

![animation](https://drive.google.com/file/d/15gRj1mPn21tB8G43mISt0Ub9K0MMzhaD/view?usp=sharing)

## Upcoming

Add fetures such as:

1. Test interactive problems.
2. Add more comparators such as:
    - single or more doubles with EPS.
    - single or more int64, ignore whitespaces.
    - compare lines, ignore whitespaces.
