#include <iostream>

#include <CDP/Singleton/Singleton.h>
#include <CDP/Visitor/Visitor.h>

using namespace Chen;
using test_type = std::string;

class Test;
void test(Test &);

class Test
{
    friend void test(Test& t);
public:
    virtual void test() = 0;
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


// ******************** Visitor *************************

class IFigure 
{
public: 
    virtual ~IFigure() = default;
};

class Sphere : public IFigure {};

class Polygon : public IFigure {};

class Drawer : public Visitor<Drawer, IFigure>, public Test
{
public:
    Drawer()
    {
        type = "Visitor";
        Register<Sphere>();
        Register<Polygon>();
    }

    void ImplVisit(Sphere*);
    void ImplVisit(Polygon*);

    virtual void test() override 
    { 
        Sphere  s;
        Polygon p;
        
        this->Visit(&s);
        this->Visit(&p);

        std::cout << std::endl;
    }
};

void Drawer::ImplVisit(Sphere*)
{
    std::cout << "ImplVisit Sphere*" << std::endl;
}

void Drawer::ImplVisit(Polygon*)
{
    std::cout << "ImplVisit Polygon*" << std::endl;
}

// ******************** Visitor *************************
