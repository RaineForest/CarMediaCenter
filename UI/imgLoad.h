
#ifdef __IMGLOAD_H__
#define __IMGLOAD_H__

#include <cstdio>
#include <GL/gl.h>
#include <GL/glu.h>
#include <png.h>

GLuint loadPNGTexture(const char* filename, int* width, int* height);

#endif //__IMGLOAD_H_

