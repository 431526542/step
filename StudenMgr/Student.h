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
		cout << "�̸� : " << mName << " , " << mClassNum << " " << "���� : " << mScore << endl;
	}

	string GetName() { return mName; }; //��ȯ���ִ� �Լ�
	int GetClassNume() { return mClassNum; };
	int GetScore() { return mScore; };

private:
protected:
};