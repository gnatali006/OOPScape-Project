#include "Hero.h"
#include <iostream>
Hero::Hero(const Point& p) : GameObject(p)
{
}

void Hero::move(int dx, int dy, const Board& board)
{
    int nextX = pos.x + dx;
    int nextY = pos.y + dy;
    if (board.isWalkable(nextX, nextY)) {
        pos.x = nextX;
        pos.y = nextY;
    }
    else {
        std::cout << "Wall hit! Movement blocked.\n";
    }
}


