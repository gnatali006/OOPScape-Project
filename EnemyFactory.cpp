#include "EnemyFactory.h"

std::unique_ptr<Enemy> EnemyFactory::createEnemy(char symbol, const Point& pos)
{
    if (symbol == 'E') return std::make_unique<StandardEnemy>(pos);
    if (symbol == 'X') return std::make_unique<FastEnemy>(pos);
    return nullptr;
}
