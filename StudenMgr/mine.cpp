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
	map<unsigned int, Student> mapStudent; //<string, Student>에서 첫번째는 키워드, 두번째는 키워드 사용시 저장할 데이터이다.


	//Student aaa = { "이름", 1,100 };
	//vecStudent.push_back(aaa); //aaa라는게 vector<Student>로 들어간다.
	//vecStudent.erase(vecStudent.begin()+1); //erase은 vecStudent.begin()에서 그 숫자에있는 배열 번호를 지운다.
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
			cout << "이름 : ";
			cin >> name;
			cout << "반 : ";
			cin >> classNum;
			cout << "점수 : ";
			cin >> score;

			Student aaa = { name, classNum, score };
			//vecStudent.push_back(aaa);//벡터를 이용한 푸쉬
			mapStudent.insert({ CreateUniqueID(), aaa });//맵을 이용한 푸쉬

			char hook;
			cout << "계속 추가하시겠습니까? (Y/N)";
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
			//int index = 0;//벡터이용시 index이다.
			unsigned int index = 0;
			for (Student s : vecStudent)
			{
				s.PrintInfo();
			}
			//cout << "몇번째 학생을 지우겠습니까? : "; //백터를 이용했을때
			cout << "제거할 학생의 이름을 입력하세요";
			cin >> index;
			//vecStudent.erase(vecStudent.begin() + index - 1);//벡터를 이용한 제거
			if (mapStudent.find(index) != mapStudent.end())
			{
				mapStudent.erase(index); //맵을 이용한 제거
			}
			
			mgrType = 0;
			break;
		}

		case 3:
		{
			unsigned int uniqueID = 0;  //string값을 받아서 이름이 같은 학생을 찾아 출력
			cout << "uniqueID를 입력하시오 : ";
			cin >> uniqueID;
			/*
			for (int i = 0; i < vecStudent.size(); ++i)  //벡터를 이용했을 때
			{
				if (vecStudent[i].GetName() != name)
					continue;

				vecStudent[i].PrintInfo();
			}*/
			//find가 성공했다면 찾은 객체의 map 주소 반환 없다면 map에 마지막 주소 반환
			//find가 실패했다면 map에 마지막 주소 반환
			auto iter = mapStudent.find(uniqueID); //맵을 이용한 찾기
			if (iter != mapStudent.end())
			{
				iter->second.PrintInfo();
			}
			mgrType = 0;
			break;
		}

		case 4:
		{
			//for (auto iter = mapStudent.begin(); iter != mapStudent.end(); iter++)//이것도 가능하다 //맵형
			for (auto iter : mapStudent)//맵형
			{
				cout << "UniqueID = " << iter.first << " ";
				iter.second.PrintInfo();
			}
			/*
			for (int i = 0; i < vecStudent.size(); ++i) //백터를 이용힌 것
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
			cout << "정말 나가시겠습니까? (Y/N) ";
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