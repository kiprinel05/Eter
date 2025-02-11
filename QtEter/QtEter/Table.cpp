#include "Table.h"
#include <windows.h>
#include <vector>
#include <stack>
#include <string>
#include "Card.h"

void setConsoleColor(int color) {
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(hConsole, color);
}

namespace table {

    Table::Table(int tableSize,int newBorderRestriction)
    {
        std::pair<std::pair<int, int>, std::pair<int, int>> border;
        border.first.first = tableSize / 2;
        border.first.second = tableSize / 2;
        border.second.first = tableSize / 2;
        border.second.second = tableSize / 2;

        m_table = createTable(tableSize);
        m_border = border;
        m_borderRestriction = newBorderRestriction;
    }

    std::vector<std::vector<std::stack<card::Card>>> Table::createTable(int tableSize)
    {
        card::Card startCard = card::Card(0, false, false, "Unknow player");
        std::stack<card::Card> newStack; newStack.push(startCard);
        std::vector<std::stack<card::Card>> column;
        for (int i = 0; i < tableSize; i++)
            column.push_back(newStack);
        std::vector<std::vector<std::stack<card::Card>>> table;
        column.resize(tableSize);
        for (int i = 0; i < tableSize; i++)
            table.push_back(column);
        return table;
    }

    std::vector<std::vector<std::stack<card::Card>>> Table::getTable() const {
        return m_table;
    }

    void Table::setTable(std::vector<std::vector<std::stack<card::Card>>> newTable,int newBorderRestriction)
    {
        int size = newTable.size();
        std::vector<std::vector<std::stack<card::Card>>> table = createTable(size);
        std::pair<std::pair<int, int>, std::pair<int, int>> newBorder;
        newBorder.first.first = size / 2;
        newBorder.first.second = size / 2;
        newBorder.second.first = size / 2;
        newBorder.second.second = size / 2;

        int rowAux = 0, columnAux = 0;
        bool viz=true;

        for (int i = 1; i < size; i++) {
            for (int j = 1; j < size; j++) {
                if (newTable[i][j].top().getPlayerName() != "Unknow player") {
                    if (viz) {
                        viz = false;
                        rowAux = i; columnAux = j;
                        table[newBorder.first.first][newBorder.first.second] = newTable[i][j];
                    }
                    else {
                        table[newBorder.first.first + i - rowAux][newBorder.first.second + j - columnAux] = newTable[i][j];
                        newBorder.second.first -= (rowAux-i);
                        if (columnAux - j > 0) newBorder.first.second -= (columnAux - j);
                        else if (columnAux - j < 0)newBorder.second.second -= (columnAux - j);
                    }
                }
            }
        }
        m_table = table;
        m_border = newBorder;
    }

    std::pair<std::pair<int, int>, std::pair<int, int>> Table::getBorder()
    {
        return m_border;
        /*int vertical;
        int horizontal;
        vertical = m_border.first.first - m_border.second.first;
        if (vertical < 0)vertical *= -1;

        horizontal = m_border.first.second - m_border.second.second;
        if (horizontal < 0)horizontal *= -1;
        vertical++; horizontal++;
        std::string result = std::to_string(vertical) + "/" + std::to_string(horizontal);
        return result;*/
    }

    void Table::setBorder(std::pair<std::pair<int, int>, std::pair<int, int>> newBorder)
    {
        m_border = newBorder;
    }

    void Table::setHoverBiggerCardPower(bool newPower)
    {
        m_hoverBiggerCardPower = newPower;
    }

    bool Table::removeSpace(int row, int column)
    {
        if(!m_table[row][column].top().isPit()){
            while (!m_table[row][column].empty()) m_table[row][column].pop();
            m_table[row][column].push(card::Card(0, false, false, "Unknow player"));
            return true;
        }
        return false;
    }

    bool Table::moveStack(int row, int column, int targetRow, int targetColumn)
    {
        if (makeMove(m_table[row][column].top(), targetRow, targetColumn)) {
            removeSpace(targetRow, targetColumn);
            if (m_table[row][column].top().getPlayerName() == "Unknow player" || m_table[targetRow][targetColumn].top().getPlayerName() != "Unknow player") return false;
            m_table[targetRow][targetColumn] = m_table[row][column];
            removeSpace(row, column);
        }
        return true;
    }

