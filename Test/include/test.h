#include <CDP/Singleton/Singleton.h>
#include <iostream>

using namespace Chen;
using test_type = std::string;

class Test;

void test(Test &);

class Test
{
    friend void test(Test& t);
public:
    virtual void test() = 0;
    void output_line(test_type type) 
    { std::cout << "***************" << type << "***************" << std::endl << std::endl; }
protected:
    test_type type = "";
};

void test(Test &t)
{
    std::cout << "*************** " << t.type << " ***************" << std::endl << std::endl;
    t.test();
    std::cout << "*************** " << t.type << " ***************" << std::endl << std::endl;
}

// ******************** Singleton ***********************

class Base : public Singleton<Base>, public Test
{
public:
    virtual void test() override 
    { 
        std::cout << "Content from Base(Singleton) : " << i << std::endl << std::endl; 
    }

    void init(test_type t) { type = t; }
private:
    int i = 1;
};

// ******************** Singleton ***********************

