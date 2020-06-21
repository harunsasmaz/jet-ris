#include "game.h"

int _main()
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
                /* code */
                break;

            case SDLK_LEFT:
                /* code */
                break;
            
            case SDLK_DOWN:
                /* code */
                break;
            
            case SDLK_x:
                /* code */
                break;
            
            case SDLK_z:
                /* code */
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