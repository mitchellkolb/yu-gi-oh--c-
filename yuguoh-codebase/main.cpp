//
//  main.cpp
//  PA4-122-mk
//
//  Created by Mitchell Kolb on 6/6/20.
//  Copyright © 2020 Mitchell Kolb. All rights reserved.
//

#include "Queue.h"
#include "Stack.h"

#include <iostream>
#include <string>
#include <fstream>
#include <cstdlib>
#include <ctime>
using namespace std;

int main()
{
    //Starts the menu of the game
    int x = 0;
    menu(x);


    //Initializing Queue
    Queue atk_p1, def_p1, atk_p2, def_p2;


    //Initializing Stack
    Stack deck1, deck2;


    //Useful variables
    string name, type, temp;
    int attack, defense;
    int p1_life = 8000; 
    int p2_life = 8000;


    //Player structs
    struct Player
    {
        string name;
        string type;
        int attack;
        int defense;
    };
    Player p1[5], p2[5];


    //File Input and Output
    ifstream iFile("Yu_Gi_Oh_Card_list.csv");
    

    //Sets the start of the deck picking randomly
    srand((unsigned int)time(0));
    x += (rand()%90 + 1);
    for(int i = 0; i < x; i++)
    {
        getline(iFile, name);
    }
    //Reads the actual line and on to make a deck 30 big
    
    //Deck for player 1
    for(int i = 0; i < 30; i++)
    {
        //Gets name 
        getline(iFile, name, ',');
        //Gets type
        getline(iFile, type, ',');
        //Gets ATK
        getline(iFile, temp, ',');
        attack = stoi(temp);
        //Gets DEF
        getline(iFile, temp);
        defense = stoi(temp);
        //Puts this info into the Stack
        deck1.push(name,type,attack,defense);
    }

    //Deck for player 2
    for(int i = 0; i < 30; i++)
    {
        //Gets name 
        getline(iFile, name, ',');
        //Gets type
        getline(iFile, type, ',');
        //Gets ATK
        getline(iFile, temp, ',');
        attack = stoi(temp);
        //Gets DEF
        getline(iFile, temp);
        defense = stoi(temp);
        //Puts this info into the Stack
        deck2.push(name,type,attack,defense);
    }


    //Gives each players hand 5 cards from their deck
    for(int i = 0; i < 5; i++)
    {
        //Player 1 Hand
        deck1.pop(name,type,attack,defense);
        p1[i].name = name;
        p1[i].type = type;
        p1[i].attack = attack;
        p1[i].defense = defense;
        //Player 2 Hand
        deck2.pop(name,type,attack,defense);
        p2[i].name = name;
        p2[i].type = type;
        p2[i].attack = attack;
        p2[i].defense = defense;
    }

    //Everything is initalized and made THE GAME FINALLY STARTS...
    //Coin toss to see who goes first
    x = (rand()%2 + 1);
    int choice, pick[5], new_card[5], stopper;
    int deck = 0;
    int main_stopper = 0;

    while(main_stopper == 0)
    {

        stopper = 0;
        while(stopper  <= 1)
        {
            if(x == 1)
            {
                //Player 1 goes
                system("clear");
                cout << "Player 1 starts their turn\n";
                cout << "Press Enter to Continue\n";
                getline(cin, type);
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                //Prints the players hand to show what they have
                cout << "Your hand contains:\n-- Name of Card -- Attack Points -- Defense Points --\n";
                for(int i = 0; i < 5; i++)
                {
                    cout << i+1 << ".\t" << p1[i].name << "  " << p1[i].attack << "  " << p1[i].defense << endl;
                }
                cout << "\nWhat card would you like to put into the ATTACK queue?\n";
                cin >> choice;
                new_card[0] = (choice - 1);
                atk_p1.enqueue(p1[(choice - 1)].name,p1[(choice - 1)].type,p1[(choice - 1)].attack,p1[(choice - 1)].defense);
                cout << "\nWhat card would you like to put into the DEFENSE queue?\n";
                cin >> choice;
                new_card[1] = (choice - 1);
                def_p1.enqueue(p1[(choice - 1)].name,p1[(choice - 1)].type,p1[(choice - 1)].attack,p1[(choice - 1)].defense);
                cout << "\nWhich mode do you want to activate for battle?\n1. ATTACK\n2. DEFENSE\n";
                cin >> pick[0];
                if(stopper == 0)
                {
                    stopper = 1;
                    x = 2;
                }
                else
                {
                    stopper = 2;
                    x = 2;
                }
            }
            else
            {
                //Player 2 goes
                system("clear");
                cout << "Player 2 starts their turn\n";
                cout << "Press Enter to Continue\n";
                getline(cin, type);
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                //Prints the players hand to show what they have
                cout << "Your hand contains:\n-- Name of Card -- Attack Points -- Defense Points --\n";
                for(int i = 0; i < 5; i++)
                {
                    cout << i+1 << ".\t" << p2[i].name << "  " << p2[i].attack << "  " << p2[i].defense << endl;
                }
                cout << "\nWhat card would you like to put into the ATTACK queue?\n";
                cin >> choice;
                new_card[2] = (choice - 1);
                atk_p2.enqueue(p2[(choice - 1)].name,p2[(choice - 1)].type,p2[(choice - 1)].attack,p2[(choice - 1)].defense);
                cout << "\nWhat card would you like to put into the DEFENSE queue?\n";
                cin >> choice;
                new_card[3] = (choice - 1);
                def_p2.enqueue(p2[(choice - 1)].name,p2[(choice - 1)].type,p2[(choice - 1)].attack,p2[(choice - 1)].defense);
                cout << "\nWhich mode do you want to activate for battle?\n1. ATTACK\n2. DEFENSE\n";
                cin >> pick[1];
                x = 1;
                if(stopper == 0)
                {
                    stopper = 1;
                    x = 1;
                }
                else
                {
                    stopper = 2;
                    x = 1;
                }
            }
        }
        
        //Compares the cards and determines a winner
        system("clear");
        //One Plays Attack and the other plays Defense
        //Player 1 wins 
        if(pick[0] == 1 && pick[1] == 2)
        {
            atk_p1.dequeue(name,type,attack,defense);
            pick[2] = attack;
            def_p2.dequeue(name,type,attack,defense);
            pick[3] = defense;
            pick[4] = (pick[2] - pick[3]);
            if(pick[4] < 0)
            {
                pick[4] = 0;
            }
            p2_life -= pick[4];
            cout << "Player 1 wins this round.\nPlayer 2 losses " << pick[4] << " life points\n";
            haveIwon(p2_life);
            cout << "Press enter to continue:\n";
            getline(cin, type);
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            
        }
        //Player 2 wins
        if(pick[1] == 1 && pick[0] == 2)
        {
            atk_p2.dequeue(name,type,attack,defense);
            pick[2] = attack;
            def_p1.dequeue(name,type,attack,defense);
            pick[3] = defense;
            pick[4] = (pick[2] - pick[3]);
            if(pick[4] < 0)
            {
                pick[4] = 0;
            }
            p1_life -= pick[4];
            cout << "Player 2 wins this round.\nPlayer 1 losses " << pick[4] << " life points\n";
            haveIwon(p1_life);
            cout << "Press enter to continue:\n";
            getline(cin, type);
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            
        }

        //Both Defense
        if(pick[0] == 2 && pick[0] == pick[1])
        {
            def_p1.dequeue(name,type,attack,defense);
            def_p2.dequeue(name,type,attack,defense);
            cout << "Both players chose defense cards. They are discarded (pun intended).\n";
            cout << "Press enter to continue:\n";
            cin.ignore();
            cin.ignore();            
        }

        //Both Attack
        if(pick[0] == 1 && pick[0] == pick[1])
        {
            //Player 1 attack points is retrieved
            atk_p1.dequeue(name,type,attack,defense);
            pick[2] = attack;
            //Player 2 attack points is retrieved
            atk_p2.dequeue(name,type,attack,defense);
            pick[3] = attack;

            if(pick[2] > pick[3])
            {
                //Player 1 has higher attack 
                pick[4] = (pick[2] - pick[3]);
                cout << "Player 1 has won\nPlayer 2 losses " << pick[4] << " life points\n";
                p2_life -= pick[4];
                haveIwon(p2_life);
                cout << "Press enter to continue:\n";
                getline(cin, type);
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
            
            }
            else if(pick[2] < pick[3])
            {
                //Player 2 has higher attack
                pick[4] = (pick[3] - pick[2]);
                cout << "Player 2 has won\nPlayer 1 losses " << pick[4] << " life points\n";
                p1_life -= pick[4];
                haveIwon(p1_life);
                cout << "Press enter to continue:\n";
                getline(cin, type);
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
            
            }
            else 
            {
                //PLayers have equal attack
                cout << "Both players chose attack and both of their attack points are equal.\nWhat are the odds?\n";
                cout << "Press enter to continue:\n";
                getline(cin, type);
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
    
            }
        }

        //Displays the health of both players
        cout << "\n\nBoth Players Life Points:\nPlayer 1: " << p1_life << "LP\n" << "Player 2: " << p2_life << "LP\n";
        cout << "Press enter to continue:\n";
        getline(cin, type);
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
            

        //Adjusting the hand of both players after the battle has ended. Based on what and where the card they choose.
        //Player 1 Hand
        type = "hello";
        deck1.pop(name,type,attack,defense);
        p1[new_card[0]].name = name;
        p1[new_card[0]].type = type;
        p1[new_card[0]].attack = attack;
        p1[new_card[0]].defense = defense;
        deck1.pop(name,type,attack,defense);
        p1[new_card[1]].name = name;
        p1[new_card[1]].type = type;
        p1[new_card[1]].attack = attack;
        p1[new_card[1]].defense = defense;
        //Player 2 Hand
        deck2.pop(name,type,attack,defense);
        p2[new_card[2]].name = name;
        p2[new_card[2]].type = type;
        p2[new_card[2]].attack = attack;
        p2[new_card[2]].defense = defense;
        deck2.pop(name,type,attack,defense);
        p2[new_card[3]].name = name;
        p2[new_card[3]].type = type;
        p2[new_card[3]].attack = attack;
        p2[new_card[3]].defense = defense;

        //This counts till the deck will be empty. Which is 12.5 turns
        deck++;
        //This is one round and this will loop back until Deck is emtpy or life points of a player reaches <= 0
    
        if(p1_life == -1)
        {
            main_stopper = 2;
        }
        if (p2_life == -1)
        {
            main_stopper = 2;
        }
        if (deck >= 12)
        {
            main_stopper = 3;
        }
    }

    //Theirs a winner!
    if(main_stopper == 3)
    {
        cout << "You ran out of cards in your players deck the game has ended.\n";
    }
    else if(p1_life == -1)
    {
        system("clear");
        cout << "Player 2 had won. Thanks for playing";
    }
    else if (p2_life == -1)
    {
        system("clear");
        cout << "Player 1 had won. Thanks for playing";
    }
    else
        cout << "Something has broken in the results screen. Ending game.";


    //This quits the game.
    return 0;
}




