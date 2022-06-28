#pragma once
#include<iostream>

using namespace std;

class Student
{
	string mName;
	int mClassNum;
	int mScore;

public:
	Student(string Name, int ClassNum, int Score) : mName(Name), mClassNum(ClassNum), mScore(Score) {};

	void PrintInfo()
	{
		cout << "이름 : " << mName << " , " << mClassNum << " " << "점수 : " << mScore << endl;
	}

	string GetName() { return mName; }; //반환해주는 함수
	int GetClassNume() { return mClassNum; };
	int GetScore() { return mScore; };

private:
protected:
};