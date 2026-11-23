#include <iostream>
#include <string>

using namespace std;

class Shape
{
private:
    int _id;

protected:
    string _name;

public:
    Shape() : _id(0), _name("shape")
    {
        cout << "Shape(): " << _name << endl;
    }

    Shape(string name) : _id(1), _name(name)
    {
        cout << "Shape(name): " << _name << endl;
    }

    Shape(const Shape &other) : _id(other._id), _name(other._name + "_copy")
    {
        cout << "Shape(const Shape&): " << _name << endl;
    }

    ~Shape()
    {
        cout << "~Shape(): " << _name << endl;
    }

    void describe()
    {
        cout << "Shape::describe: " << _name << endl;
    }

    void onlyInBase()
    {
        cout << "Shape::onlyInBase: " << _name << endl;
    }
};

class Circle : public Shape
{
private:
    int _radius;

public:
    Circle() : Shape(), _radius(1)
    {
        cout << "Circle()" << endl;
    }

    Circle(string name, int radius) : Shape(name), _radius(radius)
    {
        cout << "Circle(name, radius): " << _radius << endl;
    }

    Circle(const Circle &other) : Shape(other), _radius(other._radius)
    {
        cout << "Circle(const Circle&)" << endl;
    }

    ~Circle()
    {
        cout << "~Circle() " << _radius << endl;
    }

    void describe()
    {
        cout << "Circle::describe: radius=" << _radius << ", " << _name << endl;
        Shape::describe();
    }

    void onlyInDerived() const
    {
        cout << "Circle::onlyInDerived: radius=" << _radius << endl;
    }
};

class Square : public Shape {};

int main()
{
    cout << "1. Derived class" << endl;
    {
        Square sq;
    }

    cout << "\n2. Base and derived" << endl;
    {
        Circle c1("c1", 5);
        Circle c2(c1);
    }

    cout << "\n3. Dynamic derived object, delete" << endl;
    Circle *pc = new Circle("c3", 7);
    delete pc;

    cout << "\n4. Overridden method, call base method" << endl;
    Circle c4("c4", 3);
    c4.describe();
    c4.Shape::describe();

    cout << "\n5. Pointer to base" << endl;
    Shape *s1 = new Shape("base_obj");
    Shape *s2 = new Circle("derived_obj", 9);
    s1->describe();
    s2->describe();
    s2->onlyInBase();
    static_cast<Circle*>(s2)->onlyInDerived();
    static_cast<Circle*>(s2)->describe();
    delete s1;
    delete static_cast<Circle*>(s2);

    cout << "\n6. Shape obj = Circle(...)" << endl;
    {
        Shape sliced = Circle("tmp", 2);
        sliced.describe();
    }
    return 0;
}
