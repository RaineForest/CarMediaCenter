
#include "tts.hpp"

int main(int argc, char** argv) {
	TTS::init();
	TTS::say("this is a test");
	return 0;
}
