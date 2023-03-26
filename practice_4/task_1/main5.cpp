#include <iostream>
#include "Cone.h"

using namespace std;

int main() {
    Cone c1(3, 7);
    Cone c2(1, 2, 3, 5, 10);

    cout << "Cone 1: " << c1;
    cout << "S1: " << c1.area() << endl;
    cout << "V1: " << c1.volume() << endl;

    cout << "Cone 2: " << c2;
    cout << "S2: " << c2.area() << endl;
    cout << "V2: " << c2.volume() << endl;

    return 0;
}
