#include <iostream>
#include "cone.h"

using namespace std;

int main() {
    Cone c1(1, 2, 3, 4, 5);
    Cone c2(6, 7, 8, 9, 10);

    cout << "Конус 1:" << endl;
    cout << c1 << endl;
    cout << "Площадь поверхности: " << c1.area() << endl;
    cout << "Объём: " << c1.volume() << endl;

    cout << "Конус 2:" << endl;
    cout << c2 << endl;
    cout << "Площадь поверхности: " << c2.area() << endl;
    cout << "Объём: " << c2.volume() << endl;

    TruncatedCone tc1(4,5, 2,1);
    TruncatedCone tc2(9, 10, 4, 2);

    cout << "Усечённый конус 1:" << endl;
    cout << tc1 << endl;
    cout << "Площадь поверхности: " << tc1.area() << endl;
    cout << "Объём: " << tc1.volume() << endl;

    cout << "Усечённый конус 2:" << endl;
    cout << tc2 << endl;
    cout << "Площадь поверхности: " << tc2.area() << endl;
    cout << "Объём: " << tc2.volume() << endl;

    if (c1 == c2) {
        cout << "Конус 1 и конус 2 равны" << endl;
    } else {
        cout << "Конус 1 и конус 2 НЕ равны" << endl;
    }

    if (tc1 == tc1) {
        cout << "Усечённый конус 1 и усечённый конус 2 равны" << endl;
    } else {
        cout << "Усечённый конус 1 и усечённый конус 2 НЕ равны" << endl;
    }

    int n;
    cout << "Количество усечённых конусов: ";
    cin >> n;
    TruncatedCone* truncatedCones = new TruncatedCone[n];
    for (int i = 0; i < n; i++) {
        cout << "Данные для усечённого конуса: " << i + 1 << endl;
        truncatedCones[i].input();
    }

    for (int i = 0; i < n; i++) {
        cout << "Усечённый конус: " << i + 1 << ":" << endl;
        cout << truncatedCones[i] << endl;
        cout << "Площадь поверхности: " << truncatedCones[i].area() << endl;
        cout << "Объём: " << truncatedCones[i].volume() << endl;
    }

    cout << "Данные для конуса, с которым нужно сверить усеченные конусы: " << endl;
    Cone cone;
    cone.input();
    int count = 0;
    for (int i = 0; i < n; i++) {
        if (cone.output("r") == truncatedCones[i].output("r") && cone.output("h") == truncatedCones[i].output("h"))
            count++;
    }
    cout << "Количество усечённых конусов, образованных от одного конуса: " << count << endl;
    cout << "Нажмите enter для окончания";
    cin.get();
    return 0;
}