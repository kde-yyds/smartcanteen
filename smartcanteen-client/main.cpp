#include "mainwindow.h"
#include <QApplication>
#include <QStandardPaths>
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.setFixedSize(1280,720);// TODO: make window resizeable
    w.show();
    return a.exec();
}
