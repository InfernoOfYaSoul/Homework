#include <iostream>
using namespace std;

#ifndef N
#define N 10
#endif



int main(){
    int a[N];
    for(int i = 0; i < N; i++){
        cin >> a[i];
    }
    int r = 0;
    for (int i = 0; i < N; i++){ 
        r ^= a[i];
    }
    cout << r;

}