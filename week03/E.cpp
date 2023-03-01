#include <iostream>
using namespace std;

#ifndef N
#define N  10  // actual size of the array
#endif

void swap(int& lha, int& rha){
    lha = lha + rha;
    rha = lha - rha;
    lha = lha - rha;
}

int main() {
    int a[2 * N], b[2 * N];
    for(int i = 0; i < 2 * N; i++){
        cin >> a[i];
    }
    int i = 0, j = N, k = 0;
    while(i < N & j < 2 * N & k < 2 * N){
        if(a[i] < a [j]){
            b[k] = a[i];
            ++i;
        }else{
            b[k] = a[j];
            ++j;
        }
        ++k;
    }
    while(i < N){
        b[k] = a[i];
        ++i;
        ++k;
    }
    while(j < 2 * N){
        b[k] = a[j];
        ++j;
        ++k;
    }
    for(int i = 0; i < 2 * N; i++){
        cout << b[i] << " ";
    }
    cout << endl;
}