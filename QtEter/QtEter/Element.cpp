#include "Card.h"
#include "Element.h"
#include "Gamemode.h"
#include "Player.h"
#include "Table.h"
#include <iostream>
#include <vector>
#include <stack>

namespace Element {
	/*void activateControlledExplosion(gamemode::Gamemode& gamemode)
	{
		auto table = gamemode.getMatch()->getTable()->getTable();
		        for (auto& row : table) {
		            for (auto& stack : row) {
		                while (!stack.empty()) {
		                    stack.pop();
		                }
						stack.push(card::Card(0, false, false, "Empty"));
		            }

				}
		        std::cout << "The entire board explodes! All cards removed!\n";
	}
	void activateDestruction(gamemode::Gamemode& gamemode)
	{
		auto table = gamemode.getMatch()->getTable()->getTable();
		for (int r = 0; r < table.size(); ++r) {
			for (int c = 0; c < table[r].size(); ++c) {
				if (!table[r][c].empty()) {
					table[r][c].pop();
					std::cout << "The last opponent's card is destroyed!\n";
					return;
				}
			}
		}
	}
	void activateFire(gamemode::Gamemode& gamemode)
	{
		auto table = gamemode.getMatch()->getTable()->getTable();
		std::cout << "The illusion is reveal!\n";
	}
	void activateLava(gamemode::Gamemode& gamemode)
	{
		auto table = gamemode.getMatch()->getTable()->getTable();
		std::cout << "Select a card number: ";
		int number;
		std::cin >> number;
		for (auto& row : table) {
			for (auto& stack : row) {
				if (!stack.empty() && stack.top().getValue() == number) {
					stack.pop();
					std::cout << "A card with number " << number << " returned to its owner.\n";
				}
			}
		}
	}
	void activateAshes(gamemode::Gamemode& gamemode)
	{
		auto table = gamemode.getMatch()->getTable()->getTable();
		card::Card selectedCard;
		std::cout << "Select a played card who wants to play again: ";
	}
	void activateSquall(gamemode::Gamemode& gamemode) {
		auto table = gamemode.getMatch()->getTable()->getTable();
		for (auto& row : table) {
			for (auto& stack : row) {
				if (stack.size() > 1) {
					while (!stack.empty()) {
						auto card = stack.top();
						stack.pop();
						std::cout << "Card with value " << card.getValue() << " returned to its owner.\n";
					}
				}
			}
		}
		std::cout << "All covered cards returned to their owners.\n";
	}

	void activateHurricane(gamemode::Gamemode& gamemode) {
		auto table = gamemode.getMatch()->getTable()->getTable();
		int row, direction;
		std::cout << "Choose a fully occupied row to shift (row): ";
		std::cin >> row;
		std::cout << "Choose direction (1 for right, -1 for left): ";
		std::cin >> direction;

		std::vector<std::stack<card::Card>> shiftedRow = table[row];
		if (direction == 1) {
			auto lastStack = shiftedRow.back();
			for (int i = shiftedRow.size() - 1; i > 0; --i) {
				shiftedRow[i] = shiftedRow[i - 1];
			}
			shiftedRow[0] = lastStack;
		}
		else if (direction == -1) {
			auto firstStack = shiftedRow.front();
			for (int i = 0; i < shiftedRow.size() - 1; ++i) {
				shiftedRow[i] = shiftedRow[i + 1];
			}
			shiftedRow.back() = firstStack;
		}

		for (size_t i = 0; i < table[row].size(); ++i) {
			table[row][i] = shiftedRow[i];
		}
		std::cout << "Row shifted in direction " << direction << ".\n";
	}
	void activateFlurry(gamemode::Gamemode& gamemode) {
		auto table = gamemode.getMatch()->getTable()->getTable();
		int row, col, newRow, newCol;
		std::cout << "Choose a visible card (row, col): ";
		std::cin >> row >> col;

		if (!table[row][col].empty()) {
			auto card = table[row][col].top();
			table[row][col].pop();
			std::cout << "Choose an adjacent position to move the card (newRow, newCol): ";
			std::cin >> newRow >> newCol;

			if (abs(row - newRow) + abs(col - newCol) == 1) { 
				table[newRow][newCol].push(card);
				std::cout << "Card moved to adjacent position (" << newRow << ", " << newCol << ").\n";
			}
			else {
				std::cout << "Invalid position. Card not moved.\n";
				table[row][col].push(card);
			}
		}
		else {
			std::cout << "No visible card found at the chosen position.\n";
		}
	}

	void activateStorm(gamemode::Gamemode& gamemode) {
		auto table = gamemode.getMatch()->getTable()->getTable();
		int row, col;
		std::cout << "Choose a stack to eliminate (row, col): ";
		std::cin >> row >> col;

		if (!table[row][col].empty() && table[row][col].size() >= 2) {
			while (!table[row][col].empty()) {
				table[row][col].pop();
			}
			std::cout << "Stack at (" << row << ", " << col << ") eliminated from the game.\n";
		}
		else {
			std::cout << "Invalid selection. No stack with 2 or more cards found.\n";
		}
	}

	void activateTide(gamemode::Gamemode& gamemode) {
		auto table = gamemode.getMatch()->getTable()->getTable();
		int row1, col1, row2, col2;
		std::cout << "Choose first stack (row1, col1): ";
		std::cin >> row1 >> col1;
		std::cout << "Choose second stack (row2, col2): ";
		std::cin >> row2 >> col2;

		if (!table[row1][col1].empty() && !table[row2][col2].empty()) {
			std::swap(table[row1][col1], table[row2][col2]);
			std::cout << "Stacks swapped between positions (" << row1 << ", " << col1 << ") and (" << row2 << ", " << col2 << ").\n";
		}
		else {
			std::cout << "Invalid selection. One or both stacks are empty.\n";
		}
	}
	void activateFog(gamemode::Gamemode& gamemode, player::Player& currentPlayer) {
		auto table = gamemode.getMatch()->getTable()->getTable();

		if (currentPlayer.hasIllusion()) {
			std::cout << "You already have an illusion in play. Cannot play another illusion.\n";
			return;
		}

		card::Card illusionCard = card::Card(0, false, true, "Illusion");
		currentPlayer.playCard(illusionCard);
		std::cout << "Illusion card played on the board.\n";
	}

	void activateWave(gamemode::Gamemode& gamemode, player::Player& currentPlayer) {
		auto table = gamemode.getMatch()->getTable()->getTable();
		int row, col, newRow, newCol;
		std::cout << "Select a stack to move (row, col): ";
		std::cin >> row >> col;

		if (!table[row][col].empty()) {
			auto stack = table[row][col];
			table[row][col] = std::stack<card::Card>();

			std::cout << "Select an adjacent empty position (newRow, newCol): ";
			std::cin >> newRow >> newCol;

			if (abs(row - newRow) + abs(col - newCol) == 1 && table[newRow][newCol].empty()) {
				table[newRow][newCol] = stack;
				std::cout << "Stack moved. Play a card on the new position.\n";
				auto newCard = currentPlayer.drawCard(); 
				table[newRow][newCol].push(newCard);
			}
			else {
				std::cout << "Invalid move.\n";
				table[row][col] = stack; 
			}
		}
		else {
			std::cout << "No stack at the selected position.\n";
		}
	}
	void activateSparks(gamemode::Gamemode& gamemode, player::Player& currentPlayer, player::Player& opponent) {
		auto table = gamemode.getMatch()->getTable()->getTable();
		int row, col;
		std::cout << "Alege o carte proprie acoperită de adversar (row, col): ";
		std::cin >> row >> col;

		if (!table[row][col].empty() && table[row][col].top().isCovered() && table[row][col].top().getOwner() == currentPlayer.getId()) {
			card::Card selectedCard = table[row][col].top();
			table[row][col].pop();

			int newRow, newCol;
			std::cout << "Alege o poziție nouă (newRow, newCol): ";
			std::cin >> newRow >> newCol;

			if (table[newRow][newCol].empty()) {
				table[newRow][newCol].push(selectedCard);
				std::cout << "Cartea a fost mutată cu succes!\n";
			}
			else {
				std::cout << "Poziția selectată nu este goală.\n";
				table[row][col].push(selectedCard);
			}
		}
		else {
			std::cout << "Poziția selectată nu conține o carte proprie acoperită de adversar.\n";
		}
	}
	void activateStormy(gamemode::Gamemode& gamemode, player::Player& opponent) {
		auto table = gamemode.getMatch()->getTable()->getTable();
		int row, col;
		std::cout << "Alege o carte vizibilă a oponentului (row, col): ";
		std::cin >> row >> col;

		if (!table[row][col].empty() && !table[row][col].top().isCovered() && table[row][col].top().getOwner() == opponent.getId()) {
			card::Card selectedCard = table[row][col].top();
			table[row][col].pop();
			opponent.addToHand(selectedCard);
			std::cout << "Cartea a fost întoarsă în mâna adversarului.\n";
		}
		else {
			std::cout << "Poziția selectată nu conține o carte vizibilă a adversarului.\n";
		}
	}
	void activateMirage(gamemode::Gamemode& gamemode, player::Player& currentPlayer) {
		if (!currentPlayer.hasIllusion()) {
			std::cout << "Nu ai o iluzie plasată.\n";
			return;
		}

		card::Card newIllusion = card::Card(0, false, true, "Illusion");
		currentPlayer.replaceIllusion(newIllusion);
		std::cout << "Iluzia a fost înlocuită cu succes.\n";
	}
	void activateTsunami(gamemode::Gamemode& gamemode, player::Player& opponent) {
		auto table = gamemode.getMatch()->getTable()->getTable();
		int row;
		std::cout << "Alege un rând pentru tsunami: ";
		std::cin >> row;

		bool validRow = false;
		for (size_t i = 0; i < table[row].size(); ++i) {
			if (table[row][i].empty()) {
				validRow = true;
				break;
			}
		}

		if (validRow) {
			gamemode.getMatch()->getTable()->restrictRow(row);
			std::cout << "Rândul " << row << " este restricționat pentru tura următoare a adversarului.\n";
		}
		else {
			std::cout << "Nu există spații goale pe rândul selectat. Tsunami anulat.\n";
		}
	}
	void activateCascade(gamemode::Gamemode& gamemode) {
		auto table = gamemode.getMatch()->getTable()->getTable();
		int row;
		std::cout << "Alege un rând cu cel puțin 3 poziții ocupate: ";
		std::cin >> row;

		int occupied = 0;
		for (const auto& stack : table[row]) {
			if (!stack.empty()) ++occupied;
		}

		if (occupied >= 3) {
			char direction;
			std::cout << "Alege direcția de cădere (L pentru stânga, R pentru dreapta): ";
			std::cin >> direction;

			if (direction == 'L' || direction == 'R') {
				std::stack<card::Card> newStack;
				for (size_t i = 0; i < table[row].size(); ++i) {
					if (!table[row][i].empty()) {
						while (!table[row][i].empty()) {
							newStack.push(table[row][i].top());
							table[row][i].pop();
						}
					}
				}

				int pos = (direction == 'L') ? 0 : table[row].size() - 1;
				table[row][pos] = newStack;
				std::cout << "Cărțile au căzut spre margine.\n";
			}
			else {
				std::cout << "Direcție invalidă.\n";
			}
		}
		else {
			std::cout << "Rândul nu are suficiente poziții ocupate.\n";
		}
	}
	void activateSupport(gamemode::Gamemode& gamemode, player::Player& currentPlayer) {
		auto table = gamemode.getMatch()->getTable()->getTable();
		int row, col;
		std::cout << "Alege o carte proprie 1/2/3 pentru a-i crește valoarea cu 1 (row, col): ";
		std::cin >> row >> col;

		if (!table[row][col].empty() && table[row][col].top().getOwner() == currentPlayer.getId()) {
			auto& card = table[row][col].top();
			int value = card.getValue();

			if (value >= 1 && value <= 3) {
				card.setValue(value + 1);
				std::cout << "Valoarea cărții a fost crescută cu 1.\n";
			}
			else {
				std::cout << "Cartea selectată nu are o valoare validă (1/2/3).\n";
			}
		}
		else {
			std::cout << "Poziția selectată nu conține o carte proprie.\n";
		}
	}
	void activateEarthquake(gamemode::Gamemode& gamemode) {
		auto table = gamemode.getMatch()->getTable()->getTable();
		for (auto& row : table) {
			for (auto& stack : row) {
				if (!stack.empty() && stack.top().getValue() == 1 && !stack.top().isCovered()) {
					stack.pop();
				}
			}
		}
		std::cout << "Toate cărțile vizibile cu valoarea 1 au fost eliminate de pe tablă.\n";
	}
	void activateBorders(gamemode::Gamemode& gamemode, player::Player& currentPlayer) {
		auto table = gamemode.getMatch()->getTable()->getTable();
		int row, col;
		std::cout << "Alege o poziție pentru a plasa o carte neutră (row, col): ";
		std::cin >> row >> col;

		if (table[row][col].empty()) {
			card::Card neutralCard = card::Card(0, false, false, "Neutral");
			table[row][col].push(neutralCard);
			std::cout << "Cartea neutră a fost plasată.\n";

			int playRow, playCol;
			std::cout << "Alege o poziție pentru a plasa o carte din mână (playRow, playCol): ";
			std::cin >> playRow >> playCol;

			if (table[playRow][playCol].empty()) {
				card::Card cardToPlay = currentPlayer.playCard();
				table[playRow][playCol].push(cardToPlay);
				std::cout << "Cartea din mână a fost plasată.\n";
			}
			else {
				std::cout << "Poziția selectată pentru plasarea cărții din mână nu este goală.\n";
			}
		}
		else {
			std::cout << "Poziția selectată pentru cartea neutră nu este goală.\n";
		}
	}
	void activateAvalanche(gamemode::Gamemode& gamemode) {
		auto table = gamemode.getMatch()->getTable()->getTable();
		int row1, col1, row2, col2;
		std::cout << "Alege două teancuri adiacente pe orizontală/verticală (row1, col1, row2, col2): ";
		std::cin >> row1 >> col1 >> row2 >> col2;

		if ((row1 == row2 && abs(col1 - col2) == 1) || (col1 == col2 && abs(row1 - row2) == 1)) {
			if (!table[row1][col1].empty() && !table[row2][col2].empty()) {
				int shiftRow = row1 == row2 ? row1 : (row1 > row2 ? row2 : row1);
				int shiftCol = col1 == col2 ? col1 : (col1 > col2 ? col2 : col1);

				if (table[shiftRow][shiftCol].empty()) {
					table[shiftRow][shiftCol] = table[row1][col1];
					table[row1][col1] = {};
					table[shiftRow][shiftCol] = table[row2][col2];
					table[row2][col2] = {};
					std::cout << "Teancurile au fost shiftate cu succes.\n";
				}
				else {
					std::cout << "Poziția pentru shiftare nu este goală.\n";
				}
			}
			else {
				std::cout << "Cel puțin unul dintre teancurile selectate este gol.\n";
			}
		}
		else {
			std::cout << "Teancurile selectate nu sunt adiacente.\n";
		}
	}
	void activateBoulder(gamemode::Gamemode& gamemode, player::Player& currentPlayer) {
		auto table = gamemode.getMatch()->getTable()->getTable();
		int row, col;
		std::cout << "Alege o poziție pentru a acoperi o iluzie (row, col): ";
		std::cin >> row >> col;

		if (!table[row][col].empty() && table[row][col].top().isIllusion()) {
			card::Card cardToPlay = currentPlayer.playCard();
			table[row][col].push(cardToPlay);
			std::cout << "Iluzia a fost acoperită cu succes.\n";
		}
		else {
			std::cout << "Poziția selectată nu conține o iluzie.\n";
		}
	}



	const std::unordered_map<ElementsPower_enum::ElementsPower, std::function<void(gamemode::Gamemode&)>>& getPowerMap() {
		static const std::unordered_map<ElementsPower_enum::ElementsPower, std::function<void(gamemode::Gamemode&)>> powerMap = {
		{ElementsPower_enum::ElementsPower::ControlledExplosion, activateControlledExplosion},
		{ElementsPower_enum::ElementsPower::Destruction, activateDestruction}, 
		{ElementsPower_enum::ElementsPower::Fire, activateFire}, 
		{ElementsPower_enum::ElementsPower::Lava, activateLava}, 
		{ElementsPower_enum::ElementsPower::Ashes, activateAshes},
		{ElementsPower_enum::ElementsPower::Sparks, activateSparks},
		{ElementsPower_enum::ElementsPower::Storm, activateStorm}, 
		{ElementsPower_enum::ElementsPower::Squall, activateSquall},
		{ElementsPower_enum::ElementsPower::Hurricane, activateHurricane},
		{ElementsPower_enum::ElementsPower::Flurry, activateFlurry}, 
		{ElementsPower_enum::ElementsPower::Fog, activateFog}, 
		{ElementsPower_enum::ElementsPower::Wave, activateWave}, 
		{ElementsPower_enum::ElementsPower::Stormy, activateStormy}, 
		{ElementsPower_enum::ElementsPower::Mirage, activateMirage}, 
		{ElementsPower_enum::ElementsPower::Tsunami, activateTsunami}, 
		{ElementsPower_enum::ElementsPower::Cascade, activateCascade}, 
		{ElementsPower_enum::ElementsPower::Support, activateSupport},
		{ElementsPower_enum::ElementsPower::Earthquake, activateEarthquake}, 
		{ElementsPower_enum::ElementsPower::Crunch, activateCrunch},
		{ElementsPower_enum::ElementsPower::Borders, activateBorders}, 
		{ElementsPower_enum::ElementsPower::Avalanche, activateAvalanche}, 
		{ElementsPower_enum::ElementsPower::Boulder, activateBoulder},
		{ElementsPower_enum::ElementsPower::None, activateNone} };
	};*/
}