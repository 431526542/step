#include<iostream>

using namespace std;

class Apple
{
public:
	int Color;
	int Shape;
	bool Fruit;
	void Delicous()
	{
		cout << "����� " << Shape;
		cout << "������ " << Color;
		cout << "������ " << Fruit;
	}
};

int main()
{
	Apple* MyApple = new Apple();

	MyApple->Color = 1;
	MyApple->Shape = 2;
	MyApple->Fruit = true;
	MyApple->Delicous();

	delete MyApple;

	return 0;
}