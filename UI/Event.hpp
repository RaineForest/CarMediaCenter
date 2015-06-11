
#ifndef __EVENT_HPP__
#define __EVENT_HPP__

#include <queue>
#include <mutex>
#include <thread>
#include <condition_variable>

namespace UI {

class Event {
	public:
		Event(int x, int y);

	protected:
		int x;
		int y;
};

class KeyboardEvent : public Event {
	public:
		KeyboardEvent(unsigned char keycode, int x, int y);

	protected:
		unsigned char keycode;
};

class MouseEvent : public Event {
	public:
		MouseEvent(int button, int state, int x, int y);

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
		Event* getNextEvent();
		static void processEvents(EventDispatcher* ed);

		std::queue<Event*> eventQ;
		std::thread edt;
		std::unique_lock<std::mutex> queueLock;
		std::unique_lock<std::mutex> emptyLock;
		std::condition_variable empty;
};

}

#endif

