#include<iostream>
#include<string>

using std::cin;
using std::cout;
using std::endl;
using std::string;

int main()
{
	//string line;
	/*while (getline(cin, line))
	{
		cout << line << endl;
		cout << "����"<<line.size() <<"���ַ�"<< endl;
	}*/
	//string a = "abc";
	//string b = "bcd";
	//cout << (a < b);

	//3.5
	//string a, b;
	//while (getline(cin, a))
	//{
	//	b = b + a;        //���Ҫ�ո�Ļ�Ҫ��+�� ��
	//	cout << b << endl;
	//}

	//test
	//string s("hello");
	//for(auto c:s)
	//cout << c << endl;

	//string line;
	//getline(cin, line);
	//cout << line;

	//3.6
	string line36("ahfahgklah");
	for (auto &c : line36)           //�ǵ�һ��Ҫ�����òſ����޸ĵ�ԭֵ��
		c = 'X';
	cout << line36 << endl;
	//3,7
	string line37("safhkahgkha");
	for (string::size_type i = 0; i < line37.size(); i++)
		line37[i] = 'X';
	cout << line37 << endl;
	//3.10
	string line310("sahkgak,agkl,aljg");
	for (auto c : line310)
	{
		if (!ispunct(c))
			cout << c;
	}


	return 0;
}