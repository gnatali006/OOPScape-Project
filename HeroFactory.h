#pragma once
#include "Hero.h"
#include "KnightHero.h"
#include "WizardHero.h"
class HeroFactory {
public:
    static std::unique_ptr<Hero> createHero(int type, const Point& startPos);
};