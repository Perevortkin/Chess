#ifndef VALIDATION_H
#define VALIDATION_H
#include "tile.h"

extern Tile *tile[8][8];
extern int exp[60],max;

class validation
{
    int retVal;

public:

     int flag;
    validation();
    int chooser(Tile *temp);
    //Determines the motion of figures
    int validateBishop(Tile *temp);
    int validateQueen(Tile *temp);
    int validateKing(Tile *temp);
    int validateHorse(Tile *temp);
    int validateRook(Tile *temp);
    int validatePawn(Tile *temp);
    //Show possible moves
    void orange();
};

#endif // VALIDATION_H
