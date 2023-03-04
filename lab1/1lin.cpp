#include <iostream>
#include <chrono>
#include <random>
using namespace std;

#ifndef N
#define N 1000000
#endif


void lin(int array[N], int value, int n){
    for(int i = 0; i < n; i++){
        if(array[i] == value){
            return;
        }
    }
}

void generator(int (&array)[N]){
    int seed = 1001;
    std::default_random_engine rng(seed);
    std::uniform_int_distribution<unsigned> dstr(0, N);
    for(int i = 0; i < N; i++){
        array[i] = dstr(rng);
    }
}

int main(){
    freopen("1lin_output.csv", "w", stdout);
    int arr[N];
    generator(arr);

    for(int i = 5000; i < N; i += 5000){
        auto begin = std :: chrono :: steady_clock ::now(); 

        for (int j = 0; j < 100; j++){
            lin(arr, -1 , i);
        }

        auto end = std :: chrono :: steady_clock ::now();
        auto time_span = std :: chrono :: duration_cast < std :: chrono :: microseconds > (end - begin );
        std::cout << i << " " << time_span.count()/100.0 << std::endl;
    }
}