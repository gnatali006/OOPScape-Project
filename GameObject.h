#pragma once
#include "Point.h"
#include "Board.h"

class GameObject {
protected:
	Point pos;
public:
	GameObject(const Point& p);
	virtual ~GameObject() = default;

	Point getPos() const;
	void setPos(const Point& p);
};
