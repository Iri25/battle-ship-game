#include "UserInterface.h"
#include <iostream>
#include <ctime>
#include <cstdlib>
#include <Windows.h>
#include <string.h>

using namespace std;

UserInterface::UserInterface()
{
}

UserInterface::~UserInterface()
{
}

void UserInterface::showGame(int type)
{
    system("color 65");
    // HANDLE handle = GetStdHandle(STD_OUTPUT_HANDLE);
    //SetConsoleTextAttribute(handle, 13);
    cout << " - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -" << endl;
    cout << " -                               BattleShip!                    -" << endl;
    cout << " - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -" << endl;
    cout << " |A = 0| |B = 1| | C = 2| | D = 3| | E = 4| | F = 5| | G = 6| | H = 7| | I = 8| | J = 9| " << endl;
    cout << "\n";
    cout << " -                     User Area:                       -" << endl;
    cout << " - - - - - - - -  0 1 2 3 4 5 6 7 8 9  - - - - - - - - " << endl;
    char k[11] = "ABCDEFGHIJ"; 
    cout << endl;
    for (int i = 0; i < service.rows; i++)
    {
        cout << " | " << k[i] << " | ";
        for (int j = 0; j < service.columns; j++)
        {
            if (service.computerArea[i][j] == -1)
                cout << "X ";
            else if (service.computerArea[i][j] == 0 || type == 0)
                cout << "* ";
            else if (service.computerArea[i][j] == 1)
                cout << (char)176 << " ";
            else if (service.computerArea[i][j] == 2)
                cout << (char)177 << " ";
            else if (service.computerArea[i][j] == 3)
                cout << (char)178 << " ";
            else if (service.computerArea[i][j] == 4)
                cout << (char)240 << " ";
            else if (service.computerArea[i][j] == 5)
                cout << (char)219 << " ";
            else
                cout << service.computerArea[i][j] << " ";
        }
        cout << "|           | " << k[i] << " | ";
        for (int j = 0; j < service.columns; j++)
            if (service.userArea[i][j] == -1)
                cout << "X ";
            else if (service.userArea[i][j] == 0)
                cout << "* ";
            else if (service.userArea[i][j] == 1)
                cout << (char)176 << " ";
            else if (service.userArea[i][j] == 2)
                cout << (char)177 << " ";
            else if (service.userArea[i][j] == 3)
                cout << (char)178 << " ";
            else if (service.userArea[i][j] == 4)
                cout << (char)240 << " ";
            else if (service.userArea[i][j] == 5)
                cout << (char)219 << " ";
            else
                cout << service.userArea[i][j] << " ";
        cout << "|" << endl;
    }
   // cout << " - - - - - - - - - - - - - -           - - - - - - - - - - - - - -" << endl;
   // cout << " | The remaining ships: " << service.NumberOfComputerShips();
   // if (service.NumberOfComputerShips() == 10)
   //     cout << " |           | ";
    //else
   //     cout << "  |           | ";
    cout << "The remaining ships: " << service.NumberOfUserShips();
    if (service.NumberOfUserShips() == 10)
        cout << " | " << endl;
    else
        cout << "  | " << endl;
    cout << " - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -" << endl;
}


