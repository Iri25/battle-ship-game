#include "Service.h"
#include <ctime>
#include <cstdlib>

Service::Service()
{
}

Service::~Service()
{
}

void Service::addUserArea(int ship, int dim, int coordinates[][2])
{
    userShip[ship].initialNumberOfShips = dim;
    userShip[ship].totalNumberOfShips = dim;
    int i;
    for (i = 0; i < dim; i++)
    {
        userShip[ship].coordinates[i][0] = coordinates[i][0];
        userShip[ship].coordinates[i][1] = coordinates[i][1];
        userArea[coordinates[i][0]][coordinates[i][1]] = ship;
    }
}

void Service::addComputerArea(int ship, int dim, int coordinates[][2])
{
    computerShip[ship].initialNumberOfShips = dim;
    computerShip[ship].totalNumberOfShips = dim;
    int i;
    for (i = 0; i < dim; i++)
    {
        computerShip[ship].coordinates[i][0] = coordinates[i][0];
        computerShip[ship].coordinates[i][1] = coordinates[i][1];
        computerArea[coordinates[i][0]][coordinates[i][1]] = ship;
    }
}

int Service::getRow0or1()
{
    return rand() % 2;
}

int  Service::getRow0or3()
{
    return rand() % 4;
}

int  Service::getCoordinateX()
{
    return rand() % rows;
}

int  Service::getCoordinateY()
{
    return rand() % columns;
}

void  Service::addRandomUserArea()
{
    /* Construire random nava 1 */
    int x = getCoordinateX();
    int y = getCoordinateY();
    int ship1[1][2] = { {x, y} };
    addUserArea(1, 1, ship1);

    /* Construire random nava 2 */
    int ok = getRow0or1();
    do
    {
        do
        {
            x = getCoordinateX();
            y = getCoordinateY();
        } while ((ok == 1 && y + 1 > 9) || (ok == 0 && x + 1 > 9));
    } while (userArea[x][y] > 0 ||
        ((ok == 1 && userArea[x][y + 1] > 0) ||
            (ok == 0 && userArea[x + 1][y] > 0)
            ));
    int ship2[2][2];
    if (ok == 1) {
        ship2[0][0] = x;
        ship2[0][1] = y;
        ship2[1][0] = x;
        ship2[1][1] = y + 1;
    }
    else {
        ship2[0][0] = x;
        ship2[0][1] = y;
        ship2[1][0] = x + 1;
        ship2[1][1] = y;
    }
    addUserArea(2, 2, ship2);

    /* Construire random nava 2 */
    ok = getRow0or1();
    do
    {
        do
        {
            x = getCoordinateX();
            y = getCoordinateY();
        } while ((ok == 1 && (y + 1 > 9 || y + 2 > 9)) || (ok == 0 && (x + 1 > 9 || x + 2 > 9)));
    } while (userArea[x][y] > 0 ||
        (
        (ok == 1 && (userArea[x][y + 1] > 0 || userArea[x][y + 2] > 0)) ||
            (ok == 0 && (userArea[x + 1][y] > 0 || userArea[x + 2][y] > 0))
            )
        );
    int ship3[3][2];
    if (ok == 1)
    {
        ship3[0][0] = x;
        ship3[0][1] = y;
        ship3[1][0] = x;
        ship3[1][1] = y + 1;
        ship3[2][0] = x;
        ship3[2][1] = y + 2;
    }
    else
    {
        ship3[0][0] = x;
        ship3[0][1] = y;
        ship3[1][0] = x + 1;
        ship3[1][1] = y;
        ship3[2][0] = x + 2;
        ship3[2][1] = y;
    }
    addUserArea(3, 3, ship3);
    
    /* Construire random nava 4 */
    ok = getRow0or1();
    do
    {
        do
        {
            x = getCoordinateX();
            y = getCoordinateY();
        } while ((ok == 1 && (y + 1 > 9 || y + 2 > 9 || y + 3 > 9)) || (ok == 0 && (x + 1 > 9 || x + 2 > 9 || x + 3 > 9)));
    } while (userArea[x][y] > 0 ||
        (
        (ok == 1 && (userArea[x][y + 1] > 0 || userArea[x][y + 2] > 0 || userArea[x][y + 3] > 0)) ||
            (ok == 0 && (userArea[x + 1][y] > 0 || userArea[x + 2][y] > 0 || userArea[x + 3][y] > 0))
            )
        );
    int ship4[4][2];
    if (ok == 1)
    {
        ship4[0][0] = x;
        ship4[0][1] = y;
        ship4[1][0] = x;
        ship4[1][1] = y + 1;
        ship4[2][0] = x;
        ship4[2][1] = y + 2;
        ship4[3][0] = x;
        ship4[3][1] = y + 3;
    }
    else
    {
        ship4[0][0] = x;
        ship4[0][1] = y;
        ship4[1][0] = x + 1;
        ship4[1][1] = y;
        ship4[2][0] = x + 2;
        ship4[2][1] = y;
        ship4[3][0] = x + 3;
        ship4[3][1] = y;
    }
    addUserArea(4, 4, ship4);

     //Construire random nava 5 
    ok = getRow0or1();
    do
    {
        do
        {
            x = getCoordinateX();
            y = getCoordinateY();
        } while ((ok == 1 && (y + 1 > 9 || y + 2 > 9 || y + 3 > 9 || y + 4 > 9)) || (ok == 0 && (x + 1 > 9 || x + 2 > 9 || x + 3 > 9 || x + 4 > 9)));
    } while (userArea[x][y] > 0 ||
        (
        (ok == 1 && (userArea[x][y + 1] > 0 || userArea[x][y + 2] > 0 || userArea[x][y + 3] > 0 || userArea[x][y + 4] > 0)) ||
            (ok == 0 && (userArea[x + 1][y] > 0 || userArea[x + 2][y] > 0 || userArea[x + 3][y] > 0 || userArea[x + 4][y] > 0))
            )
        );
    int ship5[3][2];
    if (ok == 1)
    {
        ship5[0][0] = x;
        ship5[0][1] = y;
        ship5[1][0] = x;
        ship5[1][1] = y + 1;
        ship5[2][0] = x;
        ship5[2][1] = y + 2;
        ship5[3][0] = x;
        ship5[3][1] = y + 3;
        ship5[4][0] = x;
        ship5[4][1] = y + 4;
    }
    else
    {
        ship5[0][0] = x;
        ship5[0][1] = y;
        ship5[1][0] = x + 1;
        ship5[1][1] = y;
        ship5[2][0] = x + 2;
        ship5[2][1] = y;
        ship5[3][0] = x + 3;
        ship5[3][1] = y;
        ship5[4][0] = x + 4;
        ship5[4][1] = y;
    }
    addUserArea(5, 5, ship5);
}

