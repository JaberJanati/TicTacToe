#include<iostream>
#include<cstring>
#include<cstdlib>
#include "TicTacToe.h"
using namespace std;


TicTacToe::TicTacToe()      //constructor populates grid with empty values at start of game
{
    srand(time(0));        //creates random interval for computer's choice
    cout << "Welcome to the game of TicTacToe\n" << endl;
    for(int i = 0; i < 3; i++)   //populates array and outputs in form of a board
    {
        grid[i][0] = '-';
        grid[i][1] = '-';
        grid[i][2] = '-';
        cout << "|" << grid[i][0] << " |" << grid[i][1] << " |" << grid[i][2] << " |" << endl; //displays grid to player
        cout << "----------" << endl;
    }

}

void TicTacToe::PlayerTurn(char letter)
{
    if(isWinner() == false && isTie() == false) //checks if there is no winner or tie
    {
        cout << "Player's Turn: \n" << endl;
        cout << "Enter a valid coordinate to place an " << letter << endl;
        cin >> pos_x;
        cin >> pos_y;

        while(isValidPosition() == false || isValidChoice(pos_x, pos_y) == false) //checks if position enter is vaild in scope and is free
        {
           	cout << "Not a valid position, please enter new X and Y coordinates: " << endl;
           	cin >> pos_x;
           	cin >> pos_y;
        }

        int x = pos_x - '0';  //changes the charcter values to integers based on ASCII position
        int y = pos_y - '0';
        grid[x][y] = letter;	//places letter in appropriate position
        cout << endl;
        ShowBoard();		//displays grid
	}
	else
		exit(1); //exits program when a winner or tie is found
}

bool TicTacToe::isValidChoice(char coord_x, char coord_y)
{
    if(isdigit(coord_y) && isdigit(coord_x)) 		//checks if the position entered is a number
    {
        if((atoi(&pos_y) >= 0 && atoi(&pos_y) < 3) && (atoi(&coord_x) <3 && atoi(&coord_x) >=0)) //checks if the number is between zero and three
        {
            return true;
        }
    }
    return false;
}

void TicTacToe::ShowBoard()
{
    for(int i = 0; i < 3; i++)  //diplays the updated version of the board
    {
        cout << "|" << grid[i][0] << " |" << grid[i][1] << " |" << grid[i][2] << " |" << endl; //displays grid to player
        cout << "----------" << endl;
    }
}
void TicTacToe::ComputerTurn(char letter)
{
    int x, y;
    if(isWinner()== false && isTie() == false)  // checks while there is no winner or a tie
    {
	
        cout << "\nComputer's Turn: \n" << endl;
        if(attack(letter) == false)			//checks there is no way to win 
	{
		if(defend(letter, x, y) == true)	//checks if human is about to win
		{
			grid[x][y] = letter;
		}	
	}	
	
        ShowBoard();  			//board is displayed	
        cout << endl;
        cout << endl;
    }
	else
	exit(1);	//exits program if there is a winner or a tie

}


bool TicTacToe::isValidPosition()
{
    int x =  pos_x - '0';   //assigns x the ASCII number value 
    int y = pos_y - '0';

    if(grid[x][y] == '-') //checks if the position entered is empty( not an X or O)
    {
        return true;
    }
    else
    {
        return false;
    }
}

bool TicTacToe::isWinner()
{
    for(int i = 0; i < 3; i++)
    {
        if(grid[i][0] == 'X' && grid[i][1] == 'X' && grid[i][2] == 'X')//checks for a match in the row
        {
            cout << "Player X wins, Player O loses" << endl;
            return true;
        }
        else if(grid[i][0] == 'O' && grid[i][1] == 'O' && grid[i][2] == 'O') //checks for a match in the rows
        {
            cout << "Player O wins, Player X loses" << endl;
            return true;
        }
        else if(grid[0][i] == 'X' && grid[1][i] == 'X' && grid[2][i] == 'X')// checks for a match of X in the columns
        {
            cout << "Player X wins, Player O loses " << endl;
            return true;
        }
        else if(grid[0][i] == 'O' && grid[1][i] == 'O' && grid[2][i] == 'O') // checks for a match in the column of O
        {
            cout << "Player O wins, Player X loses" << endl;
            return true;
        }

    }
    if(grid[0][0] == 'X' && grid[1][1] == 'X' && grid[2][2] == 'X') //checks diagonally for a match
    {
        cout << "Player X wins, Player O loses" << endl;
        return true;
    }
    else if(grid[0][0] == 'O' && grid[1][1] == 'O' && grid[2][2] == 'O') //checks diagonally for a match for O
    {
        cout << "Player O wins, Player X loses" << endl;
        return true;
    }
    else if(grid[0][2] == 'X' && grid[1][1] == 'X' && grid[2][0] == 'X') // checks diagonally from the right for a match
    {
        cout << "Player X wins, Player O loses" << endl;
	return true;
    }
    else if(grid[0][2] == 'O' && grid[1][1] == 'O' && grid[2][0] == 'O') // checks daigonally from the right for a match
    {
        cout << "Player O wins, Player X loses" << endl;
	return true;
    }
    else
        return false;

}

