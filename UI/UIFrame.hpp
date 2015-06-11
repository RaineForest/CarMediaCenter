
#ifndef __UIFRAME_HPP__
#define __UIFRAME_HPP__

#include "UIHierarchy.hpp"

namespace UI {

class UIFrame : protected Container {
	public:
		UIFrame(int argc, char** argv);
};

}

#endif //__UIFRAME_HPP__
