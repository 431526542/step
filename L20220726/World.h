#pragma once
#include <vector>

class Actor;

class World
{
public:
	World();
	virtual ~World();

	std::vector<Actor*> ActorList;

	void SpawnActor(Actor* NewActor);
	std::vector<Actor*>::iterator DestoryActor(Actor* DeletedActor);


	void Tick();
	void Render();
};