bool TicTacToe::defend(char comp_letter, int &x_coord, int &y_coord)
{
    
    char opponent_letter;  		//stores opponents letter
    if(comp_letter == 'X')
    {
        opponent_letter = 'O';
    }
    else
        opponent_letter = 'X';


    for(int i = 0; i < 3; i++)
    {
        if(grid[i][0] == opponent_letter && grid[i][1] == opponent_letter && grid[i][2] == '-') // checks first two rows
        {
            x_coord = i;
            y_coord = 2;
            return true;
        }
        else if(grid[i][1] == opponent_letter && grid[i][2] == opponent_letter && grid[i][0] == '-') // checks last two rows
        {
            x_coord = i;
            y_coord = 0;
            return true;
        }
        else if(grid[0][i] == opponent_letter && grid[1][i]== opponent_letter && grid[2][i] == '-') // checks first two columns
        {
            x_coord = 2;
            y_coord = i;
            return true;
        }
        else if(grid[1][i] == opponent_letter && grid[2][i] == opponent_letter && grid[0][i] == '-') // checks last two colums
        {
            x_coord = 0;
            y_coord = i;
            return true;
        }
        else if(grid[0][i] == opponent_letter && grid[2][i] == opponent_letter && grid[1][i] == '-') // checks middle row
        {
            x_coord = 1;
            y_coord = i;
            return true;
        }
        else if(grid[i][0] == opponent_letter && grid[i][2] == opponent_letter && grid[i][1] == '-')  //checks the right half of the columns for a match
        {
            x_coord = i;
            y_coord = 1;
            return true;
        }

    }
    if(grid[1][1] == opponent_letter && grid[0][0] == opponent_letter && grid[2][2] == '-') //checks if opponent has two in a row in a diagonal
    {
        x_coord = 2;
        y_coord = 2;
        return true;
    }
    else if(grid[1][1]== opponent_letter && grid[2][2] == opponent_letter && grid[0][0] == '-')
    {
        x_coord = 0;
        y_coord = 0;
        return true;
    }
    else if(grid[1][1] == opponent_letter && grid[0][2] == opponent_letter && grid[2][0] == '-') //checks if opponent is about to win diagonally
    {
        x_coord = 2;
        y_coord = 0;
        return true;
    }
    else if(grid[1][1] == opponent_letter && grid[2][0] == opponent_letter && grid[0][2] == '-')
    {
        x_coord = 0;
        y_coord = 2;
        return true;
    }
    else
	random_position(comp_letter);	// if opponent is not about to win then a random position is chosen
        return false;

}

void TicTacToe::random_position(char comp_letter)
{
    int x, y, a ;
    int count = 0;
    int arr_x[count+1];
    int arr_y[count+1];

    for(int i = 0; i < 3; i ++)
    {
        for(int j = 0; j < 3; j++)
        {
            if(grid[i][j] == '-')   //checks for empty spaces in grid
            {
                arr_x[count] = i;	//puts x coordinates in array x
                arr_y[count] = j;	//puts valid y coordinates in array y
                count++;
            }
        }
    }
    a = rand()%count;   // random number is chosen based on the number of valid spaces
    x = arr_x[a];	// x and y are given empty postion and then is replaced by the letter
    y = arr_y[a];	
    grid[x][y] = comp_letter;
}

bool TicTacToe::attack(char comp_letter)
{
    if(grid[1][1] == '-')	//checks if the middle position is taken if not it takes it
    {
        grid[1][1] = comp_letter;
        return true;
    }
    else if(grid[1][1] == comp_letter && grid[0][0] == comp_letter && grid[2][2] == '-') //checks for a way to win diagonally
    {
        grid[2][2] = comp_letter;
        return true;
    }
    else if(grid[1][1] == comp_letter && grid[0][2] == comp_letter && grid[2][0] == '-')
    {
        grid[2][0] = comp_letter;
        return true;
    }
    else if(grid[0][2] == comp_letter && grid[0][0] == comp_letter && grid[1][1] == '-')
    {
        grid[1][1] = comp_letter;
        return true;

    }
    for(int i = 0; i < 3; i++)
    {
        if(grid[i][0] == comp_letter && grid[i][1]== comp_letter && grid[i][2] == '-') //checks first two rows for a possible win
        {
            grid[i][2] = comp_letter;
            return true;
        }
        else if(grid[i][1] == comp_letter && grid[i][2] == comp_letter && grid[i][0] == '-') //checks second half of row if a win is possible
        {
            grid[i][0] = comp_letter;
            return true;
        }
        else if(grid[0][i] == comp_letter && grid[1][i] == comp_letter && grid[2][i] == '-') //checks if first half of the column has a possible win
        {
            grid[2][i] = comp_letter;
            return true;
        }
        else if(grid[1][i] == comp_letter && grid[2][i] == comp_letter && grid[0][i] == '-') // checks if second half of column has a possible win
        {
            grid[0][i] = comp_letter;
            return true;
        }
        else if(grid[i][0] == comp_letter && grid[i][2] == comp_letter && grid[i][1] == '-') // checks middle column for a win
        {
            grid[i][1] = comp_letter;
            return true;
        }
        else if(grid[0][i] == comp_letter && grid[2][i] == comp_letter && grid[1][i] == '-') // checks middle row for a win
        {
            grid[1][i] = comp_letter;
            return true;
        }
    }
    return false;

}
bool TicTacToe::isTie()
{
	int count = 0;
	for(int i = 0; i < 3; i++)
    {
        for(int j = 0; j < 3; j++)
        {
            if(grid[i][j] != '-') // checks for an empty spot in the grid
            {
                count++; // increaments if spot was taken
            }
        }
    }

	if(count == 9) // if grid is completely full then it is a tie
	{
		cout << "It is a Tie" << endl;
		return true;
	}
	else
		return false;
}
