//
//  main.c
//  pxload-demo
//
//  Created by Noah Wooten on 12/13/23.
//

#include <SDL.h>
#include <SDL_ttf.h>
#include "draw/draw.h"

int main(int argc, char** argv) {
    SDL_Init(SDL_INIT_VIDEO);
    TTF_Init();
    
    DrawInit("PXLoad Demo", 640, 480);
    
    while (!DrawCtx->WantsQuit) {
        DrawBeginScene();
        DrawEndScene();
        DrawPresent();
    }
    
    return 0;
}
