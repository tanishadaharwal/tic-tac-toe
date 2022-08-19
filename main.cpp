#include <iostream>
#include <string.h>
using namespace std;

char game_matrix[3][3] = {{'1','2','3'},{'4','5','6'},{'7','8','9'}};
int row, column;
bool tie = false;
char symbol = 'X';
void display_game()
{
    cout<<"   |   |   \n";
    cout<<" "<<game_matrix[0][0]<<" | "<<game_matrix[0][1]<<" | "<<game_matrix[0][2]<<" \n";
    cout<<"___|___|___\n";
    cout<<"   |   |   \n";
    cout<<" "<<game_matrix[1][0]<<" | "<<game_matrix[1][1]<<" | "<<game_matrix[1][2]<<" \n";
    cout<<"___|___|___\n";
    cout<<"   |   |   \n";
    cout<<" "<<game_matrix[2][0]<<" | "<<game_matrix[2][1]<<" | "<<game_matrix[2][2]<<" \n";
    cout<<"   |   |\n";
}

void take_input(string p1, string p2)
{
    int digit;
    if (symbol=='X')
    {
        cout<<p1<<" Enter position: ";
        cin>>digit;
    }
    if (symbol=='O')
    {
        cout<<p2<<" Enter position: ";
        cin>>digit;
    }
    if (digit == 1)
    {
        row = 0;
        column = 0;
    }
    if (digit == 2)
    {
        row = 0;
        column = 1;
    }
    if (digit == 3)
    {
        row = 0;
        column = 2;
    }
    if (digit == 4)
    {
        row = 1;
        column = 0;
    }
    if (digit == 5)
    {
        row = 1;
        column = 1;
    }
    if (digit == 6)
    {
        row = 1;
        column = 2;
    }
    if (digit == 7)
    {
        row = 2;
        column = 0;
    }
    if (digit == 8)
    {
        row = 2;
        column = 1;
    }
    if (digit == 9)
    {
        row = 2;
        column = 2;
    }
    else if (digit < 1 || digit > 9)
        cout<<"Invalid position"<<endl;

    if (symbol == 'X' && game_matrix[row][column] != 'X' && game_matrix[row][column] != 'O')
    {
        game_matrix[row][column] = 'X';
        symbol = 'O';
    }
    else if (symbol == 'O' && game_matrix[row][column] != 'X' && game_matrix[row][column] != 'O')
    {
        game_matrix[row][column] = 'O';
        symbol = 'X';
    }
    else
    {
        cout<<"No empty space"<<endl;
        take_input(p1, p2);
    }
    cout<<"Current game status"<<endl;
    display_game();
    

}
bool check_win_draw()
{
    for (int i = 0; i < 3; i ++)
    {
        if (game_matrix[i][0] == game_matrix[i][1] && game_matrix[i][1] == game_matrix[i][2] || game_matrix[0][i] == game_matrix[1][i] && game_matrix[1][i]== game_matrix[2][i])
            return true;
    }
    if (game_matrix[0][0] == game_matrix[1][1] && game_matrix[1][1] == game_matrix[2][2] || game_matrix[0][2] == game_matrix[1][1] && game_matrix[1][1] == game_matrix[2][0])
        return true;
    for (int i = 0; i < 3; i ++)
    {
        for (int j = 0; j < 3; j ++)
        {
            if (game_matrix[i][j] != 'X' && game_matrix[i][j] != 'O')
                return false;
        }
        
    }
    tie = true;
    return true;

}
int main()
{
    string p1, p2;
    cout<<"Get ready to play tic tac toe"<<endl;
    cout<<"Enter name of the first player: ";
    cin>>p1;
    cout<<"Enter name of the second player: ";
    cin>>p2;

    while(!check_win_draw())
    {
        display_game();
        take_input(p1, p2);
        check_win_draw();
    }
    if (symbol == 'X' && tie == false)
        cout<<p2<<" is the winner"<<endl;
    else if (symbol == 'O' && tie == false)
        cout<<p1<<" is the winner"<<endl;
    else if(tie == true)
        cout<<"This game ends in a draw"<<endl;

    
        
        
    
    
}