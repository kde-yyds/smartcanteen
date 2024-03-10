#include "mainwindow.h"

#include <QApplication>

#include "config.h"

int main(int argc, char *argv[])
{


    writeConfig_String("str.cfg", "amagi");
    writeConfig_Int("int.cfg", 114514);

    std::string a1; int b1;
    readConfig_String("str.cfg", a1);
    readConfig_Int("int.cfg", b1);
    std::cout<<"a1="<<a1<<"b1="<<b1;


    QApplication a(argc, argv);
    MainWindow w;
    w.setFixedSize(1280,720);// TODO: make window resizeable
    w.show();
    return a.exec();
}
