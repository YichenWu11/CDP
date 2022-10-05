#include <iostream>
#include "Singleton.h"

class Base : public Singleton<Base>
{
public:
    void show() { std::cout << "Content from Base(Singleton) : " << i << std::endl; }
private:
    int i = 1;
};

int main(int argc, char *argv[])
{
    Base::getInstance().show();
    
    return 0;
}

