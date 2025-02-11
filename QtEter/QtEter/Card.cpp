#ifndef CARD_H
#define CARD_H

#include "Card.h"
#include <memory>
#include <iostream>

namespace card {
	Card::Card(int value,bool isEter,bool isIlusion, std::string name,bool isPit)
		: m_value(value), m_playerName(name), m_isEter(isEter),m_isIlusion(isIlusion),m_pit(isPit){}

	int Card::getValue() const {
		return m_value;
	}

	void Card::setValue(int newValue) {
		m_value = newValue;
	}

	bool Card::isEter() const {
		return m_isEter;
	}

	void Card::makeEter(bool make) {
		m_isEter = make;
	}

	bool Card::isIlusion() const {
		return m_isIlusion;
	}

	void Card::makeIlusion(bool make) {
		m_isIlusion = make;
	}

	void Card::setPlayerName(std::string name) {
		m_playerName = name;
	}

	std::string Card::getPlayerName() const {
		return m_playerName;
	}

	bool Card::isPit()
	{
		return m_pit;
	}

	void Card::setPit(bool newPit)
	{
		m_pit = newPit;
	}

}

#endif // CARD_H