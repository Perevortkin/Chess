
#include <QApplication>
#include "mainwindow.h"
#include "tile.h"
#include "loadgame.h"
#include <QFile>

int count=0;
int turn=1;
int exp[60],max=0;
extern int retVal;

Tile *click1;

Tile *tile[8][8] = { { NULL } };

class Border
{
public:
    Border();
    void outline(QWidget *baseWidget, int xPos, int yPos, int Pos)
    {
         QLabel *outLabel = new QLabel(baseWidget);

        if(!Pos)
            outLabel->setGeometry(xPos,yPos,552,20);

        else
            outLabel->setGeometry(xPos,yPos,20,512);

        outLabel->setStyleSheet("QLabel { background-color :rgb(170, 170, 127); color : black; }");
    }
};

void accessories(QWidget *baseWidget)
{
    QLabel *player2 = new QLabel(baseWidget);
    QLabel *name2 = new QLabel("Player 2", baseWidget);

    QLabel *player1 = new QLabel(baseWidget);
    QLabel *name1 = new QLabel("Player 1", baseWidget);


    name1->setGeometry(125,610,80,20);
    player1->setGeometry(100,500,100,100);
    player1->setPixmap(QPixmap(":/Images/player.jpg"));

    name2->setGeometry(125,210,80,20);
    player2->setGeometry(100,100,100,100);
    player2->setPixmap(QPixmap(":/Images/player2.jpg"));

}


void visualizeBoard(QWidget *baseWidget, Tile *tile[8][8])
{
    int i,j,k=0,hor,ver;
    Border *border[4]={ NULL };


    {
    border[0]->outline(baseWidget,330,105,0);
    border[1]->outline(baseWidget,330,637,0);
    border[2]->outline(baseWidget,330,125,1);
    border[2]->outline(baseWidget,862,125,1);
    }

    ver=125;
    for(i=0;i<8;i++)
    {
        hor=350;
        for(j=0;j<8;j++)
        {
            tile[i][j] = new Tile(baseWidget);
            tile[i][j]->tileColor=(i+j)%2;
            tile[i][j]->piece=0;
            tile[i][j]->row=i;
            tile[i][j]->col=j;
            tile[i][j]->tileNum=k++;
            tile[i][j]->tileDisplay();
            tile[i][j]->setGeometry(hor,ver,64,64);
            hor+=64;
        }
        ver+=64;
    }
}

void visualizeStartGameStage(Tile *tile[8][8])
{
    int i,j,k=0,hor,ver;
    for(j=0;j<8;j++)
    {
        tile[1][j]->piece=1;
        tile[1][j]->pieceColor=0;
        tile[1][j]->display('P');
    }

    for(j=0;j<8;j++)
    {
        tile[6][j]->piece=1;
        tile[6][j]->pieceColor=1;
        tile[6][j]->display('P');
    }

    for(j=0;j<8;j++)
    {
        tile[0][j]->piece=1;
        tile[0][j]->pieceColor=0;
        tile[7][j]->piece=1;
        tile[7][j]->pieceColor=1;
    }

    {
    tile[0][0]->display('R');
    tile[0][1]->display('H');
    tile[0][2]->display('B');
    tile[0][3]->display('Q');
    tile[0][4]->display('K');
    tile[0][5]->display('B');
    tile[0][6]->display('H');
    tile[0][7]->display('R');
    }


    {
    tile[7][0]->display('R');
    tile[7][1]->display('H');
    tile[7][2]->display('B');
    tile[7][3]->display('Q');
    tile[7][4]->display('K');
    tile[7][5]->display('B');
    tile[7][6]->display('H');
    tile[7][7]->display('R');
    }
}

struct TileConfig
{
    TileConfig(char aname, int arow, int acol, int acolor) : name(aname), row(arow), col(acol), color(acolor) {}
    char name;
    int row;
    int col;
    int color;
};

std::vector<TileConfig> loadedTiles;

void visualizeLoadedGameStage(Tile *tile[8][8])
{
    QFile file("log.txt");
    file.open(QIODevice::ReadOnly | QIODevice::Text);

    QTextStream stream(&file);
    QString line;
    do {
        line = stream.readLine();
        QStringList tokens = line.split(':', QString::SkipEmptyParts);
        if (!tokens.empty())
            loadedTiles.push_back(TileConfig(*tokens.at(0).toLatin1().data(), tokens.at(1).toInt(), tokens.at(2).toInt(), tokens.at(3).toInt()));
        //qDebug() << tokens.at(0) << tokens.at(1).toInt() << tokens.at(2).toInt();
    } while (!line.isNull());

    file.close();
    std::vector<TileConfig>::iterator itr = loadedTiles.begin();
    for (; itr != loadedTiles.end(); ++itr)
    {
        char name = itr->name;
        int row = itr->row;
        int col = itr->col;
        int color = itr->color;

        tile[row][col]->piece=1;
        tile[row][col]->pieceColor=color;
        tile[row][col]->display(name);
    }
}

void chessBoard(QWidget *baseWidget, Tile *tile[8][8])
{
    visualizeBoard(baseWidget, tile);
    visualizeStartGameStage(tile);
}

void loadChessBoard(QWidget *baseWidget, Tile *tile[8][8])
{
    visualizeBoard(baseWidget, tile);
    visualizeLoadedGameStage(tile);
}

firstwindow::firstwindow(QWidget *parent) : QDialog(parent)
{
 newGame= new QPushButton("New Game");
 newGame->raise();
 newGame->setFixedSize(150,30);

 load= new QPushButton("Load Game");
 load->setFixedSize(150,30);

 quit= new QPushButton("Quit");
 quit->setFixedSize(150,30);

 QGridLayout *layout= new QGridLayout;

 layout->addWidget(newGame,1,1,1,1);
 layout->addWidget(load,2,1,1,1);
 layout->addWidget(quit,3,1,1,1);
    setLayout(layout);
connect(quit,SIGNAL(clicked(bool)),this, SLOT(close()));
connect(newGame,SIGNAL(clicked(bool)),this,SLOT(okClicked()));
connect(load,SIGNAL(clicked(bool)),this,SLOT(loadGameClicked()));

}

 void firstwindow::okClicked()
 {

    MainWindow *myWindow=new  MainWindow();
     myWindow->setGeometry(0,0,1366,768);

     accessories(myWindow);
     chessBoard(myWindow,tile);
     this->close();

     myWindow->show();

 }
 void firstwindow::loadGameClicked()
 {
     MainWindow *myWindow=new  MainWindow();
      myWindow->setGeometry(0,0,1366,768);

      accessories(myWindow);
      loadChessBoard(myWindow,tile);
      this->close();

      myWindow->show();

 }
