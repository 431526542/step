#include "Monster.h"
#include "Engine.h"
#include "World.h"
#include "Player.h"

//#define UP      0
//#define LEFT    1
//#define RIGHT   2
//#define DOWN    3

enum EDirction
{
	UP =0,
	LEFT = 1,
	RIGHT = 2,
	DOWN = 3,
};

void Monster::Tick()
{
	ElapsedTime += GEngine->MyWorld->DeltaSeconds;

	if (ElapsedTime / 200 >= 1)
	{
		ElapsedTime = 0;

		EDirction Direction = static_cast<EDirction>(rand() % 4);

		if (Direction == EDirction::UP)
		{
			if (Predict(Location.X, Location.Y - 1))
			{
				Location.Y--;
			}
		}
		if (Direction == EDirction::LEFT)
		{
			if (Predict(Location.X - 1, Location.Y))
			{
				Location.X--;
			}
		}
		if (Direction == EDirction::RIGHT)
		{
			if (Predict(Location.X, Location.Y + 1))
			{
				Location.Y++;
			}
		}
		if (Direction == EDirction::DOWN)
		{
			if (Predict(Location.X + 1, Location.Y))
			{
				Location.X++;
			}
		}
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
