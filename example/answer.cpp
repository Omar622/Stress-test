#include<iostream>

int main(){
    long long sum;
    std::cin >> sum;
    
    const int N = 1e5;
    long long current_sum = 0;
    for(int i = 0; i <= N; ++i){
        current_sum += i;
        if(sum == current_sum){
            std::cout << i << "\n";
            break;
        }
    }

    return 0;
}