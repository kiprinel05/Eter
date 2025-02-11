#include "Gamemode.h"
#include <vector>
#include "Card.h"
#include "Player.h"
#include <string>
#include <memory>
#include <cstdlib>
#include <ctime>
#include <iostream>
#include "WizardsPower.h"
#include "ExplosionType.h"

namespace gamemode {


    WizardsPower_enum::WizardsPower getRandomWizard(std::vector<WizardsPower_enum::WizardsPower>& availableWizards) {
        int index = rand() % availableWizards.size();
        WizardsPower_enum::WizardsPower chosenWizard = availableWizards[index];
        availableWizards.erase(availableWizards.begin() + index);
        return chosenWizard;
    }

    bool DuelOfWizards::useMagicPower(WizardsPower_enum::WizardsPower power, int row, int column, int targetRow, int targetColumn) {
        switch (power) {
        case WizardsPower_enum::WizardsPower::RemoveOpponentCard:
            return removeOpponentCard(row, column);
        case WizardsPower_enum::WizardsPower::RemoveRow:
            return removeLine(row,column,targetRow);
        case WizardsPower_enum::WizardsPower::CoverOpponentCard:
            return coverOpponentCard();
        case WizardsPower_enum::WizardsPower::GainExtraEter:
            return gainExtraEter();
        case WizardsPower_enum::WizardsPower::CreatePit:
            return createPit(row, column);
        case WizardsPower_enum::WizardsPower::MoveOwnStack:
            return moveOwnStack(row, column, targetRow, targetColumn);
        case WizardsPower_enum::WizardsPower::MoveEnemyStack:
            return moveEnemyStack(row, column, targetRow, targetColumn);
        case WizardsPower_enum::WizardsPower::MoveEdgeRow:
            return moveEdgeLine(row, column, targetRow);
        default:
            std::cout << "Invalid magic power.\n";
            return false;
        }
    }

    bool DuelOfWizards::removeOpponentCard(int row, int column) {
        auto table = getMatch()->getTable()->getTable();
        if (table[row][column].top().getPlayerName()!="Unknow player" && table[row][column].top().getPlayerName() != getMatch()->getCurrentPlayer())
        {
            table[row][column].pop();
            getMatch()->getTable()->setTable(table, 4);
            return true;
        }
        else return false;
    }

    bool DuelOfWizards::removeLine(int row, int column, int targetRow) {
        auto table = getMatch()->getTable();
        auto border = getMatch()->getTable()->getBorder();
        if (row == targetRow) {
            if(border.second.second - border.first.second < 2){
                return false;
            }
            bool viz = false;
            for (int i = border.first.second; i <= border.second.second; i++)
                if (table->getTable()[row][i].top().getPlayerName() == getMatch()->getCurrentPlayer()) {
                    viz = true;
                    break;
                }
            if (!viz) return false;

            for (int i = border.first.second; i <= border.second.second; i++) {
                if(!table->removeSpace(row, i)) return false;
            }
            getMatch()->getTable()->setTable(table->getTable(),4);

        }
        else {
            if (border.second.first - border.first.first < 2) {
                return false;
            }
            bool viz = false;
            for (int i = border.first.first; i <= border.second.first; i++)
                if (table->getTable()[i][column].top().getPlayerName() == getMatch()->getCurrentPlayer()) {
                    viz = true;
                    break;
                }
            if (!viz) return false;

            for (int i = border.first.first; i <= border.second.first; i++) {
                if (!table->removeSpace(i, column)) return false;
            }
            getMatch()->getTable()->setTable(table->getTable(),4);
        }
        return true;
    }

    bool DuelOfWizards::coverOpponentCard() {
        getMatch()->getTable()->setHoverBiggerCardPower(true);
        return true;
    }

    bool DuelOfWizards::gainExtraEter() {
        if(getPlayer1()->getName() == getMatch()->getCurrentPlayer()) getPlayer1()->getCards().push_back(card::Card(0, true, false, getPlayer1()->getName()));
        else getPlayer2()->getCards().push_back(card::Card(0, true, false, getPlayer2()->getName()));
        return true;
    }

