
#include "UI.hpp"

#define HIT_TEST_PAD 0.1

namespace UI {

bool intersect(UI_Vector2_t v1, UI_Vector2_t v2){
	float dy1 = v1.head.y - v1.tail.y;
	float dx1 = v1.tail.x - v1.head.x;
	float det = v1.tail.x * v1.head.y - v1.head.x * v1.tail.y;

	float a = dy1 * v2.tail.x + dx1 * v2.tail.y - det;
	float b = dy1 * v2.head.x + dx1 * v2.head.y - det;
	
	if(a > 0 && b > 0) {
		return false;
	}
	if(a < 0 && b < 0) {
		return false;
	}

	float dy2 = v2.head.y - v2.tail.y;
	float dx2 = v2.tail.x - v2.head.x;
	det = v2.tail.x * v2.head.y - v2.head.x * v2.tail.y;

	a = dy2 * v1.tail.x + dx2 * v1.tail.y - det;
	b = dy2 * v1.head.x + dx2 * v1.head.y - det;
	
	if(a > 0 && b > 0) {
		return false;
	}
	if(a < 0 && b < 0) {
		return false;
	}

	if((dy1 * dx2 - dy2 * dx1) == 0.0f) {
		return false;
	}

	return true;
}

bool hitTest(UI_Point2_t* shape, int numPoints, UI_Point2_t off, UI_Point2_t p) {
	if(numPoints < 3) {
		//GTFO
		return false;
	}
	
	//begin bounding box shortcut
	float minX = shape[0].x, minY = shape[0].y, maxX = shape[0].x, maxY = shape[0].y;
	for(int i = 1; i < numPoints; i++) {
		if(shape[i].x < minX) {
			minX = shape[i].x;
		}
		if(shape[i].x < maxX) {
			maxX = shape[i].x;
		}
		if(shape[i].y < minY) {
			minY = shape[i].y;
		}
		if(shape[i].y < maxY) {
			maxY = shape[i].y;
		}
	}
	//if not in bounding box
	if(p.x - off.x < minX || p.x - off.x > maxX 
	|| p.y - off.y < minY || p.y - off.y > maxY) {
		return false;
	}
	//end bounding box shortcut

	//begin ray casting
	int intersects = 0;
	UI_Vector2_t ray;
	ray.head.x = p.x - off.x;
	ray.head.y = p.y - off.y;
	ray.tail.x = minX - HIT_TEST_PAD;
	ray.tail.y = p.y - off.y;
	UI_Vector2_t side;
	side.tail = shape[0];
	side.head = shape[1];
	for(int i = 0; i < numPoints; i++) {
		if(intersect(ray, side)) {
			intersects++;
		}
		side.tail = side.head;
		side.head = shape[(i+2)%numPoints];
	}

	if(intersects % 2 == 0) {
		return false;
	}
	//end ray casting
	return true;
}

}

