#include<iostream>
#include<string>
#include<conio.h>
#include"input.h"
#include"Process.h"
#include"Draw.h"
#include"Player.h"
#include"Map.h"

using namespace std;

//���ڽ����Լ�
/*
void Swap(int* X, int* Y)
{
	int Temp = *X;
	*X = *Y;
	*Y = Temp;
}*/
//����

int main()
{	
	//int*, &���� *������ ����
	/*
	int Gold = 100; 
	int* PGoid = &Gold;
	������ �޸𸮿� ����, �ؿ��ִ�&Gold�� �޸𸮿� �ִ� Gold �ּҸ� �������°�, int* �� ������ ��ġ�� ��� �׷���
	int* PGoid = &Gold; �̷��� �����ϸ� �ּҸ� �����ü� �ִ�. �����غ��� ->cout << (&Gold) << endl;, cout << PGoid << endl;
	�غ��� �Ȱ��� �ּҰ��� ���´�. ������ ���� Gold�� �ּҰ��� �ƴ� ���� ����ʹ�. �׷��� cout << *PGoid << endl; ���ָ� �ȴ�.
	�������ڸ� PGoid�� &Gold�� �ּҰ��� ������ �ְ� *PGold�� PGoid�� ������ �ִ� �ּҰ��� ���� ���ϴ� ���̴�. 

	cout << (&Gold) << endl;
	cout << PGoid << endl;
	cout << *PGoid << endl;*/
	//���� ���� �Լ�
	/*
	int A = 5;
	int B = 3;

	cout << A << "," << B << endl;
	Swap(&A, &B);
	cout << A << "," << B << endl;*/
	//heap
	/*
	int* PGold = new int();
	//int ������ �޸𸮰��� heap������ �ڸ��� ������ PGold�� �ڸ��ּҰ� ��ȯ�Ѵ�. �̰��� ���� ��������� ������� �ʰ� �޸𸮿� ������ �����Ѵ�.
	*PGold = 100; //PGold���� �ּҰ��� ã�� �� �ּ� �ڸ��� 100�� �ִ´�.
	cout << PGold << endl;
	cout << *PGold << endl;
	delete PGold; //���� ���� ��
	
	int* Scores = new int[10];
	cout << (&Scores[0]==Scores) << endl;
	cout << (&Scores[0]) << endl;
	cout << (Scores) << endl;
	Scores[0] = 1;
	*Scores = 1;
	Scores[1] = 2;
	*(Scores + 1) = 2;
	delete[] Scores; //�迭���� �ʱ�ȭ �ϴ� ���̴�. delete Scores; -> 1ĭ�� �����.

	int Number = 0;
	cin >> Number;
	int* Count = new int[Number];
	for (int i = 0; i < Number; ++i)
	{
		Count[i] = i;
	}
	for (int i = 0; i < Number; ++i)
	{
		cout << Count[i] << endl;
	}
	delete[] Count;//new -> delete, new[] -> delete[]
	*/
	//���� ����
	/*
	char Greeting[6]; //Hello�� ����ϰ� �ʹ�.
	Greeting[0] = 'H';
	Greeting[1] = 'e';
	Greeting[2] = 'l';
	Greeting[3] = 'l';
	Greeting[4] = 'o';
	Greeting[5] = 0; //nullǥ�÷� '\0'�� ǥ�� �� �� �ִ�. �̰� ������ ��ǻ�Ͱ� ���� �� �� �����Ƿ� �̻��� ���ڰ�������.
	cout << Greeting << endl;

	string Greeting2 = "Hello";
	cout << Greeting2 << endl;
	*/
	//����
	MyPlayer = new struct Player(); 
	/*���� MyPlayer = new struct Player();���� MyPlayer->X = 1;�� ����Ѵٸ� 
	������ �߻��Ѵ�. ���� �� ������ Ȯ�� �ϰ������ 
	if(MyPlayer !=nullptr)
	{
		MyPlayer->X = 1;
		MyPlayer->Y = 1;
	}
	�� ġ�� �ȴ�.*/
	if (MyPlayer)
	{
		MyPlayer->X = 1;
		MyPlayer->Y = 1;
	}

	cout << "������ ����" << endl;
	cout << "�ƹ�Ű�� �����ÿ�" << endl;

	while (true)
	{
		int KeyCode = input();
		Process(KeyCode);
		Draw();
	}

	delete MyPlayer;
	MyPlayer = nullptr; //<-�ܿ��
	//dangling pointer
	//MyPlayer->X++; (while ���̾����� ���Լ��� �Է��� �����ϸ� �۵��� �����ȴ�.)
	//��ü�� �ִµ� �װ��� ���� ������ ���� �ʴ� ���
	return 0;
}





