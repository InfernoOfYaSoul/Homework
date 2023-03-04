#include <iostream>
#include <chrono>
#include <random>
using namespace std;

#ifndef N
#define N 1000000
#endif


void bin(int value, int (&array)[N], int r, int l = 0){
    while(r >= l){
        int mid = l + (r - l) / 2;
        if (array[mid] > value){
            r = mid - 1;
        } else if (array[mid] < value){
            l = mid + 1;
        } else {
            return;
        }
    }
    return;
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
    freopen("1bin_output.txt", "w", stdout);
    int arr[N];
    generator(arr);

    for(int i = 5000; i < N; i += 5000){
        auto begin = std :: chrono :: steady_clock ::now(); 

        for (int j = 0; j < 300; j++){
            bin(-1, arr, i);
        }

        auto end = std :: chrono :: steady_clock ::now();
        auto time_span = std :: chrono :: duration_cast < std :: chrono :: nanoseconds > (end - begin );
        std::cout << i << " " << time_span.count()/300.0 << std::endl;
    }
}