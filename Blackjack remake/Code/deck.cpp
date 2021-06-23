#include <iostream>
#include <vector>
#include <string>
#include <cstdlib>
#include <ctime>
#include "card.hpp"
#include "deck.hpp"
using namespace std;

// Default constructor, creates all cards for the deck
Deck::Deck() {
    for (int i = 0; i < 52; i += 4) {
        if ((i / 4) + 1 == 1) {
            Card a("Diamond", "Ace", 11);
            cardDeck.push_back(a);
            Card b("Spade", "Ace", 11);
            cardDeck.push_back(b);
            Card c("Heart", "Ace", 11);
            cardDeck.push_back(c);
            Card d("Club", "Ace", 11);
            cardDeck.push_back(d);
        } else if (i / 4 + 1 == 2) {
            Card a("Diamond", "2", 2);
            cardDeck.push_back(a);
            Card b("Spade", "2", 2);
            cardDeck.push_back(b);
            Card c("Heart", "2", 2);
            cardDeck.push_back(c);
            Card d("Club", "2", 2);
            cardDeck.push_back(d);
        } else if (i / 4 + 1 == 3) {
            Card a("Diamond", "3", 3);
            cardDeck.push_back(a);
            Card b("Spade", "3", 3);
            cardDeck.push_back(b);
            Card c("Heart", "3", 3);
            cardDeck.push_back(c);
            Card d("Club", "3", 3);
            cardDeck.push_back(d);
        } else if (i / 4 + 1 == 4) {
            Card a("Diamond", "4", 4);
            cardDeck.push_back(a);
            Card b("Spade", "4", 4);
            cardDeck.push_back(b);
            Card c("Heart", "4", 4);
            cardDeck.push_back(c);
            Card d("Club", "4", 4);
            cardDeck.push_back(d);
        } else if (i / 4 + 1 == 5) {
            Card a("Diamond", "5", 5);
            cardDeck.push_back(a);
            Card b("Spade", "5", 5);
            cardDeck.push_back(b);
            Card c("Heart", "5", 5);
            cardDeck.push_back(c);
            Card d("Club", "5", 5);
            cardDeck.push_back(d);
        } else if (i / 4 + 1 == 6) {
            Card a("Diamond", "6", 6);
            cardDeck.push_back(a);
            Card b("Spade", "6", 6);
            cardDeck.push_back(b);
            Card c("Heart", "6", 6);
            cardDeck.push_back(c);
            Card d("Club", "6", 6);
            cardDeck.push_back(d);
        } else if (i / 4 + 1 == 7) {
            Card a("Diamond", "7", 7);
            cardDeck.push_back(a);
            Card b("Spade", "7", 7);
            cardDeck.push_back(b);
            Card c("Heart", "7", 7);
            cardDeck.push_back(c);
            Card d("Club", "7", 7);
            cardDeck.push_back(d);
        } else if (i / 4 + 1 == 8) {
            Card a("Diamond", "8", 8);
            cardDeck.push_back(a);
            Card b("Spade", "8", 8);
            cardDeck.push_back(b);
            Card c("Heart", "8", 8);
            cardDeck.push_back(c);
            Card d("Club", "8", 8);
            cardDeck.push_back(d);
        } else if (i / 4 + 1 == 9) {
            Card a("Diamond", "9", 9);
            cardDeck.push_back(a);
            Card b("Spade", "9", 9);
            cardDeck.push_back(b);
            Card c("Heart", "9", 9);
            cardDeck.push_back(c);
            Card d("Club", "9", 9);
            cardDeck.push_back(d);
        } else if (i / 4 + 1 == 10) {
            Card a("Diamond", "10", 10);
            cardDeck.push_back(a);
            Card b("Spade", "10", 10);
            cardDeck.push_back(b);
            Card c("Heart", "10", 10);
            cardDeck.push_back(c);
            Card d("Club", "10", 10);
            cardDeck.push_back(d);
        } else if (i / 4 + 1 == 11) {
            Card a("Diamond", "Jack", 10);
            cardDeck.push_back(a);
            Card b("Spade", "Jack", 10);
            cardDeck.push_back(b);
            Card c("Heart", "Jack", 10);
            cardDeck.push_back(c);
            Card d("Club", "Jack", 10);
            cardDeck.push_back(d);
        } else if (i / 4 + 1 == 12) {
            Card a("Diamond", "Queen", 10);
            cardDeck.push_back(a);
            Card b("Spade", "Queen", 10);
            cardDeck.push_back(b);
            Card c("Heart", "Queen", 10);
            cardDeck.push_back(c);
            Card d("Club", "Queen", 10);
            cardDeck.push_back(d);
        } else if (i / 4 + 1 == 13) {
            Card a("Diamond", "King", 10);
            cardDeck.push_back(a);
            Card b("Spade", "King", 10);
            cardDeck.push_back(b);
            Card c("Heart", "King", 10);
            cardDeck.push_back(c);
            Card d("Club", "King", 10);
            cardDeck.push_back(d);
        }
    }
    shuffle();
}

// Shuffle cards in deck
void Deck::shuffle() {
    srand(time(0));
    for (int i = 0; i < 50; i++) {
        int pos1 = rand() % 52;
        int pos2 = rand() % 52;
        Card storage(cardDeck[pos1].getSuit(), cardDeck[pos1].getType(), cardDeck[pos1].getValue());
        cardDeck[pos1].setSuit(cardDeck[pos2].getSuit());
        cardDeck[pos1].setType(cardDeck[pos2].getType());
        cardDeck[pos1].setValue(cardDeck[pos2].getValue());
        cardDeck[pos2].setSuit(storage.getSuit());
        cardDeck[pos2].setType(storage.getType());
        cardDeck[pos2].setValue(storage.getValue());
    }
}

// Prints deck for testing purposes - unused in actual game
void Deck::printDeck() {
    for (int i = 0; i < cardDeck.size(); i++)
        cardDeck[i].printCard();
    cout << "Current size of deck: " << cardDeck.size() << "\n";
}

// Removes card from deck
Card Deck::popDeck() {
    Card popCard(cardDeck[cardDeck.size() - 1].getSuit(), cardDeck[cardDeck.size() - 1].getType(), cardDeck[cardDeck.size() - 1].getValue());
    cardDeck.pop_back();
    return popCard;
}

// Getter functions for various private variables
string Deck::getNextCardType() {
    return cardDeck[cardDeck.size() - 1].getType();
}

int Deck::getNextCardValue() {
    return cardDeck[cardDeck.size() - 1].getValue();
}

int Deck::getCardDeckSize() {
    return cardDeck.size();
}