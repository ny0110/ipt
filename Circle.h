class Circle {
private:
    float radius, x_center, y_center;
public:
    Circle(float radius, float x_center, float y_center);
    void set_circle(float r, float x, float y);
    bool triangle_around (float a, float b, float c);
    bool triangle_in (float a, float b, float c);
    bool check_circle(float r, float x_cntr, float y_cntr);
    float get_radius();
    float get_x_center();
    float get_y_center();
    float square();

    Circle();
};