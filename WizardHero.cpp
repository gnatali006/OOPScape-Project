#include "WizardHero.h"
#include <memory>
#include <iostream>
WizardHero::WizardHero(const Point& p) : Hero(p)
{
}

void WizardHero::useAbility(const Board& board, std::vector<std::unique_ptr<Enemy>>& enemies, std::vector<Point>& highlightedRange)
{
    highlightedRange.clear();
    int n = board.getSize();

    for (int y = 0; y < n; ++y) {
        for (int x = 0; x < n; ++x) {
            if ((std::abs(pos.x - x) + std::abs(pos.y - y)) <= 4 && board.isWalkable(x, y) && !(pos == Point{ x, y })) {
                highlightedRange.push_back(Point{ x, y });
            }
        }
    }
}
