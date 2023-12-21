//
//  png_load.c
//  pxload-demo
//
//  Created by Noah Wooten on 12/21/23.
//

#include "png.h"
#include <stdio.h>

unsigned long PngLoad(const char* File) {
    if (!File)
        return 0xFFFFFFFF;
    
    FILE* PngFile = fopen(File, "rb");
    if (!PngFile)
        return 0xFFFFFFFF;
    
    
}

void* PngGetPixels(unsigned long ImageHandle) {
    
}

int PngGetWidth(unsigned long ImageHandle) {
    
}

int PngGetHeight(unsigned long ImageHandle) {
    
}
