# Stress Test

Stress Test is a tool for comparing the output of two executable files given the same random input multiple times.
This can be useful for testing the correctness of code or finding the case that cause code to fail.
![stress-test](https://user-images.githubusercontent.com/64589450/213825858-04b50328-50b8-4745-a91b-45bad81b0f45.gif)
*The above Gif shows stress test tool testing code that hardly fails (faild at first time but not in the second time).

## Idea of stress test

Stress test can check correctness of the code and find a case causes the code to fail if exist but how ? I would tell to you.

First, I would suppose you have the following:
1. Code you want to test. build it and let us call its executable file `test`.
2. Refrence code or answer. It is a code do the same task as `test` but you are sure it makes it correctly. build it and let us call its executable file `answer`.
3. Generator code, every time this code is run it will output a valid random input for `test` and `answer`. build it and let us call its executable file `generator`.

![Blank diagram - stress test](https://user-images.githubusercontent.com/64589450/213823040-ee8804f2-6345-4751-98b6-8e336f5eef0d.svg)

stress test program is doing the process shown in the figure above. Additionally, you can specify `number of test cases` (maximum number the cycle in the figure will repeat in case no conflict happened in outputs)

## Notes

1. The `generator` output is the input of `test` and `answer` and it must be compatible with the way `test` and `answer` reading input.
2. The tool works for windows and linux.
3. Stress test program is a executable `c++` code.

## Features

1. It doesn't matter the programming languages only the executable files are needed.
2. You can use the tool with the last used executablel files without entering their paths again.
3. Toos is handling most common errors.
    - Check if the given path is exist.
    - Check if the file is executalbe.
    - Check valid integer or {0, 1} while reading input.
3. Here's a [library](https://github.com/Omar622/Random-generator) will help you implementing generator if you a `C++` coder.

## How to use

-   Impelement the `generator` file then build it and remember its executable file path.
    -   If you use `C++` this [library](https://github.com/Omar622/Random-generator) will help you a lot to generate random stuff.
-   Build `test` and `answer` and remember their executable files' paths.
-   Run the Stress Test program, specifying the paths to `test`, `answer`, and `generator` and `number of test cases`.
    -   You can get stress test program from releases or by run `src\main.cpp` from the source code.
-   The Stress Test program will then handle the rest, running all executable files and comparing outputs.
-   See [Example](https://github.com/Omar622/Stress-test/tree/main/example) for more clarification.

## Life cycle

In case you are interesting, here's life cycle of the tool from start to terminate.

1. If it's not your first time to use the tool.
    - It will show you the last used paths and ask you if you want to use it now.
        - If you want to use it, the tool will proceed to test.
        - If not, the tool will ask you to enter the paths.
2. Entering data.
    - For path, you can enter path or either make the tool use the last used path.
    - Then entering number of test cases.
3. The tool will create directory `stress_test_env` in the same tool directory and it will contains:
    - `input.txt`.
        - saves output of `generator` code here.
        - `test` and `answer` will read from it.
    - `answer.txt`.
        - saves output of `answer` code here.
    - `output.txt`.
        - saves output of `test` code here.
    - `data.txt`.
        - saves used data here (paths and number of test cases).
4. Start testing.
    1. run `generator`.
        - no input.
        - output: `stress_test_env\intput.txt`.
    2. run `test`.
        - input: `stress_test_env\intput.txt`.
        - output: `stress_test_env\output.txt`.
    3. run `answer`.
        - input: `stress_test_env\intput.txt`.
        - output: `stress_test_env\answer.txt`.
    4. compare `stress_test_env\output.txt` and `stress_test_env\answer.txt`. (string comparsion)
        - If no conflict.
            - If number of test cases is done, terminate the program.
            - otherwise go to `4. Start testing.`
        - otherwise terminate.
            - input causes `test` to fail could be found in `stress_test_env\intput.txt`.
            - output of `test` in `stress_test_env\output.txt`.
            - refrence answer in `stress_test_env\answer.txt`.

## Upcoming

Add fetures such as:

1. Add more comparators such as:
    - single or more int64, ignore whitespaces.
    - single or more doubles with EPS.
    - compare lines, ignore whitespaces.
2. Calculate average code time.
3. Test interactive problems.
