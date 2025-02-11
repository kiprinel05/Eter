//#include "Game.h"
//
//namespace game {
//
//    void Turnir::initialise()
//    {
//        match::Match newMatch;
//        player::Player player1, player2;
//        card::Card card;
//        std::vector<card::Card> newCardsPlayer1, newCardsPlayer2;
//
//        // Allocate cards for Player 1
//        for (int i = 1; i <= 3; i++) {
//            card.setValue(i);
//            card.setPlayerType(card::Card::PlayerType::Player1);
//            newCardsPlayer1.push_back(card);
//            newCardsPlayer1.push_back(card);
//        }
//        card.setValue(4);
//        card.setPlayerType(card::Card::PlayerType::Player1);
//        newCardsPlayer1.push_back(card);
//
//        // Allocate cards for Player 2
//        for (int i = 1; i <= 3; i++) {
//            card.setValue(i);
//            card.setPlayerType(card::Card::PlayerType::Player2);
//            newCardsPlayer2.push_back(card);
//            newCardsPlayer2.push_back(card);
//        }
//        card.setValue(4);
//        card.setPlayerType(card::Card::PlayerType::Player2);
//        newCardsPlayer2.push_back(card);
//
//        table::Table newTable;
//
//        std::cout << "Choose game mode to determine initialization settings:\n";
//        std::cout << "1. Training\n2. Duel of Elements\n3. Duel of Wizards\n4. Combined Duel\n";
//        int tourniropt = -1;
//        std::cin >> tourniropt;
//
//        switch (tourniropt) {
//        case 1: { // Training Mode
//            newTable.alloc(3);
//            newMatch.setTable(newTable);
//            break;
//        }
//        case 2: { // Duel of Elements
//            card.setValue(2);
//            card.setPlayerType(card::Card::PlayerType::Player1);
//            newCardsPlayer1.push_back(card);
//
//            card.setValue(3);
//            card.setPlayerType(card::Card::PlayerType::Player1);
//            newCardsPlayer1.push_back(card);
//
//            card.setValue(1);
//            card.makeEter(true);
//            card.setPlayerType(card::Card::PlayerType::Player1);
//            newCardsPlayer1.push_back(card);
//            card.makeEter(false);
//
//            card.setValue(2);
//            card.setPlayerType(card::Card::PlayerType::Player2);
//            newCardsPlayer2.push_back(card);
//
//            card.setValue(3);
//            card.setPlayerType(card::Card::PlayerType::Player2);
//            newCardsPlayer2.push_back(card);
//
//            card.setValue(1);
//            card.makeEter(true);
//            card.setPlayerType(card::Card::PlayerType::Player2);
//            newCardsPlayer2.push_back(card);
//
//            newTable.alloc(4);
//            newMatch.setTable(newTable);
//            break;
//        }
//        case 3: { // Duel of Wizards
//            player1.makeWizard(true);
//            auto* wizard1 = new wizard::Wizard();
//            wizard1->setPower();
//            player1.setWizard(wizard1);
//
//            player2.makeWizard(true);
//            auto* wizard2 = new wizard::Wizard();
//            wizard2->setPower();
//            player2.setWizard(wizard2);
//
//            newTable.alloc(4);
//            newMatch.setTable(newTable);
//            break;
//        }
//        case 4: { // Combined Duel
//            card.setValue(1);
//            card.makeEter(true);
//            card.setPlayerType(card::Card::PlayerType::Player1);
//            newCardsPlayer1.push_back(card);
//
//            card.setValue(3);
//            card.setPlayerType(card::Card::PlayerType::Player2);
//            newCardsPlayer2.push_back(card);
//
//            player1.makeWizard(true);
//            auto* wizard1 = new wizard::Wizard();
//            wizard1->setPower();
//            player1.setWizard(wizard1);
//
//            player2.makeWizard(true);
//            auto* wizard2 = new wizard::Wizard();
//            wizard2->setPower();
//            player2.setWizard(wizard2);
//
//            newTable.alloc(4);
//            newMatch.setTable(newTable);
//            break;
//        }
//        default:
//            std::cerr << "Invalid choice. Restarting initialization.\n";
//            Turnir::initialise();
//            return;
//        }
//
//        // Allocate players
//        std::string player1Name, player2Name;
//        std::cout << "First player name: ";
//        std::cin >> player1Name;
//        std::cout << "Second player name: ";
//        std::cin >> player2Name;
//
//        player1.setCards(newCardsPlayer1);
//        player2.setCards(newCardsPlayer2);
//        player1.setName(player1Name);
//        player2.setName(player2Name);
//
//        newMatch.setPlayer(player1, card::Card::PlayerType::Player1);
//        newMatch.setPlayer(player2, card::Card::PlayerType::Player2);
//
//        this->setMatch(newMatch);
//        this->addMatch(newMatch);
//    }
//
//
//
//    void Turnir::check()
//    {
//
//    }
//
//}