#include <iostream>
using namespace std;

#ifndef N
#define N 10
#endif

void perm(int (&array)[N], int ind, int lft_brd){
    if(2 * ind + 1 <= lft_brd & array[ind] < array[2 * ind + 1]) swap(array[ind], array[2 * ind + 1]);
    if(2 * ind + 2 <= lft_brd & array[ind] < array[2 * ind + 2]) swap(array[ind], array[2 * ind + 2]);
}

void cheops_sort(int (&array)[N], int ind_lst, int size){
    if(ind_lst == 0) return;
    for(int i = ind_lst; i >= 0; i--){
        perm(array, i, ind_lst);
    }
    //cerr << ind_lst << " ";
    swap(array[0], array[ind_lst]);
    cheops_sort(array, ind_lst - 1, size);
}

int main(){
    int a[N];
    for(int i = 0; i < N; i++){
        cin >> a[i];
    }
    
    cheops_sort(a, N - 1, N);
    
    for(int i = 0; i < N; i++){
        cout << a[i] << " ";
    }
    cout << endl;
}