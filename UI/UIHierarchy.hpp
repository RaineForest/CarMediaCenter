
#ifndef __UIHIERARCHY_HPP__
#define __UIHIERARCHY_HPP__

#include <vector>
#include "Event.hpp"
#include "UIUtil.hpp"

namespace UI {

class Drawable {
	public:
		virtual void Draw() = 0;
		virtual void Update(float) = 0;
};

class Placeable {
	public:
		virtual UI_Point2_t getLocation();
		virtual void setLocation(GLfloat x, GLfloat y);
		virtual void setLocation(UI_Point2_t* loc);
	
	protected:
		UI_Point2_t location;
};

class Sizeable {
	public:
		virtual void setSize(float x, float y) = 0;
		
};

class Polygonal : Sizable {
	public:
		void setShape(GLfloat* xvals, GLfloat* yvals, int size);
		void setShape(UI_Point2_t* points, int size);
		void setShape(int ngon, float rot, float rad);
};

class Actionable {
	public:
		virtual void Action() = 0;
};

class Component : protected Drawable, protected Placeable, protected Sizeable {
	
};

class Container : protected Drawable, protected Placeable {
	public:
		void add(Component* c);

	protected:
		vector<Component*> components;
};

class ContainerComponent : protected Component, protected Container {};

}

#endif

