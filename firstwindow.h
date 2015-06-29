#ifndef FIRSTWINDOW_H
#define FIRSTWINDOW_H

#include <QDialog>
#include <QWidget>
#include <QPushButton>
#include <QGridLayout>
#include <QLabel>
#include <QVBoxLayout>

class firstwindow : public QDialog
{
    Q_OBJECT
public:
    explicit firstwindow(QWidget *parent = 0);

signals:

public slots:
    void okClicked();
    void loadGameClicked();
private:
    QPushButton *newGame;
    QPushButton *load;
    QPushButton *quit;
};

#endif // FIRSTWINDOW_H
