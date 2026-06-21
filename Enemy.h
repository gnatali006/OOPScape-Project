#pragma once
#include "GameObject.h"
class Enemy : public GameObject {
protected:
	bool tryMoveTowardsHeroBFS(Point& enemyPos, const Point& heroPos, const Board& board);
public:
	Enemy(const Point& p);
	virtual char getSymbol() const = 0;
	virtual void updateMovement(const Point& heroPos, const Board& board) = 0;
};