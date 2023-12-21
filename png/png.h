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
    unsigned long ImageCount;
    PPNG_IMAGE Images;
}PNG_CTX, *PPNG_CTX;
extern PPNG_CTX PngCtx;

unsigned long PngLoad(const char* File);
void* PngGetPixels(unsigned long ImageHandle);
int PngGetWidth(unsigned long ImageHandle);
int PngGetHeight(unsigned long ImageHandle);

void PngDestroy(unsigned long ImageHandle);

#endif /* png_h */
