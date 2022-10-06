#include <test.h>

int main(int argc, char *argv[])
{
    Base::getInstance().init("Singleton");
    test(Base::getInstance());

    Drawer drawer;
    test(drawer);

    return 0;
}
