#include "mainwindow.h"
#include "./ui_mainwindow.h"

#include <QPropertyAnimation>
#include <QListView>
#include <QListWidgetItem>
#include <QScroller>

#include "config.h"

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

void MainWindow::on_pushButton_show_clicked()
{
    std::string subDir;
    subDir = QString::number(ui->spinBox_grade->value()).toStdString() + "_" + QString::number(ui->spinBox_class->value()).toStdString();
    ui->listWidget_chooseItem->setMouseTracking(false);
    ui->listWidget_studentNumber->clear();

    readData_Int("number", studentNumber, subDir);

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
    readData_Int("itemNumber", itemNumber, "../remote");
    for (int i = 1; i <= itemNumber; i++)
    {
        std::string data;
        readData_String(QString::number(i).toStdString(), data, "../remote");
        QListWidgetItem *item = new QListWidgetItem (QString::fromStdString(data));
        item->setTextAlignment (Qt::AlignCenter);
        ui->listWidget_chooseItem->addItem (item);
    }
    ui->listWidget_chooseItem->setVerticalScrollMode (QListWidget::ScrollPerPixel); //make it possible to scroll smoothly with a touch pad (no animation!)
    QScroller::grabGesture (ui->listWidget_chooseItem, QScroller::LeftMouseButtonGesture); //make it possible to drag with a mouse
}

void MainWindow::on_listWidget_studentNumber_currentRowChanged(int currentRow)
{
    currentNumber = currentRow + 1;
    int item = 1;
    readData_Int(QString::number(currentNumber).toStdString(), item, QString::number(ui->spinBox_grade->value()).toStdString() + "_" + QString::number(ui->spinBox_class->value()).toStdString());
    ui->listWidget_chooseItem->setCurrentRow(item-1);
}


void MainWindow::on_spinBox_number_valueChanged()
{
    number = ui->spinBox_number->value();
    writeData_Int("itemNumber", number, "../remote");
    ui->listWidget_number->clear(); //clear listWidget before adding new lines.
    for (int i = 1; i <= number; i++)
    {
        QListWidgetItem *item = new QListWidgetItem (QString::number(i));
        item->setTextAlignment (Qt::AlignCenter);
        ui->listWidget_number->addItem (item);
    }
    ui->listWidget_number->setVerticalScrollMode (QListWidget::ScrollPerPixel); //make it possible to scroll smoothly with a touch pad (no animation!)
    QScroller::grabGesture (ui->listWidget_number, QScroller::LeftMouseButtonGesture); //make it possible to drag with a mouse

}


void MainWindow::on_listWidget_number_currentRowChanged(int currentRow)
{
    currentNumber_editWidget = currentRow + 1;
    std::string text;
    readData_String(QString::number(currentNumber_editWidget).toStdString(), text, "../remote");
    ui->lineEdit_name->setText(text.data());
}


void MainWindow::on_lineEdit_name_textChanged(const QString &arg1)
{
    writeData_String(QString::number(currentNumber_editWidget).toStdString(), arg1.toStdString(), "../remote");
}


void MainWindow::on_listWidget_chooseItem_currentRowChanged(int currentRow)
{
    int item = 1;
    readData_Int(QString::number(currentNumber).toStdString(), item, QString::number(ui->spinBox_grade->value()).toStdString() + "_" + QString::number(ui->spinBox_class->value()).toStdString());
    ui->listWidget_chooseItem->setCurrentRow(item-1);
}
