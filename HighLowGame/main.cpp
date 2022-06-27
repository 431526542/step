#include<iostream>
#include"Card.h"
#include"Initialize.h"
#include"Common.h"
#include"Shuffle.h"
#include"CardChoice.h"


using namespace std;



void main()
{
	Initialize();
	while (1)
	{
		Shuffle();
		/*
		//카드출력
		for (int i = 0; i < Max; ++i)
		{
			cout << "Mark = " << cards[i].mark<< " " << "Number = " << cards[i].number << endl;
		}*/
		CardChoice();
	}
	
}