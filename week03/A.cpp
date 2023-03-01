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
    int a[N];
    for(int i = 0; i < N; i++){
        cin >> a[i];
    }
    for(int i = 0; i < N - 1; i++){
        for(int j = 0; j < N - i - 1; j++){
            swap(a[j], a[j + 1]);
        }
    }
    for(int i = 0; i < N; i++){
        cout << a[i] << " ";
    }
    cout << endl;
}