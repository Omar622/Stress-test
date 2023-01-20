# Stress Test

Stress Test is a tool for comparing the output of two executable files given the same random input multiple times.
This can be useful for testing the correctness of code or finding the case that cause code to fail.

![stress-test-tool-github](https://user-images.githubusercontent.com/64589450/213480507-ecca4f60-2608-4d9d-9a26-cf9e5c1168e2.gif)


## Idea of stress test

Stress test can check correctness of the code and find a case causes the code to fail if exist but how ? I would tell to you.

First, I would suppose you have the following:
1. Code you want to test. build it and let us call its executable file `test`.
2. Refrence code or answer. It is a code does the same thing as `test` but you are sure it makes it correctly. build it and let us call its executable file `answer`.
3. Generator code, every time this code is run it will output a valid random input for `test` and `answer`. build it and let us call its executable file `generator`.

![Blank diagram - stress test](https://user-images.githubusercontent.com/64589450/213823040-ee8804f2-6345-4751-98b6-8e336f5eef0d.svg)

stress test program is doing the process shown in the figure above. Additionally, you can specify `number of test cases` (maximum number the cycle in the figure will repeat in case no conflict found in outputs)

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
-   Build `test` and `answer` and remember their executable files' paths.
-   Run the Stress Test program, specifying the paths to `test`, `answer`, and `generator` and `number of test cases`.
    -   You can get stress test program from releases or by run `src\main.cpp` from the source code.
-   The Stress Test program will then handle the rest, running all executable files and comparing outputs.
-   See [Example](https://github.com/Omar622/Stress-test/tree/main/example) for more clarificationز

## Upcoming

Add fetures such as:

1. Add more comparators such as:
    - single or more int64, ignore whitespaces.
    - single or more doubles with EPS.
    - compare lines, ignore whitespaces.
2. Calculate average code time.
3. Test interactive problems.
