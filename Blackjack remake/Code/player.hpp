#include <iostream>
#include <vector>
using namespace std;

class Player {
    protected:
        vector<Card> hand;
        bool isHolding;
        bool isPlaying;
        int realValue;
        int displayedValue;
        int score;
    public:
        Player();
        Player(Deck &d);
        void resetPlayer(Deck &d);
        void hit(Deck &d);
        void hold();
        void printDisplayedHand();
        void printRealHand();
        void checkPlayer();
        int isAce();
        bool getIsHolding();
        bool getIsPlaying();
        int getRealValue();
        void setRealValue(int inputRealValue);
        int getDisplayedValue();
        int getScore();
        void incrementScore();
        vector<Card> getHand();
        void matchAI(Player a);
};