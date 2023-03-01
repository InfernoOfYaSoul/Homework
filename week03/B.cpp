#include <iostream>
using namespace std;

#ifndef N
#define N  4  // actual size of the array
#endif

void swap(int& lha, int& rha){
    lha = lha + rha;
    rha = lha - rha;
    lha = lha - rha;
}

int main() {
    int a[N];
    for(int i = 0; i < N; i++){
        cin >> a[i];
    }
    for(int i = N - 2; i >= 0; i--){
        swap(a[i], a[i + 1]);
    }
    for(int i =0; i < N; i++){
        cout << a[i] << " ";
    }
    cout << endl;
}