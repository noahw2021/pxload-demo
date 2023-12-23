//
//  png_load.c
//  pxload-demo
//
//  Created by Noah Wooten on 12/21/23.
//

#include "png.h"
#include <stdio.h>

unsigned long PngLoad(const char* File) {
    if (!PngCtx)
        return 0xFFFFFFFF;
    
    if (!File)
        return 0xFFFFFFFF;
    
    FILE* PngFile = fopen(File, "rb");
    if (!PngFile)
        return 0xFFFFFFFF;
    
    fseek(PngFile, 0, SEEK_END);
    unsigned long FileLength = ftell(PngFile);
    fseek(PngFile, 0, SEEK_SET);
    
    if (FileLength > PngCtx->BufferSize) {
        free(PngCtx->Buffer);
        PngCtx->Buffer = malloc(FileLength + 1024);
    }
    
    fread(PngCtx->Buffer, FileLength, 1, PngFile);
    spng_set_png_buffer(PngCtx->SpngCtx, PngCtx->Buffer, FileLength);
    
    if (PngCtx->Images) {
        PngCtx->Images = realloc(PngCtx->Images,
            sizeof(PNG_IMAGE) * (PngCtx->ImageCount + 1));
    } else {
        PngCtx->Images = malloc(sizeof(PNG_IMAGE));
    }
    
    PPNG_IMAGE ThisImage = &PngCtx->Images[PngCtx->ImageCount];
    PngCtx->ImageCount++;
    
    unsigned long ImageSize;
    spng_decoded_image_size(PngCtx->SpngCtx, SPNG_FMT_RGBA8, &ImageSize);
    
    ThisImage->File = PngFile;
    ThisImage->Buffer = malloc(ImageSize);
    spng_decode_image(PngCtx->SpngCtx, ThisImage->Buffer, ImageSize, SPNG_FMT_RGBA8, 0);
    struct spng_ihdr IHDR;
    spng_get_ihdr(PngCtx->SpngCtx, &IHDR);
    ThisImage->w = IHDR.width;
    ThisImage->h = IHDR.height;
    
    return (PngCtx->ImageCount - 1);
}

void* PngGetPixels(unsigned long ImageHandle) {
    if (!PngCtx)
        return NULL;
    
    if (ImageHandle >= PngCtx->ImageCount)
        return NULL;
    
    PPNG_IMAGE ThisImage = &PngCtx->Images[ImageHandle];
    return ThisImage->Buffer;
}

int PngGetWidth(unsigned long ImageHandle) {
    if (!PngCtx)
        return -1;
    
    if (ImageHandle >= PngCtx->ImageCount)
        return -1;
    
    PPNG_IMAGE ThisImage = &PngCtx->Images[ImageHandle];
    return (int)ThisImage->w;
}

int PngGetHeight(unsigned long ImageHandle) {
    if (!PngCtx)
        return -1;
    
    if (ImageHandle >= PngCtx->ImageCount)
        return -1;
    
    PPNG_IMAGE ThisImage = &PngCtx->Images[ImageHandle];
    return (int)ThisImage->h;
}

void PngDestroy(unsigned long ImageHandle) {
    if (!PngCtx)
        return;
    
    if (ImageHandle >= PngCtx->ImageCount)
        return;
    
    PPNG_IMAGE ThisImage = &PngCtx->Images[ImageHandle];
    
    if (ThisImage->File) {
        fclose(ThisImage->File);
        ThisImage->File = NULL;
    }
    
    if (ThisImage->Buffer) {
        free(ThisImage->Buffer);
        ThisImage->Buffer = NULL;
    }
    
    return;
}
