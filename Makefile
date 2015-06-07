
.PHONY : default tts stt clean

default: tts stt

tts:
	cd tts/ && $(MAKE)

stt:
	cd stt/ && $(MAKE)

clean:
	cd tts/ && $(MAKE) clean
	cd stt/ && $(MAKE) clean
