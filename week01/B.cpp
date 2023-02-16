#include <iostream>
#include <cmath>

using namespace std;

int main(){
    int a, b, c, D;
    cin >> a >> b >> c;
    D = b * b - 4 * a * c;
    int ans1 = 0, ans2 = 0;
    if(D < 0){
        cout << "\n" << endl << endl;
    }
    if(D == 0){
        cout << (-b) / (2 * a) << endl;
    }
    if(D > 0){
        ans1 = (-b + sqrt(D)) / (2 * a);
        ans2 = (-b - sqrt(D)) / (2 * a);
        if(ans1 >= ans2){
            cout << ans2 << " " << ans1 << endl;
        }else{
            cout << ans1 << " " << ans2 << endl;
        }
    }
}