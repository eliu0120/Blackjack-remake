#include <iostream>
#include <vector>
using namespace std;

class AI : public Player {
    public:
        using Player::Player;
        void makeBestChoice(Deck &d);
        void matchPlayer(Player p);
};