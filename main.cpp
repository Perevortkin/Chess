#include "board.cpp"

extern int count;
extern int turn;
extern int exp[60];
extern int max;
extern int figure;
extern Tile *click1;

extern Tile *tile[8][8];

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    firstwindow *window=new firstwindow();
    window->setGeometry(450,200,400,400);
    QPalette palete;
    palete.setBrush(window->backgroundRole(),QBrush(QImage(":/Images/background.png")));
    window->setPalette(palete);
    window->show();
    return a.exec();
}

