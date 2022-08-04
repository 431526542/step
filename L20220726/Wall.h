#pragma once
#include "Actor.h"


class Wall : public Actor
{
public:
	Wall() 
	{
		Shape = '*';
		SortOrder = 2;
		bCollisionEnabled = true;
	}

	Wall(int NewX, int NewY)
	{
		Shape = '*';
		SortOrder = 2;
		bCollisionEnabled = true;
		Location.X = NewX;
		Location.Y = NewY;
	}
	virtual ~Wall() {}
};

