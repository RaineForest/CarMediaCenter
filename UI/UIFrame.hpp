
#ifndef __UIFRAME_HPP__
#define __UIFRAME_HPP__

#include "UIHierarchy.hpp"

namespace UI {

class UIFrame : public Container {
	public:
		UIFrame();

		void show(int argc, char** argv, int width, int height, const char* title);

	private:
};

}

#endif //__UIFRAME_HPP__
