//
//  png_init.c
//  pxload-demo
//
//  Created by Noah Wooten on 12/21/23.
//

#include "png.h"
PPNG_CTX PngCtx;

#include <stdlib.h>
#incldue <string.h>

void PngInit(void) {
    PngCtx = malloc(sizeof(PNG_CTX));
    memset(PngCtx, 0, sizeof(PNG_CTX));
    
    return;
}

void PngShutdown(void) {
    if (!PngCtx)
        return;
    
    free(PngCtx);
    return;
}
