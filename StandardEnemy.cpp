#include "StandardEnemy.h"

StandardEnemy::StandardEnemy(const Point& p) : Enemy(p)
{
}

char StandardEnemy::getSymbol() const
{
    return 'E';
}

void StandardEnemy::updateMovement(const Point& heroPos, const Board& board)
{
    tryMoveTowardsHeroBFS(pos, heroPos, board);
}
