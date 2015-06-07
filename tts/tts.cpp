
#include "tts.hpp"

namespace TTS {

void init() {
	festival_initialize(1, TTS_HEAP_SIZE);
	festival_eval_command("(Parameter.set 'Audio_Method 'Audio_Command)");
	festival_eval_command("(Parameter.set 'Audio_Command \"paplay $FILE --client-name=Festival --stream-name=Speech\")");
}

void say(const char* text) {
	festival_say_text(EST_String(text));
}

} // end namespace TTS

