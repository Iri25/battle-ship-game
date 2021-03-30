#pragma once

class Service
{
public:
	Service();
	~Service();

	const int rows = 10;
	const int columns = 10;
	int computerArea[10][10];
	int userArea[10][10];

	int lastComputerShip = -1;
	int idLastComputerShip = 0;

	int lastUserShip = -1;
	int idLastUserShip = 0;

	struct ships
	{
		int initialNumberOfShips;
		int totalNumberOfShips;
		int coordinates[10][2];
	};

	ships userShip[10];
	ships computerShip[10];

	void addUserArea(int ship, int dim, int coordinates[][2]);
	void addComputerArea(int ship, int dim, int coordinates[][2]);

	int getRow0or1();
	int getRow0or3();
	int getCoordinateX();
	int getCoordinateY();

	void addRandomUserArea();
	void addRandomComputerArea();

	void clearArea();

	int NumberOfComputerShips();
	int NumberOfUserShips();

	bool attackComputerShip(int x, int y);
	bool attackUserShip(int x, int y);
};