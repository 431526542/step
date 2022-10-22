#include<iostream>

using namespace std;

struct Storage
{
	int Patato;
	int Onion;
	int Carrot;

	void addVege(int a, int b, int c)
	{
		Patato += a;
		Onion += b;
		Carrot += c;
	}

	void MinuesVege(int a, int b, int c)
	{
		Patato -= a;
		if (Patato <= 0)
		{
			Patato = 0;
		}

		Onion -= b;
		if (Onion <= 0)
		{
			Onion = 0;
		}

		Carrot -= c;
		if (Carrot <= 0)
		{
			Carrot = 0;
		}
	}

	void MoveStorage(Storage& target)
	{
		Patato += target.Patato;
		Onion += target.Onion;
		Carrot += target.Carrot;

		target.Patato = 0;
		target.Onion = 0;
		target.Carrot = 0;
	}

	bool Tick()
	{
		int Order = 0;
		int a, b, c = { 0 };

		cout << " ���� : " << Patato << " ���� : " << Onion << " ��� : " << Carrot << endl;
		cout << " 0) â�� �������� ���ư��ϴ�. " << endl;
		cout << " 1) â�� ä�Ҹ� �ֽ��ϴ�. " << endl;
		cout << " 2) â�� ä�Ҹ� �����ϴ�. " << endl;
		cin >> Order;

		switch (Order)
		{
		case 0:
			return true; //TargetStorage = 0
			break;

		case 1:
			cout << "���� ���� ��� ������� ���� ä�Ҹ� �Է��ϼ���." << endl;
			cin >> a >> b >> c;
			addVege(a, b, c);
			break;

		case 2:
			cout << "���� ���� ��� ������� ���� ä�Ҹ� �Է��ϼ���." << endl;
			cin >> a >> b >> c;
			MinuesVege(a, b, c);
			break;
		}
		
		return false;
	}
};

int main()
{
	Storage s1 = { 0 };
	Storage s2 = { 100, 100, 100 };
	int TargetStorage = { 0 };
	int Order = { 0 };
	
	while (1)
	{
		system("cls");
		switch (TargetStorage)
		{
		case 1:
		{
			cout << " s1 â�� �Դϴ� " << endl;
			bool result = s1.Tick();
			if (result)
				TargetStorage = 0;
		}
				break;

		case 2:
		{
			cout << " s2 â�� �Դϴ� " << endl;
			bool result = s2.Tick();
			if (result)
				TargetStorage = 0;
		}
			break;

		default:
			cout << " 1 ) s1 â�� " << endl;
			cout << " 2 ) s2 â�� " << endl;
			cin >> TargetStorage;
			break;
		}
	}


}