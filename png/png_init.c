//
//  png_init.c
//  pxload-demo
//
//  Created by Noah Wooten on 12/21/23.
//

#include "png.h"
PPNG_CTX PngCtx;

#include <stdlib.h>
#include <string.h>

void PngInit(void) {
    PngCtx = malloc(sizeof(PNG_CTX));
    memset(PngCtx, 0, sizeof(PNG_CTX));
    
    PngCtx->SpngCtx = spng_ctx_new(0);
    PngCtx->BufferSize = (2 << 20);
    PngCtx->Buffer = malloc(PngCtx->BufferSize);
    
    return;
}

void PngShutdown(void) {
    if (!PngCtx)
        return;
    
    if (PngCtx->Buffer)
        free(PngCtx->Buffer);
    if (PngCtx->SpngCtx)
        spng_ctx_free(PngCtx->SpngCtx);
    
    for (int i = 0; i < PngCtx->ImageCount; i++) {
        PPNG_IMAGE ThisImage = &PngCtx->Images[i];
        
        if (ThisImage->File)
            fclose(ThisImage->File);
        if (ThisImage->Buffer)
            free(ThisImage->Buffer);
    }
    
    if (PngCtx->Images)
        free(PngCtx->Images);
    
    free(PngCtx);
    return;
}
