#include "Shuffle.h"
#include"Card.h"
#include"Initialize.h"
#include"Common.h"
#include<iostream>

void Shuffle()
{
	//ī�弯��
	srand((unsigned int)time(NULL)); //�ð����� �������ش�.

	for (int i = 0; i < 52; ++i)
	{
		int FirstNumber = rand() % 52;
		int SecondNumber = rand() % 52;

		stCard Temp = cards[FirstNumber];
		cards[FirstNumber] = cards[SecondNumber];
		cards[SecondNumber] = Temp;
	}
}
