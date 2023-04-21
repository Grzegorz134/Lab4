#ifndef LAB4_RECTANGLE_H
#define LAB4_RECTANGLE_H
#include "../interface.h"

class rectangle : public figure
{
private:
    double mass;
    Vector2D point1, point2;
    const char *name = "Прямоугольник";

public:
    rectangle();
    void initFromDialog() override;

    double square() override;
    double perimeter() override;

    double weight() const override;

    Vector2D position() override;

    bool operator == (const PhysObject &object) const override;
    bool operator < (const PhysObject &object) const override;

    void draw() override;
    const char *classname() override;
    unsigned int size() override;
};

#endif //LAB4_RECTANGLE_H