    bool DuelOfWizards::createPit(int row, int column) {
        card::Card pitCard = card::Card(100, false, false, "Unknow player",true);
        if (getMatch()->getTable()->makeMove(pitCard, row, column))return true;
        else return false;
        std::cout << "createPit" << std::endl; return true;
    }

    bool DuelOfWizards::moveOwnStack(int row, int column, int targetRow, int targetColumn) {
        if(getMatch()->getTable()->getTable()[row][column].top().getPlayerName() == getMatch()->getCurrentPlayer())
            if(getMatch()->getTable()->moveStack(row, column, targetRow, targetColumn)) return true;
        return false;
    }

    bool DuelOfWizards::moveEnemyStack(int row, int column, int targetRow, int targetColumn) {
        if (getMatch()->getTable()->getTable()[row][column].top().getPlayerName() != getMatch()->getCurrentPlayer())
            if (getMatch()->getTable()->moveStack(row, column, targetRow, targetColumn)) return true;
        return false;
        std::cout << "moveStackEnemy" << std::endl; return true;
    }

    bool DuelOfWizards::moveEdgeLine(int row,int column,int targetRow) {
        auto table = getMatch()->getTable();
        auto border = getMatch()->getTable()->getBorder();
        if (row == targetRow) {
            if (row == border.first.first) {
                for (int i = border.first.second; i <= border.second.second; i++) {
                    table->getTable()[border.second.first+1][i] = table->getTable()[row][i];
                    table->removeSpace(row, i);
                    getMatch()->getTable()->setTable(table->getTable(),4);
                }
            }
            else {
                for (int i = border.first.second; i <= border.second.second; i++) {
                    table->getTable()[row-1][i] = table->getTable()[border.second.first][i];
                    table->removeSpace(border.second.first, i);
                    getMatch()->getTable()->setTable(table->getTable(), 4);
                }
            }
        }
        else {
            if (column == border.first.second) {
                for (int i = border.first.first; i <= border.second.first; i++) {
                    table->getTable()[border.second.second+1][i] = table->getTable()[column][i];
                    table->removeSpace(row, i);
                    getMatch()->getTable()->setTable(table->getTable(), 4);
                }
            }
            else {
                for (int i = border.first.first; i <= border.second.first; i++) {
                    table->getTable()[column-1][i] = table->getTable()[border.second.second][i];
                    table->removeSpace(border.second.first, i);
                    getMatch()->getTable()->setTable(table->getTable(), 4);
                }
            }
        }
        std::cout << "moveEdgeRow" << std::endl; return true;
    }

    std::string DuelOfWizards::getGameModeType()
    {
        return "Duel Of Wizards";
    }


