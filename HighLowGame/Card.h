#pragma once

#define Max 52

enum CardMark
{
	Clover = 0,
	Heart,
	Dia,
	Spade
};

struct stCard //자료형 선언(자료형 커스텀 선언)
{
	CardMark mark;
	int number;
};
