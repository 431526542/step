#include "Monster.h"
#include "Engine.h"
#include "World.h"
#include "Player.h"

void Monster::Tick()
{
	ElapsedTime += GEngine->MyWorld->DeltaSeconds;
	int Random = ElapsedTime % 7;

	if (ElapsedTime / 200 >= 1)
	{
		if (Random == 1)
		{
			if (Predict(Location.X, Location.Y - 1))
			{
				Location.Y--;
			}
		}
		if (Random == 2)
		{
			if (Predict(Location.X - 1, Location.Y))
			{
				Location.X--;
			}
		}
		if (Random == 3)
		{
			if (Predict(Location.X, Location.Y + 1))
			{
				Location.Y++;
			}
		}
		if (Random == 4)
		{
			if (Predict(Location.X + 1, Location.Y))
			{
				Location.X++;
			}
		}
		ElapsedTime = 0;
	}

	
}


bool Monster::Predict(int NewX, int NewY)
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
