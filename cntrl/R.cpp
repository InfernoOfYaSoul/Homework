#include <iostream>
#include <algorithm>
using namespace std;

int main(){
    int n;
    cin >> n;
    int arrin[11];
    int arrout[11];
    int mx = 0;
    for(int i = 0; i < n; i++){
        cin >> arrin[i];
        cin >> arrout[i];
        arrout[i]++;
        if(arrout[i] > mx) mx = arrout[i];
    }
    sort(arrout, arrout + n);
    int cntr = 0;
    int flag = 0, j = 0;
    int pntr1 = 0, pntr2 = 0;
    for(int i = 0; i < mx; i++){
        j = 0;
        if(arrin[pntr1] == i && pntr1 < n){
            flag++;
            pntr1++;
            j = -1;
        }
        if(arrout[pntr2] == i && pntr2 < n){
            flag--;
            pntr2++;
            j = -1;
        }
        i += j;
        if(flag > 0 && j != -1) cntr++;

    }
    cout << cntr <<endl;
}