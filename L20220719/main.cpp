#include<iostream>
#include<string>
#include<conio.h>
#include"input.h"
#include"Process.h"
#include"Draw.h"
#include"Player.h"
#include"Map.h"

using namespace std;

//숫자스왑함수
/*
void Swap(int* X, int* Y)
{
	int Temp = *X;
	*X = *Y;
	*Y = Temp;
}*/
//게임

int main()
{	
	//int*, &변수 *변수의 사용법
	/*
	int Gold = 100; 
	int* PGoid = &Gold;
	변수를 메모리에 저장, 밑에있는&Gold은 메모리에 있는 Gold 주소를 가져오는것, int* 은 정수형 위치를 기억 그래서
	int* PGoid = &Gold; 이러한 형태하면 주소를 가져올수 있다. 실험해보자 ->cout << (&Gold) << endl;, cout << PGoid << endl;
	해보면 똑같은 주소값이 나온다. 하지만 나는 Gold의 주소값이 아닌 값을 보고싶다. 그러면 cout << *PGoid << endl; 해주면 된다.
	정리하자면 PGoid는 &Gold에 주소값을 가지고 있고 *PGold은 PGoid가 가지고 있는 주소값의 값을 구하는 것이다. 

	cout << (&Gold) << endl;
	cout << PGoid << endl;
	cout << *PGoid << endl;*/
	//숫자 스왑 함수
	/*
	int A = 5;
	int B = 3;

	cout << A << "," << B << endl;
	Swap(&A, &B);
	cout << A << "," << B << endl;*/
	//heap
	/*
	int* PGold = new int();
	//int 형으로 메모리값에 heap구간에 자리를 잡은후 PGold로 자리주소값 반환한다. 이것은 종료 선언없으면 사라지지 않고 메모리에 영원히 존재한다.
	*PGold = 100; //PGold값의 주소값을 찾아 그 주소 자리에 100을 넣는다.
	cout << PGold << endl;
	cout << *PGold << endl;
	delete PGold; //종료 선언 문
	
	int* Scores = new int[10];
	cout << (&Scores[0]==Scores) << endl;
	cout << (&Scores[0]) << endl;
	cout << (Scores) << endl;
	Scores[0] = 1;
	*Scores = 1;
	Scores[1] = 2;
	*(Scores + 1) = 2;
	delete[] Scores; //배열값을 초기화 하는 법이다. delete Scores; -> 1칸만 지운다.

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
	//문자 저장
	/*
	char Greeting[6]; //Hello를 출력하고 싶다.
	Greeting[0] = 'H';
	Greeting[1] = 'e';
	Greeting[2] = 'l';
	Greeting[3] = 'l';
	Greeting[4] = 'o';
	Greeting[5] = 0; //null표시로 '\0'로 표현 할 수 있다. 이게 없으면 컴퓨터가 끝을 알 수 없으므로 이상한 문자가찍힌다.
	cout << Greeting << endl;

	string Greeting2 = "Hello";
	cout << Greeting2 << endl;
	*/
	//게임
	MyPlayer = new struct Player(); 
	/*만약 MyPlayer = new struct Player();없이 MyPlayer->X = 1;를 사용한다면 
	에러가 발생한다. 만약 이 오류를 확인 하고싶으면 
	if(MyPlayer !=nullptr)
	{
		MyPlayer->X = 1;
		MyPlayer->Y = 1;
	}
	를 치면 된다.*/
	if (MyPlayer)
	{
		MyPlayer->X = 1;
		MyPlayer->Y = 1;
	}

	cout << "게임을 시작" << endl;
	cout << "아무키나 누르시오" << endl;

	while (true)
	{
		int KeyCode = input();
		Process(KeyCode);
		Draw();
	}

	delete MyPlayer;
	MyPlayer = nullptr; //<-외우기
	//dangling pointer
	//MyPlayer->X++; (while 문이없을때 옆함수를 입력후 실행하면 작동이 중지된다.)
	//객체가 있는데 그것을 지워 실행이 되지 않는 경우
	return 0;
}





