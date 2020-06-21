#include "pieces.h"

int Pieces::getBlockType(int pPiece, int pRotation, int pX, int pY)
{
    return pieces[pPiece][pRotation][pX][pY];
}

int Pieces::getXInitialPosition (int pPiece, int pRotation)
{
    return piecesInitialPosition [pPiece][pRotation][0];
}

int Pieces::getYInitialPosition (int pPiece, int pRotation)
{
    return piecesInitialPosition [pPiece][pRotation][1];
}