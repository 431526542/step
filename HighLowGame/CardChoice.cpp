#include "CardChoice.h"
#include "Shuffle.h"
#include"Card.h"
#include"Initialize.h"
#include"Common.h"
#include<iostream>

using namespace std;

void CardChoice()
{
	int pick;
	int Nondisclosure; //비공개카드
	cout << "52개 카드가 있습니다. 몇번째 카드를 뽑으시겠습니까?";
	cin >> pick;
	Nondisclosure = pick * 40 / 6 * (129 + 563 - 400) % 52;

	//선택한 카드를 보여준다
	if (cards[pick].mark == 0)
	{
		cout << "Clover" << " " << cards[pick].number << endl;
	}
	else if (cards[pick].mark == 1)
	{
		cout << "Heart" << " " << cards[pick].number << endl;
	}
	else if (cards[pick].mark == 2)
	{
		cout << "Dia" << " " << cards[pick].number << endl;
	}
	else if (cards[pick].mark == 3)
	{
		cout << "Spade" << " " << cards[pick].number << endl;
	}

	//두 카드를 비교하고 H/L선택
	bool Choice;
	cout << "당신이 뽑은 카드 보다 클것인지 아닐것인지 골라주세요" << endl;
	cout << "크다=1, 아니다=0 : ";
	cin >> Choice;
	if (true)
	{
		if (cards[pick].number > cards[Nondisclosure].number)
		{
			cout << "정답" << endl;
		}
		else if (cards[pick].number == cards[Nondisclosure].number)
		{
			if (cards[pick].mark > cards[Nondisclosure].mark)
			{
				cout << "정답" << endl;
			}
			else
			{
				cout << "땡" << endl;
			}
		}
		else
		{
			cout << "땡" << endl;
		}
	}
	else
	{
		if (cards[pick].number < cards[Nondisclosure].number)
		{
			cout << "정답" << endl;
		}
		else if (cards[pick].number == cards[Nondisclosure].number)
		{
			if (cards[pick].mark < cards[Nondisclosure].mark)
			{
				cout << "정답" << endl;
			}
			else
			{
				cout << "땡" << endl;
			}
		}
		else
		{
			cout << "땡" << endl;
		}
	}
}