#pragma once
#include "Actor.h"
#include "Wall.h"
#include "Player.h"

class Player : public Actor
{
public:
	Player()
	{
		Shape = 'P';
		SortOrder = 3;
		bCollisionEnabled = true;
		Location.X = 1;
		Location.Y = 1;
	}

	Player(int NewX, int NewY)
	{
		Shape = 'P';
		SortOrder = 3;
		bCollisionEnabled = true;
		Location.X = NewX;
		Location.Y = NewY;
	}

	virtual ~Player() {}

	virtual void Tick() override;

	//virtual void Render() override {} 

	bool Predict(int NewX, int NewY);
};

