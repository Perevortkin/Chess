#include "figure.h"

figure::figure()
{
str='';
tile=null;
}

figure::figure(Tile *tile)
{
    str='';
    this->tile=tile;
}

void figure::setMove(QString str)
{
    this->str=this->str+str;
}

QString figure::getMove()
{
    return str;
}

void figure::setTile(Tile * tile)
{
    this->tile=tile;
}

char figure::getFifure()
{
    char gf='e';
return gf;
}

