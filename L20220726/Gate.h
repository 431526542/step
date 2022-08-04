#pragma once
#include "Actor.h"

class Gate : public Actor
{
public:
	Gate()
	{
		Shape = 'G';
		SortOrder = 2;
		bCollisionEnabled = false;
	}

	Gate(int NewX, int NewY)
	{
		Shape = 'G';
		SortOrder = 2;
		bCollisionEnabled = false;
		Location.X = NewX;
		Location.Y = NewY;
	}
	virtual ~Gate() {}
};

