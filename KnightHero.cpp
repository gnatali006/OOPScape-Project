#include "KnightHero.h"
#include <iostream>
#include "Enemy.h"
KnightHero::KnightHero(const Point& p) : Hero(p)
{
}

void KnightHero::useAbility(const Board& board, std::vector<std::unique_ptr<Enemy>>& enemies, std::vector<Point>& highlightedRange)
{
    std::cout << "Knight strike!\n";
    bool hit = false;

    for (auto it = enemies.begin(); it != enemies.end(); ) {
        Point ePos = (*it)->getPos();
        if ((std::abs(pos.x - ePos.x) + std::abs(pos.y - ePos.y)) == 1) {
            std::cout << "Enemy at (" << ePos.x << ", " << ePos.y << ") was slain!\n";
            it = enemies.erase(it);
            hit = true;
        }
        else {
            ++it;
        }
    }
    if (!hit) std::cout << "No enemies nearby to attack.\n";
}

