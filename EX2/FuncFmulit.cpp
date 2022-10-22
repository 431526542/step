#include"FuncFmulit.h"
int funcFmulit(int a, int b)
{
	int Sum = 1;

	for (int i = 0; i < b; ++i)
	{
		Sum *= a;
	}

	return Sum;
}