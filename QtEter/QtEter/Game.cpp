#include "Game.h"
#include <iostream>
#include "Gamemode.h"
#include "Player.h"
#include "Table.h"
#include "Card.h"
#include "Match.h"
#include <string>
#include <memory>
#include <windows.h>                                                                                                                                                  

namespace game {
	gamemode::Gamemode* Game::getGamemode() const {
		return m_gamemode.get();
	}
	void Game::setGamemode(std::unique_ptr<gamemode::Gamemode> newGamemode) {
		m_gamemode = std::move(newGamemode);
	}
	void Game::selectGamemode(int selectedGamemode, std::string player1, std::string player2, int player1Score, int player2Score)
	{

		switch (selectedGamemode) {
		case 1:
		{
			std::unique_ptr<gamemode::Training> newGamemode= std::make_unique < gamemode::Training>();
			newGamemode->createNewGamemode(player1, player2,  player1Score,player2Score);
			m_gamemode = std::move(newGamemode);
			return;
		}
		case 2:
		{
			std::unique_ptr<gamemode::DuelOfWizards> newGamemode = std::make_unique < gamemode::DuelOfWizards>();
			newGamemode->createNewGamemode(player1, player2, player1Score, player2Score);
			m_gamemode = std::move(newGamemode);
			return;
		}
		default:
			std::cout << "[ nu a fost gasit modul de joc ]";
			return;
		}
		
	}
	
	bool Game::isFinish()
	{
		if (m_gamemode->getPlayer1()->getScore() >= m_gamemode->getFinishScore()) return true;
		if (m_gamemode->getPlayer2()->getScore() >= m_gamemode->getFinishScore()) return true;
		return false;
	}

