#include <iostream>
#include <cmath>
#include <limits>
using namespace std;

// Variable Decelaration
char square[3][3] = {
    {'1', '2', '3'},
    {'4', '5', '6'},
    {'7', '8', '9'},
};
char turn = 'X';
bool draw = false;

// gameModel() Function for displaying layout of game on console
void gameModel()
{
    system("CLS");
    cout << "\n\t(:---------------------- TIC TOC TOE GAME ----------------------:)\t";
    cout << "\n\t\t  (:----------- MADE BY M.ABUBAKAR -----------:)\t\n\n\n";
    cout << "\tPlayer - 1  [X]  <---- VS ---->  Player - 2  [O]\n\n";
    cout << "\tChoose a cell Numbered from 1 to 9 as below and Play :- \n\n\n\n";

    cout << "\t\t\t\t       |       |       \n";
    cout << "\t\t\t\t   " << square[0][0] << "   |   " << square[0][1] << "   |   " << square[0][2] << "   \n";
    cout << "\t\t\t\t_______|_______|_______\n";
    cout << "\t\t\t\t       |       |       \n";
    cout << "\t\t\t\t   " << square[1][0] << "   |   " << square[1][1] << "   |   " << square[1][2] << "   \n";
    cout << "\t\t\t\t_______|_______|_______\n";
    cout << "\t\t\t\t       |       |       \n";
    cout << "\t\t\t\t   " << square[2][0] << "   |   " << square[2][1] << "   |   " << square[2][2] << "   \n";
    cout << "\t\t\t\t       |       |       \n\n\n\n";
}

// playersTurn() Function For Players Turn
void playersturn()
{
label1:
    register int row, column, choice;

    if (turn == 'X')
    {
        cout << "  Player - 1  [X]  Turn : ";
    }
    else if (turn == 'O')
    {
        cout << "  Player - 2  [O]  Turn : ";
    }

    cin >> choice;

    int length = trunc(log10(choice)) + 1;

    switch (choice)
    {
    case 1:
        row = 0;
        column = 0;
        break;
    case 2:
        row = 0;
        column = 1;
        break;
    case 3:
        row = 0;
        column = 2;
        break;
    case 4:
        row = 1;
        column = 0;
        break;
    case 5:
        row = 1;
        column = 1;
        break;
    case 6:
        row = 1;
        column = 2;
        break;
    case 7:
        row = 2;
        column = 0;
        break;
    case 8:
        row = 2;
        column = 1;
        break;
    case 9:
        row = 2;
        column = 2;
        break;

    default:
        // Input 'Choice' Validation
        if (cin.fail() == 1)
        {
            // Clear The Previous Input
            cin.clear();

            // Discard The Previous Input
            cin.ignore(numeric_limits<streamsize>::max(), '\n');

            // Throwing Error and Again Input Value From User
            cout << "  \nError : Invalid Value Detected\n  Please Try Again!\n\n";
            goto label1;
        }

        // Input 'Choice' Validation
        else if (length > 1)
        {
            // Throwing Error and Again Input Value From User
            cout << "  \nError : Invalid Value Detected\n  Please Try Again!\n\n";
            goto label1;
        }
        break;
    }

    if (turn == 'X' && square[row][column] != 'X' && square[row][column] != 'O')
    {
        square[row][column] = 'X';
        turn = 'O';
    }
    else if (turn == 'O' && square[row][column] != 'X' && square[row][column] != 'O')
    {
        square[row][column] = 'O';
        turn = 'X';
    }
    else
    {
        cout << "  \nBox Already Filled\n  Please Try Again!\n\n";
        playersturn();
    }
    gameModel();
}

bool checkwin()
{
    // If Row and Column Enteries are Same With Each Other then return false
    for (int i = 0; i < 3; i++)
    {
        if ((square[i][0] == square[i][1]) && (square[i][0] == square[i][2]) || (square[0][i] == square[1][i]) && (square[0][i] == square[2][i]))
        {
            return false;
        }
    }

    // If Left Diagnals Enteries are Same With Each Other then return false
    for (int i = 0; i < 3; i++)
    {
        if (square[0][0] == square[1][1] && square[0][0] == square[2][2])
        {
            return false;
        }
    }

    // If Right Diagnals Enteries are Same With Each Other then return false
    for (int i = 0; i < 3; i++)
    {
        if (square[0][2] == square[1][1] && square[0][2] == square[2][0])
        {
            return false;
        }
    }

    // If There is Any Box Not Filled
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            if (square[i][j] != 'X' && square[i][j] != 'O')
            {
                return true;
            }
        }
    }

    // When All Box is Filled then Game is Draw
    draw = true;
    return false;
}

int main()
{
    while (checkwin())
    {
        gameModel();
        playersturn();
        checkwin();
    }

    if (turn == 'O' && draw == false)
    {
        cout << "  Player-1 is Winner Congratulations!! \n\n";
    }
    else if (turn == 'X' && draw == false)
    {
        cout << "  Player-2 is Winner Congratulations!! \n\n";
    }
    else
    {
        cout << "  DRAW GAME!!" << endl;
    }
    system("pause");
}