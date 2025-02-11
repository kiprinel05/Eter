//#include "Wizard.h"
//namespace wizard {
//	float Wizard::getPowerProbability(MagicPowers power) const
//	{
//		for (const auto& pair : magicPows) {
//			if (pair.first == power) {
//				return pair.second;
//			}
//		}
//		return 0.0f;
//	}
//	void Wizard::showMagicAbility()
//	{
//		switch (MagicAbility)
//		{
//		case wizard::Wizard::MagicPowers::Null:
//			std::cout << "Null ";
//			break;
//		case wizard::Wizard::MagicPowers::RemoveCard:
//			std::cout << "RemoveCard ";
//			break;
//		case wizard::Wizard::MagicPowers::RemoveRow:
//			std::cout << "RemoveRow";
//			break;
//		case wizard::Wizard::MagicPowers::CoverCard:
//			std::cout << "CoverCard";
//			break;
//		case wizard::Wizard::MagicPowers::MakeHole:
//			std::cout << "MakeHole";
//			break;
//		case wizard::Wizard::MagicPowers::MoveStackOfCardsWithOwn:
//			std::cout << "MoveStackOfCardsWithOwn";
//			break;
//		case wizard::Wizard::MagicPowers::NewEter:
//			std::cout << "NewEter";
//			break;
//		case wizard::Wizard::MagicPowers::MoveStackOfCardsWithEnemy:
//			std::cout << "MoveStackOfCardsWithEnemy";
//			break;
//		case wizard::Wizard::MagicPowers::MoveAnyRow:
//			std::cout << "MoveAnyRow";
//			break;
//		default:
//			std::cout << "nu are putere";
//			break;
//		}
//	}
//	std::string Wizard::getMagicPowerName() const
//	{
//		switch (MagicAbility) {
//		case MagicPowers::Null: return "Null";
//		case MagicPowers::RemoveCard: return "RemoveCard";
//		case MagicPowers::RemoveRow: return "RemoveRow";
//		case MagicPowers::CoverCard: return "CoverCard";
//		case MagicPowers::MakeHole: return "MakeHole";
//		case MagicPowers::MoveStackOfCardsWithOwn: return "MoveStackOfCardsWithOwn";
//		case MagicPowers::NewEter: return "NewEter";
//		case MagicPowers::MoveStackOfCardsWithEnemy: return "MoveStackOfCardsWithEnemy";
//		case MagicPowers::MoveAnyRow: return "MoveAnyRow";
//		default: return "Unknown";
//		}
//	}
//	void Wizard::assignRandomPower() {
//		std::random_device rd;
//		std::mt19937 gen(rd());
//
//		float totalProbability = 0.0f;
//		for (const auto& pair : magicPows) {
//			totalProbability += pair.second;
//		}
//
//		std::uniform_real_distribution<float> dist(0.0f, totalProbability);
//		float randomValue = dist(gen);
//
//		float cumulativeProbability = 0.0f;
//		for (const auto& pair : magicPows) {
//			cumulativeProbability += pair.second;
//			if (randomValue <= cumulativeProbability) {
//				MagicAbility = pair.first;
//				return;
//			}
//		}
//
//		MagicAbility = MagicPowers::Null;
//	}
//
//}