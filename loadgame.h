#ifndef LOADGAME_H
#define LOADGAME_H

#include <QDialog>
#include <QWidget>
#include <QPushButton>
#include <QGridLayout>
#include <QLabel>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <firstwindow.h>

class loadGame: public QDialog
{
    Q_OBJECT
public:
     explicit loadGame(QWidget *parent = 0);

signals:

public slots:
    void nextClicked();
    void prevClicked();
    void stopClicked();
private:
    QPushButton *next;
    QPushButton *prev;
    QPushButton *stop;
};

#endif // LOADGAME_H
