#include <iostream>
#include "Circle.h"

bool check_circle(float r1, float x1, float y1);

using namespace std;

int main() {
    Circle mas[3];
    float r, x_cntr, y_cntr;
    for (int i = 0; i < 3; i++) {
        float radius, x, y;
        cout << "Введите radius, x и y для окружности № " << i + 1 << " через пробел:" << endl;
        cin >> radius >> x >> y;
        mas[i] = Circle(radius, x, y);
    }
    for (int i = 0; i < 3; i++) {
        cout << "Площадь окружности " << i + 1 << " : " << mas[i].square() << endl;
    }
    for (int i = 0; i < 3; i++) {
        float a, b, c;
        cout << "Введите стороны треугольника, возле которого хотите описать окружность " << i + 1 << " ." << endl;
        cin >> a >> b >> c;
        if (a + b > c && b + c > a && a + c > b) {
            cout << "Окружность может быть описана около треугольника со сторонами " << mas[i].triangle_around(a, b, c) << " ." << endl;
        } else {
            cout << "Окружность НЕ может быть описана около треугольника." << endl;
        }
    }
    for (int i = 0; i < 3; i++) {
        float a, b, c;
        cout << "Введите стороны треугольника, в который хотите вписать окружность " << i + 1 << " ." << endl;
        cin >> a >> b >> c;
        if (a + b > c && b + c > a && a + c > b) {
            cout << "Окружность может быть вписана в треугольник со сторонами " << mas[i].triangle_in(a, b, c) << " ." << endl;
        } else {
            cout << "Окружность НЕ может быть вписана в треугольник." << endl;
        }
    }
    float r1, x1, y1;
    cout << "Введите значение окружности, чтобы проверить, совпадают они или нет." << endl;
    cin >> r1 >> x1 >> y1;
    bool intersects;
    for (int i = 0; i < 3; i++) {
        intersects = mas[i].check_circle(r1, x1, y1);
        if (intersects) {
            cout << "Окружности совпадают." << endl;
            break;
        } else {
            cout << "Окружности не совпадают." << endl;
            break;
        }
    }
    return 0;
}