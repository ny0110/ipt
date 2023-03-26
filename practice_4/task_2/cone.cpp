#include "Cone.h"
#include <iostream>
#include <cmath>

using namespace std;

// Конструктор по умолчанию
Cone::Cone() : x(0), y(0), z(0), r(0), h(0) {}

// Конструктор конуса с центром в начале координат
Cone::Cone(double r, double h) : x(0), y(0), z(0), r(r), h(h) {}

// Конструктор произвольного конуса
Cone::Cone(double x, double y, double z, double r, double h) : x(x), y(y), z(z), r(r), h(h) {}

// Метод ввода данных
void Cone::input() {
    cout << "Введите координаты центра основания (x y z): ";
    cin >> x >> y >> z;
    cout << "Введите радиус основания: ";
    cin >> r;
    cout << "Введите высоту: ";
    cin >> h;
}

// Метод вывода данных
void Cone::output() const {
    cout << "Координаты центра основания: (" << x << ", " << y << ", " << z << ")" << endl;
    cout << "Радиус основания: " << r << endl;
    cout << "Высота: " << h << endl;
}

double Cone::output(std::string t) const {
    if (t == "r") {
        return r;
    }
    else if (t == "h") {
        return h;
    }
    else if (t == "x") {
        return x;
    }
    else if (t == "y") {
        return y;
    }
    else if (t == "z") {
        return z;
    }
    else {
        return 0;
    }
}

// Метод вычисления площади поверхности
double Cone::surfaceArea() const {
    double L = sqrt(pow(r, 2) + pow(h, 2)); // Длина образующей
    return M_PI * r * L + M_PI * pow(r, 2); // Площадь поверхности
}

// Метод вычисления объёма
double Cone::volume() const {
    return M_PI * pow(r, 2) * h / 3; // Объём
}

// Методы сравнения конусов
bool Cone::operator==(const Cone& other) const {
    return x == other.x && y == other.y && z == other.z && r == other.r && h == other.h;
}

bool Cone::operator!=(const Cone& other) const {
    return !(*this == other);
}

//Дружественная функции перегрузки операторов ввода/вывода
istream& operator>>(istream& in, Cone& cone) {
    cone.input();
    return in;
}

ostream& operator<<(ostream& out, const Cone& cone) {
    cone.output();
    return out;
}

// Конструктор по умолчанию
TruncatedCone::TruncatedCone() : Cone(), R(0), H(0) {}

// Конструктор с параметрами
TruncatedCone::TruncatedCone(double r, double h, double R, double H) : Cone(r, h), R(R), H(H) {}

// Метод ввода данных
void TruncatedCone::input() {
    Cone::input();
    cout << "Введите радиус верхнего основания: ";
    cin >> R;
    cout << "Введите высоту усечения: ";
    cin >> H;
}

// Метод вывода данных
void TruncatedCone::output() const {
    Cone::output();
    cout << "Радиус верхнего основания: " << R << endl;
    cout << "Высота усечения: " << H << endl;
}

double TruncatedCone::output(std::string t) const {
    if (t == "R") {
        return R;
    }
    else if (t == "H") {
        return H;
    }
    else {
        return Cone::output(t);
    }
}

// Метод вычисления площади поверхности
double TruncatedCone::surfaceArea() const {
    double L = sqrt(pow(R - r, 2) + pow(H, 2)); // Длина образующей
    return M_PI * r * L + M_PI * pow(r, 2) + M_PI * R * L + M_PI * pow(R, 2); // Площадь поверхности
}

// Метод вычисления объёма
double TruncatedCone::volume() const {
    return M_PI * h * (pow(r, 2) + pow(R, 2) + r * R) / 3; // Объём
}

// Методы сравнения усечённых конусов
bool TruncatedCone::operator==(const TruncatedCone& other) const {
    return Cone::operator==(other) && R == other.R && H == other.H;
}

bool TruncatedCone::operator!=(const TruncatedCone& other) const {
    return !(*this == other);
}

//Дружественная функции перегрузки операторов ввода/вывода
istream& operator>>(istream& in, TruncatedCone& cone) {
    cone.input();
    return in;
}

ostream& operator<<(ostream& out, const TruncatedCone& cone) {
    cone.output();
    return out;
}