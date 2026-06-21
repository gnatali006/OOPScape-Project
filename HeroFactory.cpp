#include "HeroFactory.h"

std::unique_ptr<Hero> HeroFactory::createHero(int type, const Point& startPos)
{
    if (type == 1) return std::make_unique<WizardHero>(startPos);
    if (type == 2) return std::make_unique<KnightHero>(startPos);
    return nullptr;
}
