#include <iostream>
#include <string>

using namespace std;

struct Time{
    int h;
    int m;
    int s;
};

int main() {
    Time t_0, t_k, dt;
    cin >> t_0.h >> t_0.m >> t_0.s >> dt.h >> dt.m >> dt.s;
    t_k.s = (t_0.s + dt.s) % 60;
    t_k.m = (t_0.m + dt.m + (t_0.s + dt.s) / 60) % 60;
    t_k.h   = (t_0.h + dt.h + (t_0.m + dt.m + (t_0.s + dt.s) / 60) / 60) % 24;

    cout << t_k.h << ':' << t_k.m << ':' << t_k.s << endl;

    return 0;
}