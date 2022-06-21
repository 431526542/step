#include<iostream>

using namespace std;

int main()
{	


	//배열 작은값을 앞으로 변경
	int arr[10] = { 10, 3, 4, 17, 20, 30, 14, 21, 19, 7 };

	for (int i = 0; i < 10; ++i)
	{
		int lowest = i;
		for (int j = i + 1; j < 10; ++j)
		{
			if (arr[lowest] > arr[j])
				lowest = j;
		}

			int temp = arr[lowest];
			arr[lowest] = arr[i];
			arr[i] = temp;
		
	}
	for (int itr : arr)
	{
		cout << itr << " ";
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