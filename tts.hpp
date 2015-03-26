
#include "festival.h"

class TTS {
private:
	const static int heap_size = 2100000;

public:
	static void init() {
		festival_initialize(1, TTS::heap_size);
	}

	static void say(const char* text) {
		festival_say_text(EST_String(text));
	}
};
