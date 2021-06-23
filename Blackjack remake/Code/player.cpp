#include <iostream>
#include <vector>
#include <string>
#include "card.hpp"
#include "deck.hpp"
#include "player.hpp"
using namespace std;

// Default constructor
Player::Player() {
    isHolding = false;
    isPlaying = true;
    realValue = 0;
    displayedValue = 0;
    score = 0;
}

// Creates player profile
Player::Player(Deck &d) {
    score = 0;
    resetPlayer(d);
}

// Reset player profile for each round
void Player::resetPlayer(Deck &d) {
    while (hand.size() > 0)
        hand.pop_back();
    isHolding = false;
    isPlaying = true;
    realValue = 0;
    hit(d);
    hit(d);
    displayedValue = hand[0].getValue() + hand[1].getValue();
}

// Hit command
void Player::hit(Deck &d) {
    hand.push_back(d.popDeck());
    realValue += hand[hand.size() - 1].getValue();
}

// Hold command
void Player::hold() {
    isHolding = true;
}

// Print hand visible to other players
void Player::printDisplayedHand() {
    hand[0].printCard();
    hand[1].printCard();
    for (int i = 2; i < hand.size(); i++)
        cout << "Card #" << i + 1  << "\n";
    cout << "Opponent hand value: " << displayedValue;
    if (displayedValue != realValue)
        cout << " + ?\n";
    else
        cout << "\n";
}

// Check if player has a winning/eliminating hand
void Player::checkPlayer() {
    if (realValue > 20) {
        int x = isAce();
        if (x < 0 || realValue == 21)
            isPlaying = false;
        else {
            hand[x].setValue(1);
            realValue -= 10;
        }
    }
}

// Switch Ace card value from 11 to 1
int Player::isAce() {
    for (int i = 0; i < hand.size(); i++)
        if (hand[i].getType().compare("Ace") == 0 && hand[i].getValue() == 11)
            return i;
    return -1;
}

// Print player hand
void Player::printRealHand() {
    for (int i = 0; i < hand.size(); i++)
        hand[i].printCard();
    cout << "Player hand value: " << realValue << "\n";
}

// Getters and setters for various private variables
bool Player::getIsHolding() {
    return isHolding;
}

bool Player::getIsPlaying() {
    return isPlaying;
}

int Player::getRealValue() {
    return realValue;
}

void Player::setRealValue(int inputRealValue) {
    realValue = inputRealValue;
}

int Player::getDisplayedValue() {
    return displayedValue;
}

int Player::getScore() {
    return score;
}

void Player::incrementScore() {
    score++;
}

vector<Card> Player::getHand() {
    return hand;
}

// Match player object in Player vector of game.cpp to its AI object
void Player::matchAI(Player a) {
    hand = a.getHand();
    realValue = a.getRealValue();
    displayedValue = a.getDisplayedValue();
}