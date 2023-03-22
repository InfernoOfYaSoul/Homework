#include <iostream>
#include <cstring>

using namespace std;

char *resize(const char *buf, size_t size, size_t new_size){
    char* tmp = new char[new_size];
    for (int i = 0; i < min(size, new_size); i++){
        *(tmp + i)  = *(buf + i);
    }
    return tmp;
}

int main() {
    char* a = new char[10];
    resize(a, 10, 6);
    delete[] a;
}