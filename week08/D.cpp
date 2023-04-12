#include <iostream>
using std::getchar;
using std::cout;
using std::endl;

int main(){
    int flag = 0;
    for(char c = getchar(); c != '\n' && c != '\0'; c = getchar()){
        if(c == '(') 
            flag++;
        else 
            flag--; 
        if(flag < 0) break;
    }
    if(flag == 0)
        cout<<"YES"<<endl;
    else
        cout<<"NO"<<endl;
}