#include "pieces.h"

int Pieces::getBlockType(int pPiece, int pRotation, int pX, int pY)
{
    return mPieces[pPiece][pRotation][pX][pY];
}

int Pieces::getXInitialPosition (int pPiece, int pRotation)
{
    return mPiecesInitialPosition [pPiece][pRotation][0];
}

int Pieces::getYInitialPosition (int pPiece, int pRotation)
{
    return mPiecesInitialPosition [pPiece][pRotation][1];
}