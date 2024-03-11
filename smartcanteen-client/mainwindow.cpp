#include "mainwindow.h"
#include "./ui_mainwindow.h"

#include <QPropertyAnimation>
#include <QListView>
#include <QListWidgetItem>

#include "config.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    //get config when starting up
    //readConfig_Int ("studentNumber", studentNumber);
    //ui->spinBox_studentNumber->setValue (studentNumber); // do not set value here because it will cause a crash



    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_saveConfigs_clicked()
{
    studentNumber = ui->spinBox_studentNumber->value();
    writeConfig_Int ("studentNumber", studentNumber);
}


void MainWindow::on_configPushButton_clicked()
{
    if (ifOpenSettings)
    {
        //get configs and set them in ui
        readConfig_Int ("studentNumber", studentNumber);
        ui->spinBox_studentNumber->setValue (studentNumber);

        ui->configPushButton->setText("关闭设置");
        QPropertyAnimation *animation = new QPropertyAnimation {this->ui->configWidget, "geometry"};
        animation->setDuration(1000);
        animation->setStartValue(this->ui->configWidget->geometry());
        animation->setEndValue(QRect(140, 130, 981, 441));
        animation->setEasingCurve(QEasingCurve::OutExpo);
        animation->start();
    }
    else
    {
        //TODO: warn before closing if config not saved
        ui->configPushButton->setText("打开设置");
        QPropertyAnimation *animation = new QPropertyAnimation {this->ui->configWidget, "geometry"};
        animation->setDuration(1000);
        animation->setStartValue(this->ui->configWidget->geometry());
        animation->setEndValue(QRect(1140, 30, 71, 31));
        animation->setEasingCurve(QEasingCurve::OutExpo);
        animation->start();
    }
    ifOpenSettings = !ifOpenSettings;
}


void MainWindow::on_startPushButton_clicked()
{
    ui->listWidget_studentNumber->clear();
    for (int i = 1; i <= studentNumber; i++) {
        QListWidgetItem *item = new QListWidgetItem(QString::number(i));
        item->setTextAlignment(Qt::AlignCenter);
        ui->listWidget_studentNumber->addItem(item);
    }
}

