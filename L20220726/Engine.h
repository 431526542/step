#pragma once
#include<string>
#define GEngine Engine::GetInstance()

class World;
class Actor;

class Engine
{
protected:
	Engine();

	static Engine* Instance;
public:
	virtual ~Engine();

	static Engine* GetInstance()
	{
		if (Instance == nullptr)
		{
			Instance = new Engine();
		}
		return Instance;
	}

	World* MyWorld;

	void LoadMap(std::string MapFilename);
	void Run();

	void Stop();

	void Input();

	bool bIsRunning = true;

	static bool Compare(Actor* F, Actor* S);

	int KeyCode;
};


