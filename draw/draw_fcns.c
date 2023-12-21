//
//  draw_fcns.c
//  pxload-demo
//
//  Created by Noah Wooten on 12/20/23.
//

#include "draw.h"

#define R(x) (x & 0xFF000000) >> 24
#define G(x) (x & 0x00FF0000) >> 16
#define B(x) (x & 0x0000FF00) >> 8

void DrawRectangle(int x, int y, int w, int h, unsigned long Color) {
    SDL_Rect Rectangle;
    Rectangle.x = x;
    Rectangle.y = y;
    Rectangle.w = w;
    Rectangle.h = h;
    SDL_SetRenderDrawColor(DrawCtx->Renderer, R(Color), G(Color), B(Color), 255);
    SDL_RenderFillRect(DrawCtx->Renderer, &Rectangle);
    return;
}

void DrawOutline(int x, int y, int w, int h, unsigned long Color) {
    SDL_Rect Rectangle;
    Rectangle.x = x;
    Rectangle.y = y;
    Rectangle.w = w;
    Rectangle.h = h;
    SDL_SetRenderDrawColor(DrawCtx->Renderer, R(Color), G(Color), B(Color), 255);
    SDL_RenderDrawRect(DrawCtx->Renderer, &Rectangle);
    return;
}

void DrawText(int x, int y, const char* Text, unsigned long Color) {
    SDL_Color Color2;
    Color2.r = R(Color);
    Color2.g = G(Color);
    Color2.b = B(Color);
    Color2.a = 255;
    
    SDL_Surface* TextSurface = TTF_RenderText_Blended(DrawCtx->Font, Text, Color2);
    SDL_Texture* Txt = SDL_CreateTextureFromSurface(DrawCtx->Renderer, TextSurface);
    
    SDL_Rect Rectangle;
    Rectangle.x = x;
    Rectangle.y = y;
    Rectangle.w = TextSurface->w;
    Rectangle.h = TextSurface->h;
    SDL_FreeSurface(TextSurface);
    
    SDL_RenderCopy(DrawCtx->Renderer, Txt, NULL, &Rectangle);
    SDL_DestroyTexture(Txt);
    return;
}

void DrawPixels(int x, int y, int w, int h, void* Pixels) {
    SDL_Surface* Surface = SDL_CreateRGBSurfaceWithFormatFrom(Pixels,
        w, h, 32, 32, SDL_PIXELFORMAT_RGBA8888);
    SDL_Texture* Txt = SDL_CreateTextureFromSurface(DrawCtx->Renderer, Surface);
    SDL_Rect Rectangle;
    Rectangle.x = x;
    Rectangle.y = y;
    Rectangle.w = w;
    Rectangle.h = h;
    SDL_FreeSurface(Surface);
    
    SDL_RenderCopy(DrawCtx->Renderer, Txt, NULL, &Rectangle);
    SDL_DestroyTexture(Txt);
    return;
}
