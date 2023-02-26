#include "Triangle.h"
#include <cmath>

Triangle::Triangle() : a1(0), b1(0), c1(0) {}
Triangle::Triangle(double a, double b, double c) :
    a1(a), b1(b), c1(c) {}

double Triangle::get_a() {
    return a1;
}

double Triangle::get_b() {
    return b1;
}

double Triangle::get_c() {
    return c1;
}

double Triangle::get_perimeter() {
    return a1 + b1 + c1;
}

double Triangle::get_square() {
    double p = get_perimeter() / 2;
    return sqrt(p * (p - a1) * (p - b1) * (p - c1));
}

bool Triangle::isTriangle() {
    return a1 + b1 > c1 && b1 + c1 > a1 && a1 + c1 > b1;
}