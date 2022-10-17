#include <test.h>

int main(int argc, char *argv[])
{
    Base::getInstance().init("Singleton");
    test(Base::getInstance());

    Drawer drawer;
    test(drawer);

    Serializer serializer;
    test(serializer);

    DrawerFigure drawer_figure;
    test(drawer_figure);

    return 0;
}
