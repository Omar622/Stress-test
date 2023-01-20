#include<iostream>
#include<cmath>

// sum numbers form 1 to number
long long sum_sequence(long long number){
    return number * (number+1) / 2;
}

int main(){
    long long sum;
    std::cin >> sum;
    
    const int N = 1e5;
    for(int i = 0; i <= N; ++i){
        if(sum == sum_sequence(i)){
            std::cout << i << "\n";
            break;
        }
    }

    return 0;
}