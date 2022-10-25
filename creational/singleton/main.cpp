#include <iostream>
#include "singleton.h"

// Main operates as the client.
// We call the get_instance twice, only the first time the instance is created.
int main()
{
	Singleton *singlA = Singleton::get_instance();
	Singleton *singlB = Singleton::get_instance();
	return 0;
}
