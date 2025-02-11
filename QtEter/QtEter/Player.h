#ifndef PLAYER_H
#define PLAYER_H

#include <string>;
#include <vector>;
#include "Card.h"
#include <memory>
#include "WizardsPower.h"

namespace player {
	class Player {
	private:
		std::string m_name;
		int m_score;
		std::vector<card::Card> m_cards;
		WizardsPower_enum::WizardsPower m_currentPower;

	public:
		Player() = default;
		Player(std::string name,int score, std::vector<card::Card> cards, WizardsPower_enum::WizardsPower newPower);
		~Player() = default;

		void setName(std::string name);
		std::string getName() const;

		int getScore() const;
		void setScore(int newScore);

		std::vector<card::Card> getCards() const;
		void setCards(std::vector<card::Card> newCards);
		void pushCard(card::Card newCard);

		WizardsPower_enum::WizardsPower getCurrentPower();
		void setCurrentPower(WizardsPower_enum::WizardsPower newCurrentPower);
	};
}
#endif // PLAYER_H