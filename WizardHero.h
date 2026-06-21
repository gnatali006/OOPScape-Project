#pragma once
#include "Hero.h"
class WizardHero : public Hero {
public:
	WizardHero(const Point& p);
	void useAbility(const Board& board, std::vector<std::unique_ptr<Enemy>>& enemies, std::vector<Point>& highlightedRange) override;
};