#include <bits/stdc++.h>
using namespace std;
class player
{
public:
    int score;
    string name;
};

// // declaration of all the related variables :
//    player p1;
// player p2;

class snake
{
public:
    int location;
    int updated_value;
};
class ladder
{
public:
    int location;
    int updated_value;
};

// declaration of all the snakes and ladders
snake snakes[7];
ladder ladders[8];

void print_score(player players[], int n)
{
    cout << endl
         << "-----------------------------------------------------------------------------------" << endl;

    cout << "Current score of the players are : " << endl;

    for (int i = 0; i < n; i++)
    {
        cout << players[i].name << " : " << players[i].score << endl;
    }

    cout << endl
         << "-----------------------------------------------------------------------------------" << endl;
}
bool is_snake(player &x)
{
    for (int i = 0; i < 7; i++)
    {
        if (x.score == snakes[i].location)
        {
            cout << "     /\\  /\\  /\\     " << endl;
            cout << "  <\\/  \\/  \\/  \\/\\ " << endl;
            cout << x.score << "                " << snakes[i].updated_value << endl;

            x.score = snakes[i].updated_value;

            return 1;
        }
    }
    return 0;
}
bool is_ladder(player &x)
{
    for (int i = 0; i < 8; i++)
    {
        if (x.score == ladders[i].location)
        {
             cout << "  " << ladders[i].updated_value << endl;
    cout << " |--|" << endl;
    cout << " |--|" << endl;
    cout << " |--|" << endl;
    cout << " |--|" << endl;
    cout << " |--|" << endl;
    cout << "  " << x.score << endl;
            x.score = ladders[i].updated_value;
            return 1;
        }
    }
    return 0;
}

void dice_display(int x)
{
    if (x == 1)
    {
        cout << " ---------" << endl;
        cout << "|         |" << endl;
        cout << "|    0    |" << endl;
        cout << "|         |" << endl;
        cout << " ---------" << endl;
    }
    else if (x == 2)
    {

        cout << " ---------" << endl;
        cout << "| 0       |" << endl;
        cout << "|         |" << endl;
        cout << "|       0 |" << endl;
        cout << " ---------" << endl;
    }
    else if (x == 3)
    {
        cout << " ---------" << endl;
        cout << "| 0       |" << endl;
        cout << "|    0    |" << endl;
        cout << "|       0 |" << endl;
        cout << " ---------" << endl;
    }
    else if (x == 4)
    {
        cout << " ---------" << endl;
        cout << "| 0     0 |" << endl;
        cout << "|         |" << endl;
        cout << "| 0     0 |" << endl;
        cout << " ---------" << endl;
    }

    else if (x == 5)
    {
        cout << " ---------" << endl;
        cout << "| 0     0 |" << endl;
        cout << "|    0    |" << endl;
        cout << "| 0     0 |" << endl;
        cout << " ---------" << endl;
    }
    else
    {
        cout << " ---------" << endl;
        cout << "| 0     0 |" << endl;
        cout << "| 0     0 |" << endl;
        cout << "| 0     0 |" << endl;
        cout << " ---------" << endl;
    }
}
void dice_func(int &x)
{
    srand(time(NULL));
    int dice = rand() % 6 + 1;
    cout << "Dice : " << dice << endl;
    dice_display(dice);

    if (x + dice > 100)
    {
        cout << "Oops!! Try Again.";
    }
    else
        x += dice;

    if (dice == 6)
    {
        cout << "You have got the another chance , press any key to roll the dice : ";
        int m;
        cin >> m;
        dice_func(x);
    }
}

// need to look into the function
void main_func(player y[], player &x, int n)
{
    cout << x.name << " , Press any number and then enter key for the dice to roll : ";
    int temp;
    cin >> temp;
    dice_func(x.score);
    print_score(y, n);

    if (is_snake(x))
    {
        cout << "Oops !! have been bitten by snake " << endl;
        print_score(y, n);
    }

    if (is_ladder(x))
    {
        cout << "Hurray !! " << x.name << " have got the stairs " << endl;
        print_score(y, n);
    }

    if (x.score == 100)
    {
        cout << endl
             << "-----------------------------------------------------------------------------------" << endl;
        cout << " ----------------------------" << endl;
        cout << "|                            |" << endl;
        cout << "|          GAME              |" << endl;
        cout << "|          OVER              |" << endl;
        cout << "|                            |" << endl;
        cout << " ----------------------------" << endl;

        cout << x.name << " has won the Game !!" << endl;

        ;
        print_score(y, n);
    }
}

int main()
{

    // updating the snake data
    snakes[0].location = 32;
    snakes[0].updated_value = 10;

    snakes[1].location = 36;
    snakes[1].updated_value = 6;

    snakes[2].location = 48;
    snakes[2].updated_value = 26;

    snakes[3].location = 62;
    snakes[3].updated_value = 18;

    snakes[4].location = 88;
    snakes[4].updated_value = 24;

    snakes[5].location = 95;
    snakes[5].updated_value = 56;

    snakes[6].location = 97;
    snakes[6].updated_value = 78;

    // updating ladders data

    ladders[0].location = 1;
    ladders[0].updated_value = 18;

    ladders[1].location = 4;
    ladders[1].updated_value = 14;

    ladders[2].location = 8;
    ladders[2].updated_value = 30;

    ladders[3].location = 21;
    ladders[3].updated_value = 42;

    ladders[4].location = 28;
    ladders[4].updated_value = 76;

    ladders[5].location = 50;
    ladders[5].updated_value = 67;

    ladders[6].location = 71;
    ladders[6].updated_value = 92;

    ladders[7].location = 80;
    ladders[7].updated_value = 99;

    cout << endl
         << "-----------------------------------------------------------------------------------" << endl;

    cout << "~~~~~~~~~~~~~~~~~~~~~ WELCOME TO THE WORLD OF SNAKE AND LADDER ~~~~~~~~~~~~~~~~~~~";
    cout << endl
         << "-----------------------------------------------------------------------------------" << endl;

    cout << "Enter the number of player : " << endl;
    int num_of_player;
    cin >> num_of_player;

    player players[num_of_player];

    for (int i = 0; i < num_of_player; i++)
    {
        cout << "Enter the name of player " << i + 1 << " : ";
        cin >> players[i].name;
        players[i].score = 0;
    }

    print_score(players, num_of_player);

    cout << "LET THE HUNT BEGIN !!";
    cout << endl
         << "-----------------------------------------------------------------------------------" << endl;

    while (true)
    {
        for (int i = 0; i < num_of_player; i++)
        {
            main_func(players, players[i], num_of_player);
        }
    }

    return 0;
}
