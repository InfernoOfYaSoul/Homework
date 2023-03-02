#include <iostream>
using namespace std;

#ifndef N
#define N 10
#endif

void swap(int& lha, int& rha){
    lha = lha + rha;
    rha = lha - rha;
    lha = lha - rha;
}

void gnome_sort(int (&array)[N]){
    for(int j = 0; j < N; j++){
        for(int i = j; i > 0; i--){
            if(array[i] < array[i - 1]) swap(array[i], array[i - 1]);
        }
    }
}

int main(){
    int a[N];
    for(int i = 0; i < N; i++){
        cin >> a[i];
    }

    gnome_sort(a);

    for(int i = 0; i < N; i++){
        cout << a[i] << " ";
    }
    cout << endl;
}