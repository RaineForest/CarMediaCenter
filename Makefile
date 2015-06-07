
.PHONY : default tts stt clean UI

default: tts stt UI

tts:
	cd tts/ && $(MAKE)

stt:
	cd stt/ && $(MAKE)

UI:
	cd UI/ && $(MAKE)

clean:
	-cd tts/ && $(MAKE) clean
	-cd stt/ && $(MAKE) clean
	-cd UI/ && $(MAKE) clean
