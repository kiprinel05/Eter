#include "Eter.h"
#include <QtWidgets/QApplication>
#include "Game.h"
#include <windows.h>
#include <iostream>
#include <regex>

int main(int argc, char* argv[])
{
    std::string gameModeInput;
    int gameModeSelected;
    std::string player1, player2;
    std::regex nameRegex("^[A-Za-z]+$");
    std::regex gameModeRegex("^[1-2]$");
    std::unique_ptr<game::Game> myGame = std::make_unique<game::Game>();

    do {
        std::cout << "1. Training" << std::endl << "2. Duel of Wizards" << std::endl << "Alege modul de joc (1 sau 2): ";
        std::cin >> gameModeInput;
    } while (!std::regex_match(gameModeInput, gameModeRegex));

    gameModeSelected = std::stoi(gameModeInput);

    do {
        std::cout << "Nume player 1: ";
        std::cin >> player1;
    } while (!std::regex_match(player1, nameRegex));

    do {
        std::cout << "Nume player 2: ";
        std::cin >> player2;
    } while (!std::regex_match(player2, nameRegex));

    myGame->selectGamemode(gameModeSelected, player1, player2, 0, 0);

    while (!myGame->isFinish()) {
        int x, y, value, illusion;
        bool validMove = true;
        do {
            myGame->showScore();
            myGame->showCurrentPlayer();
            myGame->showWizard();
            myGame->showCards();
            if (!validMove) std::cout << "Mutarea este invalida, incearca altceva" << std::endl;
            myGame->showBoard();

            if (myGame->isExplosionTime()) {
                int direction;
                do {
                    myGame->showExplosionTime();
                    std::cin >> direction >> x >> y;
                } while (!myGame->useExplosion(direction, x, y));
            }
            else {
                if (gameModeSelected != 1) {
                    bool powerUsed = true;
                    while (powerUsed) {
                        powerUsed = false;
                        int powerUse, pointsNeededForPower = myGame->pointsNeededForPower();
                        std::cout << "- Este folosita puterea (true=1/false=0): ";
                        std::cin >> powerUse;
                        if (powerUse == 1) {
                            int firstPointX, firstPointY;
                            if (pointsNeededForPower == 0) {
                                if (myGame->usePower()) std::cout << "Magia a fost folosita" << std::endl;
                                else {
                                    powerUsed = true;
                                    std::cout << "Magia nu poate fi folosita" << std::endl;
                                }
                            }
                            else if (pointsNeededForPower > 0) {
                                std::cout << "- Selecteaza unde sa fie aplicata magia: ";
                                std::cin >> firstPointX >> firstPointY;
                                if (pointsNeededForPower == 2) {
                                    int secondPointX, secondPointY;
                                    std::cout << "- Selecteaza inca un spatiu pentru a determina randul sau coloana: ";
                                    std::cin >> secondPointX >> secondPointY;
                                    if (myGame->usePower(firstPointX, firstPointY, secondPointX, secondPointY))
                                        std::cout << "Magia a fost folosita" << std::endl;
                                    else {
                                        powerUsed = true;
                                        std::cout << "Magia nu poate fi folosita" << std::endl;
                                    }
                                }
                                else {
                                    if (myGame->usePower(firstPointX, firstPointY)) {
                                        std::cout << "Magia a fost folosita" << std::endl;
                                    }
                                    else {
                                        powerUsed = true;
                                        std::cout << "Magia nu poate fi folosita" << std::endl;
                                    }
                                }
                            }
                            myGame->showBoard();
                            myGame->showCards();
                        }
                    }
                }
                std::cout << "- Alege o carte: ";
                std::cin >> value;
                std::cout << "- Este iluzie (true=1/false=0): ";
                std::cin >> illusion;
                std::cout << "- Alege spatiul: ";
                std::cin >> x >> y;
                validMove = myGame->makeMove(value, x, y, illusion);
            }
        } while (!validMove);
    }
    myGame->showWinner();
    return 0;
}
