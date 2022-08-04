#include "Actor.h"
#include <iostream>
#include <Windows.h>

void Actor::Tick()
{
}

void Actor::Render()
{
    COORD Cur;
    Cur.X = Location.X;
    Cur.Y = Location.Y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), Cur);

	std::cout << Shape;
}
