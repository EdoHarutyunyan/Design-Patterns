#include <iostream>
#include <string>

class Abstract_interface {
    public:
        virtual void some_functionality() = 0;
};

class Implementation_interface
{
    public:
        virtual void another_functionality() = 0;
};

class Bridge : public Abstract_interface
{
    protected:
        Implementation_interface* implementation;

    public:
        Bridge(Implementation_interface* backend) {
            implementation = backend;
        }
};

class Use_case1 : public Bridge {
    public:
        Use_case1(Implementation_interface* backend) : Bridge(backend) {}

        void some_functionality(){
            std::cout << "Use_case1 on ";
            implementation->another_functionality();
        }
};

class Use_case2 : public Bridge {
    public:
        Use_case2(Implementation_interface* backend): Bridge(backend) {}

        void some_functionality() {
            std::cout << "Use_case2 on ";
            implementation->another_functionality();
        }
};

class Windows : public Implementation_interface {
    public:
        void another_functionality(){
            std::cout << "Windows :-!" << std::endl;
        }
};

class Linux : public Implementation_interface
{
    public:
        void another_functionality() {
            std::cout << "Linux! :-)" << std::endl;
        }
};

int main() {
    Abstract_interface *use_case = 0;
    Implementation_interface *osWindows = new Windows;
    Implementation_interface *osLinux = new Linux;


    /* First case */
    use_case = new Use_case1(osWindows);
    use_case->some_functionality();

    use_case = new Use_case1(osLinux);
    use_case->some_functionality();

    /* Second case */
    use_case = new Use_case2(osWindows);
    use_case->some_functionality();

    use_case = new Use_case2(osLinux);
    use_case->some_functionality();

    return 0;
}
