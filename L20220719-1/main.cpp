#include<iostream>
#include<conio.h>

using namespace std;


char Map[10][10]
{
	{'*','*','*','*','*','*','*','*','*','*'},
	{'*',' ','*',' ','C',' ',' ',' ','C','*'},
	{'*',' ','*',' ',' ',' ',' ',' ',' ','*'},
	{'*',' ','*',' ',' ',' ',' ',' ',' ','*'},
	{'*',' ','*',' ',' ',' ',' ',' ',' ','*'},
	{'*',' ','*',' ',' ','*',' ',' ',' ','*'},
	{'*',' ',' ',' ',' ','*',' ',' ',' ','*'},
	{'*',' ',' ',' ',' ','*',' ',' ',' ','*'},
	{'*','C',' ',' ',' ','*','C',' ',' ','*'},
	{'*','*','*','*','*','*','*','*','*','*'}
};

bool While = true;
int GameNum = true;
int myCoin = 0;

struct Player
{
	int X;
	int Y;
};
struct Player* MyPlayer;

struct Gate
{
	int X;
	int Y;
};
struct Gate* LevelGate;

int Input()
{
	int KeyCode = _getch();

	return KeyCode;
}

bool Predict(int FutureX, int FutureY)
{
	return(Map[FutureY][FutureX] != '*');
}

bool GameClear(int FutureX, int FutureY, Gate* gate)
{
	return(gate->Y == FutureY && gate->X == FutureX);
}

bool GetCoin(int FutureX, int FutureY)
{
	return(Map[FutureY][FutureX] == 'C');
}

void Process(int KeyCode)
{
	if (KeyCode == 'w' || KeyCode == 'W')
	{
		if (Predict(MyPlayer->X, MyPlayer->Y - 1))
		{
			if (GameClear(MyPlayer->X, MyPlayer->Y - 1, LevelGate))
			{
				While = false;
				GameNum = false;
			}
			if (GetCoin(MyPlayer->X, MyPlayer->Y - 1))
			{
				myCoin++;
				Map[MyPlayer->Y - 1][MyPlayer->X] = ' ';
			}
			MyPlayer->Y--;
		}
	}
	if (KeyCode == 's' || KeyCode == 'S')
	{
		if (Predict(MyPlayer->X, MyPlayer->Y + 1))
		{
			if (GameClear(MyPlayer->X, MyPlayer->Y + 1, LevelGate))
			{
				While = false;
				GameNum = false;
			}
			if (GetCoin(MyPlayer->X, MyPlayer->Y + 1))
			{
				myCoin++;
				Map[MyPlayer->Y + 1][MyPlayer->X] = ' ';
			}
			MyPlayer->Y++;
		}
	}
	else if (KeyCode == 'd' || KeyCode == 'D')
	{
		if (Predict(MyPlayer->X + 1, MyPlayer->Y))
		{
			if (GameClear(MyPlayer->X + 1, MyPlayer->Y, LevelGate))
			{
				While = false;
				GameNum = false;
			}
			if (GetCoin(MyPlayer->X + 1, MyPlayer->Y))
			{
				myCoin++;
				Map[MyPlayer->Y][MyPlayer->X + 1] = ' ';
			}
			MyPlayer->X++;
		}
	}
	else if (KeyCode == 'a' || KeyCode == 'A')
	{
		if (Predict(MyPlayer->X - 1, MyPlayer->Y))
		{
			if (GameClear(MyPlayer->X - 1, MyPlayer->Y, LevelGate))
			{
				While = false;
				GameNum = false;
			}
			if (GetCoin(MyPlayer->X - 1, MyPlayer->Y))
			{
				myCoin++;
				Map[MyPlayer->Y][MyPlayer->X - 1] = ' ';
			}
			MyPlayer->X--;
		}
	}
	else if (KeyCode == 27)
	{
		While = false;
		GameNum = true;
	}
}


void Draw()
{
	system("cls");

	for (int Y = 0; Y < 10; ++Y)
	{
		for (int X = 0; X < 10; ++X)
		{
			if (X == MyPlayer->X && Y == MyPlayer->Y)
			{
				cout << "P" << ' ';
			}
			else if (X == LevelGate->X && Y == LevelGate->Y)
			{
				cout << "G" << ' ';
			}
			else
			{
				cout << Map[Y][X] << ' ';
			}
		}
		cout << endl;
	}
}

void End()
{
	system("cls");
	if (GameNum == true)
	{
		cout << "Bye Bye" << endl;
	}
	else
	{
		cout << "Good" << endl;
		cout << "MyCoin = " << myCoin << endl;
	}
}


int main()
{
	MyPlayer = new struct Player();
	if (MyPlayer)
	{
		MyPlayer->X = 1;
		MyPlayer->Y = 1;
	}

	LevelGate = new struct Gate();
	if (LevelGate)
	{
		LevelGate->X = 8;
		LevelGate->Y = 8;
	}

	while (While)
	{
		int KeyCode = Input();
		Process(KeyCode);
		Draw();
	}
	End();

	delete MyPlayer;
	MyPlayer = nullptr;

	delete LevelGate;
	LevelGate = nullptr;
	return 0;
}