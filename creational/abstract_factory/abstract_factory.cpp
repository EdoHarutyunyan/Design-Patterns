#include <iostream>
#include <string>

// Default Classes
class Device
{
public:
	virtual void inline send(std::string data) = 0;
};

class Wifi : public Device
{
public:
	inline void send(std::string data)
	{
        std::cout << "Sent By Wifi: "<< data << std::endl;
	}
};

class Bluetooth : public Device
{
public:
	void inline send(std::string data)
	{
        std::cout << "Sent By Bluetooth: " << data << std::endl;
	}
};

// Abstract Factory Started
// Problem: Multiple if every function for handle the environment
// Solution: Build Abstract Factory and get method

class Abstract_factory
{
public:
	virtual Device* get() = 0;
};

class Device_abstract_factory : public Abstract_factory
{
public:
	Device* get()
	{
		if (true) // Confitions
		{
			return new Wifi;
		}
		else
		{
			return new Bluetooth;
		}
	}
};

int main()
{
	Abstract_factory *obj_af = new Device_abstract_factory;
	Device* device;
	device = obj_af->get();
	device->send("\nAbstract Factory Design Pattern Worked.");
}
