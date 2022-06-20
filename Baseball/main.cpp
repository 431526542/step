#include<iostream>

using namespace std;

int main()
{
	int arr[10] = { 30,18,10,42,2,9,13,24,50,22 };

	




	for (int i = 0; i < 11; ++i)
	{
		cout << arr[i] <<",";
	}
	



	/*
	//야구경기
	int a[3] = { 1,2,3 };
	int b[3] = { 0 };

	while (1)
	{
		cin >> b[0] >> b[1] >> b[2];

		system("cls");
		int streak = { 0 };
		int ball = { 0 };
		int out = { 0 };

		for (int i = 0; i < 3; ++i)
		{
			if (a[i] == b[i])
			{
				streak++;
			}

			for (int j = 0; j < 3; ++j)
			{
				if (i == j)
					continue; //i랑j가 같다면  밑에있는걸 실행하지 않고 for문을 실행
				if (a[i] == b[j])
				{
					ball++;
					break; // 다 찾으면 for 문이 break된다
				}
			}
	
		}

		cout << endl;	

		if (streak == 0 && ball == 0)
		{
			cout << "OUT" << endl;
		}
		else if (streak == 3)
		{
			cout << "경기종료" << endl;
		}
		else
		{
			cout << "S : " << streak << "B : " << ball << endl;
		}
	}*/
}