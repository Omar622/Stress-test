## Example

This is example illustrating the idea of stress test and how to use it. (written in `C++`)

## Here I have
1. Code do some task. (in file [test](https://github.com/Omar622/Stress-test/blob/main/example/test.cpp))
    - The task is:
        - Given 64-bit integer `N` as input. `(0 <= N <= 5000050000)`
        - You have to find `X` such that `1 + 2 + ... + X-1 + X = N`.
        - It is guaranteed there is always a solution with the given input.
    - The code solves this task by formula `X = sqrt(2*N)` and I am not sure if this formula is correct.
2. Code do the same task but I am sure it would do it correctly. (in file [answer](https://github.com/Omar622/Stress-test/blob/main/example/answer.cpp))
    - The code solves the same task by linear search
        - Loop for all numbers from 0 to 100000 and check if sum numbers form 0 to current number is equal to `N` or not.
        - Break from loop when number is found.
3. Code generates random input at every time it is run. (in file [generator](https://github.com/Omar622/Stress-test/blob/main/example/generator.cpp))
    - I used here [Random Generator Library](https://github.com/Omar622/Random-generator) to help me generates random stuff by `C++`.

## Using stress test

After downloading stress test tool Here's illustrating video.

https://user-images.githubusercontent.com/64589450/213822235-603a95e3-2113-4f64-8c9a-db3f55191023.mp4

As you can see the formula is working and `test` code is correct.

Here's `input`, `output`, and `answer` files content within running stress test.

https://user-images.githubusercontent.com/64589450/213824843-38376119-4b01-4a66-8c4c-7878967a6b01.mp4
