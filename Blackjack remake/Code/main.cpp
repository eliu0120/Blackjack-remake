#include <iostream>
#include <string>
#include <vector>
#include "card.hpp"
#include "deck.hpp"
#include "player.hpp"
#include "AI.hpp"
#include "game.hpp"
using namespace std;

int main() {
    // Variables for function
    bool isRunning = true, inGame = true;
    char response1 = 0;
    int response2 = 0;

    // Allows .exe to run until user chooses to quit
    while (isRunning) {
        cout << "Blackjack!!!\n\n\n\n\n1) Play\n2) Quit\n";
        cin >> response1;

        // Play option
        if (response1 == '1') {
            system("cls");
            inGame = true;
            cout << "Instructions:\nTry to beat your opponents.\nEveryone starts with two cards in their hand - each card has a certain value\nYou can add cards by hitting, or choose to hold your current hand\nIf you are the first player to have a hand value is 21, you win\nIf your hand value is > 21, you lose\nIf no one has a hand value of 21, person with hand value closes to 21 wins\nKeep playing until all cards (52) from deck are used\nPlayer who wins the most rounds win the game\n\nInput any key to continue\n";
            cin >> response1;
            system("cls");
            cout << "Game modes:\n1) 1 player vs. AI\n2) 2 players\n3) Custom players vs. AI\n4) Custom players\n5) Return to title screen\n";
            cin >> response1;

            // 1 Player vs. AI game
            if (response1 == '1') {
                while (inGame) {
                    system("cls");
                    cout << "1 Player vs. AI\n";
                    Game::gameWithAI(1);
                    cout << "Play again?\n1) Yes\n2) No\n";
                    cin >> response1;
                    if (response1 != '1') {
                        inGame = false;
                        system("cls");
                    }
                }
            
            // 2 Player game
            } else if (response1 == '2') {
                while (inGame) {
                    system("cls");
                    cout << "2 Player game\n";
                    Game::gameNoAI(2);
                    cout << "Play again?\n1) Yes\n2) No\n";
                    cin >> response1;
                    if (response1 != '1') {
                        inGame = false;
                        system("cls");
                    }
                }

            // Custom players vs. AI game           
            } else if (response1 == '3') {
                while (inGame) {
                    system("cls");
                    cout << "How many players would like to play (minimum: 2, maximum: 12)?\n";
                    cin >> response2;
                    if (response2 > 1 && response2 < 13) {
                        cout << "\nvs. AI game with " << response2 << " players\n";
                        Game::gameWithAI(response2);
                    } else
                        cout << "\nError\n";
                    cout << "Play again?\n1) Yes\n2) No\n";
                    cin >> response1;
                    if (response1 != '1') {
                        inGame = false;
                        system("cls");
                    }
                }

            // Custom players
            } else if (response1 == '4') {
                while (inGame) {
                    system("cls");
                    cout << "How many players would like to play (minimum: 2, maximum: 13)?\n";
                    cin >> response2;
                    if (response2 > 1 && response2 < 14) {
                        cout << "\nvs. Normal game with " << response2 << " players\n";
                        Game::gameNoAI(response2);
                    } else
                        cout << "\nError\n";
                    cout << "Play again?\n1) Yes\n2) No\n";
                    cin >> response1;
                    if (response1 != '1') {
                        inGame = false;
                        system("cls");
                    }
                }

            // Return to player menu
            } else
                system("cls");
        
        // Quit game
        } else 
            isRunning = false;
    }

    return 1;

    /* TEST CODE
    Deck d;
    AI a(d);
    a.printRealHand();
    cout << d.getNextCardValue() << "\n\n";
    a.makeBestChoice(d);
    a.printRealHand();
    cout << d.getNextCardValue() << "\n";

    Player p(d);
    cout << p.getIsHolding() << "\n";
    cout << p.getIsPlaying() << "\n";
    cout << "\n";
    p.printRealHand();
    p.checkPlayer();
    while (p.getIsPlaying()) {
        p.hit(d);
        p.printRealHand();
        p.checkPlayer();
    }
    cout << "\n" << p.getIsPlaying() << "\n";
    p.hold();
    cout << p.getIsHolding() << "\n";
    p.incrementScore();
    cout << p.getScore() << "\n";
    p.resetPlayer(d);
    cout << "\n";
    p.printRealHand();

    Card test("spade", "8", 8);
    cout << test.getSuit() << "\n";
    cout << test.getType() << "\n";
    cout << test.getValue() << "\n";
    test.setSuit("diamond");
    test.setType("9");
    test.setValue(9);
    test.printCard();

    cout << "\n";
    vector<Card> c;
    c.push_back(D.popDeck());
    c.push_back(D.popDeck());
    c.push_back(D.popDeck());
    for (int i = 0; i < c.size(); i++)
        c[i].printCard();
    return 1;

    p.hit(d);
    p.hit(d);
    p.hit(d);
    p.printRealHand();
    cout << "\n";
    p.printDisplayedHand();
    cout << "\n";
    d.printDeck();
    */
}