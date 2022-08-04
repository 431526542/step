#include <iostream>
#include <fstream>
#include "Engine.h"
#include "World.h"
#include "Player.h"
#include "Monster.h"
#include "Gate.h"
#include "Floor.h"
#include<algorithm>
#include<conio.h>

void Player::Tick()
{
	if (GEngine->KeyCode == 'Q' || GEngine->KeyCode == 'q')
	{
		GEngine->Stop();
	}

	if (GEngine->KeyCode == 'W' || GEngine->KeyCode == 'w')
	{
		if (Predict(Location.X, Location.Y-1))
		{
			Location.Y--;
		}
	}
	if (GEngine->KeyCode == 'S' || GEngine->KeyCode == 's')
	{
		if (Predict(Location.X, Location.Y + 1))
		{
			Location.Y++;
		}

	}
	if (GEngine->KeyCode == 'D' || GEngine->KeyCode == 'd')
	{
		if (Predict(Location.X + 1, Location.Y))
		{
			Location.X++;
		}

	}
	if (GEngine->KeyCode == 'A' || GEngine->KeyCode == 'a')
	{
		if (Predict(Location.X - 1, Location.Y))
		{
			Location.X--;
		}

	}
}

bool Player::Predict(int NewX, int NewY)
{
	for (auto CurrentActor : GEngine->MyWorld->ActorList)
	{
		if (CurrentActor->bCollisionEnabled &&
			CurrentActor->Location.X == NewX &&
			CurrentActor->Location.Y == NewY)
		{
			return false;
		}
	}
	return true;
}
