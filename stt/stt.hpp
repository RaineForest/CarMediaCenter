
#ifndef __STT_HPP__
#define __STT_HPP__

#include <pulse/simple.h>

namespace STT {

class CaptureDevice {
	public:
		CaptureDevice();
		~CaptureDevice();

		
	private:
		pa_simple* s; //connection to pulse server
};

}

#endif