	void Game::changePlayer()
	{
		if (m_gamemode->getMatch()->getCurrentPlayer() == m_gamemode->getPlayer1()->getName()) {
			m_gamemode->getMatch()->setCurrentPlayer(m_gamemode->getPlayer2()->getName());
		} 
		else {
			m_gamemode->getMatch()->setCurrentPlayer(m_gamemode->getPlayer1()->getName());
		}
	}
	void Game::setWinner(std::string name)
	{
		if (m_gamemode->getPlayer1()->getName() == name) {
			m_gamemode->getPlayer1()->setScore(m_gamemode->getPlayer1()->getScore() + 1);
		}
		else {
			m_gamemode->getPlayer2()->setScore(m_gamemode->getPlayer2()->getScore() + 1);
		}

		m_gamemode->createNewGamemode(m_gamemode->getPlayer1()->getName(), m_gamemode->getPlayer2()->getName(), m_gamemode->getPlayer1()->getScore(), m_gamemode->getPlayer2()->getScore());


		std::cout << name << " win the match" << std::endl;
	}
	void Game::setEqual()
	{
		m_gamemode->getPlayer1()->setScore(m_gamemode->getPlayer1()->getScore() + 1);
		m_gamemode->getPlayer2()->setScore(m_gamemode->getPlayer2()->getScore() + 1);

		m_gamemode->createNewGamemode(m_gamemode->getPlayer1()->getName(), m_gamemode->getPlayer2()->getName(), m_gamemode->getPlayer1()->getScore(), m_gamemode->getPlayer2()->getScore());

		std::cout << "It's draw!"<<std::endl;
	}
	bool Game::usePower(int row, int column, int targetRow, int targetColumn)
	{
		if (m_gamemode->getPlayer1()->getName() == m_gamemode->getMatch()->getCurrentPlayer())
			if (m_gamemode->useMagicPower(m_gamemode->getPlayer1()->getCurrentPower(), row, column, targetRow, targetColumn)) {
				m_gamemode->getPlayer1()->setCurrentPower(WizardsPower_enum::WizardsPower::None);
				return true;
			}
			else return false;
		else
			if (m_gamemode->useMagicPower(m_gamemode->getPlayer2()->getCurrentPower(), row, column, targetRow, targetColumn)) {
				m_gamemode->getPlayer2()->setCurrentPower(WizardsPower_enum::WizardsPower::None);
				return true;
			}
			else return false;
	}
	int Game::pointsNeededForPower()
	{
		return m_gamemode->pointsNeededForPower();
	}
	std::string Game::getGameModeType()
	{
		return m_gamemode->getGameModeType();
	}
	bool Game::isExplosionTime()
	{
		return m_gamemode->getMatch()->getTable()->isExplosionTime() && !m_gamemode->getMatch()->getExplosion()->isUsed();
	}
	bool Game::useExplosion(int direction, int x, int y)
	{
		auto table = m_gamemode->getMatch()->getTable()->getTable();
		auto explosion = m_gamemode->getMatch()->getExplosion()->getExplosion(direction);
		auto border = m_gamemode->getMatch()->getTable()->getBorder();
		if (x <= border.first.first || x >= border.second.first || y <= border.first.second || y >= border.second.second) return false;
		card::Card startCard = card::Card(0, false, false, "Unknow player");
		for (int i = x - 1, q = 0; i <= x + 1; i++, q++)
			for (int j = y - 1, w = 0; j <= y + 1; j++, w++){
				if (explosion[q][w] == 2) {
					while (!table[i][j].empty())
					{
						card::Card newCard = card::Card(table[i][j].top().getValue(), table[i][j].top().isEter(), table[i][j].top().isIlusion(), table[i][j].top().getPlayerName());
						if (table[i][j].top().getPlayerName() == m_gamemode->getPlayer1()->getName() && table[i][j].top().getPlayerName() != "Unknow player") {
							m_gamemode->getPlayer1()->pushCard(newCard);
						}
						else if (table[i][j].top().getPlayerName() == m_gamemode->getPlayer2()->getName() && table[i][j].top().getPlayerName() != "Unknow player") {
							m_gamemode->getPlayer2()->pushCard(newCard);
						}
						table[i][j].pop();
					}
				}
				if(explosion[q][w] != 0) m_gamemode->getMatch()->getTable()->removeSpace(i, j);
			}


		m_gamemode->getMatch()->getExplosion()->setIsUsed(true);
		return true;
	}
	bool Game::makeMove(int value, int row, int column, int ilusion)
	{
		std::string currentPlayerName = m_gamemode->getMatch()->getCurrentPlayer();
		card::Card card=card::Card(value,false, ilusion, currentPlayerName);

		int viz;
		if (m_gamemode->getMatch()->getTable()->makeMove(card, row, column))viz = 1;
		else viz = 0;

		if (viz) {
			if (card.getPlayerName() == m_gamemode->getPlayer1()->getName()) {
				std::vector<card::Card> newCards = m_gamemode->getPlayer1()->getCards();
				for (int i = 0; i < newCards.size(); i++)
					if (newCards[i].getValue() == card.getValue()) {
						for (int j = i; j < newCards.size() - 1; j++)
							newCards[j] = newCards[j + 1];
						newCards.pop_back();
						break;
					}
				m_gamemode->getPlayer1()->setCards(newCards);

			}
			else {
				std::vector<card::Card> newCards = m_gamemode->getPlayer2()->getCards();
				for (int i = 0; i < newCards.size(); i++)
					if (newCards[i].getValue() == card.getValue()) {
						for (int j = i; j < newCards.size() - 1; j++)
							newCards[j] = newCards[j + 1];
						newCards.pop_back();
						break;
					}
				m_gamemode->getPlayer2()->setCards(newCards);

			}

			std::string winner = m_gamemode->getMatch()->isWinner(m_gamemode->getPlayer1()->getName(), m_gamemode->getPlayer2()->getName(), m_gamemode->getPlayer1()->getCards().size() == 0 && m_gamemode->getPlayer2()->getCards().size() == 0, row, column);
			if (winner != "none" && winner != "equal") {
				setWinner(winner);
			}
			else if (winner == "equal") setEqual();
			
			changePlayer();
			return true;
		}
		else {
			return false;
		}
		
	}

	std::string Game::getBorder()
	{
		int vertical;
		int horizontal;
		auto border = m_gamemode->getMatch()->getTable()->getBorder();
		vertical = border.first.first - border.second.first;
		if (vertical < 0)vertical *= -1;

		horizontal = border.first.second - border.second.second;
		if (horizontal < 0)horizontal *= -1;
		vertical++; horizontal++;
		std::string result = std::to_string(vertical) + "/" + std::to_string(horizontal);
		return result;
	}



