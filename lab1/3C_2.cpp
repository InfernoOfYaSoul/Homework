#include <iostream>
#include <chrono>
#include <random>
using namespace std;

#ifndef N
#define N 500000
#endif

int cntr[N+1];

void lin(int value, int (&array)[N], int n){
    for(int i = 0; i < n; i++){
        if (array[i] == value & array[i] != array[0]){
            cntr[i]++;
            return;
        }
        if(cntr[i] < cntr[i + 1]){
            swap(cntr[i], cntr[i + 1]);
            swap(array[i], array[i + 1]);
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
    freopen("3C_2.txt", "w", stdout);
    int arr[N];
    generator(arr);

    for(int i = 200; i < N; i += 800){
        std::default_random_engine rng(1001);
	    std::uniform_int_distribution<unsigned> dstr(0, N);

        int k = 0;
        auto begin = std :: chrono :: steady_clock ::now(); 

        for(int j = 500; j > 0; j--){
            k = dstr(rng);
            if (k % 2 == 0){
                k = rand()%10+1;
            }
            lin(k, arr, i);
        }

        auto end = std :: chrono :: steady_clock ::now();
        auto time_span = std :: chrono :: duration_cast < std :: chrono :: microseconds > (end - begin );
        std::cout << i << " " << time_span.count()/100.0 << std::endl;
    }
}