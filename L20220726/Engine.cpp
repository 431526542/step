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

Engine* Engine::Instance = nullptr; 

Engine::Engine()
{
	MyWorld = nullptr;
}

Engine::~Engine()
{
	delete MyWorld;
}

void Engine::LoadMap(std::string MapFilename)
{
	MyWorld = new World();

	std::ifstream ReadFileStream;
	ReadFileStream.open(MapFilename);
	if (ReadFileStream.is_open())
	{
		int Y = 0;
		while (!ReadFileStream.eof())
		{
			char Temp[256];
			ReadFileStream.getline(Temp, 256);
			
			int X = 0;
			while (X < strlen(Temp))
			{
				MyWorld->SpawnActor(new Floor(X, Y));
				if (Temp[X] == '*')
				{
					MyWorld->SpawnActor(new Wall(X, Y));
				}
				else if (Temp[X] == 'P')
				{
					MyWorld->SpawnActor(new Player(X, Y));
				}
				else if (Temp[X] == 'M')
				{
					MyWorld->SpawnActor(new Monster(X, Y));
				}
				else if (Temp[X] == 'G')
				{
					MyWorld->SpawnActor(new Gate(X, Y));
				}
				X++;
			}
			Y++;
		}
	}
	ReadFileStream.close();
	/*
	for (int i = 0; i < MyWorld->ActorList.size(); ++i)
	{
		for (int j = i + 1; j < MyWorld->ActorList.size(); ++j)
		{
			if (MyWorld->ActorList[i]->SortOrder < MyWorld->ActorList[j]->SortOrder)
			{
				Actor* Temp = MyWorld->ActorList[i];
				MyWorld->ActorList[i] = MyWorld->ActorList[j];
				MyWorld->ActorList[j] = Temp;
			}
		}
	}*/

	std::sort(MyWorld->ActorList.begin(), MyWorld->ActorList.end(), Engine::Compare);
}



void Engine::Run()
{
	while (bIsRunning)
	{
		Input();
		MyWorld->Tick();
		MyWorld->Render();
	}
}

void Engine::Stop()
{
	bIsRunning = false;
}

void Engine::Input()
{
	KeyCode = _getch();
}

bool Engine::Compare(Actor* F, Actor* S)
{
	return F->SortOrder < S->SortOrder;
}
