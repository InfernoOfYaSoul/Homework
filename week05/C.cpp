#include <iostream>
using namespace std;

int main(){
    int inpt = 1;
    int cntr = 0;
    int* tmp = new int[inpt];
    while(inpt != 0){
        cin >> inpt;
        int* arr = new int[cntr + 1];
        for(int i = 0; i < cntr; i++){
            arr[i] = tmp[i];
        }
        arr[cntr] = inpt;
        delete [] tmp;
        tmp = arr;
        cntr++;
    }
    for(int k = 0; k < cntr-1; k++){
        cout << *(tmp+k) - *(tmp + k + 1) << ' ';
    }
    cout << endl;
    delete [] tmp;
    return 0;
}