void Service::addRandomComputerArea()
{
    /* Construire random nava 1 */
    int x = getCoordinateX();
    int y = getCoordinateY();
    int ship1[1][2] = { {x, y} };
    addComputerArea(1, 1, ship1);

    /* Construire random nava 2 */
    int ok = getRow0or1();
    do
    {
        do
        {
            x = getCoordinateX();
            y = getCoordinateY();
        } while ((ok == 1 && y + 1 > 9) || (ok == 0 && x + 1 > 9));
    } while (computerArea[x][y] > 0 ||
        (
        (ok == 1 && computerArea[x][y + 1] > 0) ||
            (ok == 0 && computerArea[x + 1][y] > 0)
            )
        );
    int ship2[2][2];
    if (ok == 1) {
        ship2[0][0] = x;
        ship2[0][1] = y;
        ship2[1][0] = x;
        ship2[1][1] = y + 1;
    }
    else {
        ship2[0][0] = x;
        ship2[0][1] = y;
        ship2[1][0] = x + 1;
        ship2[1][1] = y;
    }
    addComputerArea(2, 2, ship2);

    /* Construire random nava 3 */
    ok = getRow0or1();
    do
    {
        do
        {
            x = getCoordinateX();
            y = getCoordinateY();
        } while ((ok == 1 && (y + 1 > 9 || y + 2 > 9)) || (ok == 0 && (x + 1 > 9 || x + 2 > 9)));
    } while (computerArea[x][y] > 0 ||
        (
        (ok == 1 && (computerArea[x][y + 1] > 0 || computerArea[x][y + 2] > 0)) ||
            (ok == 0 && (computerArea[x + 1][y] > 0 || computerArea[x + 2][y] > 0))
            )
        );
    int ship3[3][2];
    if (ok == 1)
    {
        ship3[0][0] = x;
        ship3[0][1] = y;
        ship3[1][0] = x;
        ship3[1][1] = y + 1;
        ship3[2][0] = x;
        ship3[2][1] = y + 2;
    }
    else
    {
        ship3[0][0] = x;
        ship3[0][1] = y;
        ship3[1][0] = x + 1;
        ship3[1][1] = y;
        ship3[2][0] = x + 2;
        ship3[2][1] = y;
    }
    addComputerArea(3, 3, ship3);

    /* Construire random nava 4 */
    ok = getRow0or1();
    do
    {
        do {
            x = getCoordinateX();
            y = getCoordinateY();
        } while ((ok == 1 && (y + 1 > 9 || y + 2 > 9 || y + 3 > 9)) || (ok == 0 && (x + 1 > 9 || x + 2 > 9 || x + 3 > 9)));
    } while (computerArea[x][y] > 0 ||
        (
        (ok == 1 && (computerArea[x][y + 1] > 0 || computerArea[x][y + 2] > 0 || computerArea[x][y + 3] > 0)) ||
            (ok == 0 && (computerArea[x + 1][y] > 0 || computerArea[x + 2][y] > 0 || computerArea[x + 3][y] > 0))
            )
        );
    int ship4[4][2];
    if (ok == 1)
    {
        ship4[0][0] = x;
        ship4[0][1] = y;
        ship4[1][0] = x;
        ship4[1][1] = y + 1;
        ship4[2][0] = x;
        ship4[2][1] = y + 2;
        ship4[3][0] = x;
        ship4[3][1] = y + 3;
    }
    else
    {
        ship4[0][0] = x;
        ship4[0][1] = y;
        ship4[1][0] = x + 1;
        ship4[1][1] = y;
        ship4[2][0] = x + 2;
        ship4[2][1] = y;
        ship4[3][0] = x + 3;
        ship4[3][1] = y;
    }
    addComputerArea(4, 4, ship4);

    // Construire random nava 5 
    ok = getRow0or1();
    do
    {
        do
        {
            x = getCoordinateX();
            y = getCoordinateY();
        } while ((ok == 1 && (y + 1 > 9 || y + 2 > 9 || y + 3 > 9 || y + 4 > 9)) || (ok == 0 && (x + 1 > 9 || x + 2 > 9 || x + 3 > 9 || x + 4 > 9)));
    } while (computerArea[x][y] > 0 ||
        (
        (ok == 1 && (computerArea[x][y + 1] > 0 || computerArea[x][y + 2] > 0 || computerArea[x][y + 3] > 0 || computerArea[x][y + 4] > 0)) ||
            (ok == 0 && (computerArea[x + 1][y] > 0 || computerArea[x + 2][y] > 0 || computerArea[x + 3][y] > 0 || computerArea[x + 4][y] > 0))
            )
        );
    int ship5[3][2];
    if (ok == 1) {
        ship5[0][0] = x;
        ship5[0][1] = y;
        ship5[1][0] = x;
        ship5[1][1] = y + 1;
        ship5[2][0] = x;
        ship5[2][1] = y + 2;
        ship5[3][0] = x;
        ship5[3][1] = y + 3;
        ship5[4][0] = x;
        ship5[4][1] = y + 4;
    }
    else
    {
        ship5[0][0] = x;
        ship5[0][1] = y;
        ship5[1][0] = x + 1;
        ship5[1][1] = y;
        ship5[2][0] = x + 2;
        ship5[2][1] = y;
        ship5[3][0] = x + 3;
        ship5[3][1] = y;
        ship5[4][0] = x + 4;
        ship5[4][1] = y;
    }
    addComputerArea(5, 5, ship5);
}

