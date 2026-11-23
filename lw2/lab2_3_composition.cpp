#include <iostream>

using namespace std;

class Point
{
private:
    int _x;
    int _y;

public:
    Point() : _x(0), _y(0)
    {
        cout << "Point()" << endl;
    }

    Point(int x, int y) : _x(x), _y(y)
    {
        cout << "Point(x, y)" << endl;
    }

    Point(const Point &other) : _x(other._x), _y(other._y)
    {
        cout << "Point(const Point&)" << endl;
    }

    ~Point()
    {
        cout << "~Point(" << _x << ", " << _y << ")" << endl;
    }

    void print()
    {
        cout << "Point::print: (" << _x << ", " << _y << ")" << endl;
    }
};

class CircleByValue
{
private:
    Point _center;
    int _radius;

public:
    CircleByValue() : _center(), _radius(1)
    {
        cout << "CircleByValue()" << endl;
    }

    CircleByValue(int x, int y, int radius) : _center(x, y), _radius(radius)
    {
        cout << "CircleByValue(x, y, radius)" << endl;
    }

    CircleByValue(const CircleByValue &other) : _center(other._center), _radius(other._radius)
    {
        cout << "CircleByValue(const CircleByValue&)" << endl;
    }

    ~CircleByValue()
    {
        cout << "~CircleByValue() " << _radius << endl;
    }

    void print()
    {
        cout << "CircleByValue::print: radius=" << _radius << endl;
        _center.print();
    }
};

class CircleByPointer
{
private:
    Point *_center;
    int _radius;

public:
    CircleByPointer() : _center(nullptr), _radius(1)
    {
        cout << "CircleByPointer()" << endl;
        _center = new Point();
    }

    CircleByPointer(int x, int y, int radius) : _center(nullptr), _radius(radius)
    {
        cout << "CircleByPointer(x, y, radius)" << endl;
        _center = new Point(x, y);
    }

    CircleByPointer(const CircleByPointer &other) : _center(nullptr), _radius(other._radius)
    {
        cout << "CircleByPointer(const CircleByPointer&)" << endl;
        _center = new Point(*other._center);
    }

    ~CircleByPointer()
    {
        cout << "~CircleByPointer(): radius=" << _radius << endl;
        delete _center;
    }

    void print()
    {
        cout << "CircleByPointer::print: radius=" << _radius << endl;
        _center->print();
    }
};

int main()
{
    cout << "Composition" << endl;
    {
        cout << "create c1:" << endl;
        CircleByValue c1;
        cout << "create c2:" << endl;
        CircleByValue c2(10, 20, 5);
        cout << "create c3:" << endl;
        CircleByValue c3(c2);
        c3.print();
    }

    cout << endl << "Composition: pointer to object is a member" << endl;
    {
        cout << "create c1:" << endl;
        CircleByPointer c1;
        cout << "create c2:" << endl;
        CircleByPointer c2(10, 20, 5);
        cout << "create c3:" << endl;
        CircleByPointer c3(c2);
        c3.print();
    }
    return 0;
}
