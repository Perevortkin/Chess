#ifndef TILE_H
#define TILE_H
#include <QLabel>
#include <QDebug>

class Tile: public QLabel
{
public:

    int tileColor;//Field
    int piece;//Determines is it figure
    int pieceColor;// 0-black, 1-white
    int row,col,tileNum;
    char pieceName;//Determines figure


    Tile(QWidget* pParent=0, Qt::WindowFlags f=0) : QLabel(pParent, f) {};
    Tile(const QString& text, QWidget* pParent = 0, Qt::WindowFlags f = 0) : QLabel(text, pParent, f){};

    void mousePressEvent(QMouseEvent *event);
    void display(char elem);
    void tileDisplay();
    void log();
};

#endif // TILE_H
