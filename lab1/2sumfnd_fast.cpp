#include <iostream>
#include <chrono>
#include <random>
using namespace std;

#ifndef N
#define N 1000
#endif


void fnd_sum_fast(int k, int array[N], int n){
    int r = n - 1, l = 0;
    while (r >= l){
        if (array[r] + array[l] > k){
            r--;
        } else if (array[r] + array[l] < k){
            l++;
        } else {
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
    std::sort(std::begin(array), std::end(array));
}

int main(){
    freopen("2sumfnd_fast_output.txt", "w", stdout);
    int arr[N];
    generator(arr);

    for(int i = 50; i < N; i += 50){
        auto begin = std :: chrono :: steady_clock ::now(); 

        for (int j = 0; j < 100; j++){
            fnd_sum_fast(-1, arr, i);
        }

        auto end = std :: chrono :: steady_clock ::now();
        auto time_span = std :: chrono :: duration_cast < std :: chrono :: microseconds > (end - begin );
        std::cout << i << " " << time_span.count()/100.0 << std::endl;
    }
}