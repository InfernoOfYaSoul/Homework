#include <iostream>
using namespace std;


int recursive_power(int base, int power){
    if(power == 1){
        return base; 
    }else{
        return base * recursive_power(base, power - 1); 
    }    
}

int main(){
    int b, p;
    cin >> b >> p;
    if (p == 0){
        cout << 1 << endl;
    }else{
        int ans = recursive_power(b, p);
        cout << ans << endl;
    }
}