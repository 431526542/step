#include "Draw.h"
#include"Player.h"
#include<iostream>
#include"Map.h"

using namespace std;

void Draw()
{
	system("cls");

	for (int Y = 0; Y < 10; ++Y)
	{
		for (int X = 0; X < 10; ++X)
		{
			if (X == MyPlayer->X && Y == MyPlayer->Y)
			{
				cout << "P" << ' ';
			}
			else
			{
				cout << Map[Y][X] << ' ';
			}

		}
		cout << endl;
	}
}