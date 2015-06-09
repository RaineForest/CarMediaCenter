
#ifndef __BUTTON_HPP__
#define __BUTTON_HPP__

#include "UI.hpp"
#include <functional>

namespace UI {

using BtnDrawFunc = std::function<void()>;
using BtnUpdateFunc = std::function<void(float)>;
using BtnActionFunc = std::function<void(Event e)>;

class Button : public Component, public Actionable {
	public:
		Button();
		~Button();

		void Draw();
		void Update(float dt);
		void Action();

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
// Factories
/////////////////////////////////////////

BtnDrawFunc btnColor(float r, float g, float b, float a = 1.0);
BtnDrawFunc btnCenterText(char* str);

}

#endif //__BUTTON_HPP__

