#include "tile.h"
#include "validation.h"
#include <QVector>


QVector<QString> str;
validation *valid = new validation();
extern int count,turn;
extern QWidget *myWidget;
extern Tile *click1;
extern Tile *tile[8][8];

void validate(Tile *temp,int c);
void disOrange();

void Tile::log()
{

         str.push_back(QString::number(this->tileNum+1));
    str.push_back(QString('\n'));

}

void Tile::mousePressEvent(QMouseEvent *event)
{
    validate(this,++count);

}
void Tile::display(char elem)
{
    this->pieceName=elem;
    if(this->pieceColor && this->piece)
    {
        switch(elem)
        {
            case 'P': this->setPixmap(QPixmap(":/Images/pawn_white.svg"));
                      break;
            case 'R': this->setPixmap(QPixmap(":/Images/rook_white.svg"));
                      break;
            case 'H': this->setPixmap(QPixmap(":/Images/knight_white.svg"));
                      break;
            case 'K': this->setPixmap(QPixmap(":/Images/king_white.svg"));
                      break;
            case 'Q': this->setPixmap(QPixmap(":/Images/queen_white.svg"));
                      break;
            case 'B': this->setPixmap(QPixmap(":/Images/bishop_white.svg"));
                      break;
        }
    }
    else if(this->piece)
    {
        switch(elem)
        {
        case 'P': this->setPixmap(QPixmap(":/Images/pawn_black.svg"));
                  break;
        case 'R': this->setPixmap(QPixmap(":/Images/rook_black.svg"));
                  break;
        case 'H': this->setPixmap(QPixmap(":/Images/knight_black.svg"));
                  break;
        case 'K': this->setPixmap(QPixmap(":/Images/king_black.svg"));
                  break;
        case 'Q': this->setPixmap(QPixmap(":/Images/queen_black.svg"));
                  break;
        case 'B': this->setPixmap(QPixmap(":/Images/bishop_black.svg"));
                  break;
        }
    }
    else
        this->clear();
}

void validate(Tile *temp, int c)
{
    int retValue,i;

    if(c==1)
    {

        if(temp->piece && (temp->pieceColor==turn))
        {

            retValue=valid->chooser(temp);
            if(retValue)
            {
                temp->log();
                click1= new Tile();
                temp->setStyleSheet("QLabel {background-color: green;}");
                click1=temp;
            }
            else
            {

                count=0;
            }
        }
        else
        {

            count=0;
        }

            qDebug()<<"c = 1";
    }

    else
    { 
        if(temp->tileNum==click1->tileNum)
        {
            click1->tileDisplay();
            disOrange();
            max=0;
            count=0;
        }

        for(i=0;i<max;i++)
        {            
            if(temp->tileNum==exp[i])
            {
                click1->piece=0;
                temp->piece=1;

                temp->pieceColor=click1->pieceColor;
                temp->pieceName=click1->pieceName;

                click1->display(click1->pieceName);
                temp->display(click1->pieceName);

                click1->tileDisplay();
                temp->tileDisplay();


                disOrange();

                max=0;
                temp->log();
                turn=(turn+1)%2;
                count=0;
            }

            else
            {

                count=1;
            }

            qDebug()<<"c != 1 zzzzzzzz";
        }
    }
}
void Tile::tileDisplay()
{

    if(this->tileColor)
        this->setStyleSheet("QLabel {background-color: rgb(120, 120, 90);}:hover{background-color: rgb(170,85,127);}");
    else
        this->setStyleSheet("QLabel {background-color: rgb(211, 211, 158);}:hover{background-color: rgb(170,95,127);}");
}
void disOrange()
{
    int i;

    for(i=0;i<max;i++)
       tile[exp[i]/8][exp[i]%8]->tileDisplay();

}
