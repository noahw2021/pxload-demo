//
//  draw.h
//  pxload-demo
//
//  Created by Noah Wooten on 12/13/23.
//

#ifndef draw_h
#define draw_h

#include <SDL.h>
#include <SDL_ttf.h>

typedef struct _DRAW_CTX {
    SDL_Window* Window;
    SDL_Renderer* Renderer;
    TTF_Font* Font;
    
    unsigned char WantsQuit;
    unsigned char InternalKeyMap[256];
    unsigned char MBStates[2];
    int MouseX, MouseY;
}DRAW_CTX, *PDRAW_CTX;
extern PDRAW_CTX DrawCtx;

void DrawInit(const char* Name, int w, int h);
void DrawShutdown(void);

void DrawBeginScene(void);
void DrawEndScene(void);
void DrawPresent(void);

void DrawRectangle(int x, int y, int w, int h, unsigned long Color);
void DrawOutline(int x, int y, int w, int h, unsigned long Color);
void DrawText(int x, int y, const char* Text, unsigned long Color);
void DrawPixels(int x, int y, int w, int h, void* Pixels);

#endif /* draw_h */
