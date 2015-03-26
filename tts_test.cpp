
#include "tts.hpp"
#include <iostream>

int main(int argc, char** argv) {
	cout << "starting" << endl;
	TTS::init();
	cout << "initialized" << endl;
	TTS::say("this is a test");
	cout << "done" << endl;
	return 0;
}
