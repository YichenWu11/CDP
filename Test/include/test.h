#include "Singleton.h"
#include <iostream>

using test_type = std::string;

class Test
{
public:
    virtual void test() = 0;
    void output_line(test_type type) 
    { std::cout << "***************" << type << "***************" << std::endl << std::endl; }
};

// ******************** Singleton ***********************

class Base : public Singleton<Base>, public Test
{
public:
    virtual void test() override 
    { 
        Test::output_line(type);
        std::cout << "Content from Base(Singleton) : " << i << std::endl << std::endl; 
        Test::output_line(type);
    }
private:
    test_type type = "Single";
    int i = 1;
};

// ******************** Singleton ***********************

