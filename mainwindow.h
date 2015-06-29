#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include "firstwindow.h"




class MainWindow : public QDialog
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private slots:
    void on_pushButton_clicked();
    void on_savedButton_clicked();

private:

    QPushButton *stop;
    QPushButton *save;
};

#endif // MAINWINDOW_H
