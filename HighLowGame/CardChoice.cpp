#include "CardChoice.h"
#include "Shuffle.h"
#include"Card.h"
#include"Initialize.h"
#include"Common.h"
#include<iostream>

using namespace std;

void CardChoice(int& money, const int& chip)
{
	//cout << "배팅한 금액 : " << chip << endl;
	int pick;
	int Nondisclosure; //비공개카드
	cout << "52개 카드가 있습니다. 몇번째 카드를 뽑으시겠습니까?";
	cin >> pick;
	Nondisclosure = pick * 40 / 6 * (129 + pick - 56) % 52;

	//선택한 카드를 보여준다
	if (cards[pick].mark == 3)
	{
		cout << "Clover" << " " << cards[pick].number << endl;
	}
	else if (cards[pick].mark == 2)
	{
		cout << "Heart" << " " << cards[pick].number << endl;
	}
	else if (cards[pick].mark == 1)
	{
		cout << "Dia" << " " << cards[pick].number << endl;
	}
	else if (cards[pick].mark == 0)
	{
		cout << "Spade" << " " << cards[pick].number << endl;
	}

	//두 카드를 비교하고 H/L선택
	bool Choice;
	cout << "당신이 뽑은 카드보다 클것인지 아닐것인지 골라주세요" << endl;
	cout << "크다=1, 작다=0 -> ";
	cin >> Choice;

	if (true)
	{
		if (cards[pick].number < cards[Nondisclosure].number)
		{
			cout << "정답" << endl;
			money += chip * 2;
		}
		else if (cards[pick].number == cards[Nondisclosure].number)
		{
			if (cards[pick].mark < cards[Nondisclosure].mark)
			{
				cout << "정답" << endl;
				money += chip * 2;
			}
			else
			{
				cout << "땡" << endl;
				money -= chip;
			}
		}
		else
		{
			cout << "땡" << endl;
			money -= chip;
		}
	}
	else //false
	{
		if (cards[pick].number > cards[Nondisclosure].number)
		{
			cout << "정답" << endl;
			money += chip * 2;
		}
		else if (cards[pick].number == cards[Nondisclosure].number)
		{
			if (cards[pick].mark > cards[Nondisclosure].mark)
			{
				cout << "정답" << endl;
				money += chip * 2;
			}
			else
			{
				cout << "땡" << endl;
				money -= chip;
			}
		}
		else
		{
			cout << "땡" << endl;
			money -= chip;
		}
	}

	//비공개 카드정보
	if (cards[Nondisclosure].mark == 3)
	{
		cout << "Clover" << " " << cards[Nondisclosure].number << endl;
	}
	else if (cards[Nondisclosure].mark == 2)
	{
		cout << "Heart" << " " << cards[Nondisclosure].number << endl;
	}
	else if (cards[Nondisclosure].mark == 1)
	{
		cout << "Dia" << " " << cards[Nondisclosure].number << endl;
	}
	else if (cards[Nondisclosure].mark == 0)
	{
		cout << "Spade" << " " << cards[Nondisclosure].number << endl;
	}
}