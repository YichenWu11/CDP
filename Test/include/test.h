#include <iostream>

#include <CDP/Singleton/Singleton.h>
#include <CDP/Visitor/Visitor.h>
#include <CDP/Visitor/General_Visitor.h>

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
    test_type name = "";
};

class Sphere : public IFigure {
public: 
    Sphere() { name = "Sphere"; }
};

class Polygon : public IFigure {
public: 
    Polygon() { name = "Polygon"; }
};


// Drawer
class Drawer : public Visitor<Drawer, IFigure>, public Test
{
public:
    Drawer()
    {
        type = " Visitor ";
        Register<Sphere>();
        Register<Polygon>();
    }

    void ImplVisit(Sphere*);
    void ImplVisit(Polygon*);

    void test() override 
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
    std::cout << "Draw Sphere*" << std::endl;
}

void Drawer::ImplVisit(Polygon*)
{
    std::cout << "Draw Polygon*" << std::endl;
}


// Serializer
class Serializer : public Visitor<Serializer, IFigure>, public Test
{
public:
    Serializer()
    {
        type = " Visitor ";
        Register<Sphere>();
        Register<Polygon>();
    }

    void ImplVisit(Sphere*);
    void ImplVisit(Polygon*);

    void test() override 
    { 
        Sphere  s;
        Polygon p;
        
        this->Visit(&s);
        this->Visit(&p);

        std::cout << std::endl;
    }
};

void Serializer::ImplVisit(Sphere*)
{
    std::cout << "Serialize Sphere*" << std::endl;
}

void Serializer::ImplVisit(Polygon*)
{
    std::cout << "Serialize Polygon*" << std::endl;
}


// GeneralVisitor

template<typename Func>
class FigureVisitor;

using DerivedFigures = std::tuple<Sphere, Polygon>;

template<typename R, typename... Args>
class FigureVisitor<R(Args...)>
    : public GeneralVisitor<FigureVisitor<R(Args...)>, IFigure, DerivedFigures, R(Args...)>, public Test
{
public:
    virtual R ImplVisit(IFigure *, Args...) { throw std::runtime_error("not implemented"); }
};

// 定制访问函数签名
class DrawerFigure : public FigureVisitor<int(int)> {
public:
    DrawerFigure() { type = " Visitor "; }

    int ImplVisit(IFigure *figure, int) override {
        std::cout << figure->name << std::endl;
        return 1;
    }
    
    void test() override
    {
        Sphere  s;
        Polygon p;
        
        this->Visit(&s,1);
        this->Visit(&p,1);

        std::cout << std::endl;
    }
};

// ******************** Visitor *************************