    bool Table::makeMove(card::Card card, int row, int column)
    {
        card::Card currentCard = m_table[row][column].top();
        if (card.isPit() && m_table[row][column].top().getPlayerName() != "Unknow player") return false;
        //Verify : false - you put a card on another card of yours
        if (currentCard.getPlayerName() == card.getPlayerName() && !card.isPit()) return false;
        //Verify : false - your card is less than or equal to the initial card
        if ((!m_hoverBiggerCardPower && currentCard.getValue() >= card.getValue()) || currentCard.isPit()) return false;

        //Verify : true - if you start the game, the first card is in the center
        int centerOfTable = m_table.size() / 2;
        if (m_table[centerOfTable][centerOfTable].top().getPlayerName() == "Unknow player") {
            m_table[centerOfTable][centerOfTable].push(card);
            return true;
        }

        //Verify : true - your card have value bigger than initial card ( this must be for hover the first card put )
        if (m_hoverBiggerCardPower || (currentCard.getValue() < card.getValue() && currentCard.getPlayerName() != "Unknow player")) {
            m_table[row][column].push(card);
            return true;
        }

        //Verify : false - don't place one card near another 
        if (m_table[row - 1][column].top().getPlayerName() == "Unknow player" &&
            m_table[row - 1][column + 1].top().getPlayerName() == "Unknow player" &&
            m_table[row][column + 1].top().getPlayerName() == "Unknow player" &&
            m_table[row + 1][column + 1].top().getPlayerName() == "Unknow player" &&
            m_table[row + 1][column].top().getPlayerName() == "Unknow player" &&
            m_table[row + 1][column - 1].top().getPlayerName() == "Unknow player" &&
            m_table[row][column - 1].top().getPlayerName() == "Unknow player" &&
            m_table[row - 1][column - 1].top().getPlayerName() == "Unknow player")  return false;

        //Verify : false - you place one care outside the map
        if ((m_border.second.second - m_border.first.second == 2 &&
            (column < m_border.first.second || column > m_border.second.second)) ||
            (m_border.second.first - m_border.first.first == 2 &&
                (row < m_border.first.first || row > m_border.second.first)))
            return false;

        //Verify : if border of the map need to be enlarged
        if (row < m_border.first.first) m_border.first.first = row;
        if (row > m_border.second.first) m_border.second.first = row;
        if (column < m_border.first.second) m_border.first.second = column;
        if (column > m_border.second.second) m_border.second.second = column;

        m_table[row][column].push(card);
        m_hoverBiggerCardPower = false;



        return true;
    }
    std::string Table::isWinningLine()
    {
        if ((m_border.second.first - m_border.first.first > 1 || m_border.second.second - m_border.first.second > 1) &&
            (m_border.second.first - m_border.first.first != 0 && m_border.second.second - m_border.first.second != 0)) {
            if (m_border.second.first - m_border.first.first > 1 && m_border.second.second - m_border.first.second > 1) {
                //Verify : table is 3X3
                int centerX = m_border.second.first - 1;
                int centerY = m_border.second.second - 1;
                std::string centerPlayerName = m_table[centerX][centerY].top().getPlayerName();
                //Verify : the center of the table, if it is part of a winning line 
                if(centerPlayerName != "Unknow player")
                    if ((m_table[centerX - 1][centerY].top().getPlayerName() == centerPlayerName && m_table[centerX + 1][centerY].top().getPlayerName() == centerPlayerName) ||
                        (m_table[centerX][centerY - 1].top().getPlayerName() == centerPlayerName && m_table[centerX][centerY + 1].top().getPlayerName() == centerPlayerName) ||
                        (m_table[centerX - 1][centerY - 1].top().getPlayerName() == centerPlayerName && m_table[centerX + 1][centerY + 1].top().getPlayerName() == centerPlayerName) ||
                        (m_table[centerX - 1][centerY + 1].top().getPlayerName() == centerPlayerName && m_table[centerX + 1][centerY - 1].top().getPlayerName() == centerPlayerName)) return centerPlayerName;


                //Verify : the reste of the center points from margin lines, if they are part of a winning line 
                centerPlayerName = m_table[centerX - 1][centerY].top().getPlayerName();
                if (centerPlayerName != "Unknow player" && m_table[centerX - 1][centerY - 1].top().getPlayerName() == centerPlayerName && m_table[centerX - 1][centerY + 1].top().getPlayerName() == centerPlayerName) return centerPlayerName;


                centerPlayerName = m_table[centerX + 1][centerY].top().getPlayerName();
                if (centerPlayerName != "Unknow player" && m_table[centerX + 1][centerY - 1].top().getPlayerName() == centerPlayerName && m_table[centerX + 1][centerY + 1].top().getPlayerName() == centerPlayerName) return centerPlayerName;


                centerPlayerName = m_table[centerX][centerY - 1].top().getPlayerName();
                if (centerPlayerName != "Unknow player" && m_table[centerX - 1][centerY - 1].top().getPlayerName() == centerPlayerName && m_table[centerX + 1][centerY - 1].top().getPlayerName() == centerPlayerName) return centerPlayerName;


                centerPlayerName = m_table[centerX][centerY + 1].top().getPlayerName();
                if (centerPlayerName != "Unknow player" && m_table[centerX - 1][centerY + 1].top().getPlayerName() == centerPlayerName && m_table[centerX + 1][centerY + 1].top().getPlayerName() == centerPlayerName) return centerPlayerName;

                return "none";
            }

            //Verify : table is 2X3
            if (m_border.second.first - m_border.first.first == 1) {
                int centerX = m_border.second.first - 1;
                int centerY = m_border.second.second - 1;
                std::string centerPlayerName = m_table[centerX][centerY].top().getPlayerName();
                if (centerPlayerName != "Unknow player" && m_table[centerX][centerY - 1].top().getPlayerName() == centerPlayerName && m_table[centerX][centerY + 1].top().getPlayerName() == centerPlayerName) return centerPlayerName;

                centerPlayerName = m_table[centerX+1][centerY].top().getPlayerName();
                if (centerPlayerName != "Unknow player" && m_table[centerX + 1][centerY - 1].top().getPlayerName() == centerPlayerName && m_table[centerX + 1][centerY + 1].top().getPlayerName() == centerPlayerName) return centerPlayerName;

                return "none";
            }

            //Verify : table is 3X2
            if (m_border.second.second - m_border.first.second == 1) {
                int centerX = m_border.second.first - 1;
                int centerY = m_border.second.second - 1;
                std::string centerPlayerName = m_table[centerX][centerY].top().getPlayerName();
                if (centerPlayerName != "Unknow player" && m_table[centerX - 1][centerY].top().getPlayerName() == centerPlayerName && m_table[centerX + 1][centerY].top().getPlayerName() == centerPlayerName) return centerPlayerName;

                centerPlayerName = m_table[centerX][centerY + 1].top().getPlayerName();
                if (centerPlayerName != "Unknow player" && m_table[centerX - 1][centerY+1].top().getPlayerName() == centerPlayerName && m_table[centerX + 1][centerY + 1].top().getPlayerName() == centerPlayerName) return centerPlayerName;

                return "none";
            }

        }
        else {
            return "none";
        }
    }
    std::string Table::isWinningScore(std::string player1Name, std::string player2Name)
    {
        auto calculateScore = [&](const std::string& playerName) {
            int score = 0;
            for (const auto& row : m_table)
                for (const auto& cell : row)
                    if (!cell.empty() && cell.top().getPlayerName() == playerName)
                        score += cell.top().getValue();
            return score;
            };

        int scoreP1 = calculateScore(player1Name);
        int scoreP2 = calculateScore(player2Name);

        if (scoreP1 > scoreP2) return player1Name;
        else if (scoreP1 == scoreP2) return "equal";
        else return player2Name;
    }

    bool Table::isExplosionTime()
    {
        int ok = 0;
        bool viz = true;
        if (m_border.second.second - m_border.first.second == 2)
            for (int i = m_border.first.first; i <= m_border.second.first; i++)
            {
                for (int j = m_border.first.second; j <= m_border.second.second; j++){
                    if (m_table[i][j].top().getPlayerName() == "Unknow player") 
                        viz = false;
                }
                
                if (viz){
                   ok++;
                }
                viz = true;
            }
        if (m_border.second.first - m_border.first.first == 2)
            for (int i = m_border.first.second; i <= m_border.second.second; i++)
            {
                for (int j = m_border.first.first; j <= m_border.second.first; j++){
                    if (m_table[i][j].top().getPlayerName() == "Unknow player")
                        viz = false;
                }
                if (viz) {
                    ok++;
                }
                viz = true;
            }
        if (ok >= 2) return true;
        return false;
    }
    bool Table::useExplosion(std::vector<std::vector<int>> explosion, int x, int y)
    {
        
        
        return true;
    }
}