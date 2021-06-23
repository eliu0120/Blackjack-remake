#include <iostream>
#include <vector>
#include "card.hpp"
#include "deck.hpp"
#include "player.hpp"
#include "AI.hpp"
#include "game.hpp"
using namespace std;

// Stores all players playing the game
vector<Player> Game::players;

// Game with AI functions
void Game::gameWithAI(int playerSize) {

    // Create/reset conditions for game
    Deck d;
    Game::resetPlayers();
    for (int i = 0; i < playerSize; i++) {
        Player p(d);
        Game::players.push_back(p);
    }
    AI a(d);
    Game::players.push_back(a);

    /*  TEST CODE 
    Game::players[players.size() - 1].setRealValue(22);
    for (int i = 0; i < Game::players.size(); i++)
        Game::players[i].printRealHand();
    cout << Game::checkRoundVictory() << "\n\n";
    Game::determineWinner();
    for (int i = 0; i < Game::players.size(); i++)
        cout << players[i].getScore() << "\n";
    */
    
    // Game sequnce
    while (d.getCardDeckSize() > 0) {
        // Check if any player has a score of 21
        int roundVictory = Game::checkRoundVictory();

        // Allows each player to have their turn
        for (int i = 0; i < Game::players.size() - 1; i++) 
            if (roundVictory == 0) {
                Game::round(i, d);
                roundVictory = Game::checkRoundVictory();
            }

        // AI turn
        if (roundVictory == 0) {
            system("cls");
            char response = 0;
            cout << "Player " << Game::players.size() << "'s (AI) turn.\n\n";
            a.checkPlayer();
            a.makeBestChoice(d);
            Game::players[players.size() - 1].matchAI(a);
            cout << "\nThis concludes Player " << Game::players.size() << "'s (AI) turn. Input anything to continue.\n";
            cin >> response;
        }

        // Determines winner of round
        Game::determineWinner();

        // Resets all player hands if enough cards in deck remaining
        if (Game::players.size() * 2 <= d.getCardDeckSize()) {
            for (int i = 0; i < Game::players.size(); i++) 
                Game::players[i].resetPlayer(d);
            Game::players[players.size() - 1].checkPlayer();
            a.matchPlayer(Game::players[players.size() - 1]);
        } else // If not enough cards in deck remaining, remove remaining cards
            while (d.getCardDeckSize() > 0)
                d.popDeck();
    }

    // Determines winner of game
    Game::gameOver();
}

// Game without AI
void Game::gameNoAI(int playerSize) {

    // Create/reset conditions for game
    Deck d;
    Game::resetPlayers();
    for (int i = 0; i < playerSize; i++) {
        Player p(d);
        Game::players.push_back(p);
    }

    /*  TEST CODE
    Game::players[players.size() - 1].setRealValue(21);
    for (int i = 0; i < Game::players.size(); i++)
        Game::players[i].printRealHand();
    cout << Game::checkRoundVictory() << "\n\n";
    Game::determineWinner();
    for (int i = 0; i < Game::players.size(); i++)
        cout << players[i].getScore() << "\n";
    */
    
    // Game sequnce
    while (d.getCardDeckSize() > 0) {
        // Check if any player has a score of 21
        int roundVictory = Game::checkRoundVictory();

        // Allows each player to have their turn
        for (int i = 0; i < Game::players.size(); i++) 
            if (roundVictory == 0) {
                Game::round(i, d);
                roundVictory = Game::checkRoundVictory();
            } 

        // Determines winner of round
        Game::determineWinner();

        // Resets all player hands if enough cards in deck remaining
        if (Game::players.size() * 2 <= d.getCardDeckSize())
            for (int i = 0; i < Game::players.size(); i++)
                Game::players[i].resetPlayer(d);
        else // If not enough cards in deck remaining, remove remaining cards
            while (d.getCardDeckSize() > 0)
                d.popDeck();
    }

    // Determines winner of game
    Game::gameOver();
}

