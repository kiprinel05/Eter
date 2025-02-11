
#include "Gamemode.h"
#include "Player.h"
#include "Match.h"
#include "Card.h"
#include <memory>


namespace gamemode {
	player::Player* Gamemode::getPlayer1() const
	{
		return m_player1.get();
	}
	void Gamemode::setPlayer1(std::unique_ptr <player::Player> newPlayer)
	{
		m_player1 = std::move(newPlayer);
	}

	player::Player* Gamemode::getPlayer2() const
	{
		return m_player2.get();
	}

	void Gamemode::setPlayer2(std::unique_ptr <player::Player> newPlayer)
	{
		m_player2 = std::move(newPlayer);
	}
	int Gamemode::getFinishScore() const {
		return m_finishScore;
	}
	void Gamemode::setFinishScore(int newScore) {
		m_finishScore = newScore;
	}

	bool Gamemode::getMagicUsedPlayer1()
	{
		return m_magicUsedPlayer1;
	}

	void Gamemode::setMagicUsedPlayer1(bool newMagicUsedPlayer)
	{
		m_magicUsedPlayer1= newMagicUsedPlayer;
	}

	bool Gamemode::getMagicUsedPlayer2()
	{
		return m_magicUsedPlayer2;
	}

	void Gamemode::setMagicUsedPlayer2(bool newMagicUsedPlayer)
	{
		m_magicUsedPlayer2 = newMagicUsedPlayer;
	}
	match::Match* Gamemode::getMatch() const
	{
		return m_match.get();
	}

	void Gamemode::setMatch(std::unique_ptr<match::Match> newMathc)
	{
		m_match = std::move(newMathc);
	}


	void Gamemode::createNewGamemode(std::string namePlayer1, std::string namePlayer2, int scorePlayer1, int scorePlayer2){}

	std::string Gamemode::wizardEnumToString(WizardsPower_enum::WizardsPower power) { return ""; }

	bool Gamemode::useMagicPower(WizardsPower_enum::WizardsPower power, int row, int column, int targetRow, int targetColumn) { return false; }

	int Gamemode::pointsNeededForPower(){return 0;}

	std::string Gamemode::getGameModeType(){return "";}
}
