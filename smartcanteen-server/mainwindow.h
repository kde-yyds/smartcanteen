#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_pushButton_show_clicked();

    void on_listWidget_studentNumber_currentRowChanged(int currentRow);

    void on_spinBox_number_valueChanged();

    void on_listWidget_number_currentRowChanged(int currentRow);

    void on_lineEdit_name_textChanged(const QString &arg1);

    void on_listWidget_chooseItem_currentRowChanged(int currentRow);

private:
    Ui::MainWindow *ui;
};
#endif // MAINWINDOW_H
