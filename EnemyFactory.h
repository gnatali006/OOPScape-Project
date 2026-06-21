#pragma once
#include "Enemy.h"
#include "StandardEnemy.h"
#include "FastEnemy.h"
class EnemyFactory {
public:
	static std::unique_ptr<Enemy> createEnemy(char symbol, const Point& pos);
};