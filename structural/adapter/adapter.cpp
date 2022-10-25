#include <iostream>
using namespace std;

class Circle {
 public:
    virtual void draw() = 0;
};

class StandardCircle {
public:
    StandardCircle(double radius) {
        m_radius = radius;
        std::cout << "StandardCircle:  create. radius = "<< m_radius << std::endl;
    }
    inline void old_draw() {
        std::cout << "StandardCircle:  old_draw. " << m_radius << std::endl;
    }

private:
    double m_radius ;
};

class Adapter : public Circle, private StandardCircle {
public:
    Adapter( double diameter) : StandardCircle(diameter/2) {
        std::cout << "Adapter: create. diameter = " << diameter << std::endl;
    }

    virtual void draw() {
        std::cout << "Adapter: draw." << std::endl;
        old_draw();
    }
};

int main() {
    Circle*  ob = new Adapter(13);
    ob -> draw();
}
