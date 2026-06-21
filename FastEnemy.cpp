#include "FastEnemy.h"

FastEnemy::FastEnemy(const Point& p) : Enemy(p)
{
}

char FastEnemy::getSymbol() const
{
    return 'X';
}

void FastEnemy::updateMovement(const Point& heroPos, const Board& board)
{
    tryMoveTowardsHeroBFS(pos, heroPos, board);
    if (!(pos == heroPos)) {
        tryMoveTowardsHeroBFS(pos, heroPos, board);
    }
}
