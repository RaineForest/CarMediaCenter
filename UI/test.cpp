
#include "UI.hpp"

using namespace UI;

int main(int argc, char** argv) {
	UIFrame frame = UIFrame();

	Button red = Button();
	red.setShape(6, 0.0f, 0.25f);
	red.setDraw(btnColor(1.0f, 0.0f, 0.0f));
	red.setLocation(.425f, 0.25f);
	frame.add(&red);

	Button green = Button();
	green.setShape(6, 0.0f, 0.25f);
	green.setDraw(btnColor(0.0f, 1.0f, 0.0f));
	green.setLocation(0.0f, 0.0f);
	frame.add(&green);

	Button blue = Button();
	blue.setShape(6, 0.0f, 0.25f);
	blue.setDraw(btnColor(0.0f, 0.0f, 1.0f));
	blue.setLocation(0.0f, 0.5f);
	frame.add(&blue);
	
	frame.show(argc, argv, 640, 480, "CarMediaCenter");
	
	return 0;
}

