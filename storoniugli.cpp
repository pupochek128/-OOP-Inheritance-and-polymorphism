#include <iostream>
#include <string>
#include <cmath>

class Figure {
protected:
    std::string _name;

public:
    virtual ~Figure() {}

    virtual std::string get_name() {
        return _name;
    }

    virtual void print_info() = 0;
};


class Triangle : public Figure {
private:
    double _a, _b, _c;
    double _A, _B, _C;

public:
    Triangle(double a, double b, double c, double A, double B, double C) : _a(a), _b(b), _c(c), _A(A), _B(B), _C(C) {
        _name = "Треугольник";
    }

    double get_a() {
        return _a;
    }

    double get_b() {
        return _b;
    }

    double get_c() {
        return _c;
    }

    double get_A() {
        return _A;
    }

    double get_B() {
        return _B;
    }

    double get_C() {
        return _C;
    }

    void print_info() {
        std::cout << _name << ":" << std::endl;
        std::cout << "Стороны: a=" << _a << " b=" << _b << " c=" << _c << std::endl;
        std::cout << "Углы: A=" << _A << " B=" << _B << " C=" << _C << std::endl;
        std::cout << std::endl;
    }
};


class RightTriangle : public Triangle {
public:
    RightTriangle(double a, double b) : Triangle(a, b, sqrt(a*a + b*b), atan(a/b)*180/M_PI, atan(b/a)*180/M_PI, 90) {
        _name = "Прямоугольный треугольник";
    }
};


class IsoscelesTriangle : public Triangle {
public:
    IsoscelesTriangle(double a, double base_angle) : Triangle(a, a, a, base_angle, base_angle, 180 - 2*base_angle) {
        _name = "Равнобедренный треугольник";
    }
};


class EquilateralTriangle : public Triangle {
public:
    EquilateralTriangle(double a) : Triangle(a, a, a, 60, 60, 60) {
        _name = "Равносторонний треугольник";
    }
};


class Quadrangle : public Figure {
private:
    double _a, _b, _c, _d;
    double _A, _B, _C, _D;

public:
    Quadrangle(double a, double b, double c, double d, double A, double B, double C, double D) : _a(a), _b(b), _c(c), _d(d), _A(A), _B(B), _C(C), _D(D) {
        _name = "Четырёхугольник";
    }

    double get_a() {
        return _a;
    }

    double get_b() {
        return _b;
    }

    double get_c() {
        return _c;
    }

    double get_d() {
        return _d;
    }

    double get_A() {
        return _A;
    }

    double get_B() {
        return _B;
    }

    double get_C() {
        return _C;
    }

    double get_D() {
        return _D;
    }

    void print_info() {
        std::cout << _name << ":" << std::endl;
        std::cout << "Стороны: a=" << _a << " b=" << _b << " c=" << _c << " d=" << _d << std::endl;
        std::cout << "Углы: A=" << _A << " B=" << _B << " C=" << _C << " D=" << _D << std::endl;
        std::cout << std::endl;
    }
};


class Rectangle : public Quadrangle {
public:
    Rectangle(double a, double b) : Quadrangle(a, b, a, b, 90, 90, 90, 90) {
        _name = "Прямоугольник";
    }
};


class Square : public Rectangle {
public:
    Square(double a) : Rectangle(a, a) {
        _name = "Квадрат";
    }
};
class Parallelogram : public Quadrangle {
public:
    Parallelogram(double a, double b, double angle) : Quadrangle(a, b, a, b, angle, 180 - angle, angle, 180 - angle) {
        _name = "Параллелограмм";
    }
};


class Rhombus : public Parallelogram {
public:
    Rhombus(double a, double angle) : Parallelogram(a, a, angle) {
        _name = "Ромб";
    }
};


int main() {
    // Создание экземпляров классов
    Triangle triangle(10, 20, 30, 50, 60, 70);
    RightTriangle right_triangle(10, 20);
    IsoscelesTriangle isosceles_triangle(10, 50);
    EquilateralTriangle equilateral_triangle(30);
    Quadrangle quadrangle(10, 20, 30, 40, 50, 60, 70, 80);
    Rectangle rectangle(10, 20);
    Square square(20);
    Parallelogram parallelogram(20, 30, 40);
    Rhombus rhombus(30, 40);

    // Вывод информации о фигурах
    triangle.print_info();
    right_triangle.print_info();
    isosceles_triangle.print_info();
    equilateral_triangle.print_info();
    quadrangle.print_info();
    rectangle.print_info();
    square.print_info();
    parallelogram.print_info();
    rhombus.print_info();

    return 0;
}