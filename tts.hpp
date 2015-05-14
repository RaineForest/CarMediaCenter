
#include "festival.h"

#define USE_PULSE

class TTS {
private:
	const static int heap_size = 2100000;

public:
	static void init() {
		festival_initialize(1, TTS::heap_size);
		festival_eval_command("(Parameter.set 'Audio_Method 'Audio_Command)");
#ifdef USE_PULSE
		festival_eval_command("(Parameter.set 'Audio_Command \"paplay $FILE --client-name=Festival --stream-name=Speech\")");
#elif USE_ALSA
		festival_eval_command("(Parameter.set 'Audio_Command \"aplay -q -c 1 -t raw -f s16 -r $SR $FILE\")");
#endif
	}

	static void say(const char* text) {
		festival_say_text(EST_String(text));
	}
};
