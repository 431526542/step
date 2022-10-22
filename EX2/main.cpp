#include<iostream>
#include"FuncSum.h"
#include"FuncSum3.h"
#include"FuncRemain.h"
#include"FuncMinues.h"
#include"FuncDivid.h"
#include"FuncFmulit.h"
#include"FuncAverage.h"

using namespace std;

#define multi2(x) x*x

int main()
{
	int r = multi2(5+1);
	cout << r << endl;

	int Sum = { 0 };
	int a, b = { 0 };
	char c = 0;

	while (1)
	{
		cin >> a >> c >> b;

		switch (c)
		{
		case '+':
			Sum = a + b;
			break;
		case '-':
			Sum = a - b;
			break;
		case '*':
			Sum = a * b;
			break;
		case '/':
			Sum = a / b;
			break;
		case '%':
			Sum = a % b;
			break;
		case '^':
			Sum = funcFmulit(a, b);
			break;
		default:
			break;
		}
		cout << a << c << b << "=" << Sum << endl;
	}
	
	
}