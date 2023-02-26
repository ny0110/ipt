#include <iostream>
#include "Triangle.h"

using namespace std;

int main() {
    Triangle mas[3];
    for (int i = 0; i < 3; i++) {
        double a, b, c;
        cout << "Введите a, b и c для треугольника № " << i + 1 << " через пробел: " << endl;
        cin >> a >> b >> c;
        while (!Triangle(a, b, c).isTriangle()) {
            cout << "Такого треугольника не существует. Введите стороны треугольника " << i + 1 << ":" << endl;
            cin >> a >> b >> c;
        }
        mas[i] = Triangle(a, b, c);
    }
    for (int i = 0; i < 3; i++) {
        cout << "Периметр треугольника " << i + 1 << " : " << mas[i].get_perimeter() << endl;
        cout << "Площадь треугольника " << i + 1 << " : " << mas[i].get_square() << endl;
    }
    return 0;
}