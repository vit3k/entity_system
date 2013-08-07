#pragma once
#include <list>
#include <memory>
#include "../Application/Clock.h"
#include "SFML/Graphics.hpp"

class Control;

typedef int ControlId;
typedef std::shared_ptr<Control> ControlStrongPtr;
typedef std::list<ControlStrongPtr> ChildrenList;

class Control
{
private:
	ControlId id;
	ChildrenList children;
	bool visible;
	int width;
	int height;
	int x;
	int y;
public:
	Control():x(0),y(0),width(800),height(600) {};
	bool Visible() { return visible; };
	ControlId Id() { return id; };
	int Width() { return width; };
	void Width(int value) { width = value; };
	int Height() { return height; };
	void Height(int value) { height = value; };
	int X() { return x; };
	void X(int value) { x = value; };
	int Y() { return y; };
	void Y(int value) { y = value; };
	virtual void Init() {};
	virtual void Render(Time delta,sf::RenderTarget* target) {};
};

