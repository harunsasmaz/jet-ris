#include "board.h"

Board::Board(Pieces* pieces, int screenHeight)
{
    this->pieces = pieces;
    this->screenHeight = screenHeight;
}

void Board::initBoard()
{
    for(int i = 0; i < BOARD_WIDTH; ++i)
        for(int j = 0; i < BOARD_HEIGHT; ++j)
            board[i][j] = POS_FREE;
}

void Board::storePiece(int x, int y, int piece, int rotation)
{
    for (int i1 = x, i2 = 0; i1 < x + PIECE_BLOCKS; i1++, i2++)
    {
        for (int j1 = y, j2 = 0; j1 < y + PIECE_BLOCKS; j1++, j2++)
        {   
            if (pieces->getBlockType(piece, rotation, j2, i2) != 0)      
                board[i1][j1] = POS_FILLED;    
        }
    }
}

bool Board::isGameOver()
{
    for(int i = 0; i < BOARD_WIDTH; ++i)
        if(board[i][0] == POS_FILLED) return true;
    return false;
}

void Board::deleteLine(int pY)
{
    for(int i = pY; i > 0; --i)
        for(int j = 0; j < BOARD_WIDTH; ++j)
            board[j][i] = board[j][i - 1];
}

void Board::deletePossibleLines()
{   
    int i;
    for(int j = 0; j < BOARD_HEIGHT; ++j)
    {
        i = 0;
        while(i < BOARD_WIDTH)
        {
            if(board[i][j] == POS_FREE) break;
            i++;
        }
        if(i == BOARD_WIDTH) deleteLine(j);
    }
}

bool Board::isFreeBlock(int X, int Y)
{
    return board[X][Y] == POS_FREE ? true : false;
}

int Board::getXPosInPixels(int pos)
{
    return  (BOARD_POSITION - (BLOCK_SIZE * (BOARD_WIDTH / 2)) ) + (pos * BLOCK_SIZE);
}

int Board::getYPosInPixels(int pos)
{
    return (screenHeight - (BLOCK_SIZE * BOARD_HEIGHT)) + (pos * BLOCK_SIZE);
}

bool Board::isPossibleMovement(int x, int y, int piece, int rotation)
{
    for (int i1 = x, i2 = 0; i1 < x + PIECE_BLOCKS; i1++, i2++)
    {
        for (int j1 = y, j2 = 0; j1 < y + PIECE_BLOCKS; j1++, j2++)
        {   
            // Check if the piece is outside the limits of the board
            if (i1 < 0 || i1 > BOARD_WIDTH  - 1 || j1 > BOARD_HEIGHT - 1)
                if (pieces->getBlockType(piece, rotation, j2, i2) != 0)
                    return false;       
 
            // Check if the piece have collisioned with a block already stored in the map
            if (j1 >= 0) 
                if (pieces->getBlockType(piece, rotation, j2, i2) != 0 && !isFreeBlock(i1, j1) )
                    return false;
        }
    }
 
    // No collision
    return true;
}