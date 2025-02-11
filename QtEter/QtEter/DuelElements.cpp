#include "Gamemode.h"
#include <vector>
#include "Card.h"
#include "Player.h"
#include <string>
#include <memory>
#include <cstdlib>
#include <ctime>
#include <iostream>
#include "ElementsPower.h"
#include "Element.h"

namespace gamemode {
    ElementsPower_enum::ElementsPower getRandomElement(std::vector<ElementsPower_enum::ElementsPower>& availableElements) {
        int index = rand() % availableElements.size();
        ElementsPower_enum::ElementsPower chosenElements = availableElements[index];
        availableElements.erase(availableElements.begin() + index);
        return chosenElements;
    }
    
    //    DuelOfElements::DuelOfElements() : Gamemode(), powerUsedByPlayer1(false), powerUsedByPlayer2(false) {
    //        availablePowers = chooseRandomPowers();
    //    }
    //
    //    DuelOfElements::DuelOfElements(int finishScore, std::unique_ptr<player::Player> player1, std::unique_ptr<player::Player> player2, std::unique_ptr<match::Match> match)
    //        : Gamemode(finishScore, std::move(player1), std::move(player2), std::move(match)), powerUsedByPlayer1(false), powerUsedByPlayer2(false) {
    //        availablePowers = chooseRandomPowers();
    //    }
    //
    //    DuelOfElements::~DuelOfElements() {}
    //
    //    void DuelOfElements::createNewGamemode(std::string namePlayer1, std::string namePlayer2, int scorePlayer1, int scorePlayer2) {
    //        std::vector<card::Card> cards = {
    //            card::Card(1, false, false, namePlayer1),
    //            card::Card(2, false, false, namePlayer1),
    //            card::Card(2, false, false, namePlayer1),
    //            card::Card(3, false, false, namePlayer1),
    //            card::Card(3, false, false, namePlayer1),
    //            card::Card(4, false, false, namePlayer1),
    //            card::Card(0, false, false, "Eter")
    //        };
    //
    //        auto newPlayer1 = std::make_unique<player::Player>(namePlayer1, scorePlayer1, cards);
    //        auto newPlayer2 = std::make_unique<player::Player>(namePlayer2, scorePlayer2, cards);
    //
    //        int tableSize = 4;
    //        std::vector<std::vector<std::stack<card::Card>>> table(tableSize, std::vector<std::stack<card::Card>>(tableSize));
    //
    //        setFinishScore(3);
    //        setPlayer1(std::move(newPlayer1));
    //        setPlayer2(std::move(newPlayer2));
    //        availablePowers = chooseRandomPowers();
    //    }
    //
    //    void DuelOfElements::controlledExplosion() {
    //        auto table = getMatch()->getTable()->getTable();
    //        for (auto& row : table) {
    //            for (auto& stack : row) {
    //                while (!stack.empty()) {
    //                    stack.pop();
    //                }
    //            }
    //        }
    //        std::cout << "The entire board explodes! All cards removed!\n";
    //    }
    //
    //    void DuelOfElements::destruction() {
    //        auto table = getMatch()->getTable()->getTable();
    //        for (int r = 0; r < table.size(); ++r) {
    //            for (int c = 0; c < table[r].size(); ++c) {
    //                if (!table[r][c].empty()) {
    //                    table[r][c].pop();
    //                    std::cout << "The last opponent's card is destroyed!\n";
    //                    return;
    //                }
    //            }
    //        }
    //    }
    //
    //    void DuelOfElements::flames() {
    //        std::cout << "The opponent's illusion is revealed!\n";
    //    }
    //
    //    void DuelOfElements::lava() {
    //        auto table = getMatch()->getTable()->getTable();
    //        std::cout << "Select a card number: ";
    //        int number;
    //        std::cin >> number;
    //        for (auto& row : table) {
    //            for (auto& stack : row) {
    //                if (!stack.empty() && stack.top().getValue() == number) {
    //                    stack.pop();
    //                    std::cout << "A card with number " << number << " returned to its owner.\n";
    //                }
    //            }
    //        }
    //    }
    //
    //    void DuelOfElements::fromAshes() {
    //        std::cout << "A previously removed card returns to play!\n";
    //    }
    //
    //    void DuelOfElements::useElementalPower(ElementalPowers power, int row, int column) {
    //        if (std::find(availablePowers.begin(), availablePowers.end(), power) == availablePowers.end()) {
    //            std::cout << "This power is not available!\n";
    //            return;
    //        }
    //
    //        switch (power) {
    //        case ElementalPowers::ControlledExplosion:
    //            controlledExplosion();
    //            break;
    //        case ElementalPowers::Destruction:
    //            destruction();
    //            break;
    //        case ElementalPowers::Flames:
    //            flames();
    //            break;
    //        case ElementalPowers::Lava:
    //            lava();
    //            break;
    //        case ElementalPowers::FromAshes:
    //            fromAshes();
    //            break;
    //        default:
    //            std::cout << "Invalid elemental power used!\n";
    //            break;
    //        }
    //
    //        availablePowers.erase(std::remove(availablePowers.begin(), availablePowers.end(), power), availablePowers.end());
    //    }
    //













