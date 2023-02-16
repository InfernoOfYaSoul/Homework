#include <iostream>
using namespace std;

int evkl(int a, int b){
    if (b == 0){ return a; }
    return evkl(b, a % b);
}

int main(){
    int a, b;
    cin >> a >> b;
    int ans = evkl(a, b);
    cout << ans << endl;
}