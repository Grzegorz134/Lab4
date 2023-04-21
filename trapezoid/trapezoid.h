#ifndef LAB4_TRAPEZOID_H
#define LAB4_TRAPEZOID_H
#include "../interface.h"

class trapezoid : public figure
{
private:
    double mass;
    Vector2D point1, point2, point3, point4;
    const char *name = "Равнобедренная трапеция";

public:
    trapezoid();
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

#endif //LAB4_TRAPEZOID_H