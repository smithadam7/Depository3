#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private slots:
    void on_actionExit_triggered();

    void on_actionAbout_triggered();

    void on_pushButton_3_clicked();

    void on_pushButton_ceasarDecrypt_clicked();

    void on_clearButton_clicked();

    void on_reverseButton_clicked();

private:
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
