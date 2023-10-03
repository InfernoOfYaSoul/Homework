#include <iostream>
#include <cmath>
using namespace std;

int main(){
    int n;
    cin >> n;
    if(n == 0){
        cout<<0;
        return 0;
    }
    int arrs[10], arrt = 0, arrf[100];
    for(int i = 0; i < n; i++){
        cin >> arrs[i];
    }
    for(int i = 0; i < 100; i++){
        arrf[i] = -1;
    }
    for(int i = 0; i < n; i++){
        int j = 0;
        while(arrs[i] > 0){
            arrt += arrs[i] % 10 * pow(7, j);
            //cout<<arrt[i]<<" "<<arrs[i]<<endl;
            arrs[i] = arrs[i]/10;
            j++;
        }
    }
    
        int j = 0;
        while(arrt > 0){
            arrf[j] = arrt % 4;
            arrt = arrt / 4;
            j++;
        }
    
    for(int i = 99; i >= 0; i--){
        if(arrf[i] != -1)cout<<arrf[i];
    }
}