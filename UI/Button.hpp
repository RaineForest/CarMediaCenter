
#ifndef __BUTTON_HPP__
#define __BUTTON_HPP__

#include "UI.hpp"

namespace UI {

class Button {
	public:
		Button();
		~Button();

		void Draw();
		void Update(float dt);
		void Action();

		UI_Point2_t getLocation();
		void setLocation(GLfloat x, GLfloat y);
		void setLocation(UI_Point2_t* loc);

		void setShape(GLfloat* xvals, GLfloat* yvals, int size);
		void setShape(UI_Point2_t* points, int size);
		void setShape(int ngon, float rot, float rad);

		void setDraw(void (*func)(void));
		void setUpdate(void (*func)(float));
		void setAction(void (*func)(void));

	private:
		void (*draw)(void);
		void (*update)(float);
		void (*action)(void);

		UI_Point2_t* shape;
		int sides;
		UI_Point2_t location;
};

}

#endif //__BUTTON_HPP__

