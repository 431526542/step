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
	int Nondisclosure; //�����ī��
	cout << "52�� ī�尡 �ֽ��ϴ�. ���° ī�带 �����ðڽ��ϱ�?";
	cin >> pick;
	Nondisclosure = pick * 40 / 6 * (129 + 563 - 400) % 52;

	//������ ī�带 �����ش�
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

	//�� ī�带 ���ϰ� H/L����
	bool Choice;
	cout << "����� ���� ī�� ���� Ŭ������ �ƴҰ����� ����ּ���" << endl;
	cout << "ũ��=1, �ƴϴ�=0 : ";
	cin >> Choice;
	if (true)
	{
		if (cards[pick].number > cards[Nondisclosure].number)
		{
			cout << "����" << endl;
		}
		else if (cards[pick].number == cards[Nondisclosure].number)
		{
			if (cards[pick].mark > cards[Nondisclosure].mark)
			{
				cout << "����" << endl;
			}
			else
			{
				cout << "��" << endl;
			}
		}
		else
		{
			cout << "��" << endl;
		}
	}
	else
	{
		if (cards[pick].number < cards[Nondisclosure].number)
		{
			cout << "����" << endl;
		}
		else if (cards[pick].number == cards[Nondisclosure].number)
		{
			if (cards[pick].mark < cards[Nondisclosure].mark)
			{
				cout << "����" << endl;
			}
			else
			{
				cout << "��" << endl;
			}
		}
		else
		{
			cout << "��" << endl;
		}
	}
}