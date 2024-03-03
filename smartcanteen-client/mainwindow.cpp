#include "mainwindow.h"
#include "./ui_mainwindow.h"


#include "config.h"
#include "standardPath.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}
