#include <iostream>
#include <chrono>
#include <random>

using namespace std;

#ifndef N
#define N 1000
#endif

void swap(int& lha, int& rha){
    int buffer = lha;
    lha = rha;
    rha = buffer;
}

void generate_array(int (&array)[N]){
    int seed = 1001;
    std::default_random_engine rng(seed);
    std::uniform_int_distribution<unsigned> dstr(0, 1000);
    for(int i = 0; i < N; i++){
        array[i] = dstr(rng);
    }
}
/*
/\︿╱\
\0_ 0 /╱\╱ 
\▁︹_/
*/


int step(int (&array)[N], int k, int n){
    int swp_cntr = 0;
    for(int i = 0; i < n - k; i += k){
        for (int j = i+k; j >=0; j -= k){
            if (array[j] < array[j-1]){
                swap(array[j], array[j-1]);
                swp_cntr++;
            }
        }
    }
    return swp_cntr;
}

int sort(int (&array)[N], int n){
    int cntr = 0;
    for (int i = n/2; i > 0; i /= 2){
        cntr += step(array, i, n);
    }
    return cntr;

}
/*
/\︿╱\
\0_ 0 /╱\╱ 
\▁︹_/
*/

int main(){
    freopen("C1_stat.txt", "w", stdout);
    int arr[N];
    for (int i = 0; i <= N; i += 10){
        int t = 0, swap_cntr = 0;
        for (int j = 0; j < 1000; j++){
            generate_array(arr);
            auto begin = chrono::steady_clock::now();
            swap_cntr += sort(arr, i);
            auto end = chrono::steady_clock::now();
            auto time_span = chrono::duration_cast<chrono::microseconds>(end - begin);
            t += time_span.count();
        }
        cout << i << ' ' << t/1000 << ' ' << swap_cntr/1000 << endl;
    }
    return 0;
}
/*
/\︿╱\
\0_ 0 /╱\╱ 
\▁︹_/
*/
