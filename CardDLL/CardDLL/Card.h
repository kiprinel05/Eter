#ifndef CARD_H
#define CARD_H

#include <memory>
#include <iostream>
#include <string>


#ifdef CARD_EXPORTS
#define CARD_API __declspec(dllexport)  // When building the DLL
#else
#define CARD_API __declspec(dllimport)  // When using the DLL in another project
#endif

namespace card {

    class CARD_API Card {  // Apply dllexport/dllimport to the class itself
    public:
        Card() = default;
        Card(int value, bool isEter, bool isIlusion, std::string name);  // Constructor
        ~Card() = default;

        int getValue() const;
        void setValue(int newValue);

        bool isEter() const;
        void makeEter(bool make);

        bool isIlusion() const;
        void makeIlusion(bool make);

        void setPlayerName(std::string name);
        std::string getPlayerName() const;

    private:
        int m_value{ 0 };  // Do not add __declspec(dllexport) to member variables
        bool m_isEter{ false };
        bool m_isIlusion{ false };
        std::string m_playerName;
    };
}

#endif // CARD_H
