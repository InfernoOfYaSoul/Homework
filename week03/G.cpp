#include <iostream>
using namespace std;

#ifndef N
#define N 5
#endif



int main(){
    int a[N];
    for(int i = 0; i < N; i++){
        cin >> a[i];
    }
    for (int i = 1; i < N; i++){ 
        a[0] ^= a[i];
    }
    cout << a[0] << endl;

}