//
//  draw_init.c
//  pxload-demo
//
//  Created by Noah Wooten on 12/13/23.
//

#include "draw.h"
#include <stdlib.h>
#include <string.h>

PDRAW_CTX DrawCtx;

void DrawInit(const char* Name, int w, int h) {
    DrawCtx = malloc(sizeof(DRAW_CTX));
    memset(DrawCtx, 0, sizeof(DRAW_CTX));
    
    SDL_Init(SDL_INIT_VIDEO);
    TTF_Init();
    
    DrawCtx->Window = SDL_CreateWindow(Name, SDL_WINDOWPOS_CENTERED,
        SDL_WINDOWPOS_CENTERED, w, h, 0);
    DrawCtx->Renderer = SDL_CreateRenderer(DrawCtx->Window, -1, SDL_RENDERER_SOFTWARE);
    DrawCtx->Font = TTF_OpenFont("/Library/Fonts/Arial.ttf", 12);
    
    return;
}

void DrawShutdown(void) {
    if (!DrawCtx)
        return;
    
    TTF_CloseFont(DrawCtx->Font);
    SDL_DestroyRenderer(DrawCtx->Renderer);
    SDL_DestroyWindow(DrawCtx->Window);
    free(DrawCtx);
    return;
}
