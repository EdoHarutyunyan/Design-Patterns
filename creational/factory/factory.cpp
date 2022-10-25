#include <iostream>
#include <string>

class Shape {
public:
       virtual inline void draw() = 0;
       static Shape* create(std::string type);
};

class Circle : public Shape {
public:
       inline void draw() {
           std::cout << "draw(). Circle" << std::endl;
       }

       friend class Shape;
};

class Square : public Shape {
public:
       inline void draw() {
           std::cout << "draw(). Square" << std::endl;
       }

       friend class Shape;
};

Shape* Shape::create(std::string type) {
    if ( type == "circle" ) {
        return new Circle();
    }
    if ( type == "square" ) {
        return new Square();
    }
    return nullptr;
}

int main(){
   Shape* ob1 = Shape::create("circle");
   Shape* ob2 = Shape::create("square");
   ob1->draw();
   ob2->draw();
}
