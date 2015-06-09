
#ifndef __EVENT_HPP__
#define __EVENT_HPP__

#include <queue>
#include <thread>

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
	public:
		MouseEvent();

	protected:
		int button;
		int state;
};

class EventDispatcher {
	public:
		EventDispatcher();

		void addKeyboardEvent(unsigned char keycode, int x, int y);
		void addMouseEvent(int button, int state, int x, int y);

	private:
		queue<Event*> eventQ;
};

}

#endif

