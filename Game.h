#pragma once
#include <iostream>
#include <vector>
#include <string>
#include <memory>
#include "Point.h"
#include "Board.h"
#include "GameObject.h"
#include "FastEnemy.h"
#include "StandardEnemy.h"
#include "Hero.h"
#include "WizardHero.h"
#include "Enemy.h"
#include "KnightHero.h"
#include "EnemyFactory.h"
#include "HeroFactory.h"

class Game {
private:
	Board board;
	std::unique_ptr<Hero> hero;
	std::vector<std::unique_ptr<Enemy>> enemies;
	std::vector<Point> highlightedRange;
	Point startHeroPos = { 0, 0 };
	bool gameRunning;

	void setupLevel(const std::string& filename);
	void chooseHero();
	bool handlePlayerInput();
	bool checkGameOverConditions();
	void printMap();
public:
	Game();
	void run();

};