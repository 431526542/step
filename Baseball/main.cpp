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
	//�߱����
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
					continue; //i��j�� ���ٸ�  �ؿ��ִ°� �������� �ʰ� for���� ����
				if (a[i] == b[j])
				{
					ball++;
					break; // �� ã���� for ���� break�ȴ�
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
			cout << "�������" << endl;
		}
		else
		{
			cout << "S : " << streak << "B : " << ball << endl;
		}
	}*/
}