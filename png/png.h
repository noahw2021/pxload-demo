//
//  png.h
//  pxload-demo
//
//  Created by Noah Wooten on 12/21/23.
//

#ifndef png_h
#define png_h

void PngInit(void);
void PngShutdown(void);

typedef struct _PNG_IMAGE {
    unsigned long Reserved;
}PNG_IMAGE, *PPNG_IMAGE;

typedef struct _PNG_CTX {
    unsigned long Reserved;
}PNG_CTX, *PPNG_CTX;

unsigned long PngLoad(const char* File);
void* PngGetPixels(unsigned long ImageHandle);
unsigned long PngGetWidth(unsigned long ImageHandle);
unsigned long PngGetHeight(unsigned long ImageHandle);

unsigned long PngCreate(const char* Name, void* Pixels,
    unsigned long w, unsigned long h);

void PngDestroy(unsigned long ImageHandle);

#endif /* png_h */
