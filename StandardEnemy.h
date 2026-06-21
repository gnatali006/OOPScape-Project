#pragma once
#include "Enemy.h"
class StandardEnemy : public Enemy {
public:
	StandardEnemy(const Point& p);
	char getSymbol() const override;
	void updateMovement(const Point& heroPos, const Board& board) override;
};