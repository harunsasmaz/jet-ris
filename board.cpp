#include "board.h"

void Board::initBoard()
{
    for(int i = 0; i < BOARD_WIDTH; ++i)
        for(int j = 0; i < BOARD_HEIGHT; ++j)
            mBoard[i][j] = POS_FREE;
}

void Board::storePiece(int pX, int pY, int pPiece, int pRotation)
{
    for (int i1 = pX, i2 = 0; i1 < pX + PIECE_BLOCKS; i1++, i2++)
    {
        for (int j1 = pY, j2 = 0; j1 < pY + PIECE_BLOCKS; j1++, j2++)
        {   
            if (mPieces->getBlockType(pPiece, pRotation, j2, i2) != 0)      
                mBoard[i1][j1] = POS_FILLED;    
        }
    }
}

