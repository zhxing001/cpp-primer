#include<vector>
#include<iostream>
#include<string>

using std::string;
using std::vector;
using std::cin;
using std::cout;
using std::endl;

int main()
{
	//vector<string> s1{ 10 ,"hss" };  //���ﲻƥ��ʱ������С������һ����Ч����
	//cout << s1[1] << endl;
	//cout << s1[2] << endl;
	

	//3/14
	//vector<int>  i1;
	//int a;
	//while (cin >> a&& "end")    //end��β
	//	i1.push_back(a);
	//for (decltype(i1.size()) i = 0; i < i1.size(); i++)
	//	cout << i1[i] << endl;
	//cout << i1.size();

	//3.15
	//vector<string>  s15;
	//string s;
	//while (cin >> s)
	//{
	//	s15.push_back(s);
	//	cout << s15.size();
	//}
	
	//for (decltype(s15.size()) i = 0; i < s1.size(); i++)
	//	cout << s15[i] << endl;
	vector<unsigned>  score(11, 0);
	vector<int> grade;
	unsigned gradex;
	cout << "������ɼ�������101ʱֹͣ" << endl;
	while (cin >> gradex)
	{
		if (gradex == 101)
			break;
		if (gradex <= 100)
			grade.push_back(gradex);
	}
	

	//3.17
	//vector<string> v17;
	//string v;
	//while (cin >> v)
	//{
	//	if (v == "end")
	//		break;
	//	else
	//		v17.push_back(v);
	//}
	//for (auto &vv : v17)
	//{
	//	for (auto &ss : vv)
	//		ss = toupper(ss);
	//	cout << vv << endl;
	//}
	//3.19
	//vector<int> v191(10, 42);
	//for (auto v : v191)
	//	cout << v << " ";
	//cout << endl;

	//vector<int> v192{ 42, 42,42,42,42,42,42,42,42,42 };
	//for (auto v : v192)
	//	cout << v << " ";
	//cout << endl;

	//vector<int> v193(10);
	//for (auto &v : v193)
	//	v = 42;
	//for (auto v : v193)
	//	cout << v << " ";
	//cout << endl;

	////3.20
	//vector<int>  v20;
	//int vv20;
	//cout << "����������������0ʱֹͣ" << endl;
	//while (cin >> vv20)
	//{
	//	if (vv20 == 0)
	//		break;
	//	else
	//		v20.push_back(vv20);
	//}
	//auto num_v = v20.size();
	//cout << "size of v20 is " << num_v<<endl;
	//for (decltype(v20.size()) i = 0; i < num_v - 1; i++)
	//	cout << v20[i] + v20[i + 1] << endl;
	//
	//for (decltype(v20.size()) i = 0; i <= num_v/2 ; i++)
	//	cout << v20[i] + v20[num_v-1-i] << endl;       //����һ��Ҫ�ǵü�1��Ҫ���ͻ�Խ��


	//3.22
	vector<string> text{"would","you", "love", "me", "for", "the", "readong", "and", "do"};
	for (auto it = text.begin(); it != text.end(); it++)
	{
		
		*it->begin() = toupper(*it->begin());    //begin()�õ�����һ������������������ò��ܵõ�����
		cout << *it << endl;
	}

	//3.23
	vector<int> i23(10, 23);
	for (auto it = i23.begin(); it != i23.end(); it++)
	{
		*it = 2*(*it);
		cout << *it << endl;
	}

	//3.24
	vector<int> i24(10,1);
	for (auto ii24 = i24.begin(); ii24 != i24.end()-1; ii24++)
		*(ii24 +1)= 2*(*ii24);
	for (auto ii24 = i24.begin(); ii24 != i24.end(); ii24++)
		cout << *ii24 << " ";
	cout << endl;
	
	for (auto ii24 = i24.begin(); ii24 != i24.end() - 1; ii24++)
		cout << *ii24 + *(ii24 + 1)<<" ";
	cout << endl;


	for (auto beg = i24.begin(),end = i24.end(); beg<end; beg++, end--)
		cout << *beg + *(end-1) << " ";   //����endָ��������һ��Ԫ�صĺ��棬�ǵü���1
	cout << endl;

	//3.25

	for (auto it = grade.begin(); it != grade.end(); it++)
	{
		int num = *it / 10;      //���ǵڼ�����
		score[num]++;
	}
	for (auto it = score.begin(); it != score.end(); it++)
		cout << *it << " ";
	cout << endl;


	//3.26  ��������֧�ּӷ�������
	return 0;
}