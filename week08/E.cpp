#include <iostream>
using std::getchar;
using std::cout;
using std::endl;

//Я НЕ БУД ИСПОЛЬЗОВАТЬ СТРУКТУРУ Я НЕ БУД ИСПОЛЬЗОВАТЬ СТРУКТУРУ Я НЕ БУД ИСПОЛЬЗОВАТЬ СТРУКТУРУ

int main(){
    int f1 = 0, f2 = 0, f3 = 0, f4 = 0;
    for(char c = getchar(); c != '\n' && c != '\0'; c = getchar()){
        if(c == '(') f1++;
        if(c == ')') f1--;
        if(c == '[') f2++;
        if(c == ']') f2--;
        if(c == '{') f3++;
        if(c == '}') f3--;
        if(c == '<') f4++;
        if(c == '>') f4--;
        if(f1< 0 || f2 <0 || f3 <0 || f4 <0) break;
        
    }
    if(f1 == 0 && f2 == 0 && f3 == 0 && f4 == 0)
        cout<<"YES"<<endl;
    else
        cout<<"NO"<<endl;
}