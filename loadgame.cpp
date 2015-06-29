#include "loadgame.h"

loadGame::loadGame(QWidget *parent) : QDialog(parent)
{
    QVBoxLayout *mainLay= new QVBoxLayout;
    QVBoxLayout *lay= new QVBoxLayout;
    //lay->setMargin(100);
    QVBoxLayout *lay2= new QVBoxLayout;
    //lay->setMargin(100);
    mainLay->addLayout(lay);
    mainLay->addLayout(lay2);

    next=new QPushButton("Next");
    stop=new QPushButton("Stop");
    prev=new QPushButton("Prev");

    next->setFixedSize(150,30);
    stop->setFixedSize(150,30);
    prev->setFixedSize(150,30);

    lay->addWidget(next);
    lay->addWidget(prev);
    lay->addWidget(stop);

    setLayout(mainLay);
    connect(next,SIGNAL(clicked(bool)),this,SLOT(nextClicked()));
    connect(stop,SIGNAL(clicked(bool)),this,SLOT(stopClicked()));
    connect(prev,SIGNAL(clicked(bool)),this,SLOT(prevClicked()));
}
void loadGame::nextClicked()
{

}

void loadGame::prevClicked()
{

}

void loadGame::stopClicked()
{
    firstwindow *window=new firstwindow();
    window->setGeometry(450,200,400,400);
    QPalette palete;
    palete.setBrush(window->backgroundRole(),QBrush(QImage(":/Images/background.png")));
    window->setPalette(palete);

    window->show();
    this->close();
}
