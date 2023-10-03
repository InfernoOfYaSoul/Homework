#include <iostream>
#include <algorithm>
using namespace std;


unsigned int minf(unsigned int a, unsigned int b, unsigned int c, unsigned int d){
    if(a <= b && a <= c && a <= d) return a;
    if(b <= a && b <= c && b <= d) return b;
    if(c <= b && c <= a && c <= d) return c;
    if(d <= b && d <= a && d <= c) return d;
}

int main(){
    int n = 0;
    cin >> n;
    unsigned int arr[302][302][3] = {{{0}}};
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= n; j++){
            cin >> arr[i][j][0];
        }
    }
    for(int i = 2; i <= n; i++){
        arr[i][0][1] = 1000;
        arr[i][0][2] = 1000;
    }
    for(int i = 2; i <= n; i++){
        arr[0][i][1] = 1000;
        arr[0][i][2] = 1000;
    }
    arr[1][1][1] = 0;
    arr[1][1][2] = 0;

    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= n; j++){
            int f = arr[i][j][0];
            while(f % 5 == 0){
                arr[i][j][1]++;
                f = f / 5;
            }
            
            f = arr[i][j][0];
            while(f % 2 == 0){
                arr[i][j][2]++;
                f = f/2;
            }
            
            unsigned int mn = minf(arr[i-1][j][1], arr[i-1][j][2], arr[i][j-1][2], arr[i][j-1][1]);
            if(arr[i-1][j][1] == mn){
                int a = 0;
                if(arr[i][j-1][2] == mn){
                    if(arr[i-1][j][2] < arr[i][j-1][1]){
                        arr[i][j][2] = arr[i-1][j][2];
                        arr[i][j][1] = arr[i-1][j][1];
                    }else{
                        arr[i][j][2] = arr[i][j-1][2];
                        arr[i][j][1] = arr[i][j-1][1];
                    }
                    a++;
                }
                if(arr[i][j-1][1] == mn){
                    arr[i][j][1] = arr[i][j-1][1];
                    arr[i][j][2] = min(arr[i][j-1][2], arr[i-1][j][2]);
                    a++;
                }
                if(a == 0){
                    arr[i][j][1] = arr[i-1][j][1];
                    arr[i][j][2] = arr[i-1][j][2];
                }
            }
            /////////////////////////
            if(arr[i-1][j][2] == mn){
                int a = 0;
                if(arr[i][j-1][1] == mn){
                    if(arr[i-1][j][1] < arr[i][j-1][2]){
                        arr[i][j][2] = arr[i-1][j][2];
                        arr[i][j][1] = arr[i-1][j][1];
                    }else{
                        arr[i][j][2] = arr[i][j-1][2];
                        arr[i][j][1] = arr[i][j-1][1];
                    }
                    a++;
                }
                if(arr[i][j-1][2] == mn){
                    arr[i][j][2] = arr[i][j-1][2];
                    arr[i][j][1] = min(arr[i][j-1][1], arr[i-1][j][1]);
                    a++;
                }
                if(a == 0){
                    arr[i][j][1] = arr[i-1][j][1];
                    arr[i][j][2] = arr[i-1][j][2];
                }
            }
            /////////////////////////
            if(arr[i][j-1][2] == mn){
                int a = 0;
                if(arr[i-1][j][1] == mn){
                    if(arr[i][j-1][1] > arr[i-1][j][2]){
                        arr[i][j][2] = arr[i-1][j][2];
                        arr[i][j][1] = arr[i-1][j][1];
                    }else{
                        arr[i][j][2] = arr[i][j-1][2];
                        arr[i][j][1] = arr[i][j-1][1];
                    }
                    a++;
                }
                if(arr[i-1][j][2] == mn){
                    arr[i][j][2] = arr[i][j-1][2];
                    arr[i][j][1] = min(arr[i][j-1][1], arr[i-1][j][1]);
                    a++;
                }
                if(a == 0){
                    arr[i][j][1] = arr[i][j-1][1];
                    arr[i][j][2] = arr[i][j-1][2];
                }
            }
            //////////////////
            if(arr[i][j-1][1] == mn){
                int a = 0;
                if(arr[i-1][j][2] == mn){
                    if(arr[i-1][j][2] < arr[i][j-1][1]){
                        arr[i][j][2] = arr[i-1][j][2];
                        arr[i][j][1] = arr[i-1][j][1];
                    }else{
                        arr[i][j][2] = arr[i][j-1][2];
                        arr[i][j][1] = arr[i][j-1][1];
                    }
                    a++;
                }
                if(arr[i-1][j][1] == mn){
                    arr[i][j][1] = arr[i][j-1][1];
                    arr[i][j][2] = min(arr[i][j-1][2], arr[i-1][j][2]);
                    a++;
                }
                if(a == 0){
                    arr[i][j][1] = arr[i][j-1][1];
                    arr[i][j][2] = arr[i][j-1][2];
                }
            }
            /*
            if(arr[i-1][j][2] == mn || arr[i-1][j][1] == mn){
                int a = 0;
                if(mn == arr[i][j-1][2]){
                    arr[i][j][2] += arr[i][j - 1][2];
                    arr[i][j][1] += min(arr[i][j - 1][1], arr[i - 1][j][1]);
                    a++;
                }
                if(mn == arr[i][j-1][1]){
                    arr[i][j][1] += arr[i][j - 1][1];
                    arr[i][j][2] += min(arr[i][j - 1][2], arr[i - 1][j][2]);
                    a++;
                }
                if(a == 0){
                    arr[i][j][2] += arr[i-1][j][2];
                    arr[i][j][1] += arr[i-1][j][1];
                }
            }else{
                int a = 0;
                if(arr[i-1][j][2] == mn){
                    arr[i][j][2] += arr[i][j - 1][2];
                    arr[i][j][1] += min(arr[i][j - 1][1], arr[i - 1][j][1]);
                    a++;
                }
                if(arr[i-1][j][1] == mn){
                    arr[i][j][1] += arr[i][j - 1][1];
                    arr[i][j][2] += min(arr[i][j - 1][2], arr[i - 1][j][2]);
                    a++;
                }
                if(a == 0){
                    arr[i][j][1] += arr[i][j - 1][1];
                    arr[i][j][2] += arr[i][j - 1][2];
                }
            }
            */
        
        }
    }
    cout << min(arr[n][n][1], arr[n][n][2]);
}