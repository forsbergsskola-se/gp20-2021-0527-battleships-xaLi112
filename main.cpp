#include <iostream>
#include <ctime>

using namespace std;

const int rows = 10;
const int elements = 10;
int MaxShips = 5;

int ShipGame[rows][elements];

void Clear()
{
    for (int i = 0; i < rows; i++)
    {
        for(int s=0; s < elements; s++)
        {
            ShipGame[i][s] = 0;
        }
    }
}

void Show(){
    for (int i = 0; i < rows; i++)
    {
        for(int s=0; s < elements; s++){
            cout << ShipGame[i][s] << " ";
        }
        cout << endl;
    }
}

int NumberOfShips()
{
    int c = 0; // value of ships
    for (int i = 0; i < rows; i++)
    {
        for(int s=0; s < elements; s++)
        {
           if (ShipGame[i][s] == 1)
           c++;
        }
    }
    return c;
}

void SetShips()
{
    int Ships = 0; // amount of ships
    while (Ships < MaxShips) {
        int x = rand() % rows; // put random ships
        int y = rand() % elements;
        if (ShipGame[x][y] !=1)
        {
            Ships++;
            ShipGame[x][y] = 1;
        }
    }
}

bool  Attack(int x, int y) // guessing function
{

    if(ShipGame[x][y] == 1) //if there is a number 1 at the position..
    {
        ShipGame[x][y] = 2; // return 2...hit
        return true;
    }
    return false; // else skip
}



int main() {

    srand(time(NULL));
    Clear();
    SetShips();
    int Position1, Position2;
    char prompt;
    while (1)
    {
        cout << "Admiral! where should we attack: "; cin >> Position1 >> Position2;
        if(Attack(Position1,Position2))
            cout << "That was a hit!" << endl;
        else
            cout << "That was a miss.." << endl;
        cout << "There are " << NumberOfShips() << " Ships left in the battlefield" << endl;
        cout << "Do you want to surrender? (y/n)"; cin >> prompt;
        if(prompt == 'y')
            break;
    }
    cout << "Game over!" << endl;
    Show();
    system("Pause");
    return 0;
}
