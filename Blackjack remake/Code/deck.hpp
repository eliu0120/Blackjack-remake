#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Deck {
    private:
        vector<Card> cardDeck;
    public:
        Deck();
        void shuffle();
        void printDeck();
        Card popDeck();
        string getNextCardType();
        int getNextCardValue();
        int getCardDeckSize();
};