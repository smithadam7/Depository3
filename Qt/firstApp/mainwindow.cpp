//Adam Smith
//PA3
#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QMessageBox>
#include <string>
#include <QString>
#include <stack>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_actionExit_triggered()
{
    delete ui;
    exit(0);
}

void MainWindow::on_actionAbout_triggered()
{
    QMessageBox::information(this,tr("Cryptolator"),tr("Version 0.1 \nMade by: Adam Smith\nCSCI 2312"));
}

void MainWindow::on_pushButton_3_clicked()
{
    std::string plainStr;
    QString plainQStr;
    plainStr = ui->lineEdit_4->text().toStdString();
    int rotation = ui->spinBoxRotate->value();
    std::string tempStr = plainStr;
    for(unsigned long i = 0;i<plainStr.size();i++){
        if(rotation>=0){
            tempStr[i] = (tempStr[i]+rotation) % 126;
            if((tempStr[i]>=0) && (tempStr[i]<32)){
                tempStr[i] += 31;
            }
        }
        else{
            tempStr[i]=(tempStr[i]+rotation) % 126;
            if((tempStr[i]>=0) && (tempStr[i] < 32)){
                tempStr[i] = 126 - 31+tempStr[i];
            }
        }
    }
    plainStr = tempStr;
    ui->lineEdit_5->setText(plainQStr.fromStdString(plainStr));
}

void MainWindow::on_pushButton_ceasarDecrypt_clicked()
{
    std::string plainStr;
    QString plainQStr;
    plainStr = ui->lineEdit_5->text().toStdString();
    int rotation = ui->spinBoxRotate->value();
    rotation = 0-rotation;
    std::string tempStr = plainStr;
    for(unsigned long i = 0;i<plainStr.size();i++){
        if(rotation>=0){
            tempStr[i] = (tempStr[i]+rotation) % 126;
            if((tempStr[i]>=0) && (tempStr[i]<32)){
                tempStr[i] += 31;
            }
        }
        else{
            tempStr[i]=(tempStr[i]+rotation) % 126;
            if((tempStr[i]>=0) && (tempStr[i] < 32)){
                tempStr[i] = 126 - 31+tempStr[i];
            }
        }
    }
    plainStr = tempStr;
    ui->lineEdit_4->setText(plainQStr.fromStdString(plainStr));
}

void MainWindow::on_clearButton_clicked()
{
    ui->originalWord->clear();
    ui->wordReversed->clear();
}

void MainWindow::on_reverseButton_clicked()
{
    std::stack<char> s;
    QString plainQStr;
    plainQStr= ui->originalWord->text();
    std::string tempStr = plainQStr.toStdString();
    for(int i=0;i<tempStr.size();i++){
        s.push(tempStr[i]);
    }

    for(int i=0;i<tempStr.size();i++){
        tempStr[i]=s.top();
        s.pop();
    }
    ui->wordReversed->setText(plainQStr.fromStdString(tempStr));

}
