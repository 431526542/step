#include<iostream>
#include"Student.h"
#include<vector>
#include<map>

using namespace std;

unsigned int UniqueID = 0;

unsigned int CreateUniqueID()
{
	return ++UniqueID;
}

int main()
{
	vector<Student> vecStudent;
	map<unsigned int, Student> mapStudent; //<string, Student>���� ù��°�� Ű����, �ι�°�� Ű���� ���� ������ �������̴�.


	//Student aaa = { "�̸�", 1,100 };
	//vecStudent.push_back(aaa); //aaa��°� vector<Student>�� ����.
	//vecStudent.erase(vecStudent.begin()+1); //erase�� vecStudent.begin()���� �� ���ڿ��ִ� �迭 ��ȣ�� �����.
	string name = "";
	int classNum = 0;
	int score = 0;

	
	bool check = 1;
	int mgrType = 0;
	while (check)
	{
		switch (mgrType)
		{
		case 1:
		{
			cout << "�̸� : ";
			cin >> name;
			cout << "�� : ";
			cin >> classNum;
			cout << "���� : ";
			cin >> score;

			Student aaa = { name, classNum, score };
			//vecStudent.push_back(aaa);//���͸� �̿��� Ǫ��
			mapStudent.insert({ CreateUniqueID(), aaa });//���� �̿��� Ǫ��

			char hook;
			cout << "��� �߰��Ͻðڽ��ϱ�? (Y/N)";
			cin >> hook;
			if (hook == 'Y')
			{
				mgrType = 1;
			}
			else
			{
				mgrType = 0;
			}
			break;
		}

		case 2:
		{
			//int index = 0;//�����̿�� index�̴�.
			unsigned int index = 0;
			for (Student s : vecStudent)
			{
				s.PrintInfo();
			}
			//cout << "���° �л��� ����ڽ��ϱ�? : "; //���͸� �̿�������
			cout << "������ �л��� �̸��� �Է��ϼ���";
			cin >> index;
			//vecStudent.erase(vecStudent.begin() + index - 1);//���͸� �̿��� ����
			if (mapStudent.find(index) != mapStudent.end())
			{
				mapStudent.erase(index); //���� �̿��� ����
			}
			
			mgrType = 0;
			break;
		}

		case 3:
		{
			unsigned int uniqueID = 0;  //string���� �޾Ƽ� �̸��� ���� �л��� ã�� ���
			cout << "uniqueID�� �Է��Ͻÿ� : ";
			cin >> uniqueID;
			/*
			for (int i = 0; i < vecStudent.size(); ++i)  //���͸� �̿����� ��
			{
				if (vecStudent[i].GetName() != name)
					continue;

				vecStudent[i].PrintInfo();
			}*/
			//find�� �����ߴٸ� ã�� ��ü�� map �ּ� ��ȯ ���ٸ� map�� ������ �ּ� ��ȯ
			//find�� �����ߴٸ� map�� ������ �ּ� ��ȯ
			auto iter = mapStudent.find(uniqueID); //���� �̿��� ã��
			if (iter != mapStudent.end())
			{
				iter->second.PrintInfo();
			}
			mgrType = 0;
			break;
		}

		case 4:
		{
			//for (auto iter = mapStudent.begin(); iter != mapStudent.end(); iter++)//�̰͵� �����ϴ� //����
			for (auto iter : mapStudent)//����
			{
				cout << "UniqueID = " << iter.first << " ";
				iter.second.PrintInfo();
			}
			/*
			for (int i = 0; i < vecStudent.size(); ++i) //���͸� �̿��� ��
			{
				cout << "index = " << i << " ";
				vecStudent[i].PrintInfo();
			}*/
			/*
			for (Student s : vecStudent)
			{
				s.PrintInfo();
			}*/
			mgrType = 0;
			break;
		}
		case 5:
		{
			cout << "���� �����ðڽ��ϱ�? (Y/N) ";
			char hook;
			cin >> hook;
			if (hook == 'Y')
			{
				check = 0;
			}
			else
			{
				mgrType = 0;
			}
			break;
		}

		default:
			cout << "[[StudentManager]]" << endl;
			cout << "1) add Student" << endl;
			cout << "2) delete Student" << endl;
			cout << "3) find Student" << endl;
			cout << "4) print all Student" << endl;
			cout << "5) exit" << endl;
			cin >> mgrType;
			system("cls");
			break;
		}
	}

	for (Student s : vecStudent)
	{
		s.PrintInfo();
	}
	


}