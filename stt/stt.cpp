
#include "stt.hpp"

#define SAMP_PER_SEC 44100
#define SAMP_FORMAT PA_SAMPLE_S16LE //signed 16 bit
#define SAMP_CHANNELS 2

namespace STT {

CaptureDevice::CaptureDevice() {
	pa_sample_spec ss;
	ss.format = SAMP_FORMAT;
	ss.channels = SAMP_CHANNELS;
	ss.rate = SAMP_PER_SEC;

	s = pa_simple_new(NULL,
			  "Car Console",
			  PA_STREAM_RECORD,
			  NULL,
			  "Microphone Command Input",
			  &ss,
			  NULL,
			  NULL,
			  NULL);

}

CaptureDevice::~CaptureDevice() {
	pa_simple_free(s);
}

}

