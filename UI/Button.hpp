
#ifndef __BUTTON_HPP__
#define __BUTTON_HPP__

#include "UIHierarchy.hpp"
#include <functional>

namespace UI {

using BtnDrawFunc = std::function<void()>;
using BtnUpdateFunc = std::function<void(float)>;
using BtnActionFunc = std::function<void(Event e)>;

class Button : public Component, public Actionable, public Polygonal {
	public:
		Button();
		Button(const Button& c) = default;
		~Button();

		void Draw();
		void Update(float dt);
		void Action(Event e);

		void setDraw(BtnDrawFunc func);
		void setUpdate(BtnUpdateFunc func);
		void setAction(BtnActionFunc func);

	private:
		BtnDrawFunc draw;
		BtnUpdateFunc update;
		BtnActionFunc action;
};


/////////////////////////////////////////
// Factories
/////////////////////////////////////////

BtnDrawFunc btnColor(float r, float g, float b, float a = 1.0f);
BtnDrawFunc btnCenterText(char* str);

}

#endif //__BUTTON_HPP__

