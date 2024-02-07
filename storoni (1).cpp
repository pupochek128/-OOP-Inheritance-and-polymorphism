#include <iostream>
#include <string>

class Figure {
protected:
    int _sides_count;
    std::string _name;

public:
    Figure(int sides_count) : _sides_count(sides_count), _name("Фигура") {}

    int get_sides_count() {
        return _sides_count;
    }

    std::string get_name() {
        return _name;
    }
};


class Triangle : public Figure {
public:
    Triangle() : Figure(3) {
        _name = "Треугольник";
    }
};


class Quadrangle : public Figure {
public:
    Quadrangle() : Figure(4) {
        _name = "Четырёхугольник";
    }
};


int main() {
   
    Figure figure(0);
    Triangle triangle;
    Quadrangle quadrangle;

    std::cout << "Количество сторон:" << std::endl;
    std::cout << figure.get_name() << ": " << figure.get_sides_count() << std::endl;
    std::cout << triangle.get_name() << ": " << triangle.get_sides_count() << std::endl;
    std::cout << quadrangle.get_name() << ": " << quadrangle.get_sides_count() << std::endl;

    return 0;
}