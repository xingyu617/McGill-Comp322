/*
 * main.cpp
 *
 *  Created on: 2020?3?11?
 *      Author: 18796
 */
#include"blackjack.h"
int main ()
{
cout << "\tWelcome to the Comp322 Blackjack game!" << endl << endl ;
BlackJackGame game;
// The main loop of the game
bool playAgain = true ;
char answer = 'y' ;
while (playAgain)
{
game.play();
// Check whether the player would like to play another round
cout << "Would you like another round? (y/n): " ;
cin >> answer;
cout << endl << endl ;
playAgain = (answer == 'y' ? true : false );
}
cout << "Gave over!" ;
return 0 ;
}


