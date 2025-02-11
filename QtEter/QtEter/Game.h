#ifndef GAME_H
#define GAME_H

#include "Player.h"
#include "Card.h"
#include "Table.h"
#include "Match.h"
#include <vector>
#include <memory>
#include <iostream>
#include <fstream>
#include "Gamemode.h" 

namespace game {
	class Game {
	public:

		Game() = default;
		~Game() = default;


		gamemode::Gamemode* getGamemode() const;
		void setGamemode(std::unique_ptr<gamemode::Gamemode> newGamemode);

		void selectGamemode(int selectedGamemode, std::string player1, std::string player2, int player1Score, int player2Score);
		bool isFinish();
		bool makeMove(int value, int row, int column, int ilusion);
		std::string getBorder();
		void changePlayer();
		void setWinner(std::string name);
		void setEqual();
		bool usePower(int row = 0, int column = 0, int targetRow = 0, int targetColumn = 0);
		int pointsNeededForPower();
		std::string getGameModeType();
		bool isExplosionTime();
		bool useExplosion(int direction,int x,int y);

		void showCurrentPlayer();
		void showBoard();
		void showCards();
		void showScore();
		void showWinner();
		void showWizard();
		void showExplosionTime();
		

		void setColor(int color);



	private:
		//save slots
		std::unique_ptr<gamemode::Gamemode> m_gamemode{ std::make_unique<gamemode::Gamemode>() };
		std::unique_ptr<gamemode::Gamemode> m_gamemode2{ std::make_unique<gamemode::Gamemode>() };
		std::unique_ptr<gamemode::Gamemode> m_gamemode3{ std::make_unique<gamemode::Gamemode>() };


	};
}

#endif //GAME_H