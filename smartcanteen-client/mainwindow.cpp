#include "mainwindow.h"
#include "./ui_mainwindow.h"

#include <QPropertyAnimation>
#include <QListView>
#include <QListWidgetItem>
#include <QScroller>

#include "ssh.h"

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
    writeConfig_Int("studentNumber", studentNumber);
    Class = ui->spinBox_class->value();
    writeConfig_Int("Class", Class);
    grade = ui->spinBox_grade->value();
    writeConfig_Int("grade", grade);
    host = ui->lineEdit_ipAddress->text().toStdString();
    writeConfig_String("host", host);
    username = ui->lineEdit_userName->text().toStdString();
    writeConfig_String("username", username);
    password = ui->lineEdit_userPasswd->text().toStdString();
    writeConfig_String("password", password);               // it is insecure to store password directly into a text file.
}


void MainWindow::on_configPushButton_clicked()
{
    if(ifOpenSettings)
    {
        //get configs and set them in ui
        readConfig_Int("studentNumber", studentNumber);
        ui->spinBox_studentNumber->setValue (studentNumber);
        readConfig_Int("grade", grade);
        ui->spinBox_grade->setValue(grade);
        readConfig_Int("Class", Class);
        ui->spinBox_class->setValue(Class);
        readConfig_String("host", host);
        ui->lineEdit_ipAddress->setText(QString::fromStdString(host));
        readConfig_String("username", username);
        ui->lineEdit_userName->setText(QString::fromStdString(username));
        readConfig_String("password", password);
        ui->lineEdit_userPasswd->setText(QString::fromStdString(password));

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
        animation->setEndValue(QRect (1140, 30, 71, 31));
        animation->setEasingCurve(QEasingCurve::OutExpo);
        animation->start();
    }
    ifOpenSettings = !ifOpenSettings;
}


void MainWindow::on_startPushButton_clicked()
{
    if(ifOpenMainWidget)
    {
        get_list_from_remote();
        ui->listWidget_studentNumber->clear();

        // show student number on the left listWidget
        for (int i = 1; i <= studentNumber; i++)
        {
            QListWidgetItem *item = new QListWidgetItem (QString::number(i));
            item->setTextAlignment (Qt::AlignCenter);
            ui->listWidget_studentNumber->addItem (item);
        }
        ui->listWidget_studentNumber->setVerticalScrollMode (QListWidget::ScrollPerPixel); //make it possible to scroll smoothly with a touch pad (no animation!)
        QScroller::grabGesture (ui->listWidget_studentNumber, QScroller::LeftMouseButtonGesture); //make it possible to drag with a mouse

        //show items on the right listWidget
        //this is a stub. we should get these files from a server and save them in a data dir.
        readData_Int("itemNumber", itemNumber, "remote");
        for (int i = 1; i <= itemNumber; i++)
        {
            std::string data;
            readData_String(QString::number(i).toStdString(), data, "remote");
            QListWidgetItem *item = new QListWidgetItem (QString::fromStdString(data));
            item->setTextAlignment (Qt::AlignCenter);
            ui->listWidget_chooseItem->addItem (item);
        }
        ui->listWidget_chooseItem->setVerticalScrollMode (QListWidget::ScrollPerPixel); //make it possible to scroll smoothly with a touch pad (no animation!)
        QScroller::grabGesture (ui->listWidget_chooseItem, QScroller::LeftMouseButtonGesture); //make it possible to drag with a mouse


        ui->startPushButton->setText("停止食雪");
        QPropertyAnimation *animation = new QPropertyAnimation {this->ui->widget, "geometry"};
        animation->setDuration(1000);
        animation->setStartValue(this->ui->widget->geometry());
        animation->setEndValue(QRect(140, 130, 981, 441));
        animation->setEasingCurve(QEasingCurve::OutExpo);
        animation->start();
    }else{
        ui->startPushButton->setText("我要食雪");
        QPropertyAnimation *animation = new QPropertyAnimation {this->ui->widget, "geometry"};
        animation->setDuration(1000);
        animation->setStartValue(this->ui->widget->geometry());
        animation->setEndValue(QRect(70, 30, 71, 31));
        animation->setEasingCurve(QEasingCurve::OutExpo);
        animation->start();
    }
    ifOpenMainWidget = ! ifOpenMainWidget;
}


void MainWindow::on_listWidget_studentNumber_currentRowChanged(int currentRow)
{
    currentNumber = currentRow + 1;
    int item = 1;
    readData_Int(QString::number(currentNumber).toStdString(), item, local_storage_dir);
    ui->listWidget_chooseItem->setCurrentRow(item-1);
}


void MainWindow::on_listWidget_chooseItem_currentRowChanged(int currentRow)
{
    currentItem = currentRow + 1;
    item[currentNumber] = currentItem;
    writeData_Int(QString::number(currentNumber).toStdString(), currentItem, local_storage_dir);
}


void MainWindow::on_pushButton_submit_clicked()
{
    writeData_Int("number", studentNumber, local_storage_dir);
    push_data_to_remote();
}

