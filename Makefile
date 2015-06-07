
.PHONY : default tts clean

default: tts

tts:
	cd tts/ && $(MAKE)

clean:
	cd tts/ && $(MAKE) clean
