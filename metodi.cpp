#include <iostream>
#include <cmath>
using namespace std;

class Shape {
protected:
    int sides_count;
    string name;
public:
    Shape() { sides_count = 0; name = "Фигура"; }
    virtual void print_info() {
        cout << name << ":" << endl;
        cout << (check() ? "Правильная" : "Неправильная") << endl;
        cout << "Количество сторон: " << sides_count << endl;
    }
    virtual bool check() {
        return sides_count > 0;
    }
};

class Triangle : public Shape {
private:
    int sides[3];
    int angles[3];
public:
    Triangle(int a, int b, int c, int A, int B, int C) {
        if (a+b > c && a+c > b && b+c > a && A+B+C == 180) {
            sides[0] = a;
            sides[1] = b;
            sides[2] = c;
            angles[0] = A;
            angles[1] = B;
            angles[2] = C;
            sides_count = 3;
            name = "Треугольник";
        }
        else {
            cout << "Invalid triangle!" << endl;
        }
    }
    void print_info() {
        cout << name << ":" << endl;
        cout << (check() ? "Правильная" : "Неправильная") << endl;
        cout << "Количество сторон: " << sides_count << endl;
        if (check()) {
            cout << "Стороны: a=" << sides[0] << " b=" << sides[1] << " c=" << sides[2] << endl;
            cout << "Углы: A=" << angles[0] << " B=" << angles[1] << " C=" << angles[2] << endl;
        }
    }
    bool check() {
        return sides_count == 3;
    }
};

class RightTriangle : public Triangle {
public:
    RightTriangle(int a, int b) : Triangle(a, b, sqrt(a*a+b*b), 90, atan(double(a)/b)*180/M_PI, 90) {
        name = "Прямоугольный треугольник";
    }
};

class IsoscelesTriangle : public Triangle {
public:
    IsoscelesTriangle(int a, int b, int A) : Triangle(a, b, b, A, 180-A, A) {
        name = "Равнобедренный треугольник";
    }
};

class EquilateralTriangle : public Triangle {
public:
    EquilateralTriangle(int a) : Triangle(a, a, a, 60, 60, 60) {
        name = "Равносторонний треугольник";
    }
};

class Quadrangle : public Shape {
private:
    int sides[4];
    int angles[4];
public:
    Quadrangle(int a, int b, int c, int d, int A, int B, int C, int D) {
        if (A+B+C+D == 360) {
            sides[0] = a;
            sides[1] = b;
            sides[2] = c;
            sides[3] = d;
            angles[0] = A;
            angles[1] = B;
            angles[2] = C;
            angles[3] = D;
            sides_count = 4;
            name = "Четырёхугольник";
        }
        else {
            cout << "Invalid quadrangle!" << endl;
        }
    }
    void print_info() {
        cout << name << ":" << endl;
        cout << (check() ? "Правильная" : "Неправильная") << endl;
        cout << "Количество сторон: " << sides_count << endl;
        if (check()) {
            cout << "Стороны: a=" << sides[0] << " b=" << sides[1] << " c=" << sides[2] << " d=" << sides[3] << endl;
            cout << "Углы: A=" << angles[0] << " B=" << angles[1] << " C=" << angles[2] << " D=" << angles[3] << endl;
        }
    }
    bool check() {
        return sides_count == 4;
    }
};

class Rectangle : public Quadrangle {
public:
    Rectangle(int a, int b) : Quadrangle(a, b, a, b, 90, 90, 90, 90) {
        name = "Прямоугольник";
    }
};

class Square : public Rectangle {
public:
    Square(int a) : Rectangle(a, a) {
        name = "Квадрат";
    }
};

class Parallelogram : public Quadrangle {
public:
    Parallelogram(int a, int b, int A) : Quadrangle(a, b, a, b, A, 180-A, A, 180-A) {
        name = "Параллелограмм";
    }
};

class Rhombus : public Parallelogram {
public:
    Rhombus(int a, int A) : Parallelogram(a, a, A) {     name = "Ромб";
      }
      };

      int main() {
      Shape shape;
      shape.print_info();
      cout << endl;

      Triangle triangle(10, 20, 30, 50, 60, 70);
      triangle.print_info();
      cout << endl;

      RightTriangle right_triangle(10, 20);
      right_triangle.print_info();
      cout << endl;

      IsoscelesTriangle isosceles_triangle(10, 20, 50);
      isosceles_triangle.print_info();
      cout << endl;

      EquilateralTriangle equilateral_triangle(30);
      equilateral_triangle.print_info();
      cout << endl;

      Quadrangle quadrangle(10, 20, 30, 40, 50, 60, 70, 80);
      quadrangle.print_info();
      cout << endl;

      Rectangle rectangle(10, 20);
      rectangle.print_info();
      cout << endl;

      Square square(20);
      square.print_info();
      cout << endl;

      Parallelogram parallelogram(20, 30, 30);
      parallelogram.print_info();
      cout << endl;

      Rhombus rhombus(30, 30);
      rhombus.print_info();
      cout << endl;

      return 0;
      }