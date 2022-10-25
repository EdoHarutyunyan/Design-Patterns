#include <iostream>
#include <string>
using namespace std;


class Body{
    public:
        string m_shape;
};

class Wheel{
    public:
        int m_size;
};

class Engine{
    public:
        int m_horsepower;
};


class Car{
    public:
        Wheel* wheels[4];
        Engine* engine;
        Body* body;

        void specifications(){
            std::cout << "Body: " << body -> m_shape << std::endl;
            std::cout << "Engine Horsepower: " << engine->m_horsepower << std::endl;
            std::cout << "Tire Size: "<< wheels[0]->m_size << std::endl;
        }
};

class Builder{
    public:
        virtual Wheel* getWheel() = 0;
        virtual Engine* getEngine() = 0;
        virtual Body* getBody() = 0;
};


class BMWBuilder : public Builder{
    public:
        Wheel* getWheel(){
            Wheel* wheel = new Wheel();
            wheel->m_size = 22;
            return wheel;
        }
        Engine* getEngine(){
            Engine* engine = new Engine();
            engine->m_horsepower = 400;
            return engine;
        }
        Body* getBody(){
            Body* body = new Body();
            body->m_shape = "SUV";
            return body;
        }
};

class TeslaBuilder : public Builder {
    public:
        Wheel* getWheel(){
            Wheel* wheel = new Wheel();
            wheel->m_size = 16;
            return wheel;
        }

        Engine* getEngine(){
            Engine* engine = new Engine();
            engine->m_horsepower = 85;
            return engine;
        }

        Body* getBody(){
            Body* body = new Body();
            body->m_shape = "hatchback";
            return body;
        }
};

class Director {
    Builder* builder;
    public:
        void setBuilder(Builder* newBuilder){
            builder = newBuilder;
        }

        Car* getCar(){
            Car* car = new Car();

            car->body = builder->getBody();

            car->engine = builder->getEngine();

            car->wheels[0] = builder->getWheel();
            car->wheels[1] = builder->getWheel();
            car->wheels[2] = builder->getWheel();
            car->wheels[3] = builder->getWheel();

            return car;
        }
};

int main(){
    Car* car;
    Director director;
    BMWBuilder bmw;
    TeslaBuilder tesla;

    std::cout << "BMW" << std::endl;
    director.setBuilder(&bmw);
    car = director.getCar();
    car->specifications();

    std::cout << std::endl;

    std::cout<< "Tesla" << std::endl;
    director.setBuilder(&tesla);
    car = director.getCar();
    car->specifications();

    return 0;
}
