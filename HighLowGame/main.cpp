#include<iostream>
#include"Card.h"
#include"Initialize.h"
#include"Common.h"
#include"Shuffle.h"
#include"CardChoice.h"


using namespace std;

enum EnGameState
{
	Ready = 0,
	Beating,
	Playing
};

void main()
{
	int money = 10000;
	int chip = { 0 };
	cout << "잔고 : " << money << endl;





	Initialize();
	bool IsPlaying = true;
	EnGameState gs = Ready;

	while (IsPlaying)
	{
		switch (gs)
		{
		case Ready:
			cout << "게임을 플레이 하시겠습니다까?(Y/N)" << endl;
			char chPlaying;
			cin >> chPlaying;
			switch (chPlaying)
			{
			case 'Y':
				gs = Beating;
				system("cls");
				break;

			case 'N':
				IsPlaying = false;
				break;

			default:
				break;
			}
			break;

		case Playing:
			Shuffle();
			/*
			//카드출력
			for (int i = 0; i < Max; ++i)
			{
				cout << "Mark = " << cards[i].mark<< " " << "Number = " << cards[i].number << endl;
			}*/
			CardChoice();

			gs = Ready;
			break;

		case Beating:
			cout << "배팅금액 : " << endl;
			cin >> chip;
			gs = Playing;
			break;
		}
		
	}
	
}