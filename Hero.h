#pragma once
#include "GameObject.h"
#include "Enemy.h"
class Hero : public GameObject {
public:
	Hero(const Point& p);
	void move(int dx, int dy, const Board& board);
	virtual void useAbility(const Board& board, std::vector<std::unique_ptr<Enemy>>& enemies, std::vector<Point>& highlightedRange) = 0;
	
};