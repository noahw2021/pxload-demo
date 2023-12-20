//
//  main.c
//  pxload-demo
//
//  Created by Noah Wooten on 12/13/23.
//

#include <SDL.h>
#include <SDL_ttf.h>

int main(int argc, char** argv) {
    SDL_Init(SDL_INIT_VIDEO);
    TTF_Init();
    
    SDL_Window* Window = SDL_CreateWindow("PXLoad Demonstration", 10, 10, 640, 480, 0);
    SDL_Renderer* Renderer = SDL_CreateRenderer(Window, -1, SDL_RENDERER_ACCELERATED);
    TTF_Font* Font = TTF_OpenFont("/Library/Fonts/Arial.ttf", 12);
    
    SDL_Event Event;
    while (1) {
        int WantsQuit = 0;
        while (SDL_PollEvent(&Event) && !WantsQuit) {
            if (Event.type == SDL_QUIT)
                WantsQuit = 1;
        }
        
        if (WantsQuit)
            break;
        
        
        
        SDL_RenderPresent(Renderer);
    }
    return 0;
}
