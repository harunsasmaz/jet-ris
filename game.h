#ifndef _GAME_
#define _GAME_

#include "board.h"
#include "pieces.h"
#include "io.h"
#include <time.h>
#include <stdlib.h>

#define WAIT_TIME 750

class Game
{
public:
 
    Game(Board *pBoard, Pieces *pPieces, IO *pIO, int pScreenHeight);
 
    void drawScene();
    void createNewPiece();
 
    int posX, posY;               // Position of the piece that is falling down
    int piece, rotation;         // Kind and rotation the piece that is falling down
 
private:
 
    int screenHeight;              // Screen height in pixels
    int nextPosX, nextPosY;       // Position of the next piece
    int nextPiece, nextRotation;  // Kind and rotation of the next piece
 
    Board *mBoard;
    Pieces *mPieces;
    //IO *mIO;
 
    int getRand(int lower, int upper);
    void initGame();
    void drawPiece(int pX, int pY, int pPiece, int pRotation);
    void drawBoard();
};

#endif