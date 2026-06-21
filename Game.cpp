#include "Game.h"
Game::Game() : gameRunning(true) {}

void Game::setupLevel(const std::string& filename) {
    board.loadLevel(filename);
    int n = board.getSize();
    int sCount = 0, fCount = 0;

    for (int y = 0; y < n; ++y) {
        for (int x = 0; x < n; ++x) {
            char ch = board.getCell(x, y);
            if (ch == 'S') {
                sCount++;
                startHeroPos = { x, y };
                board.clearCell(x, y);
            }
            else if (ch == 'F') {
                fCount++;
            }
            else if (ch == 'E' || ch == 'X') {
                std::unique_ptr<Enemy> newEnemy = EnemyFactory::createEnemy(ch, Point{ x, y });
                enemies.push_back(std::move(newEnemy));
                board.clearCell(x, y);
            }
        }
    }

    if (sCount != 1) throw std::invalid_argument("Must contain exactly one 'S'!");
    if (fCount != 1) throw std::invalid_argument("Must contain exactly one 'F'!");
}

void Game::chooseHero() {
    int choice = 0;
    while (choice != 1 && choice != 2) {
        std::cout << "Choose your hero:\n1) Wizard (Teleport)\n2) Knight (Combat Strike)\nSelection: ";
        if (std::cin >> choice) {
            if (choice != 1 && choice != 2) {
                std::cout << "Invalid choice! Try again.\n";
                continue;
            }
            hero = HeroFactory::createHero(choice, startHeroPos);
        }
        else {
            std::cout << "Invalid input! Please enter a number.\n\n";
            std::cin.clear();
            std::cin.ignore(10000, '\n');
        }
    }
}

void Game::printMap() {
    int size = board.getSize();
    std::cout << "   ";
    for (int x = 0; x < size; ++x) std::cout << x % 10 << " ";
    std::cout << "\n";

    for (int y = 0; y < size; ++y) {
        std::cout << y % 10 << "  ";
        for (int x = 0; x < size; ++x) {
            Point currentPoint = { x, y };

            if (hero && hero->getPos() == currentPoint) {
                std::cout << "H ";
            }
            else {
                bool enemyPrinted = false;
                for (auto& el : enemies) {
                    if (el->getPos() == currentPoint) {
                        std::cout << el->getSymbol() << " ";
                        enemyPrinted = true;
                        break;
                    }
                }
                if (!enemyPrinted) {
                    bool isHighlighted = false;
                    for (const auto& p : highlightedRange) {
                        if (p == currentPoint) {
                            isHighlighted = true;
                            break;
                        }
                    }

                    if (isHighlighted) {
                        std::cout << "+ ";
                    }
                    else {
                        std::cout << board.getCell(x, y) << " ";
                    }
                }
            }
        }
        std::cout << "\n";
    }
}

bool Game::handlePlayerInput() {
    std::cout << "Command (L/R/U/D/OOP): ";
    std::string input;
    std::cin >> input;
    if (input.empty()) return false;
    
    for (auto& c : input) c = toupper(c);
    
    if (input == "L") hero->move(-1, 0, board);
    else if (input == "R") hero->move(1, 0, board);
    else if (input == "U") hero->move(0, -1, board);
    else if (input == "D") hero->move(0, 1, board);
    else if (input == "OOP") {
        hero->useAbility(board, enemies, highlightedRange);

        if (!highlightedRange.empty()) {
            printMap();
            std::cout << "Teleport to (x y): (Must be inside the highlighted range)\n> ";
            int tx, ty;
            if (std::cin >> tx >> ty) {
                Point target = { tx, ty };
                bool valid = false;
                for (auto& p : highlightedRange) {
                    if (p == target) valid = true;
                }
                if (valid) {
                    hero->setPos(target);
                    std::cout << "Teleportation successful!\n";
                }
                else {
                    std::cout << "Target out of range or blocked.\n";
                }
            }
            highlightedRange.clear();
        }
        return true;
    }
    else {
        std::cout << "Invalid command!\n";
        return false;
    }
    return true;
}

bool Game::checkGameOverConditions() {
    if (board.getCell(hero->getPos().x, hero->getPos().y) == 'F') {
        printMap();
        std::cout << "Victory!\n";
        return true;
    }
    for (auto& el : enemies) {
        if (el->getPos() == hero->getPos()) {
            printMap();
            std::cout << "Game over! An enemy caught you.\n";
            return true;
        }
    }
    return false;
}

void Game::run() {
    try {
        setupLevel("level3.txt");
    }
    catch (const std::exception& e) {
        std::cout << "Critical error during loading: " << e.what() << "\n";
        return;
    }
    chooseHero();
    std::cout << "Game started successfully!\n\n";

    while (gameRunning) {
        printMap();

        if (!handlePlayerInput()) continue;

        if (checkGameOverConditions()) {
            gameRunning = false;
            break;
        }

        for (auto& el : enemies) {
            el->updateMovement(hero->getPos(), board);
        }

        if (checkGameOverConditions()) {
            gameRunning = false;
            break;
        }
    }
}