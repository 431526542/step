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
		cout << "모양은 " << Shape;
		cout << "색깔은 " << Color;
		cout << "과일은 " << Fruit;
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