#ifndef TABLE_H
#define TABLE_H

#include <vector>
#include <stack>
#include <iostream>
#include "Card.h"

namespace table {
    class Table {
    private:
        std::vector<std::vector<std::stack<card::Card>>> m_table{};
        std::pair<std::pair<int, int>, std::pair<int, int>> m_border{};
        int m_borderRestriction{ 3 };
        bool m_hoverBiggerCardPower{ false };

    public:
        std::vector<std::vector<std::stack<card::Card>>> createTable(int tableSize);
        Table()=default;
        Table(int tableSize,int newBorderRestriction);
        ~Table() = default;

        std::vector<std::vector<std::stack<card::Card>>> getTable() const;
        void setTable(std::vector<std::vector<std::stack<card::Card>>> newTable, int newBorderRestriction);

        std::pair<std::pair<int, int>, std::pair<int, int>> getBorder();
        void setBorder(std::pair<std::pair<int, int>, std::pair<int, int>> newBorder);

        void setHoverBiggerCardPower(bool newPower);
        bool removeSpace(int row, int column);
        bool moveStack(int row,int column,int targetRow,int targetColumn);

        bool makeMove(card::Card card, int row, int column);
        std::string isWinningLine();
        std::string isWinningScore(std::string player1Name,std::string player2Name);

        bool isExplosionTime();
        bool useExplosion(std::vector<std::vector<int>> explosion,int x,int y);

    };
}
#endif //TABLE_H
