#include <iostream>
#include <chrono>
#include <random>
using namespace std;

#ifndef N
#define N 1000
#endif


void fnd_sum(int k, int array[N], int n){
    for(int i = 0; i < n; i++){
        for(int j = i + 1; j < n; j++){
            if(array[i] + array[j] == k){
                return;
            }
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
    freopen("2sumfnd_output.txt", "w", stdout);
    int arr[N];
    generator(arr);

    for(int i = 50; i < N; i += 50){
        auto begin = std :: chrono :: steady_clock ::now(); 

        for (int j = 0; j < 100; j++){
            fnd_sum(-1, arr, i);
        }

        auto end = std :: chrono :: steady_clock ::now();
        auto time_span = std :: chrono :: duration_cast < std :: chrono :: microseconds > (end - begin );
        std::cout << i << " " << time_span.count()/100.0 << std::endl;
    }
}