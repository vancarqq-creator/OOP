#include <iostream>
#include <string>

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
        cout << "Point::print: " << "(" << _x << ", " << _y << ")" << endl;
    }

    void move(int dx, int dy);
};

void Point::move(int dx, int dy)
{
    _x += dx;
    _y += dy;
    cout << "Point::move: " << "moved by (" << dx << ", " << dy << ")" << endl;
}

int main()
{
    cout << "1. Static objects (different constructors)" << endl;
    Point p1;
    Point p2(10, 20);
    Point p3(p2);
    p2.print();
    p2.move(1, 1);

    cout << "\n2. Dynamic objects (new / delete)" << endl;
    Point *d1 = new Point();
    Point *d2 = new Point(5, 6);
    Point *d3 = new Point(*d2);
    d2->print();
    delete d1;
    delete d2;
    delete d3;

    cout << "\n3. Assignment: object to object" << endl;
    Point a(1, 1);
    Point b(2, 2);
    b = a;
    a.move(100, 100);
    a.print();
    b.print();

    cout << "\n4. Assignment: pointer to pointer" << endl;
    Point *pa = new Point(1, 1);
    Point *pb = pa;
    pa->move(100, 100);
    pa->print();
    pb->print();
    delete pa;

    cout << "\n5. Destruction of static object on leaving scope" << endl;
    {
        Point inner(7, 7);
        inner.print();
    }
    cout << "Hello" << endl;
    return 0;
}
