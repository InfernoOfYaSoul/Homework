#include <iostream>
using namespace std;

#ifndef N
#define N 10
#endif

int perm(int (&array)[N], int ind_left_base, int ind_right_base){
    int pivot = array[ind_right_base];
    int ind_turn = ind_left_base;

    for(int i = ind_left_base; i <= ind_right_base; i++){
        if(array[i] < pivot){
            swap(array[i], array[ind_turn]);
            ++ind_turn;
        }
    }
    swap(array[ind_turn], array[ind_right_base]);
    return ind_turn;
}

void qsort(int (&array)[N], int ind_left_base, int ind_right_base){
    if(ind_left_base >= ind_right_base){ 
        
        return;
    
    }
    
    int pivot = perm(array, ind_left_base, ind_right_base);
    
    qsort(array, ind_left_base, pivot - 1);
    qsort(array, pivot + 1, ind_right_base);
}

int main(){
    int a[N];
    for(int i = 0; i < N; i++){
        cin >> a[i];
    }
    qsort(a, 0, N-1);
    
    for(int i = 0; i < N; i++){
        cout << a[i] << " ";
    }
    cout << endl;
}