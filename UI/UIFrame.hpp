
#ifndef __UIFRAME_HPP__
#define __UIFRAME_HPP__

#include <GL/freeglut.h>
#include "UIUtil.hpp"
#include <queue>
#include <thread>

namespace UI {

class UIFrame {
	public:
		UIFrame();
		~UIFrame();

		show();
		
		add

	private:
		queue<Event> eventQ;
};

}

#endif //__UIFRAME_HPP__
