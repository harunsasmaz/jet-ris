#include "game.h"

Game::Game(Board* board, Pieces* pieces, IO* io, int screenHeight)
{
    this->io = io;
    this->mBoard = board;
    this->mPieces = pieces;
    this->screenHeight = screenHeight;
}

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
    Color color;

    int pixelsX = mBoard->getXPosInPixels(x);
    int pixelsY = mBoard->getYPosInPixels(y);

    for(int i = 0; i < PIECE_BLOCKS; ++i)
    {
        for(int j = 0; j < PIECE_BLOCKS; ++j)
        {
            switch (mPieces->getBlockType(piece, rotation, j, i))
            {
                case 1: color = GREEN; break;
                case 2: color = BLUE; break;
            }

            if (mPieces->getBlockType(piece, rotation, j, i) != 0)
                io->drawRectangle(pixelsX + i * BLOCK_SIZE, pixelsY + j * BLOCK_SIZE, 
                                    (pixelsX + i * BLOCK_SIZE) + BLOCK_SIZE - 1, 
                                    (pixelsY + j * BLOCK_SIZE) + BLOCK_SIZE - 1, 
                                    color);
        }
    }
}

void Game::drawBoard()
{
    int mX1 = BOARD_POSITION - (BLOCK_SIZE * (BOARD_WIDTH / 2)) - 1;
    int mX2 = BOARD_POSITION + (BLOCK_SIZE * (BOARD_WIDTH / 2));
    int mY = screenHeight - (BLOCK_SIZE * BOARD_HEIGHT);
     
    io->drawRectangle (mX1 - BOARD_LINE_WIDTH, mY, mX1, screenHeight - 1, BLUE);
 
    io->drawRectangle (mX2, mY, mX2 + BOARD_LINE_WIDTH, screenHeight - 1, BLUE);
     
    mX1 += 1;
    for (int i = 0; i < BOARD_WIDTH; i++)
    {
        for (int j = 0; j < BOARD_HEIGHT; j++)
        {   
            if (!mBoard->isFreeBlock(i, j))  
                io->drawRectangle(mX1 + i * BLOCK_SIZE, mY + j * BLOCK_SIZE, 
                                    (mX1 + i * BLOCK_SIZE) + BLOCK_SIZE - 1, 
                                    (mY + j * BLOCK_SIZE) + BLOCK_SIZE - 1, 
                                    RED);
        }
    }   
}

void Game::drawScene()
{
    drawBoard();
    drawPiece(posX, posY, piece, rotation);
    drawPiece(nextPosX, nextPosY, nextPiece, nextRotation);
}