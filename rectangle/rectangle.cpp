#include "rectangle.h"
#include "cmath"
#include "iostream"

rectangle::rectangle()
{
    mass = 0;
    point1 = point2 = {0,0};
}

void rectangle::initFromDialog()
{
    std::cout << "Ввод прямоугольника выполняется по шаблону: Координаты первой точки, Координаты второй точки, Вес" << std::endl;
    std::cin >> point1.x >> point1.y >> point2.x >> point2.y >> mass;
}

const char *rectangle::classname()
{
    return name;
}

double rectangle::square()
{
    double len1 = sqrt(pow(point2.y - point1.y, 2));
    double len2 = sqrt(pow(point2.x - point1.y, 2));
    return len1 * len2;
}

double rectangle::perimeter()
{
    double len1 = sqrt(pow(point2.y - point1.y, 2));
    double len2 = sqrt(pow(point2.x - point1.y, 2));
    return (len1 + len2) * 2.0;
}

double rectangle::weight() const
{
    return mass;
}

Vector2D rectangle::position()
{
    Vector2D center;

    center.x = (point1.x + point2.x) / 2;
    center.y = (point1.y + point2.y) / 2;

    return center;
}

bool rectangle::operator == (const PhysObject &object) const
{
    return mass == object.weight();
}

bool rectangle::operator < (const PhysObject &object) const
{
    return mass < object.weight();
}

void rectangle::draw()
{
    std::cout << "Информация о фигуре: " << std::endl;

    std::cout << "Тип >> " << name << std::endl;

    std::cout << "Координаты (X;Y) >> " << "(" << point1.x << ";" << point1.y << ")" << " ";
    std::cout << "(" << point2.x << ";" << point1.y << ")" << " ";
    std::cout << "(" << point1.x << ";" << point2.y << ")" << " ";
    std::cout << "(" << point2.x << ";" << point2.y << ")" << std::endl;
    std::cout << "Вес = " << mass << std::endl;

    std::cout << "Периметр = " << perimeter() << std::endl;
    std::cout << "Площадь = " << square() << std::endl;

    std::cout << "Центр = (" << position().x << " ; " << position().y << ")" << std::endl;
}

unsigned int rectangle::size()
{
    return sizeof(*this);
}