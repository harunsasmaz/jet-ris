#ifndef _IO_
#define _IO_

#include "SDL/include/SDL.h"                            
#include "SDL/SDL_GfxPrimitives/sdl_gfxprimitives.h"

#pragma comment (lib, "SDL/lib/SDL.lib")
#pragma comment (lib, "SDL/SDL_GfxPrimitives/SDL_GfxPrimitives_Static.lib")

enum Color {BLACK, RED, GREEN, BLUE, CYAN, MAGENTA, YELLOW, WHITE, COLOR_MAX}; // Colors

class IO
{
    public:
        IO                      ();
        void drawRectangle      (int pX1, int pY1, int pX2, int pY2, enum Color pC);
        void clearScreen        ();
        int getScreenHeight     ();
        int initGraph           ();
        int pollkey             ();
        int getkey              ();
        int isKeyDown           (int pKey);
        void updateScreen       ();
};

#endif