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

vector<string> StringCutByKey(const string& source, char key) //���Ͱ� �Լ� ���� �̷��� �����
{
	vector<string>arrStr;

	int findKey = 0; //����� ����
	while (1)
	{
		int temp = source.find(key, findKey); //name=join 
		if (temp == string::npos) // temp = 9
			break;

		string out = source.substr(findKey, temp - findKey);
		out.erase(remove(out.begin(), out.end(), ' '), out.end());//ex)name =  jin ���� ������� �ڷ� ���� "name=jin   "��������������� ������ �����. "name=jin"�̷��� �ȴ�.
		arrStr.push_back(out);
		findKey = temp + 1;
	}

	string out = source.substr(findKey);
	out.erase(remove(out.begin(), out.end(), ' '), out.end());//ex)name =  jin ���� ������� �ڷ� ���� "name=jin   "��������������� ������ �����. "name=jin"�̷��� �ȴ�.
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

//176���� �ٸ� ������ ����ҽ� �Ʒ��� ���� ���ش�.
/*
bool compare(student a, student b)
{
	return a.age > b.age;
}
*/

int main()
{
	//�⺻ ���� ������ ���õȰ�
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
		cout << "���������� �����߽��ϴ�" << endl;
	}
	*/

	vector<student> arrSd;
	string line;
	ifstream file("writeFile.txt");
	int i = { 0 };//(3) 4���� 5���� ���� �����
	if (file.is_open())
	{
		while (getline(file, line)) //getline�� �� ifstream file�� file�� ���پ� �а� line�ȿ� �ִ´�.
		{
			/*
			student newarrsd; //(1)arrSd�� �ƹ��͵� ������  �̸� ������ �ϳ� ����� �ְ�
			int point = line.find("=");
			arrSd.push_back(newarrsd);//(2)1�� ���� ������ arrSd�� Ǫ����
			arrSd[i].name = line.substr(point + 1, line.length());//(4) arrsd�� line��1��° �̸��� ����
			++i;//(5) 4�������� �ٸ� �̸��� ���� �� ������ i�� ��ĭ�� �÷� ���� ����
			*/
			/*
			student st;
			string left;
			string right;
			StringCutHalfwithKey(line, '=', left, right);
			st.name = right;
			arrSd.push_back(st);
			*/
			/* //�̿ϼ�
			student sd;
			int Apoint = line.find("=");
			int Bpoint = line.find(" ");
			int Cpoint = line.rfind("=");
			arrSd.push_back(sd);
			arrSd[i].name = line.substr(Apoint + 1, Bpoint);
			arrSd[i].score = stof(line.substr(Cpoint + 1, line.length()));//stof�� float ǥ����
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
		cout << "�����б⸦ �����߽��ϴ�" << endl;
	}

	//sort(arrSd.begin(), arrSd.end(), compare); //�̹���� �ٸ� ����� �Ʒ���
	sort(arrSd.begin(), arrSd.end(), [](student a, student b) {return a.age > b.age; });

	for (student s : arrSd)
	{
		s.printInfo();
	}
}