    void DuelOfWizards::createNewGamemode(std::string namePlayer1, std::string namePlayer2, int scorePlayer1, int scorePlayer2)
    {
        //srand(static_cast<unsigned>(time(0)));

        const std::vector<WizardsPower_enum::WizardsPower> wizardNames = {
            WizardsPower_enum::WizardsPower::RemoveOpponentCard,
            WizardsPower_enum::WizardsPower::RemoveRow,WizardsPower_enum::WizardsPower::CoverOpponentCard,
            WizardsPower_enum::WizardsPower::CreatePit, 
            WizardsPower_enum::WizardsPower::MoveOwnStack,WizardsPower_enum::WizardsPower::GainExtraEter,
            WizardsPower_enum::WizardsPower::MoveEnemyStack,WizardsPower_enum::WizardsPower::MoveEdgeRow
        };
        std::vector<WizardsPower_enum::WizardsPower> availableWizards = wizardNames;
        WizardsPower_enum::WizardsPower wizardPlayer1 = getRandomWizard(availableWizards);
        WizardsPower_enum::WizardsPower wizardPlayer2 = getRandomWizard(availableWizards);

        std::vector<card::Card> cards = {
            card::Card(1,false,false,namePlayer1),
            card::Card(1,false,false,namePlayer1),
            card::Card(2,false,false,namePlayer1),
            card::Card(2,false,false,namePlayer1),
            card::Card(2,false,false,namePlayer1),
            card::Card(3,false,false,namePlayer1),
            card::Card(3,false,false,namePlayer1),
            card::Card(3,false,false,namePlayer1),
            card::Card(4,false,false,namePlayer1),
            card::Card(0,false,false,"Eter")
        };

        std::unique_ptr<player::Player> newPlayer1PTR = std::make_unique<player::Player>(namePlayer1, scorePlayer1, cards, WizardsPower_enum::WizardsPower::GainExtraEter);
        cards = {
            card::Card(1,false,false,namePlayer2),
            card::Card(1,false,false,namePlayer2),
            card::Card(2,false,false,namePlayer2),
            card::Card(2,false,false,namePlayer2),
            card::Card(2,false,false,namePlayer2),
            card::Card(3,false,false,namePlayer2),
            card::Card(3,false,false,namePlayer2),
            card::Card(3,false,false,namePlayer2),
            card::Card(4,false,false,namePlayer2),
            card::Card(0,false,false,"Eter")
        };
        std::unique_ptr<player::Player> newPlayer2PTR = std::make_unique<player::Player>(namePlayer2, scorePlayer2, cards, WizardsPower_enum::WizardsPower::RemoveOpponentCard);

        std::unique_ptr<match::Match> newMatch = std::make_unique < match::Match>(std::make_unique<table::Table>(9, 4), namePlayer1, ExplosionType_enum::ExplosionType::ExplosionType1);
        setFinishScore(3);
        setPlayer1(std::move(newPlayer1PTR));
        setPlayer2(std::move(newPlayer2PTR));
        setMatch(std::move(newMatch));
    }
    std::string DuelOfWizards::wizardEnumToString(WizardsPower_enum::WizardsPower power)
    {
        switch (power)
        {
        case WizardsPower_enum::WizardsPower::RemoveOpponentCard:
            return "Remove Opponent Card";
        case WizardsPower_enum::WizardsPower::RemoveRow:
            return "Remove Row";
        case WizardsPower_enum::WizardsPower::CoverOpponentCard:
            return "Cover Opponent Card";
        case WizardsPower_enum::WizardsPower::CreatePit:
            return "Create Pit";
        case WizardsPower_enum::WizardsPower::MoveOwnStack:
            return "Move Stack Own";
        case WizardsPower_enum::WizardsPower::GainExtraEter:
            return "Gain Extra Eter";
        case WizardsPower_enum::WizardsPower::MoveEnemyStack:
            return "Move Stack Enemy";
        case WizardsPower_enum::WizardsPower::MoveEdgeRow:
            return "Move Edge Row";
        default:
            return "None";
        }
    }
    int DuelOfWizards::pointsNeededForPower()
    {
        if (getPlayer1()->getName() == getMatch()->getCurrentPlayer()){
            if (getPlayer1()->getCurrentPower() == WizardsPower_enum::WizardsPower::GainExtraEter || getPlayer1()->getCurrentPower() == WizardsPower_enum::WizardsPower::CoverOpponentCard) return 0;
            else if (getPlayer1()->getCurrentPower() == WizardsPower_enum::WizardsPower::RemoveOpponentCard || getPlayer1()->getCurrentPower() == WizardsPower_enum::WizardsPower::CreatePit) return 1;
            else return 2;
        }
        else {
            if (getPlayer2()->getCurrentPower() == WizardsPower_enum::WizardsPower::GainExtraEter || getPlayer2()->getCurrentPower() == WizardsPower_enum::WizardsPower::CoverOpponentCard) return 0;
            else if (getPlayer2()->getCurrentPower() == WizardsPower_enum::WizardsPower::RemoveOpponentCard || getPlayer2()->getCurrentPower() == WizardsPower_enum::WizardsPower::CreatePit) return 1;
            else return 2;
        }
    }
}
