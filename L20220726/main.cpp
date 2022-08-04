#include "Engine.h"
#include<iostream>
#include<algorithm>
#include<vector>
#include"Actor.h"

using namespace std;

int main()
{
	Engine* MyEngine = Engine::GetInstance();

	MyEngine->LoadMap("Level1.txt");
	MyEngine->Run();

	delete MyEngine;

	/*int Arr[10] = { 10,9,5,2,4,1,3,6,8,7 };
	vector <int> Arrs = { 10,9,5,2,4,1,3,6,8,7 };
	
	int temp, index, min;
	for (int i = 0; i < 10; ++i)
	{
		min = 11;
		for (int j = i; j < 10; ++j)
		{
			if (min > Arr[j])
			{
				min = Arr[j];
				index = j;
			}
		}
		temp = Arr[i];
		Arr[i] = min;
		Arr[index] = temp;

	}*/
	//std::sort(&Arr[0], &Arr[10]);
	/*
	std::sort(Arr.begin(), Arr.end(), std::greater);
	std::sort(Arr.begin(), Arr.end(), std::less);
	for (auto Arr : Arr)
	{
		std::cout << Arr << " ";
	}*/

	/*
	Engine* MyEngine = new Engine();

	MyEngine->LoadMap("Level1.txt");
	MyEngine->Run();

	delete MyEngine;*/

	return 0;
}