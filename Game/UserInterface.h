#pragma once
#include "Service.h"

class UserInterface
{
private:
	Service service;
	void game();
	void showGame(int type);
public:
	UserInterface();
    ~UserInterface();

	void run();
};