#include <iostream>
#include <vector>
#include <string>
#include "card.hpp"
#include "deck.hpp"
#include "player.hpp"
#include "AI.hpp"
using namespace std;

// Determine best choice for AI
void AI::makeBestChoice(Deck &d) {
    checkPlayer();
    printRealHand();
    while (!isHolding) {
        int x = isAce();
        if (realValue + d.getNextCardValue() < 22 && d.getCardDeckSize() > 0) {
            cout << "\nAI hits!\n";
            hit(d);
            printRealHand();
        } else if (d.getNextCardType().compare("Ace") == 0 && realValue != 21 && d.getCardDeckSize() > 0) {
            cout << "\nAI hits!\n";
            hit(d);
            hand[hand.size() - 1].setValue(1);
            realValue -= 10;
            printRealHand();
        } else if (x > -1 && realValue != 21 && d.getCardDeckSize() > 0) {
            hand[x].setValue(1);
            realValue -= 10;
            cout << "\nAI hits!\n";
            hit(d);
            printRealHand();
        } else {
            cout << "\nAI holds!\n";
            hold();
        }
    }
}

// Match AI object to its Player object in Player vector of game.cpp
void AI::matchPlayer(Player p) {
    hand = p.getHand();
    realValue = p.getRealValue();
    displayedValue = p.getDisplayedValue();
    isHolding = false;
}