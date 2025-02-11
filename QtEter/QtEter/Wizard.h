//
//#include <iostream>
//#include <vector>
//#include <random>
//#include <stdio.h>
//#include <stdlib.h>
//#include <time.h>
//
//
//namespace wizard {
//	class Wizard {
//
//	public:
//		enum class MagicPowers {
//			Null,
//			RemoveCard,
//			RemoveRow,
//			CoverCard,
//			MakeHole,
//			MoveStackOfCardsWithOwn,
//			NewEter,
//			MoveStackOfCardsWithEnemy,
//			MoveAnyRow
//		};
//
//		float probability{ 0 };
//
//		std::vector<std::pair<MagicPowers, float>> magicPows = {
//			{ MagicPowers::RemoveCard, 1.0f },
//			{ MagicPowers::RemoveRow, 0.65f },
//			{ MagicPowers::CoverCard, 0.75f },
//			{ MagicPowers::MakeHole, 0.5f },
//			{ MagicPowers::MoveStackOfCardsWithOwn, 0.85f },
//			{ MagicPowers::NewEter, 0.4f },
//			{ MagicPowers::MoveStackOfCardsWithEnemy, 0.6f },
//			{ MagicPowers::MoveAnyRow, 0.7f }
//		};
//		//Wizard()=default;
//		~Wizard() = default;
//		Wizard(float bProb = 0.5f) : probability(bProb) {}
//
//		float getPowerProbability(MagicPowers power) const;
//		void setPower() { assignRandomPower(); }
//		MagicPowers getMagicAbility() const { return MagicAbility; }
//		void showMagicAbility();
//		std::string getMagicPowerName() const;
//	private:
//		MagicPowers MagicAbility = MagicPowers::Null;
//		void assignRandomPower();
//	};
//}