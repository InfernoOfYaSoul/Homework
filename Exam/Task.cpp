#include <iostream>
#include <vector>
using namespace std;

int pow(long long b, unsigned long long e) {
       double v = 1.0;
       while(e != 0) {
              if((e & 1) != 0) {
                     v *= b;
              }
              b *= b;
              e >>= 1;
       }
       return v;
}


int main(){
    int n, p, n1;
    cin >> n >> p;
    vector <int> N;
    n1 = n;
    while(n1 != 0){
        N.push_back(n1%10);
        n1 = n1 / 10;
    }
    for(int i = N.size() - 1; i >= 0; i--){
        n1 += pow(N[i], p + N.size() - 1 - i);
    }
    if(n1 % n ==0){
        cout << n1 / n;
    }else{
        cout<< -1;
    }
}

void dig_pow(int n, int p){
    int n, p, n1;
    cin >> n >> p;
    vector <int> N;
    n1 = n;
    while(n1 != 0){
        N.push_back(n1%10);
        n1 = n1 / 10;
    }
    for(int i = N.size() - 1; i >= 0; i--){
        n1 += pow(N[i], p + N.size() - 1 - i);
    }
    if(n1 % n ==0){
        cout << n1 / n;
    }else{
        cout<< -1;
    }
}