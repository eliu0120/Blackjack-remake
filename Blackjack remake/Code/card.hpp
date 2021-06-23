#include <iostream>
#include <string>
using namespace std;

class Card {
    private:
        string suit;
        string type;
        int value;
    public:
        Card();
        Card(string toSuit, string toType, int toValue);
        string getSuit();
        string getType();
        int getValue();
        void setSuit(string toSuit);
        void setType(string toType);
        void setValue(int toValue);
        void printCard();
};