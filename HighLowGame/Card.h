#pragma once

#define Max 52

enum CardMark
{
	Clover = 0,
	Heart,
	Dia,
	Spade
};

struct stCard //�ڷ��� ����(�ڷ��� Ŀ���� ����)
{
	CardMark mark;
	int number;
};
