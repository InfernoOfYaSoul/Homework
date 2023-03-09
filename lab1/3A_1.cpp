#include <iostream>
#include <chrono>
#include <random>

#ifndef N
#define N 500000
#endif

void swap(int&lha, int&rha){
    int buffer = lha;
    lha = rha;
    rha = buffer;
}

void lin(int value, int (&array)[N], int n){
    for(int i = 0; i < n; i++){
        if (array[i] == value & i != 0){
            swap(array[i], array[0]);
            return;
        }
    }
    return;
}

void generate_array(int (&array)[N]){
    unsigned seed = 10000;
    std::default_random_engine rng(seed);
    std::uniform_int_distribution<unsigned> dstr(0, N);
    for(int i = 0; i < N; i++){
        array[i] = dstr(rng);
    }
}

int main() {
    freopen("3A_1.txt", "w", stdout);
    int arr[N];
    int k = 0;
    unsigned seed = 1001;
    for(int n = 5000; n <= N; n += 5000){
        std::default_random_engine rng(seed);
	    std::uniform_int_distribution<unsigned> dstr(0, N);
        auto begin = std::chrono::steady_clock::now();
        for(int j = 1000; j > 0; j--){
            k = dstr(rng);
            lin(k, arr, n);
        }
        auto end = std::chrono::steady_clock::now();
        auto time_span = std::chrono::duration_cast<std::chrono::microseconds>(end - begin);
        std::cout << n << ' ' << time_span.count()/1000.0<< std::endl;
    }
    return 0;
}