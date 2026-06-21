#pragma once
#include "Enemy.h"
class FastEnemy : public Enemy {
public:
	FastEnemy(const Point& p);
	char getSymbol() const override;
	void updateMovement(const Point& heroPos, const Board& board) override;
};