    void DuelOfElements::createNewGamemode(std::string namePlayer1, std::string namePlayer2, int scorePlayer1, int scorePlayer2)
    {
    //    std::vector<ElementsPower_enum::ElementsPower> availableElements = {
    //        ElementsPower_enum::ElementsPower::ControlledExplosion,
    //        ElementsPower_enum::ElementsPower::Destruction,
    //        ElementsPower_enum::ElementsPower::Fire,
    //        ElementsPower_enum::ElementsPower::Lava,
    //        ElementsPower_enum::ElementsPower::Ashes
    //    };
    //    ElementsPower_enum::ElementsPower powerPlayer1 = getRandomElement(availableElements);
    //    ElementsPower_enum::ElementsPower powerPlayer2 = getRandomElement(availableElements);

    //    std::cout << "Player 1 receives: " << static_cast<int>(powerPlayer1) << std::endl;
    //    std::cout << "Player 2 receives: " << static_cast<int>(powerPlayer2) << std::endl;
    //    
    //    const auto& powerMap = Element::getPowerMap();

    //    if (powerMap.find(powerPlayer1) != powerMap.end()) { powerMap.at(powerPlayer1)(); };
    //    if (powerMap.find(powerPlayer2) != powerMap.end()) { powerMap.at(powerPlayer2)(); };

    //    std::vector<card::Card> cards = {
    //        card::Card(1,false,false,namePlayer1),
    //        card::Card(1,false,false,namePlayer1),
    //        card::Card(2,false,false,namePlayer1),
    //        card::Card(2,false,false,namePlayer1),
    //        card::Card(2,false,false,namePlayer1),
    //        card::Card(3,false,false,namePlayer1),
    //        card::Card(3,false,false,namePlayer1),
    //        card::Card(3,false,false,namePlayer1),
    //        card::Card(4,false,false,namePlayer1),
    //        card::Card(0,false,false,"Eter")
    //    };

    //    std::unique_ptr<player::Player> newPlayer1PTR = std::make_unique<player::Player>(namePlayer1, scorePlayer1, cards, ElementsPower_enum::ElementsPower::None);
    //    cards = {
    //        card::Card(1,false,false,namePlayer2),
    //        card::Card(1,false,false,namePlayer2),
    //        card::Card(2,false,false,namePlayer2),
    //        card::Card(2,false,false,namePlayer2),
    //        card::Card(2,false,false,namePlayer2),
    //        card::Card(3,false,false,namePlayer2),
    //        card::Card(3,false,false,namePlayer2),
    //        card::Card(3,false,false,namePlayer2),
    //        card::Card(4,false,false,namePlayer2),
    //        card::Card(0,false,false,"Eter")
    //    };
    //    std::unique_ptr<player::Player> newPlayer2PTR = std::make_unique<player::Player>(namePlayer2, scorePlayer2, cards, ElementsPower_enum::ElementsPower::None);
    //
    //    int tableSize = 9;
    //
    //    card::Card startCard = card::Card(0, false, false, "Unknow player");
    //    std::stack<card::Card> newStack; newStack.push(startCard);
    //    std::vector<std::stack<card::Card>> column;
    //    for (int i = 0; i < tableSize; i++)
    //        column.push_back(newStack);
    //    std::vector<std::vector<std::stack<card::Card>>> table;
    //    column.resize(tableSize);
    //    for (int i = 0; i < tableSize; i++)
    //        table.push_back(column);
    //    std::pair<std::pair<int, int>, std::pair<int, int>> border;
    //    border.first.first = tableSize / 2;
    //    border.first.second = tableSize / 2;
    //    border.second.first = tableSize / 2;
    //    border.second.second = tableSize / 2;

    //    std::unique_ptr<table::Table>newTable = std::make_unique<table::Table>(table, border);


    //    //std::unique_ptr<table::Table>newTable = std::make_unique<table::Table>(createTable(9));
    //    std::unique_ptr<match::Match> newMatch = std::make_unique < match::Match>(std::move(newTable), namePlayer1);
    //    setFinishScore(5);
    //    setPlayer1(std::move(newPlayer1PTR));
    //    setPlayer2(std::move(newPlayer2PTR));
    //    setMatch(std::move(newMatch));
    }
}

