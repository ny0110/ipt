class Triangle {
private:
    double a1, b1, c1;
public:
    Triangle();
    bool isTriangle();
    Triangle(double a, double b, double c);
    double get_a();
    double get_b();
    double get_c();
    double get_perimeter();
    double get_square();
};