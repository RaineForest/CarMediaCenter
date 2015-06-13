
#ifndef __UIFRAME_HPP__
#define __UIFRAME_HPP__

#include "UIHierarchy.hpp"

namespace UI {

class UIFrame : protected Container {
	public:
		UIFrame(int argc, char** argv);

	private:
		static UIFrame* thisInstance;

		static void drawCallback();
		static void reshapeCallback(GLint width, GLint height);
};

}

#endif //__UIFRAME_HPP__
