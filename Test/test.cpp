#include <iostream>
#include "Singleton.h"
#include "test.h"

int main(int argc, char *argv[])
{
    Base::getInstance().test();

    return 0;
}
