#include <iostream>
using namespace std;
int main()
{
    int i;
    char board[3][3] = {
        {' ', ' ', ' '},
        {' ', ' ', ' '},
        {' ', ' ', ' '}};
    const char player1 = 'X';
    const char player2 = 'O';
    char current_player = player1;
    int row = -1, column = -1;
    char winner = ' ';
    bool game_over = false;
       cout << "    |     |    \n";
        cout << "  " << board[0][0] << " |  " << board[0][1] << "  |  " << board[0][2] << "\n";
        cout << "____|_____|____\n";
        cout << "    |     |    \n";
        cout << "  " << board[1][0] << " |  " << board[1][1] << "  |  " << board[1][2] << "\n";
        cout << "____|_____|____\n";
        cout << "    |     |    \n";
        cout << "  " << board[2][0] << " |  " << board[2][1] << "  |  " << board[2][2] << "\n";
    for (i = 0; i < 9; i++)
    {


        cout << "Current player is \t" << current_player << "\n";
        while (true)
        {
            if (winner != ' ')
            {
                break;
            }
            cout << "Enter the place (0-2) [Row] and [Column]\t";
            cin >> row >> column;
            if (row < 0 || row > 2 || column < 0 || column > 2)
            {
                cout << "Invalid row column number, Try again!!!" << endl;
            }
            else if (board[row][column] != ' ')
            {
                cout << "The place is full, please try again !!!" << endl;
            }
            else
            {
                break;
            }
            // row = -1;
            // column = -1;
            cin.clear();
            cin.ignore(1000, '\n');
        }

        board[row][column] = current_player;

        cout << "    |     |    \n";
        cout << "  " << board[0][0] << " |  " << board[0][1] << "  |  " << board[0][2] << "\n";
        cout << "____|_____|____\n";
        cout << "    |     |    \n";
        cout << "  " << board[1][0] << " |  " << board[1][1] << "  |  " << board[1][2] << "\n";
        cout << "____|_____|____\n";
        cout << "    |     |    \n";
        cout << "  " << board[2][0] << " |  " << board[2][1] << "  |  " << board[2][2] << "\n";

        // row check
        for (int j = 0; j < 3; j++)
        {
            if (board[j][0] != ' ' && board[j][1] == board[j][0] && board[j][2] == board[j][0])
            {
                winner = board[0][0];
                game_over = true;
                break;
            }
        }
        // column check
        for (int k = 0; k < 3; k++)
        {
            if (board[0][k] != ' ' && board[1][k] == board[0][k] && board[2][k] == board[0][k])
            {
                winner = board[0][k];
                game_over = true;
                break;
            }
        }

        // diagonal check
        if (board[0][0] != ' ' && board[0][0] == board[1][1] && board[0][0] == board[2][2])
        {
            winner = board[0][0];
            game_over = true;
            break;
        }
        else if (board[0][2] != ' ' && board[1][1] == board[0][2] && board[2][0] == board[0][2])
        {
            winner = board[0][2];
            game_over = true;
            break;
        }
        if (game_over)
        {
            i = 8;
        }
        current_player = (current_player == player1) ? player2 : player1;
    }
    if (winner != ' ')
    {
        cout << "The winner is .. " << winner << endl;
    }
    else
    {
        cout << "Game draw!!!";
    }
    return 0;
}
