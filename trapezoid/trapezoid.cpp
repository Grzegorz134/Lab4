#include "trapezoid.h"
#include "cmath"
#include "iostream"

trapezoid::trapezoid()
{
    mass = 0;
    point1 = point2 = point3 = point4 = {0,0};
}

const char *trapezoid::classname()
{
    return name;
}

double trapezoid::weight() const
{
    return mass;
}

unsigned int trapezoid::size()
{
    return sizeof(*this);
}

bool trapezoid::operator == (const PhysObject &object) const
{
    return mass == object.weight();
}

bool trapezoid::operator < (const PhysObject &object) const
{
    return mass < object.weight();
}

void trapezoid::initFromDialog()
{
    std::cout << "Ввод трапеции выполняется по шаблону: Координаты двух верхних точек, Координаты двух нижних точек, Масса" << std::endl;

    std::cin >> point1.x >> point1.y;
    std::cin >> point2.x >> point2.y;
    std::cin >> point3.x >> point3.y;
    std::cin >> point4.x >> point4.y;

    std::cin >> mass;
}

Vector2D trapezoid::position()
{
    Vector2D center;
    center.x = (point1.x + point2.x + point3.x + point4.x) / 4;
    center.y = (point1.y + point2.y + point3.y + point4.y) / 4;
    return center;
}

void trapezoid::draw()
{
    std::cout << "Информация о фигуре: " << std::endl;

    std::cout << "Тип >> " << name << std::endl;

    std::cout << "Координаты (X;Y) >> " << "(" << point1.x << ";" << point1.y << ")" << " ";
    std::cout << "(" << point2.x << ";" << point2.y << ")" << " ";
    std::cout << "(" << point3.x << ";" << point3.y << ")" << " ";
    std::cout << "(" << point4.x << ";" << point4.y << ")" << std::endl;

    std::cout << "Вес = " << mass << std::endl;

    std::cout << "Периметр = " << perimeter() << std::endl;
    std::cout << "Площадь = " << square() << std::endl;

    std::cout << "Центр = (" << position().x << " ; " << position().y << ")" << std::endl;
}

double trapezoid::perimeter()
{
    double len1 = sqrt( pow(point2.x - point1.x,2) + pow(point2.y - point2.y,2));
    double len2 = sqrt( pow(point4.x - point3.x,2) + pow(point4.y - point3.y,2));
    double len3 = sqrt( pow(point1.x - point3.x,2) + pow(point1.y - point3.y,2));
    return len1 + len2 + len3 * 2;
}

double trapezoid::square()
{
    double len1 = sqrt( pow(point2.x - point1.x,2) + pow(point2.y - point2.y,2));
    double len2 = sqrt( pow(point4.x - point3.x,2) + pow(point4.y - point3.y,2));
    double height = sqrt(pow(point1.y - point3.y,2));

    return ((len1 + len2) / 2) * height;
}