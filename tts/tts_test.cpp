
#include "tts.hpp"
#include <iostream>

using namespace TTS;

int main(int argc, char** argv) {
	cout << "starting" << endl;
	init();
	cout << "initialized" << endl;
	say("this is a test");
	cout << "done" << endl;
	return 0;
}
