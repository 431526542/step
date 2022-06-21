#include "Shuffle.h"
#include"Card.h"
#include"Initialize.h"
#include"Common.h"
#include<iostream>

void Shuffle()
{
	//카드섞기
	srand((unsigned int)time(NULL)); //시간값에 대입해준다.

	for (int i = 0; i < 52; ++i)
	{
		int FirstNumber = rand() % 52;
		int SecondNumber = rand() % 52;

		stCard Temp = cards[FirstNumber];
		cards[FirstNumber] = cards[SecondNumber];
		cards[SecondNumber] = Temp;
	}
}
