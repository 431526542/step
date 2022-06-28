#include "CardChoice.h"
#include "Shuffle.h"
#include"Card.h"
#include"Initialize.h"
#include"Common.h"
#include<iostream>

using namespace std;

void CardChoice(int& money, const int& chip)
{
	//cout << "������ �ݾ� : " << chip << endl;
	int pick;
	int Nondisclosure; //�����ī��
	cout << "52�� ī�尡 �ֽ��ϴ�. ���° ī�带 �����ðڽ��ϱ�?";
	cin >> pick;
	Nondisclosure = pick * 40 / 6 * (129 + pick - 56) % 52;

	//������ ī�带 �����ش�
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

	//�� ī�带 ���ϰ� H/L����
	bool Choice;
	cout << "����� ���� ī�庸�� Ŭ������ �ƴҰ����� ����ּ���" << endl;
	cout << "ũ��=1, �۴�=0 -> ";
	cin >> Choice;

	if (true)
	{
		if (cards[pick].number < cards[Nondisclosure].number)
		{
			cout << "����" << endl;
			money += chip * 2;
		}
		else if (cards[pick].number == cards[Nondisclosure].number)
		{
			if (cards[pick].mark < cards[Nondisclosure].mark)
			{
				cout << "����" << endl;
				money += chip * 2;
			}
			else
			{
				cout << "��" << endl;
				money -= chip;
			}
		}
		else
		{
			cout << "��" << endl;
			money -= chip;
		}
	}
	else //false
	{
		if (cards[pick].number > cards[Nondisclosure].number)
		{
			cout << "����" << endl;
			money += chip * 2;
		}
		else if (cards[pick].number == cards[Nondisclosure].number)
		{
			if (cards[pick].mark > cards[Nondisclosure].mark)
			{
				cout << "����" << endl;
				money += chip * 2;
			}
			else
			{
				cout << "��" << endl;
				money -= chip;
			}
		}
		else
		{
			cout << "��" << endl;
			money -= chip;
		}
	}

	//����� ī������
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