#include<iostream>
#include "Random-generator\random_generator_lib.h"

// sum numbers form 1 to number
long long sum_sequence(long long number){
    return number * (number+1) / 2;
}

int main(){
    const int N = 1e5;
    int number = random32(0, N);

    long long sum = sum_sequence(number);
    std::cout << sum << "\n";

    return 0;
}