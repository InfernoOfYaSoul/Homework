#include <iostream>
#include <string>

using namespace std;


struct Street{
    int beginning_x;
    int beginning_y;
    int ending_x;
    int ending_y;
} street1, street2;

void swap(int &lha, int &rha) {
    int tmp = lha;
    lha = rha;
    rha = tmp;
}

int main() {
    int success = 0;
    cin >> street1.beginning_x >> street1.beginning_y >> street1.ending_x >> street1.ending_y >> street2.beginning_x >>
        street2.beginning_y >> street2.ending_x >> street2.ending_y;

    if (street1.beginning_x > street1.ending_x) {
        swap(street1.beginning_x, street1.ending_x);
    }
    if (street1.beginning_y > street1.ending_y) {
        swap(street1.beginning_y, street1.ending_y);
    }
    if (street2.beginning_x > street2.ending_x) {
        swap(street2.beginning_x, street2.ending_x);
    }
    if (street2.beginning_y > street2.ending_y) {
        swap(street2.beginning_y, street2.ending_y);   
    }

    if (street1.beginning_x <= street2.ending_x and street1.ending_x >= street2.beginning_x and
        street1.beginning_y <= street2.ending_y and street1.ending_y >= street2.beginning_y) {
        success = -1;
    } else {
        success = 1;
    }

    if (success == -1) {
        cout << "NO" << endl;
    } else if (success == 1) {
        cout << "YES" << endl;
    } else {
        cout << "ERROR" << endl;
    }
}