void UserInterface::run()
{
    srand(time(NULL));
    service.clearArea();
    service.addRandomUserArea();
    service.addRandomComputerArea();

    int position1, position2;
    int positionX = -1, positionY = -1;
    char prompt = 'n';
    char work = 'n';
    int exite;
    int hit = 0;
    int wasHit = 0;
    int verification;

    do
    {
        cout << "You want to get out of the game faster? (y/n): ";
        cin >> work;
    } while (work != 'y' && work != 'n');

    while (1)
    {
        system("cls");
        showGame(1);

        if ((work == 'y' || work == 'n') && (prompt == 'y' || prompt == 'n'))
        {
            if (hit == 1 && service.lastComputerShip == 1)
                cout << " Me: A fost distrusa o parte din nava (" << service.idLastComputerShip << ")! ... (" << position1 << "," << position2 << ")" << endl;
            else if (hit == 1 && service.lastComputerShip == 0)
                cout << " Me: A fost distrusa intreaga nava (" << service.idLastComputerShip << ")! ... (" << position1 << "," << position2 << ")" << endl;
            else if (hit == 2)
                cout << " Me: No ship at that position!   ... (" << position1 << "," << position2 << ")" << endl;

            if (wasHit && service.lastUserShip == 1)
                cout << " PC: A fost distrusa o parte din nava (" << service.idLastUserShip << ")! ... (" << positionX << "," << positionY << ")" << endl;
            else if (wasHit && service.lastUserShip == 0)
                cout << " PC: A fost distrusa intreaga nava (" << service.idLastUserShip << ")! ... (" << positionX << "," << positionY << ")" << endl;
            else if (positionX > -1 && positionY > -1)
                cout << " PC: You were attacked at " << positionX << "," << positionY << " coordinates! " << endl;
            cout << " - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -" << endl;

            if (prompt == 'n' && service.NumberOfComputerShips() != 0)
            {
                do
                {
                    cout << " Me: Please input location: ";
                    cin >> position1 >> position2;
                } while (position1 < 0 || position1 > 10 || position2 < 0 || position2 > 10);
                if (service.attackComputerShip(position1, position2))
                    hit = 1;
                else
                    hit = 2;
            }
            if (wasHit == 1)
            {
                do
                {
                    verification = service.getRow0or3();
                } while
                    (
                    (verification == 0 && (positionY + 1 >= 10 || service.userArea[positionX][positionY + 1] < 0)) ||
                        (verification == 1 && (positionX + 1 >= 10 || service.userArea[positionX + 1][positionY] < 0)) ||
                        (verification == 2 && (positionY - 1 < 0 || service.userArea[positionX][positionY - 1] < 0)) ||
                        (verification == 3 && (positionX - 1 < 0 || service.userArea[positionX - 1][positionY] < 0))
                        );
                if (verification == 0 && positionY + 1 < 10)
                {
                    positionY += 1;
                    if (service.attackUserShip(positionX, positionY))
                        wasHit = 1;
                    else
                        wasHit = 0;
                }
                else if (verification == 1 && positionX + 1 < 10)
                {
                    positionX += 1;
                    if (service.attackUserShip(positionX, positionY))
                        wasHit = 1;
                    else
                        wasHit = 0;
                }
                else if (verification == 2 && positionY - 1 >= 0)
                {
                    positionY -= 1;
                    if (service.attackUserShip(positionX, positionY))
                        wasHit = 1;
                    else
                        wasHit = 0;

                }
                else if (verification == 3 && positionX - 1 >= 0)
                {
                    positionX -= 1;
                    if (service.attackUserShip(positionX, positionY))
                        wasHit = 1;
                    else
                        wasHit = 0;
                }
                else
                {
                    do
                    {
                        positionX = service.getCoordinateX();
                        positionY = service.getCoordinateY();
                    } while (service.userArea[positionX][positionY] < 0);
                    if (service.attackUserShip(positionX, positionY))
                        wasHit = 1;
                    else
                        wasHit = 0;
                }
            }
            else
            {
                do
                {
                    positionX = service.getCoordinateX();
                    positionY = service.getCoordinateY();
                } while (service.userArea[positionX][positionY] < 0);
                if (service.attackUserShip(positionX, positionY))
                    wasHit = 1;
                else
                    wasHit = 0;
            }

            if (service.NumberOfComputerShips() == 0)
            {
                exite = 1;
                break;
            }
            if (service.NumberOfUserShips() == 0)
            {
                exite = 2;
                break;
            }
        }

        if (work == 'y')
        {
            cout << " - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -" << endl;
            if (hit == 1 && service.lastComputerShip == 1)
                cout << " Me: A fost distrusa o parte din nava (" << service.idLastComputerShip << ")! ... (" << position1 << "," << position2 << ")" << endl;
            else if (hit == 1 && service.lastComputerShip == 0)
                cout << " Me: A fost distrusa intreaga nava (" << service.idLastComputerShip << ")! ... (" << position1 << "," << position2 << ")" << endl;
            else if (hit == 2)
            {
                cout << " Me: No ship at that position!   ... (" << position1 << "," << position2 << ")" << endl;
            }
            if (wasHit && service.lastUserShip == 1)
                cout << " PC: A fost distrusa o parte din nava (" << service.idLastUserShip << ")! ... (" << positionX << "," << positionY << ")" << endl;
            else if (wasHit && service.lastUserShip == 0)
                cout << " PC: A fost distrusa intreaga nava (" << service.idLastUserShip << ")! ... (" << positionX << "," << positionY << ")" << endl;
            else if (positionX > -1 && positionY > -1)
                cout << " PC: You were attacked at " << positionX << "," << positionY << " coordinates! " << endl;
            cout << " - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -" << endl;
            cout << " Me: Do you want to surrender (y/n) ? ";
            cin >> prompt;
        }
        if (prompt == 'y')
        {
            exite = 0;
            break;
        }
    }
    if (exite == 0)
    {
        cout << " You chose to quit the game !" << endl;
        while (1);
    }
    else if (exite == 1)
    {
        cout << "Congratulations, you won!" << endl;
    }
    else if (exite == 2)
    {
        cout << " It looks like the computer won!" << endl;
        while (1);
    }
}