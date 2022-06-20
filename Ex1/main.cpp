#include<iostream>

using namespace std;

int main()
{	
	
	int n;
	cin >> n;

	for (int i = 1; i <= n; ++i)
	{
		for (int j = 0; j <= n - 1; ++j)
		{
			cout << "";
			for (int k; k = j+1; ++k)
			{
				cout << "*";
			}
		}
		cout << "";
	}
	/*
	float tall, weight = { 0 };
	cin >> tall >> weight;

	float reweight = (tall - 100) * 0.9;
	float obesity = ((weight - reweight) * 100) / reweight;

	if (obesity <= 10)
	{
		cout << "정상" << endl;
	}
	else if (obesity>20)
	{
		cout << "비만" << endl;
	}
	else
	{
		cout << "과체중" << endl;
	}
	*/
}