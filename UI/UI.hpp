
#ifndef __UI_HPP__
#define __UI_HPP__

#include <GL/gl.h>

namespace UI {

typedef struct UI_Point2 {
	float x;
	float y;
} UI_Point2_t;

typedef struct UI_Vector2 {
	UI_Point2_t tail; //src
	UI_Point2_t head; //dest
} UI_Vector2_t;

bool intersect(UI_Vector2_t v1, UI_Vector2_t v2);
bool hitTest(UI_Point2_t* shape, int numPoints, UI_Point2_t off, UI_Point2_t p);

}

#endif //__UI_HPP__

