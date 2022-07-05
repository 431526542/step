#include<iostream>
#include<string>
#include<vector>

using namespace std;

//(1)
void StringCutHalfwithKey(const string& source, char key, string& leftstr, string& rightstr)
{
	int index = source.find(key);
	leftstr = source.substr(0, index);
	rightstr = source.substr(index+1, source.length());
}
//(2)
vector<string> StringCutByKey(const string& source, char key) //벡터값 한수 사용시 이렇게 사용함
{
	vector<string>arrStr;

	int findKey = 0; //강사님 정답
	while (1)
	{
		int temp = source.find(key, findKey); //name=join 
		if (temp == string::npos) // temp = 9
			break;
		
		arrStr.push_back(source.substr(findKey, temp - findKey));
		findKey = temp + 1;
	}
	arrStr.push_back(source.substr(findKey));

	return arrStr;
}
//(3)
struct student
{
	string name;
	float score;
	int age;

	void printInfo()
	{
		cout << "name = " << name << " score = " << score << " age = " << age << endl;
	}

};

int main()
{
	student st1;
	string strData = "name=john score=3.6 age=20";
	vector<string>arrStr = StringCutByKey(strData, ' ');
	for (string s : arrStr)
	{
		string left = "";
		string right = "";
		StringCutHalfwithKey(s, '=', left, right);
		if (left == "name")
		{
			st1.name = right;
		}
		else if (left == "score")
		{
			st1.score = stoi(right);
		}
		else if (left == "age")
		{
			st1.age = stoi(right);
		}
	}
	st1.printInfo();

	//더하기//
	/*
	string str = "123+456";
	cin >> str;
	int point = str.rfind("+"); //문자열의 위치가 찍힌다. +의 위치가 왼쪽 부터 0 1 2 3번째 이기 때문이다.
	cout << "point = " << point << endl;

	string leftstr = str.substr(0, point); // 0부터 point 까지 짜르는것
	cout << "leftstr = " << leftstr << endl;

	string  rightstr = str.substr(point + 1, str.length());
	cout << "rightstr = " << rightstr << endl;

	int leftNum = stoi(leftstr);
	int rightNum = stoi(rightstr);//문자를 숫자로 변형해주는 프로그램
	cout << "leftNum = " << leftNum << endl;
	cout << "rightNum = " << rightNum << endl;
	cout << "leftNum + rightNum = " << leftNum + rightNum << endl;
	*/
	//빼기//
	/*
	string str = "123-456";
	int point = str.find("-");
	cout << point << endl;
	string leftstr = str.substr(0, point);
	string rightstr = str.substr(point + 1, str.length());
	int leftNum = stoi(leftstr);
	int rightNum = stoi(rightstr);
	cout << "leftNum - rightNum = " << leftNum - rightNum << endl;
	*/
	//vector를 사용한 어래이 스트링 AAA BBB 따로 출력//
	/*
	vector<string> arrString;
	string str = "AAA BBB CCC DDD EEE FFF GGG HHH";
	for (int i = 0; i < 8; ++i)
	{
		int temp = str.find(" ");
		string tempstr = str.substr(i*4, temp);
		arrString.push_back(tempstr);
		cout << "arrString[" << i << "] = " << arrString[i] << endl;
	}

	int findKey = 0; //강사님 정답
	while (1)
	{
		int temp = str.find(" ", findKey);
		if (temp == string::npos)
			break;

		arrString.push_back(str.substr(findKey,temp-findKey));
		findKey = temp + 1;
	}
	for (string s : arrString)
	{
		cout << "arrString[" << findKey << "] = " << s << endl;
	}
	*/
	//arrString[0]="AAA", arrInt[0]=111이런식으로 출력//
	/*
	vector<string> arrString;
	vector<int> arrInt;
	string str = "AAA=111 BBB=222 CCC=333 DDD=444 EEE=555";
	for (int i = 0; i < 5; ++i)
	{
		int Apoint = str.find("=");
		int Numpoint = str.find(" ");

		arrString.push_back(str.substr(i * 8, Apoint));
		arrInt.push_back(stoi(str.substr(i * 8 + 4, Numpoint)));
		cout << "arrString[" << i << "] = "  << arrString[i] << " ,arrInt[" << i << "] = " << arrInt[i] << endl;
	}

	int findKey = 0; //강사님 정답
	while (1)
	{
		int temp = str.find(" ", findKey);
		if (temp == string::npos)
			break;

		string subStr = str.substr(findKey, temp - findKey);
		int subTemp = str.find("=");
		arrString.push_back(subStr.substr(0, subTemp));
		string strNum = subStr.substr(subTemp + 1, subStr.length());
		arrInt.push_back(stoi(strNum));
		findKey = temp + 1;
	}
	for (string s : arrString)
	{
		cout << s << endl;
	}
	*/
	//(1) StringCutHalfwithKey 출력하기
	/*
	vector<string> arrString;
	vector<int> arrInt;
	string a = "AAA=111 BBB=222 CCC=333 DDD=444 EEE=555";

	int findKey = 0; //강사님 정답
	while (1)
	{
		int temp = a.find(" ", findKey);
		if (temp == string::npos)
			break;

		string subStr;
		string strNum;
		StringCutHalfwithKey(a.substr(findKey, temp - findKey), '=', subStr, strNum);
		arrString.push_back(subStr);
		arrInt.push_back(stoi(strNum));
		findKey = temp + 1;
	}
	for (string s : arrString)
	{
		cout << s << endl;
	}
	for (int s : arrInt)
	{
		cout << s << endl;
	}*/
	//(2) 벡터값 함수 StringCutByKey 만들고 출력하기
	/*
	string a = "aaa bbb ccc ddd eee";

	vector<string>arrStr = StringCutByKey(a, ' ');

	for (string s : arrStr)
	{
		cout << s << endl;
	}
	*/
	//(2)
	/*
	vector<string> arrString;
	vector<int> arrInt;
	string str = "AAA=111 BBB=222 CCC=333 DDD=444 EEE=555";

	vector<string>arrStr = StringCutByKey(str, ' ');

	for (string s : arrStr)
	{
		string subStr,  strNum;
		StringCutHalfwithKey(s, '=', subStr, strNum);
		arrString.push_back(subStr);
		arrInt.push_back(stoi(strNum));
	}

	for (string s : arrString)
	{
		cout << s << endl;
	}

	for (int s : arrInt)
	{
		cout << s << endl;
	}*/

}