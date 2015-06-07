
#ifndef __TTS_HPP__
#define __TTS_HPP__

#include <festival/festival.h>

#define TTS_HEAP_SIZE 210000

namespace TTS {

void init();
void say(const char* text);

} // end namespace TTS

#endif

