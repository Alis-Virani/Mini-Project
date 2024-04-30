#include <iostream>
#include <string>
using namespace std;

char space[3][3] = {{'1', '2', '3'}, {'4', '5', '6'}, {'7', '8', '9'}};
int row, column;
char token = 'x';
bool tie=0;
string p1 = "";
string p2 = "";

void fun1()
{
    cout << "    |     |    " << endl;
    cout << " " << space[0][0] << "  |  " << space[0][1] << "  |  " << space[0][2] << endl;
    cout << " " << endl;
    cout << "    |     |    " << endl;
    cout << " " << space[1][0] << "  |  " << space[1][1] << "  |  " << space[1][2] << endl;
    cout << " " << endl;
    cout << "    |     |    " << endl;
    cout << " " << space[2][0] << "  |  " << space[2][1] << "  |  " << space[2][2] << endl;
    cout << "    |     |    " << endl;
}

void fun2()
{
    int digit;
    if (token == 'x')
    {
        cout << p1 << " Please enter the place from 1 to 9: ";
        cin >> digit;
    }

    if (token == 'o')
    {
        cout << p2 << " Please enter the place from 1 to 9: ";
        cin >> digit;
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
        cout << "enter valid place :)" << endl;

    if (token == 'x' && space[row][column] != 'x' && space[row][column] != 'o')
    {
        space[row][column] = 'x';
        token = 'o';
    }
    else if (token == 'o' && space[row][column] != 'x' && space[row][column] != 'o')
    {
        space[row][column] = 'o';
        token = 'x';
    }
    else
    {
        cout << "There is no empty space" << endl;
    
    }
}

bool fun3()
{
    for (int i = 0; i < 3; i++)
    {
        if (space[i][0] == space[i][1] && space[i][0] == space[i][2] || space[0][i] == space[1][i] && space[0][i] == space[2][i])
            return true;
    }

    if (space[0][0] == space[1][1] && space[0][0] == space[2][2] || space[0][2] == space[1][1] && space[0][2] == space[2][0])
        return true;

    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            if (space[i][j] != 'x' && space[i][j] != 'o')
                return false;
        }
    }
    tie = true;
    return false;
}

int main()
{
    cout << " Name of Player 1 :- ";
    getline(cin, p1);
    cout << " Name of Player 2 :- ";
    getline(cin, p2);
    cout << endl;
    cout << " First turn will be of " << p1 << " and then " << p2 << endl;

    while (!fun3() && tie!=true)
    {
        fun1();
        fun2();
        fun3();
    }
    if(tie){
        cout<<"drow";
    }
    else if (token == 'x' && tie == false)
    {
        fun1();
        cout<< p2 << " Wins"<< endl;
    }
    else if (token == 'o' && tie == false)
    {
        fun1();
        cout << p1 << " Wins" << endl;
    }
    
}
