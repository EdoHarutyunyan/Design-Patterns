#pragma once

class Singleton
{
public:
     Singleton(const Singleton&) = delete;
     Singleton& operator=(const Singleton&) = delete;
     static Singleton *get_instance();

private:
     Singleton() {}
     static Singleton* s_instance;
};
