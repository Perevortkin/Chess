#ifndef FIGURE_H
#define FIGURE_H
#include "tile.h"

class figure
{
    QString str;
    Tile *tile;
public:
    figure();
    figure(Tile *);
    void setMove(QString);
    QString getMove();
    void setTile(Tile *);
    char getFifure();

};

#endif // FIGURE_H
