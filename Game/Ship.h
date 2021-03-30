#pragma once/*
#include <ctime>
#include <cstdlib>
const int rows = 10;
const int columns = 10;

int computerArea[rows][columns];
int userArea[rows][columns];

struct ships
{
    int initialNumberOfShips;
    int totalNumberOfShips;
    int coordinates[10][2];
};
ships computer[10];
ships user[10];

int last_nava = -1;
int last_nava_id = 0;

int last_my_nava = -1;
int last_my_nava_id = 0;

*/

int getRand0or1() {
    return rand() % 2;
}

int getRand0or3() {
    return rand() % 4;
}

int getCoordX() {
    return rand() % rows;
}

int getCoordY() {
    return rand() % columns;
}