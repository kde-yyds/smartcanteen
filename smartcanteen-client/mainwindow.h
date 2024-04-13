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
    void on_pushButton_saveConfigs_clicked();

    void on_configPushButton_clicked();

    void on_startPushButton_clicked();

    void on_listWidget_studentNumber_currentRowChanged(int currentRow);

    void on_listWidget_chooseItem_currentRowChanged(int currentRow);

    void on_pushButton_submit_clicked();

private:
    Ui::MainWindow *ui;
};
#endif // MAINWINDOW_H
