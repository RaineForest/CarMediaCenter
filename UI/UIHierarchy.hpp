
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
		Placeable();

		UI_Point2_t getLocation();
		void setLocation(GLfloat x, GLfloat y);
		void setLocation(UI_Point2_t* loc);
	
	protected:
		UI_Point2_t location;
};

class Sizeable {
	public:
		Sizeable();

		UI_Point2_t getSize();
		void setSize(float x, float y);

	protected:
		UI_Point2_t scale;
};

class Polygonal : public Sizeable {
	public:
		Polygonal();
		~Polygonal();

		UI_Point2_t* getShape();
		int getNumSides();
		void setShape(GLfloat* xvals, GLfloat* yvals, int n);
		void setShape(UI_Point2_t* points, int n);
		void setShape(int ngon, float rot, float rad);

	protected:
		UI_Point2_t* shape;
		int sides;
};

class Actionable {
	public:
		virtual void Action(Event e) = 0;
};

class Component : public Drawable, public Placeable, public Sizeable {
	public:
		Component() {};
		Component(const Component& c) = default;
};

class Container : public Drawable, public Placeable {
	public:
		virtual void Draw();
		virtual void Update(float dt);

		void add(Component* c);
		Component* remove(Component* c);
		Component* remove(int index);
		std::vector<Component*> removeAll();

	protected:
		std::vector<Component*> components;
};

class ContainerComponent : public Component, public Container {};

}

#endif

