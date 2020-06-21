#include "game.h"

int Game::getRand(int low, int high)
{
    return rand() % (high - low + 1) + low;
}

void Game::initGame()
{
    // Init random numbers
    srand ((int) time(NULL));
 
    // First piece
    piece          = getRand (0, 6);
    rotation       = getRand (0, 3);
    posX           = (BOARD_WIDTH / 2) + mPieces->getXInitialPosition(piece, rotation);
    posY           = mPieces->getYInitialPosition(piece, rotation);
 
    //  Next piece
    nextPiece      = getRand (0, 6);
    nextRotation   = getRand (0, 3);
    nextPosX       = BOARD_WIDTH + 5;
    nextPosY       = 5;    
}

void Game::createNewPiece()
{
    // The new piece
    piece           = nextPiece;
    rotation       = nextRotation;
    posX           = (BOARD_WIDTH / 2) + mPieces->getXInitialPosition(piece, rotation);
    posY           = mPieces->getYInitialPosition(piece, rotation);
 
    // Random next piece
    nextPiece      = getRand (0, 6);
    nextRotation   = getRand (0, 3);
}

void Game::drawPiece(int x, int y, int piece, int rotation)
{
    color mColor;
    for(int i = 0; i < PIECE_BLOCKS; ++i)
    {
        for(int j = 0; j < PIECE_BLOCKS; ++j)
        {
            switch (mPieces->getBlockType(piece, rotation, j, i))
            {
                case 1: mColor = GREEN; break;
                case 2: mColor = BLUE; break;
            }
        }
    }
}