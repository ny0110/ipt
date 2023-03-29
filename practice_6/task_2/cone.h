using namespace std;

class Cone {
protected:
    double x, y, z;
    double r;
    double h;
public:
    Cone();
    Cone(double r, double h);
    Cone(double x, double y, double z, double r, double h);
    void input();
    void output() const;
    double output(string t) const;
    double area() const;
    double volume() const;
    bool operator==(const Cone& other) const;
    bool operator!=(const Cone& other) const;
    friend istream& operator>>(istream& in, Cone& cone);
    friend ostream& operator<<(ostream& out, const Cone& cone);
};

class TruncatedCone : public Cone {
private:
    double R;
    double H;
public:
    TruncatedCone();
    TruncatedCone(double r, double h, double R, double H);
    void input();
    void output() const;
    double output(string t) const;
    double area() const;
    double volume() const;
    bool operator==(const TruncatedCone& other) const;
    bool operator!=(const TruncatedCone& other) const;
    friend istream& operator>>(istream& in, TruncatedCone& cone);
    friend ostream& operator<<(ostream& out, const TruncatedCone& cone);
};