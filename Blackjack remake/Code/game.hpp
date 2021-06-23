#include <iostream>
#include <vector>
using namespace std;

class Game {
    private:
        static vector<Player> players;
    public:
        static void gameWithAI(int playerSize);
        static void gameNoAI(int playerSize);
        static void round(int playerNumber, Deck &d);
        static int checkRoundVictory();
        static void determineWinner();
        static void gameOver();
        static void resetPlayers();
};