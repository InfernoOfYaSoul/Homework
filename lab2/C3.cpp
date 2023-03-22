#include <iostream>
#include <vector>
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

int Fib(vector<int>& f){
    int i = 1;
    while(f[i] <= N){
        f.push_back(f[i-1] + f[i]);
        i++;
    }
    return i - 1;
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

int sort(int (&array)[N], vector<int>& F, int n, int ptr){
    int cntr = 0;
    for (int j = ptr; j >= 1; j--){
        int i = F[j];
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
    freopen("C3_stat.txt", "w", stdout);
    int arr[N];
    vector <int> fib;
    fib.push_back(1);
    fib.push_back(1);
    int pntr = Fib(fib);
    cerr<< pntr<<" "<<fib[pntr];

    for (int i = 0; i <= N; i += 10){
        int t = 0, swap_cntr = 0;
        for (int j = 0; j < 1000; j++){
            generate_array(arr);
            auto begin = chrono::steady_clock::now();
            swap_cntr += sort(arr, fib, i, pntr);
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