	void Game::showCurrentPlayer()
	{
		std::cout << "Is " << m_gamemode->getMatch()->getCurrentPlayer() << "'s turn" << std::endl;
	}

	void Game::showBoard()
	{
		std::vector<std::vector<std::stack<card::Card>>> table = m_gamemode->getMatch()->getTable()->getTable();

		std::cout << "+---------------------+" << std::endl; // Linie de sus



		for (int i = 1; i < table.size()-1;i++) {
			std::cout << "| "; // Delimitator la începutul liniei
			for (int j = 1; j < table[i].size()-1;j++) {

				if(!table[i][j].top().getValue() || table[i][j].top().isPit())setColor(15);
				else if(table[i][j].top().getPlayerName()==m_gamemode->getPlayer1()->getName())setColor(12);
				else setColor(6);

				if (table[i][j].top().isIlusion())std::cout << "#";
				else if (table[i][j].top().isPit()) std::cout << "@";
				else std::cout << table[i][j].top().getValue();
				setColor(15); // Alb (codul 15 pentru text normal)
				std::cout << " "; // Spațiu între cifre
			}
			std::cout << "|" << std::endl; // Delimitator la sfârșitul liniei
		}

		std::cout << "+---------------------+" << std::endl<<"Explosion:"<<std::endl; // Linie de jos
		for (const auto& rand : m_gamemode->getMatch()->getExplosion()->getExplosion(0)) {
			for (int val : rand) {
				if (val == 0) std::cout << "0 ";
				else if (val == 1) std::cout << "X ";
				else if (val == 2) std::cout << "# "; // Caracter special de palmă
				else std::cout << "? "; // În caz că apare o valoare neașteptată
			}
			std::cout << std::endl;
		}
	}
	void Game::showCards()
	{
		std::cout << m_gamemode->getMatch()->getCurrentPlayer() << "'s cards: ";


		std::vector<card::Card> playerCards;
		if (m_gamemode->getMatch()->getCurrentPlayer() == m_gamemode->getPlayer1()->getName()) {
			playerCards = m_gamemode->getPlayer1()->getCards();
		}
		else {
			playerCards=m_gamemode->getPlayer2()->getCards();
		}

		for (int i = 0; i < playerCards.size(); i++) {
			std::cout << playerCards[i].getValue() << " ";
		}
		std::cout << std::endl;
	}
	void Game::showScore()
	{
		std::cout<<"Score ::   " << m_gamemode->getPlayer1()->getName() << ": " << m_gamemode->getPlayer1()->getScore() << " | " << m_gamemode->getPlayer2()->getScore() << " :" << m_gamemode->getPlayer2()->getName() << std::endl;
	}
	void Game::showWinner()
	{
		if (m_gamemode->getPlayer1()->getScore() == m_gamemode->getFinishScore())
			std::cout << std::endl << std::endl << "FINISH! " << m_gamemode->getPlayer1()->getName() << " win the training mode!";
		else
			std::cout << std::endl << std::endl << "FINISH! " << m_gamemode->getPlayer2()->getName() << " win the training mode!";
	}
	void Game::showWizard()
	{
		WizardsPower_enum::WizardsPower power;
		if (m_gamemode->getPlayer1()->getName() == m_gamemode->getMatch()->getCurrentPlayer())
			std::cout<< m_gamemode->getPlayer1()->getName() <<"'s power: " << m_gamemode->wizardEnumToString(m_gamemode->getPlayer1()->getCurrentPower()) << std::endl;
		else
			std::cout << m_gamemode->getPlayer2()->getName() << "'s power: " << m_gamemode->wizardEnumToString(m_gamemode->getPlayer2()->getCurrentPower()) << std::endl;

	}
	void Game::showExplosionTime()
	{
		std::cout << "Explosion need to by used by " << m_gamemode->getMatch()->getCurrentPlayer() <<". Enter explosion's direction (0-N, 1-E, 2-S, 3-W) and space (x y): ";
	}
	void Game::setColor(int color) {
		HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
		SetConsoleTextAttribute(hConsole, color);
	}

}