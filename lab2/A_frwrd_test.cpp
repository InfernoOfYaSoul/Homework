#include <iostream>
#include <random>
using namespace std;

#ifndef N
#define N 20
#endif

void swap(unsigned& lha, unsigned& rha){
    unsigned buffer = lha;
    lha = rha;
    rha = buffer;
}

void forward_step(unsigned (&array)[N], unsigned const begin_idx, unsigned const end_idx){
    for (unsigned i = begin_idx + 1; i <= end_idx; i++){
        if (array[i] < array[i-1]){
            swap(array[i], array[i-1]);
        }
    }
}

void generate_array(unsigned (&array)[N]){
    int seed = 1001;
    std::default_random_engine rng(seed);
    std::uniform_int_distribution<unsigned> dstr(0, 1000);
    for(int i = 0; i < N; i++){
        array[i] = dstr(rng);
    }
    /*
    /\︿╱\
    \0_ 0 /╱\╱ 
    \▁︹_/
    */
}

void test(unsigned (&array)[N], unsigned const begin_idx, unsigned const end_idx){
    unsigned buffer[N];
    for (int i = 0; i < N; i++){
        buffer[i] = array[i];
    }
    forward_step(array, begin_idx, end_idx);
    for (unsigned i = begin_idx + 1; i < end_idx; i++){
        if (buffer[i] < array[i-1]){
            cout << "NO" << endl;
            return;
        }
    }
    cout << "YES" << endl;
}

int main(){
    unsigned arr[N];
    generate_array(arr);
    for (unsigned i = 5; i <= N; i += 5){
        generate_array(arr);  
        test(arr, 0, i);
    }
}