void Service::clearArea()
{
    for (int i = 0; i < rows; i++)
        for (int j = 0; j < columns; j++)
        {
            computerArea[i][j] = 0;
            userArea[i][j] = 0;
        }
}

int Service::NumberOfComputerShips()
{
    int c = 0;
    for (int i = 1; i <= 5; i++)
        if (computerShip[i].totalNumberOfShips != 0)
            c++;
    return c;
}

int Service::NumberOfUserShips() 
{
    int c = 0;
    for (int i = 1; i <= 5; i++)
        if (userShip[i].totalNumberOfShips != 0)
            c++;
    return c;
}

bool Service::attackComputerShip(int x, int y)
{
    if (computerArea[x][y] > 0)
    {
        int ship = computerArea[x][y];
        computerShip[ship].totalNumberOfShips--;
        if (computerShip[ship].totalNumberOfShips > 0)
            lastComputerShip = 1;
        else
            lastComputerShip = 0;
        idLastComputerShip = ship;
        computerArea[x][y] = -1;
        return true;
    }
    return false;
}

bool Service::attackUserShip(int x, int y)
{
    if (userArea[x][y] > 0)
    {
        int ship = userArea[x][y];
        userShip[ship].totalNumberOfShips--;
        if (userShip[ship].totalNumberOfShips > 0)
            lastUserShip = 1;
        else
            lastUserShip = 0;
        idLastUserShip = ship;
        userArea[x][y] = -1;
        return true;
    }
    return false;
}
