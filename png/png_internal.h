//
//  png_internal.h
//  pxload-demo
//
//  Created by Noah Wooten on 12/21/23.
//

#ifndef png_internal_h
#define png_internal_h

typedef struct _IPNG_IHDR {
    unsigned long Width;
    unsigned long Height;
    unsigned char BitDepth;
    unsigned char ColorType;
    unsigned char InterlaceMethod;
}IPNG_IHDR, *PIPNG_IHDR;

#endif /* png_internal_h */
