#include<iostream>
#include<vector>
#include<string>
#include<list>
#include<algorithm>
#include<numeric>
#include<functional>
#include<iterator>
#include<fstream>
using namespace std;
using namespace std::placeholders;

void write_jiou(const string &s_num, const string &s_odd, const string &s_even);

int main()
{
	//istream_iterator<int> in(cin), eof;  //�յĵ��������Ե�β����
	//cout << accumulate(in, eof, 0) << endl;

	vector<string> vec1;
	ifstream  in1("test.txt");
	istream_iterator<string> str(in1);
	istream_iterator<string> end;
	copy(str, end, back_inserter(vec1));
	for (int i = 0; i < vec1.size(); i++)
	{
		cout << vec1[i]<<" ";
	}
	cout << endl;
	

	//10.30
	/*istream_iterator<int> in(cin), eof;
	vector<int> vec30;
	copy(in, eof, inserter(vec30, vec30.begin()));
	
	sort(vec30.begin(), vec30.end());
	for (auto v : vec30)
		cout << v << " ";
	cout << endl;*/
	//10.31
	//istream_iterator<int> in31(cin), eof31;
	//vector<int> vec31;
	//
	//unique_copy(in31, eof31, inserter(vec31, vec31.begin()));
	//sort(vec31.begin(), vec31.end());
	//
	//for (auto v : vec31)
	//	cout << v << " ";
	//cout << endl;

	//10.33
	//write_jiou("1.txt", "2.txt", "3.txt");
	//10.34
	vector<int> vec34 = { 1,2,3,3,4,5,6,6,7,8,9,0,1 };
	for (auto beg = vec34.rbegin(); beg != vec34.rend(); beg++)
		cout << *beg << " ";
	cout << endl;
	for (auto end = vec34.end(); end != vec34.begin(); end--)
		cout << *(end-1) << " ";    //����������Ȼ�ǿ��Եģ���һȻ���ٽ�����
	cout << endl;  
	//10.36
	list<int> l36(vec34.begin(), vec34.end());
	for (auto l : l36)
		cout << l << " ";
	cout << endl;
	cout<<*find(l36.rbegin(), l36.rend(),0)<<endl;
	//10.37
	vector<int> vec37(vec34.begin(), vec34.begin() + 10);
	cout << vec37.size() << endl;
	list<int> l37;
	copy(vec37.rbegin() + (10-7) , vec37.rbegin() + (10-3+1),/*��Ϊ���ҿ����䣬��������Ҫ��1*/ inserter(l37,l37.begin()));
	for (auto v : vec37)
		cout << v << " ";
	cout << endl;
	for (auto l : l37)
		cout << l << " ";
	cout << endl;
	//10.42
	list<int> l42(vec34.begin(), vec34.end());   //��vec34����ʼ��list
	l42.sort();      //����
	l42.unique();    //ȥ���ظ�
	for (auto l : l42)
		cout << l << " ";
	cout << endl;




	return 0;
}

void write_jiou(const string &s_num, const string &s_odd,const string &s_even)
{
	ifstream in_num(s_num);   //�ļ���ȡ����
	ofstream out1(s_odd), out2(s_even);   //�����ļ�д�����
	ostream_iterator<int> it1(out1," ");
	ostream_iterator<int> it2(out2,"\n");
	vector<int> vec;  //����������
	istream_iterator<int> beg(in_num), end;   //����IO������
	copy(beg, end, inserter(vec, vec.begin()));  //ͨ�������������ֿ���vec

	for (auto v : vec)
	{
		if (v % 2)
		{
			*it1++ = v;
		}
		if (~v % 2)
		{
			*it2++ = v;
		}
	}
}
//IO����͵��������ʹ�ÿ��Ա���ʹ��<<��>>�����Ҳ�ܺ��á