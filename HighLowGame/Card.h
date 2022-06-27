#pragma once
#include<iostream>
#include<string>
#define Max 52

using namespace std;

enum CardMark
{
	Clover = 3,
	Heart = 2,
	Dia = 1,
	Spade = 0
};

struct stCard //자료형 선언(자료형 커스텀 선언)
{
	CardMark mark;
	int number;

	/*
	string GetStrMark()
	{
		switch (mark)
		{
		case Clover: return "Clover"; break;
		case Heart: return "Heart"; break;
		case Dia: return "Dia"; break;
		case Spade: return "Spade"; break;
		default: return""; break;
		}
	}
	*/

};
