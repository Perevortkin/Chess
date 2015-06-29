
#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QFile>
#include <QVector>
#include <QTextStream>
extern QVector<QString> str;
MainWindow::MainWindow(QWidget *parent) :
    QDialog(parent)
{

    QVBoxLayout *lay= new QVBoxLayout;
    lay->setMargin(100);
    stop=new QPushButton("Stop");
    save=new QPushButton("Save");
    stop->setFixedSize(150,30);
    save->setFixedSize(150,30);
    lay->addWidget(save);
    lay->addWidget(stop);


    setLayout(lay);
    connect(stop,SIGNAL(clicked(bool)),this,SLOT(on_pushButton_clicked()));
    connect(save,SIGNAL(clicked(bool)),this,SLOT(on_savedButton_clicked()));
}

MainWindow::~MainWindow()
{
}


void MainWindow::on_pushButton_clicked()
{
    firstwindow *window=new firstwindow();
    window->setGeometry(450,200,400,400);
    QPalette palete;
    palete.setBrush(window->backgroundRole(),QBrush(QImage(":/Images/background.png")));
    window->setPalette(palete);

    window->show();
    this->close();
}
void MainWindow::on_savedButton_clicked()
{
     QFile file("log.txt");
     file.open(QIODevice::WriteOnly | QIODevice::Text);

     QTextStream out(&file);
         QVector<QString>::Iterator iter;
         int i=0;
     for(iter=str.begin();iter!=str.end();iter++)
     {
         out<<str[i];
         i++;
     }
     file.close();

}
