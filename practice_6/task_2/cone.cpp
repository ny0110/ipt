#include <iostream>
#include <cmath>
#include "cone.h"

using namespace std;

Cone::Cone() {
    x = y = z = r = h = 0;
}

Cone::Cone(double r, double h) {
    x = y = z = 0;
    r = r;
    h = h;
}

Cone::Cone(double x, double y, double z, double r, double h) {
    x = x;
    y = y;
    z = z;
    r = r;
    h = h;
}

void Cone::input() {
    cout << "Координаты центра основания (x; y; z): ";
    cin >> x >> y >> z;
    cout << "Радиус основания: ";
    cin >> r;
    cout << "Высота: ";
    cin >> h;
}

void Cone::output() const {
    cout << "Координаты центра основания: (" << x << "; " << y << "; " << z << ")" << endl;
    cout << "Радиус основания: " << r << endl;
    cout << "Высота: " << h << endl;
}

double Cone::output(string t) const {
    if (t == "x") {
        return x;
    } else if (t == "y") {
        return y;
    } else if (t == "z") {
        return z;
    } else if (t == "r") {
        return r;
    } else if (t == "h") {
        return h;
    } else {
        return 0;
    }
}

double Cone::area() const {
    double l = sqrt(r * r + h * h);
    return 3.14159265 * r * l + 3.14159265 * r * r;
}

double Cone::volume() const {
    return 3.14159265 * r * r * h / 3;
}

bool Cone::operator==(const Cone& other) const {
    return x == other.x && y == other.y && z == other.z && r == other.r && h == other.h;
}

bool Cone::operator!=(const Cone& other) const {
    return !(*this == other);
}

istream& operator>>(istream& in, Cone& cone) {
    cone.input();
    return in;
}

ostream& operator<<(ostream& out, const Cone& cone) {
    cone.output();
    return out;
}

TruncatedCone::TruncatedCone() {
    Cone();
    R = H = 0;
}

TruncatedCone::TruncatedCone(double r, double h, double R, double H) {
    Cone(r, h);
    R = R;
    H = H;
}

void TruncatedCone::input() {
    Cone::input();
    cout << "Радиус верхнего основания: ";
    cin >> R;
    cout << "Высота усечения: ";
    cin >> H;
}

void TruncatedCone::output() const {
    Cone::output();
    cout << "Радиус верхнего основания: " << R << endl;
    cout << "Высота усечения: " << H << endl;
}

double TruncatedCone::output(string t) const {
    if (t == "R") {
        return R;
    } else if (t == "H") {
        return H;
    } else {
        return Cone::output(t);
    }
}

double TruncatedCone::area() const {
    double r2 = R - r;
    double L = sqrt(r2 * r2 + H * H);
    return 3.14159265 * r * L + 3.14159265 * r * r + 3.14159265 * R * L + 3.14159265 * R * R;
}

double TruncatedCone::volume() const {
    return 3.14159265 * h * (r * r + R * R + r * R) / 3;
}

bool TruncatedCone::operator==(const TruncatedCone& other) const {
    return Cone::operator==(other) && R == other.R && H == other.H;
}

bool TruncatedCone::operator!=(const TruncatedCone& other) const {
    return !(*this == other);
}

istream& operator>>(istream& in, TruncatedCone& cone) {
    cone.input();
    return in;
}

ostream& operator<<(ostream& out, const TruncatedCone& cone) {
    cone.output();
    return out;
}