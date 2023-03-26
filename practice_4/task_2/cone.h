#include <iostream>

class Cone {
protected:
    double x, y, z; // координаты центра основания
    double r; // радиус основания
    double h; // высота

public:
    Cone(); // конструктор по умолчанию
    Cone(double r, double h); // конструктор конуса с центром в начале координат
    Cone(double x, double y, double z, double r, double h); // конструктор произвольного конуса

    void input(); // метод ввода данных
    void output() const; // метод вывода данных
    double output(std::string t) const; // метод вывода определённого параметра

    double surfaceArea() const; // метод вычисления площади поверхности
    double volume() const; // метод вычисления объёма

    // Методы сравнения конусов
    bool operator==(const Cone& other) const;
    bool operator!=(const Cone& other) const;

    // Дружественные функции перегрузки операций ввода/вывода
    friend std::istream& operator>>(std::istream& in, Cone& cone);
    friend std::ostream& operator<<(std::ostream& out, const Cone& cone);
};

class TruncatedCone : public Cone {
private:
    double R; // радиус верхнего основания
    double H; // высота усечения

public:
    TruncatedCone(); // конструктор по умолчанию
    TruncatedCone(double r, double h, double R, double H); // конструктор с параметрами

    void input(); // метод ввода данных
    void output() const; // метод вывода данных
    double output(std::string t) const; // метод вывода определённого параметра

    double surfaceArea() const; // переопределение метода вычисления площади поверхности
    double volume() const; // переопределение метода вычисления объёма

    // Методы сравнения усечённых конусов
    bool operator==(const TruncatedCone& other) const;
    bool operator!=(const TruncatedCone& other) const;

    // Дружественные функции перегрузки операций ввода/вывода
    friend std::istream& operator>>(std::istream& in, TruncatedCone& cone);
    friend std::ostream& operator<<(std::ostream& out, const TruncatedCone& cone);
};