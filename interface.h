#ifndef LAB4_INTERFACE_H
#define LAB4_INTERFACE_H

class Vector2D
{
public:
    double x,y;
};


class GeoFig
{
public:
    virtual double square() = 0;
    virtual double perimeter() = 0;
};


class PhysObject
{
public:
    virtual double weight() const = 0;
    virtual Vector2D position() = 0;
    virtual bool operator == (const PhysObject &object) const = 0;
    virtual bool operator < (const PhysObject &object) const = 0;
};


class Printable
{
public:
    virtual void draw() = 0;
};


class BaseCOjbect
{
public:
    virtual const char *classname() = 0;
    virtual unsigned int size() = 0;
};


class DialogInitiable
{
public:
    virtual void initFromDialog() = 0;
};


class figure : public GeoFig, public PhysObject, public Printable, public BaseCOjbect, public DialogInitiable {};

#endif //LAB4_INTERFACE_H