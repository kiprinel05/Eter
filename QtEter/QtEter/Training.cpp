#include "Gamemode.h"
#include <vector>
#include "Card.h"
#include "Player.h"
#include <string>
#include <memory>
#include "WizardsPower.h"

namespace gamemode {
	void Training::createNewGamemode(std::string namePlayer1, std::string namePlayer2, int scorePlayer1, int scorePlayer2)
	{
		std::vector<card::Card> cards = {
				card::Card(1,false,false,namePlayer1),
				card::Card(1,false,false,namePlayer1),
				card::Card(2,false,false,namePlayer1),
				card::Card(2,false,false,namePlayer1),
				card::Card(3,false,false,namePlayer1),
				card::Card(3,false,false,namePlayer1),
				card::Card(4,false,false,namePlayer1)
		};
		std::unique_ptr<player::Player>newPlayer1PTR = std::make_unique<player::Player>(namePlayer1, scorePlayer1, cards, WizardsPower_enum::WizardsPower::None);
		cards = {
			card::Card(1,false,false,namePlayer2),
			card::Card(1,false,false,namePlayer2),
			card::Card(2,false,false,namePlayer2),
			card::Card(2,false,false,namePlayer2),
			card::Card(3,false,false,namePlayer2),
			card::Card(3,false,false,namePlayer2),
			card::Card(4,false,false,namePlayer2)
		};
		std::unique_ptr<player::Player>newPlayer2PTR = std::make_unique<player::Player>(namePlayer2, scorePlayer2, cards, WizardsPower_enum::WizardsPower::None);

		std::unique_ptr<match::Match> newMatch = std::make_unique < match::Match>(std::make_unique<table::Table>(7, 3), namePlayer1, ExplosionType_enum::ExplosionType::ExplosionType2);

		setFinishScore(3);
		setPlayer1(std::move(newPlayer1PTR));
		setPlayer2(std::move(newPlayer2PTR));
		setMatch(std::move(newMatch));
	}
	std::string Training::getGameModeType()
	{
		return "Training";
	}
}