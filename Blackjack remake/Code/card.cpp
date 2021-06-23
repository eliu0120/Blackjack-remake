#include <iostream>
#include <string>
#include "card.hpp"
using namespace std;

// Default constructor
Card::Card() {
    suit;
    type;
    value;
}

// Create card
Card::Card(string toSuit, string toType, int toValue) {
    suit = toSuit;
    type = toType;
    value = toValue;
}

// Getters and setters for various private variables
string Card::getSuit() {
    return suit;
}

string Card::getType() {
    return type;
}

int Card::getValue() {
    return value;
}

void Card::setSuit(string toSuit) {
    suit = toSuit;
}

void Card::setType(string toType) {
    type = toType;
}

void Card::setValue(int toValue) {
    value = toValue;
}

// Print card
void Card::printCard() {
    cout << suit << " " << type << "; Value = " << value << "\n";
}