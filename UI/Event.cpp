
#include "Event.hpp"

namespace UI {

Event::Event(int x, int y) {
	this->x = x;
	this->y = y;
}

KeyboardEvent::KeyboardEvent(unsigned char keycode, int x, int y) 
		: Event(x, y) {
	this->keycode = keycode;
}

MouseEvent::MouseEvent(int button, int state, int x, int y) 
		: Event(x, y) {
	this->button = button;
	this->state = state;
}

EventDispatcher::EventDispatcher() {
	edt = std::thread(processEvents, this);
}

void EventDispatcher::addKeyboardEvent(unsigned char keycode, int x, int y) {
	queueLock.lock();
	eventQ.push(new KeyboardEvent(keycode, x, y));
	empty.notify_all();
	queueLock.unlock();
}

void EventDispatcher::addMouseEvent(int button, int state, int x, int y) {
	queueLock.lock();
	eventQ.push(new MouseEvent(button, state, x, y));
	empty.notify_all();
	queueLock.unlock();
}

Event* EventDispatcher::getNextEvent() {
	Event* e = eventQ.front();
	eventQ.pop();
	return e;
}

void EventDispatcher::processEvents(EventDispatcher* ed) {
	while(true) {
		if(ed->eventQ.size() == 0) {
			ed->empty.wait(ed->emptyLock);
		}

		Event* e = ed->getNextEvent();
		//TODO: do something, i didn't think beyond this point yet
	}
}

}

