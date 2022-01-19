# Stress Test project
# Overview
many and many times in competitve programming when you have a solution got WA(wrong answer) and you do not know why and can not see any problem with your code. Now, you have to do a stress test. Stress test is a simple idea that if you have a code getting WA(wrong answer) or you want to test it - let us call it "myCode file" - and have a code getting the wright answer and never got WA(wrong answer) - let us call it "answer file" - you can simply give them random test cases to both of them and compare the output of each one to another. If the output of "myCode file" differs form "answer file" then you have a test fails "myCode file". This is the simple idea and what our project do. I made this project to help me test my code easily, specially I do competitive programming most of time.


# How project works
project has 6 files:
  1) "myCode.cpp" where code you want to test should be in.
  2) "answer.cpp" where code generates the wright answer should be in.
  3) "input.in" file where input will be generated in.
  4) "output.out" file where "myCode.cpp" will print its output in.
  5) "answer.out" file where "answer.cpp" will print its output in.
  6) "stressTest.cpp" file that control the whole stress test process.

briefly, in "stressTest.cpp" I make random function refrenced to time of runing file (to differ from time to time), build "myCode.cpp" and "answer.cpp" once, then for number of tests, the project will build random test and run the excuted files and compare the outputs. take care that project compare two outputs as **string comparsion** (case and space senstive). feel free if you want to take this project and update it.  

Note: In the project there is an example of comparing to codes. "myCode.cpp" calculates sum of subarray by prefix sum technique, "answer.cpp" calculates the same by brute force. input is number of test cases in one line and size of array(maximum 100 number) in another line and the array(maximum number is billion) in another line and number of queries in another line and in each line two idices in array refers to the left index and right index you should print the sum of the segment between.


# How to use project
All you have to do after downlad this project in your device is:
  1. set your code(code you want to test) in file "myCode.cpp".
  2. find and set code that generates the reference answer in file "answer.cpp".
  3. open "stressTest.cpp" file and do this:
     - set number of tests you want in "tc" variable in line 110. (put on your consideration the time that your machine will take to run the number of tests you put will fit)
     - write code to build only one random test case in function "buildTests" in line 27.
  4. then run "stressTest.cpp" file in the usual way and you will get to each test:
     - "AC" refers to Accepted (two codes have the same output).
     - "failed in test i" and "WA in line j" and the expected output and your wrong output.
     - "failed in test i" and "files has no equal sizes" means that two codes does not output the same size of output.

PLZ: make sure you have read how project works section above.  
Note: if "myCode.cpp" file failed in a test, the program will stop and you can see the test in "input.in" file and the output in "output.out" and the answer in "answer.out".  
Note: there are some functions like "buildHugeNumber" in line 15 in "stressTest.cpp" file, help to build huge random number of n digit.  
      also "randll" in line 23 in "stressTest.cpp" file, help to get random long long.  
