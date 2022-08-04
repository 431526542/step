#pragma once
#include "Actor.h"

class Floor : public Actor
{
public:
	Floor() 
	{
		Shape = ' ';
		SortOrder = 1;
		bCollisionEnabled = false;
	}
	Floor(int NewX, int NewY)
	{
		Shape = ' ';
		SortOrder = 1;
		bCollisionEnabled = false;
		Location.X = NewX;
		Location.Y = NewY;
	}
	virtual ~Floor() {}
};

