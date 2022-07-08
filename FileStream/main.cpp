#include<iostream>
#include<string>
#include<vector>
#include<fstream>
#include<algorithm>

using namespace std;

void StringCutHalfwithKey(const string& source, char key, string& leftstr, string& rightstr)
{
	int index = source.find(key);

	leftstr = source.substr(0, index);
	leftstr.erase(remove(leftstr.begin(), leftstr.end(), ' '), leftstr.end());

	rightstr = source.substr(index + 1, source.length());
	rightstr.erase(remove(rightstr.begin(), rightstr.end(), ' '), rightstr.end());
}

vector<string> StringCutByKey(const string& source, char key) //벡터값 함수 사용시 이렇게 사용함
{
	vector<string>arrStr;

	int findKey = 0; //강사님 정답
	while (1)
	{
		int temp = source.find(key, findKey); //name=join 
		if (temp == string::npos) // temp = 9
			break;

		string out = source.substr(findKey, temp - findKey);
		out.erase(remove(out.begin(), out.end(), ' '), out.end());//ex)name =  jin 에서 빈공간을 뒤로 보내 "name=jin   "빈공간시작점에서 끝까지 지운다. "name=jin"이렇게 된다.
		arrStr.push_back(out);
		findKey = temp + 1;
	}

	string out = source.substr(findKey);
	out.erase(remove(out.begin(), out.end(), ' '), out.end());//ex)name =  jin 에서 빈공간을 뒤로 보내 "name=jin   "빈공간시작점에서 끝까지 지운다. "name=jin"이렇게 된다.
	arrStr.push_back(out);

	return arrStr;
}

void ReadStudent(student& st,const string& str)
{
	vector<string>arrstr = StringCutByKey(line, ',');
	for (string s : arrstr)
	{
		string left;
		string right;
		StringCutHalfwithKey(s, '=', left, right);
		if (left == "name")
		{
			st.name = right;
		}
		else if (left == "age")
		{
			st.age = stoi(right);
		}
		else if (left == "score")
		{
			st.score = stof(right);
		}

	}
}


struct student
{
	string name = "";
	int age = 0;
	float score = 0;

	void printInfo()
	{
		cout << "name = " << name << " score = " << score << " age = " << age << endl;
	}
};

//176번과 다른 버전을 사용할시 아래와 같이 켜준다.
/*
bool compare(student a, student b)
{
	return a.age > b.age;
}
*/

int main()
{
	//기본 파일 생성과 관련된것
	/*
	string str = "dddddddddd";
	ofstream file("writeFile.txt");
	if (file.is_open())
	{
		file << "aaaaaaaaaaa\n";
		file << "11111111111" << endl;
		file << "ccccccccccc" << endl;
		file << str;
		file.close();
	}
	else
	{
		cout << "파일저장을 실패했습니다" << endl;
	}
	*/

	vector<student> arrSd;
	string line;
	ifstream file("writeFile.txt");
	int i = { 0 };//(3) 4번과 5번을 위해 만든것
	if (file.is_open())
	{
		while (getline(file, line)) //getline은 위 ifstream file의 file을 한줄씩 읽고 line안에 넣는다.
		{
			/*
			student newarrsd; //(1)arrSd에 아무것도 없으니  미리 파일을 하나 만들어 주고
			int point = line.find("=");
			arrSd.push_back(newarrsd);//(2)1에 만든 파일을 arrSd에 푸쉬백
			arrSd[i].name = line.substr(point + 1, line.length());//(4) arrsd에 line의1번째 이름을 저장
			++i;//(5) 4번저장후 다른 이름이 있을 수 있으니 i를 한칸더 올려 파일 만듬
			*/
			/*
			student st;
			string left;
			string right;
			StringCutHalfwithKey(line, '=', left, right);
			st.name = right;
			arrSd.push_back(st);
			*/
			/* //미완성
			student sd;
			int Apoint = line.find("=");
			int Bpoint = line.find(" ");
			int Cpoint = line.rfind("=");
			arrSd.push_back(sd);
			arrSd[i].name = line.substr(Apoint + 1, Bpoint);
			arrSd[i].score = stof(line.substr(Cpoint + 1, line.length()));//stof는 float 표현식
			++i;*/
			/*
			student st;
			vector<string>arrstr = StringCutByKey(line, ',');
			for (string s : arrstr)
			{
				string left;
				string right;
				StringCutHalfwithKey(s, '=', left, right);
				if (left == "name")
				{
					st.name = right;
				}
				else if (left == "age")
				{
					st.age = stoi(right);
				}
				else if (left == "score")
				{
					st.score = stof(right);
				}
				
			}
			arrSd.push_back(st);*/
			student st;
			ReadStudent(st, line);
			arrSd.push_back(st);
		}
		file.close();
	}
	else
	{
		cout << "파일읽기를 실패했습니다" << endl;
	}

	//sort(arrSd.begin(), arrSd.end(), compare); //이방법과 다른 방법은 아래에
	sort(arrSd.begin(), arrSd.end(), [](student a, student b) {return a.age > b.age; });

	for (student s : arrSd)
	{
		s.printInfo();
	}
}