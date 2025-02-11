#ifndef GAMEMODE_H
#define GAMEMODE_H

#include <string>
#include "Player.h"
#include "Match.h"
#include <memory>
#include <vector>
#include <cstdlib>
#include <algorithm>
#include <random>
#include "WizardsPower.h"


namespace gamemode {
	
	class Gamemode {

	private:
		int m_finishScore{0};
		bool m_magicUsedPlayer1{ true };
		bool m_magicUsedPlayer2{ true };
		std::unique_ptr <player::Player> m_player1{ std::make_unique <player::Player>()};
		std::unique_ptr <player::Player>m_player2{ std::make_unique <player::Player>()};
		std::unique_ptr<match::Match>m_match{ std::make_unique < match::Match>() };
	public:
		Gamemode()=default;
		~Gamemode()=default;

		player::Player* getPlayer1() const;
		void setPlayer1(std::unique_ptr <player::Player> newPlayer);

		player::Player* getPlayer2() const;
		void setPlayer2(std::unique_ptr <player::Player> newPlayer);

		int getFinishScore() const;
		void setFinishScore(int newScore);

		bool getMagicUsedPlayer1();
		void setMagicUsedPlayer1(bool newMagicUsedPlayer);

		bool getMagicUsedPlayer2();
		void setMagicUsedPlayer2(bool newMagicUsedPlayer);

		match::Match* getMatch() const;
		void setMatch(std::unique_ptr<match::Match> newMathc);

		virtual void createNewGamemode(std::string namePlayer1, std::string namePlayer2, int scorePlayer1, int scorePlayer2);
		virtual std::string wizardEnumToString(WizardsPower_enum::WizardsPower power);
		virtual bool useMagicPower(WizardsPower_enum::WizardsPower power, int row = 0, int column = 0, int targetRow = 0, int targetColumn = 0);
		virtual int pointsNeededForPower();
		virtual std::string getGameModeType();

	};





	class Training : public Gamemode
	{
	public:
		Training()=default;
		//Training(int finishScore, std::unique_ptr <player::Player> player1, std::unique_ptr <player::Player> player2, std::unique_ptr<match::Match> match);
		~Training() = default;

		void createNewGamemode(std::string namePlayer1, std::string namePlayer2, int scorePlayer1,int scorePlayer2) override;
		std::string getGameModeType();
	};













	class DuelOfWizards : public Gamemode {
	public:

		DuelOfWizards()=default;
		//DuelOfWizards(int finishScore, std::unique_ptr<player::Player> player1, std::unique_ptr<player::Player> player2, std::unique_ptr<match::Match> match);
		~DuelOfWizards()=default;

		bool useMagicPower(WizardsPower_enum::WizardsPower power, int row=0, int column=0, int targetRow=0, int targetColumn=0) override;
		void createNewGamemode(std::string namePlayer1, std::string namePlayer2, int scorePlayer1, int scorePlayer2) override;
		std::string wizardEnumToString(WizardsPower_enum::WizardsPower power) override;
		int pointsNeededForPower() override;
		std::string getGameModeType();

		/*powers*/
		bool removeOpponentCard(int row, int column);
		bool removeLine(int row, int column, int targetRow);
		bool coverOpponentCard();
		bool gainExtraEter();
		bool createPit(int row, int column);
		bool moveOwnStack(int row, int column, int targetRow, int targetColumn);
		bool moveEnemyStack(int row, int column, int targetRow, int targetColumn);
		bool moveEdgeLine(int row, int column,int targetRow);


	};

}

#endif //GAMEMODE_H