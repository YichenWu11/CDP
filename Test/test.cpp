#include <test.h>

int main(int argc, char *argv[])
{
    // Base::getInstance().test();
    Base::getInstance().init("Singleton");
    test(Base::getInstance());

    return 0;
}
