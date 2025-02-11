#pragma once
#include <iostream>;
#include <vector>;
#include <memory>;

namespace card {

	class Card {

	public:

		Card() = default;
		Card(int value,bool isEter,bool isIlusion, std::string name,bool isPit = false);
		~Card() = default;

		int getValue() const;
		void setValue(int newValue);

		bool isEter() const;
		void makeEter(bool make);

		bool isIlusion() const;
		void makeIlusion(bool make);

		void setPlayerName(std::string name);
		std::string getPlayerName() const;

		bool isPit();
		void setPit(bool newPit);


	private:
		int m_value{ 0 };
		bool m_isEter{ false };
		bool m_isIlusion{ false };
		bool m_pit{ false };
		std::string m_playerName;
	};
}