
#ifndef __EVENT_HPP__
#define __EVENT_HPP__

namespace UI {

class Event {
	protected:
		int x;
		int y;
};

class KeyboardEvent : protected Event {
	public:
		KeyboardEvent();

	protected:
		unsigned char keycode;
};

class MouseEvent : protected Event {

};

}

#endif

