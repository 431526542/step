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
	cout << "�ܰ� : " << money << endl;





	Initialize();
	bool IsPlaying = true;
	EnGameState gs = Ready;

	while (IsPlaying)
	{
		switch (gs)
		{
		case Ready:
			cout << "������ �÷��� �Ͻðڽ��ϴٱ�?(Y/N)" << endl;
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
			//ī�����
			for (int i = 0; i < Max; ++i)
			{
				cout << "Mark = " << cards[i].mark<< " " << "Number = " << cards[i].number << endl;
			}*/
			CardChoice();

			gs = Ready;
			break;

		case Beating:
			cout << "���ñݾ� : " << endl;
			cin >> chip;
			gs = Playing;
			break;
		}
		
	}
	
}