#include "Board.h"
#include <stdexcept>
#include <fstream>
#include <iostream>

Board::Board() : size(0)
{
}

bool Board::isWalkable(int x, int y) const
{
	if (x < 0 || x >= size || y < 0 || y >= size) return false;
	return grid[y][x] != '*';
}

int Board::getSize() const
{
	return size;
}

char Board::getCell(int x, int y) const
{
	if (x < 0 || x >= size || y < 0 || y >= size) return '*';
	return grid[y][x];
}

void Board::clearCell(int x, int y)
{
	if (x >= 0 && x < size && y >= 0 && y < size) {
		grid[y][x] = ' ';
	}
}


void Board::loadLevel(const std::string& filename)
{
    std::ifstream file(filename);
    if (!file.is_open()) {
        throw std::runtime_error("File could not be opened!");
    }

    int n;
    if (!(file >> n)) {
        throw std::invalid_argument("Failed to read size n.");
    }
    if (n < MIN_SIZE || n > MAX_SIZE) {
        throw std::out_of_range("Size n must be between 2 and 64.");
    }

    size = n;
    grid = std::vector<std::vector<char>>(size, std::vector<char>(size));
    file.ignore();

    for (int y = 0; y < size; y++) {
        std::string line;
        if (!std::getline(file, line)) {
            throw std::runtime_error("File contains fewer rows than expected.");
        }
        if (line.length() < static_cast<size_t>(size)) {
            throw std::runtime_error("Row has fewer characters than expected.");
        }

        for (int x = 0; x < size; x++) {
            char ch = line[x];
            if (ch != '*' && ch != ' ' && ch != 'S' && ch != 'F' && ch != 'E' && ch != 'X') {
                throw std::invalid_argument("Invalid character detected.");
            }
            grid[y][x] = ch;
        }
    }
}