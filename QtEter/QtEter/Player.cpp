#include "Player.h"
#include <iostream>
#include <string>
#include <vector>
#include "Card.h"
#include <memory>
#include "WizardsPower.h"
#include "ElementsPower.h"

namespace player {
	Player::Player(std::string name, int score, std::vector<card::Card> cards, WizardsPower_enum::WizardsPower newPower)
		: m_name(name), m_score(score), m_cards(cards), m_currentPower(newPower) {
	}
	void Player::setName(std::string name) {
		m_name = name;
	}

	std::string Player::getName() const {
		return m_name;
	}

	int Player::getScore() const {
		return m_score;
	}

	void Player::setScore(int newScore) {
		m_score = newScore;
	}

	void Player::setCards(std::vector<card::Card> newCards)
	{
		m_cards = newCards;
	}

	void Player::pushCard(card::Card newCard)
	{
		m_cards.push_back(newCard);
	}

	WizardsPower_enum::WizardsPower Player::getCurrentPower()
	{
		return m_currentPower;
	}

	void Player::setCurrentPower(WizardsPower_enum::WizardsPower newCurrentPower)
	{
		m_currentPower = newCurrentPower;
	}

	std::vector<card::Card> Player::getCards() const {
		return m_cards;
	}
}