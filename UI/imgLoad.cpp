
#include "imgLoad.h"

GLuint loadPNGTexture(const char* filename, int* width, int* height) {
	png_byte header[8];

	FILE* file = fopen(filename, "rb");
	if(!file) {
		return 0;
	}

	fread(header, 1, 8, file);

	if(png_sig_cmp(header, 0, 8)) {
		fclose(file);
		return 0;
	}

	png_structp png_ptr = png_create_read_struct(PNG_LIBPNG_VER_STRING, 
						     NULL, 
						     NULL, 
						     NULL);
	if(!png_ptr) {
		fclose(file);
		return 0;
	}
}
