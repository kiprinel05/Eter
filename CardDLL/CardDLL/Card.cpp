#include "Card.h"
#include "pch.h"
#include <string>

namespace card {

    // Define the constructor and member functions outside the class.
    Card::Card(int value, bool isEter, bool isIlusion, std::string name)
        : m_value(value), m_isEter(isEter), m_isIlusion(isIlusion), m_playerName(name) {
    }

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

}
