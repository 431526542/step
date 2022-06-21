#include<iostream>
#include<string>

using namespace std;

char* copyString(const char* str)
{
	char* result = new char[strlen(str)+1];
	strcpy_s(result, strlen(str)+1, str);
	return result;
}

char* appendStrings(const char* str1, const char* str2, const char* str3)
{
	int size = strlen(str1) + strlen(str2) + strlen(str3) + 1;
	char* result = new char[strlen(str1) + strlen(str2) + strlen(str3) + 1];
	strcpy_s(result, size, str1); // ���ڿ��� ����
	strcpy_s(result, size, str2); // ���ڿ��� ���̱�
	strcpy_s(result, size, str3); //���ڿ��� ���̱�
	return result;
}

string_view extractExtension(string_view filleName)
{
	return filleName.substr(filleName.rfind('.')); //������ ���ڿ� ã��
}

int main()
{

	char* c = appendStrings("Hello1", "Hello2", "Hello3");
	cout << c << endl;
	size_t s1 = sizeof(c);//������� ���� ���ϴ� ��ɾ�� �̰�
	size_t s2 = strlen(c);
	cout << "sizeof = " << s1 << "strlen = " << s2 << endl;

	const char* str1 = "Hello \"World\"!";
	const char* str2 = R"(Hello "World"!)";
	const char* str3 = "Line1\n/line2";
	const char* str4 =
R"(Line1
line2)";
	cout << str1 << str2 << str3 << str4 << endl;

	//---------[string]-----------------------------//
	string A("12");
	string B("34");
	string C;
	C = A + B;
	cout << C << endl;

	string myString = "hello";
	myString += " , there ";
	string my0therString = myString;
	if (myString == my0therString)
	{
		my0therString[0] = 'H';
	}
	cout<< myString <<endl;
	cout << my0therString << endl;

	auto temp = 1.0;
	auto string1 = "Hello World";
	auto string2 = "Hello World"s;

	long double d = 3.14L;
	string string3 = to_string(d);

	const string toParse = "123USD";
	size_t index = 0;
	int value = stoi(toParse, &index);
	cout << "Parse value : " << value << endl;
	cout << "First non-parsed charactor : " << toParse[index] << "'" << endl;



	string str11 = "Hello";
	string_view sv = " world";
	auto result = str11 + sv.data();



	string fileName = R"(C:\temp\my file.ext)";
	cout << "C++ string : " << extractExtension(fileName) << endl;

	const char* cString = R"(C:\temp\my file.ext)";
	cout << "C string : " << extractExtension(cString) << endl;

	cout << "Literal : " << extractExtension(R"(C:\temp\my file.ext)") << endl;
}