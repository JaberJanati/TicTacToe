#ifndef TICTACTOE_H
#define TICTACTOE_H

class TicTacToe
{
public:
    TicTacToe();
    void PlayerTurn(char letter);                           //Function simulates the players turn
    void ComputerTurn(char letter);                      //function simulates computers turn
    bool isValidChoice(char coord_x, char coord_y);         //checks if the number entered by player is valid
    bool isValidPosition();                                 //checks if the position is empty or not
    bool isWinner();                                        //checks if someone won
    void ShowBoard();                                       //displays the gameboard
    bool isTie();                                           //checks if there is a tie
    bool defend(char comp_letter, int &x_coord, int &y_coord);    //computer defends from human winning
    bool attack(char comp_letter);				// computer checks if it has a possible iwin
    void random_position(char comp_letter);			// random position is chosen for computer

private:
    char grid[3][3];                                       //array that holds the tictactoe board
    char pos_x;                                             //x coordintate that player enters
    char pos_y;                                             //y coordinate that player enters
};

#endif // TICTACTOE_H
