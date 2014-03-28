//Title: Tic-Tac-Toe Program
//Author: Jaber
//Created on: Feburary 10, 2014
// Description: Program generates a tic tac toe board and allows playing between player and computer
//player has the choice of going first and being 'X' or goind second 'O'
//Purpose: Uses Classes to show the ability of encapsulation
//Built with: TicTacToe.h and TicTacToe.cpp

#include<iostream>
#include<string>
#include<cstdlib>
#include "TicTacToe.h"
#include "TicTacToe.cpp"
using namespace std;


int main()
{
    TicTacToe game;                                         //object of type TicTacToe
    char choice;	                                            //holds the players choice y or n

    cout << "Would you like to make the first move? (y/n)" << endl;
    cin >> choice;

    while((choice != 'y') && (choice != 'n'))                         //checks to see who goes first
    {
	cout << "Invalid enter either 'y' or 'n' " << endl;
	cin >> choice;
    }

    switch(choice)                                                   //determines whether the player is X or O
    {
	case 'y':
	    cout << "\nPlayer is 'X' and Computer is 'O'\n" << endl;
		while(game.isWinner() == false)    //continue playing until a tie or winner is found
		{
			if(game.isTie() == false)
			{
				game.PlayerTurn('X');
				game.ComputerTurn('O');
			}
			else
				exit(1);
		}
		break;
	case 'n':
	    cout << "\nPlayer has 'O' and Computer has 'X'\n" << endl;
		while(game.isWinner() == false)
		{
			if(game.isTie() == false)
			{
				game.ComputerTurn('X');
				game.PlayerTurn('O');
			}
			else
				exit(1);
		}
		break;

	}

	return 0;

}
