#include "game.h"
#include <stdio.h>
#include <stdlib.h>

#ifdef __cplusplus
extern "C"
#endif

int main(int argc, char* argv[])
{
    IO io;
    int screenHeight = io.getScreenHeight();

    Pieces pieces;
    Board board(&pieces, screenHeight);
    Game game(&board, &pieces, &io, screenHeight);

    unsigned long time = SDL_GetTicks();

    while(!io.isKeyDown(SDLK_ESCAPE))
    {
        io.clearScreen();
        game.drawScene();
        io.updateScreen();

        int key = io.pollkey();

        switch (key)
        {
            case SDLK_RIGHT:
                if (board.isPossibleMovement(game.posX + 1, game.posY, game.piece, game.rotation))
                    game.posX++;
                break;

            case SDLK_LEFT:
                if (board.isPossibleMovement(game.posX - 1, game.posY, game.piece, game.rotation))
                    game.posX--;
                break;
            
            case SDLK_DOWN:
                if (board.isPossibleMovement(game.posX, game.posY + 1, game.piece, game.rotation))
                    game.posY++;
                break;
            
            case SDLK_x:
                while (board.isPossibleMovement(game.posX, game.posY, game.piece, game.rotation)) 
                    game.posY++;
 
                board.storePiece (game.posX, game.posY - 1, game.piece, game.rotation);
                board.deletePossibleLines();
                if (board.isGameOver())
                {
                    io.getkey();
                    exit(0);
                }
                game.createNewPiece();
                break;
            
            case SDLK_z:
                if (board.isPossibleMovement(game.posX, game.posY, game.piece, (game.rotation + 1) % 4))
                    game.rotation = (game.rotation + 1) % 4;
                break;

            default:
                break;
        }

        unsigned long time2 = SDL_GetTicks();

        if((time2 - time) > WAIT_TIME)
        {
            if(board.isPossibleMovement(game.posX, game.posY + 1, game.piece, game.rotation))
                game.posY++;
            else {
                board.storePiece(game.posX, game.posY, game.piece, game.rotation);
                board.deletePossibleLines();

                if(board.isGameOver())
                {
                    io.getkey();
                    exit(0);
                }

                game.createNewPiece();
            }

            time = SDL_GetTicks();
        }
    }

    return 0;
}