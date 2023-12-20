//
//  draw_sdl.c
//  pxload-demo
//
//  Created by Noah Wooten on 12/13/23.
//

#include "draw.h"

void DrawBeginScene(void) {
    SDL_Event Event;
    while (SDL_PollEvent(&Event)) {
        if (Event.type == SDL_QUIT) {
            DrawCtx->WantsQuit = 1;
            break;
        }
        
        if (Event.type == SDL_KEYUP)
            DrawCtx->InternalKeyMap[Event.key.keysym.scancode] = 0;
        
        if (Event.type == SDL_KEYDOWN)
            DrawCtx->InternalKeyMap[Event.key.keysym.scancode] = 1;
        
        if (Event.type == SDL_MOUSEBUTTONUP) {
            DrawCtx->MBStates[Event.button.button == SDL_BUTTON_LEFT ? 0 : 1] = 0;
        }
        
        if (Event.type == SDL_MOUSEBUTTONDOWN) {
            DrawCtx->MBStates[Event.button.button == SDL_BUTTON_LEFT ? 0 : 1] = 1;
        }
        
        if (Event.type == SDL_MOUSEMOTION) {
            DrawCtx->MouseX = Event.motion.x;
            DrawCtx->MouseX = Event.motion.y;
        }
    }
}

void DrawEndScene(void) {
    return;
}

void DrawPresent(void) {
    SDL_RenderPresent(DrawCtx->Renderer);
}
