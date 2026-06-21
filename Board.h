#pragma once
#include <vector>
#include <string>
#include "Point.h"
#include <memory>
class Board {
	std::vector<std::vector<char>> grid;
	int size;
	const int MIN_SIZE = 2;
	const int MAX_SIZE = 64;
public:
	Board();

	bool isWalkable(int x, int y) const;
	int getSize() const;
	char getCell(int x, int y) const;
	void clearCell(int x, int y);
	
	void loadLevel(const std::string& filename);
};