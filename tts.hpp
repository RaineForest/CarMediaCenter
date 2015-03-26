
#include "festival.h"

class TTS {
private:
	const static int heap_size = 2100000;

public:
	static void init() {
		festival_initialize(1, TTS::heap_size);
		//for alsa
		festival_eval_command("(Parameter.set 'Audio_Method 'Audio_Command)");
		festival_eval_command("(Parameter.set 'Audio_Command \"aplay -q -c 1 -t raw -f s16 -r $SR $FILE\")");
		//end for alsa
	}

	static void say(const char* text) {
		festival_say_text(EST_String(text));
	}
};
