#include <iostream>
#include <string>

using namespace std;

struct Students{
    string name;
    int bal;
};

int main() {
    int M = 0;
    Students data[10];
    for (int i = 0; i < 10; i++) {
        cin >> (data[i]).name >> (data[i]).bal;
    }
    cin >> M;
    string ans[10];
    int j = 0;
    for (int i = 0; i < 10; i++) {
        if ((data[i]).bal > M) {
            ans[j] = (data[i]).name;
            j++;
        }
    }
    for (int k = 0; k < j - 1; k++) {
        cout << ans[k] << ' ';
    }
    cout << ans[j] << endl;
    return 0;
}