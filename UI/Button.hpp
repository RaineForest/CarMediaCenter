
#ifndef __BUTTON_HPP__
#define __BUTTON_HPP__

#include "UI.hpp"
#include <functional>

namespace UI {

class Button;

using BtnDrawFunc = std::function<void()>;
using BtnUpdateFunc = std::function<void(float)>;
using BtnActionFunc = std::function<void()>;

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

		void setDraw(BtnDrawFunc func);
		void setUpdate(BtnUpdateFunc func);
		void setAction(BtnActionFunc func);

	private:
		BtnDrawFunc draw;
		BtnUpdateFunc update;
		BtnActionFunc action;

		UI_Point2_t* shape;
		int sides;
		UI_Point2_t location;
};


/////////////////////////////////////////
// Predefined styles
/////////////////////////////////////////

BtnDrawFunc btnSolidColor(float r, float g, float b);

}

#endif //__BUTTON_HPP__