// Function for each player turn
void Game::round(int playerNumber, Deck &d) {
    system("cls");

    // Check to see if player has 2 ace cards
    Game::players[playerNumber].checkPlayer();

    // Allows player to see cards they have + opponent cards visible to them
    cout << "Player " << playerNumber + 1 << "'s turn:\n\n";
    for (int i = 0; i < Game::players.size(); i++) {
        cout << "Player " << i + 1 << "'s hand:\n";
        if (i == playerNumber)
            Game::players[i].printRealHand();
        else
            Game::players[i].printDisplayedHand();
        cout << "\n";
    }

    // Allows players to choose hit or hold (if possible)
    char response = 0;
    while (!Game::players[playerNumber].getIsHolding() && Game::players[playerNumber].getIsPlaying())
        if (d.getCardDeckSize() > 0) {
            cout << "Cards remaining: " << d.getCardDeckSize() << "\nMake your choice:\n1) Hit\n2) Hold\n";
            cin >> response;
            if (response == '1') {
                cout << "\nHit\n";
                Game::players[playerNumber].hit(d);
                Game::players[playerNumber].checkPlayer();
                Game::players[playerNumber].printRealHand();
            } else {
                cout << "\nHold\n";
                Game::players[playerNumber].hold();
            }
        } else {
            cout << "Card deck is out of cards, holding!\n";
            Game::players[playerNumber].hold();
        }

    // Concludes player's turn
    cout << "\nThis concludes player " << playerNumber + 1 << "'s turn. Input anything to continue\n";
    cin >> response;
}

// Function to check if any player has a score of 21
int Game::checkRoundVictory() {
    for (int i = 0; i < Game::players.size(); i++) {
        Game::players[i].checkPlayer();
        if (!Game::players[i].getIsPlaying()) 
            if (Game::players[i].getRealValue() == 21)
                return i + 1;
    }
    return 0;
}

// Function to determine winner of each round
void Game::determineWinner() {
    system("cls");
    int winningPlayer = 0;

    // If a player has score of 21
    if (Game::checkRoundVictory() != 0) {
        winningPlayer = Game::checkRoundVictory() - 1;
        Game::players[winningPlayer].incrementScore();        
    } else { // If nobody has a score of 21
        while (!Game::players[winningPlayer].getIsPlaying() && winningPlayer < Game::players.size())
            winningPlayer++;
        for (int i = 0; i < Game::players.size(); i++)
            if (Game::players[i].getRealValue() > Game::players[winningPlayer].getRealValue() && Game::players[i].getIsPlaying())
                winningPlayer = i;
        if (winningPlayer < Game::players.size())
            Game::players[winningPlayer].incrementScore();
    }

    // Displays winner of round (If there is one)
    if (winningPlayer < Game::players.size())
        cout << "Player " << winningPlayer + 1 << " wins the round!\n"; 
    else
        cout << "No winners this round.\n";

    // Displays all players' hands
    for (int i = 0; i < Game::players.size(); i++) {
        cout << "\nPlayer " << i + 1 << "'s hand:\n";
        Game::players[i].printRealHand();
    }

    // Displays each players' score
    cout << "\nScores:\n";
    for (int i = 0; i < Game::players.size(); i++) 
        cout << "\nPlayer " << i + 1 << "'s score: " << Game::players[i].getScore();
    cout << "\n\nInput any response to contine.\n";
    char response = 0;
    cin >> response;
}

// End game function
void Game::gameOver() {
    system("cls");
    cout << "Game finished! Rankings: \n";

    // Rank player scores
    vector<int> scores;
    vector<int> rankings;
    for (int i = 0; i < Game::players.size(); i++) {
        scores.push_back(Game::players[i].getScore());
        rankings.push_back(i + 1);
    }
    int storage;
    for (int i = scores.size() - 1; i > 0; i--)
        for (int j = 0; j < i; j++) 
            if (scores[j] < scores[j + 1]) {
                storage = scores[j];
                scores[j] = scores[j + 1];
                scores[j + 1] = storage;
                storage = rankings[j];
                rankings[j] = rankings[j + 1];
                rankings[j + 1] = storage;
            } 

    // Display player scores
    for (int i = 0; i < scores.size(); i++)
        cout << "#" << i + 1 << ": Player " << rankings[i] << ": Score: " << scores[i] << "\n";
    char response;
    cout << "\nInput anything to continue.\n";
    cin >> response;
    system("cls");
}

// Reset player vector
void Game::resetPlayers() {
    while (Game::players.size() > 0)
        Game::players.pop_back();
}