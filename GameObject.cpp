#include "GameObject.h"

GameObject::GameObject(const Point& p) : pos(p)
{
}

Point GameObject::getPos() const
{
	return pos;
}

void GameObject::setPos(const Point& p)
{
	pos = p;
}
