#include<iostream>
#include<vector>
#include<list>
#include<array>
#include<string>
#include<deque>
#include<forward_list>
using std::cout;
using std::cin;
using std::endl;
using std::vector;
using std::list;
using std::array;
using std::string;
using std::deque;
using std::forward_list;
//9.4
bool FindInVec(vector<int>::iterator &, vector<int>::iterator &, int);
//9.5
vector<int>::iterator& FindInVec1(vector<int>::iterator &i1, vector<int>::iterator &i2, int i);

unsigned long long climbStairs(int n);
unsigned long long jiecheng(int n);
void double_and_insert(vector<int> &v, int some_val);
void Insert_string(forward_list<string> &fl, string &s1, string &s2);

int main()
{
	//vector<int> v1(10);
	//int i = 0;
	//for (auto &v : v1)    //����Ҫ�����ò����޸ĵ��������������
	//{
	//	v = i;
	//	i++;
	//}
	//for (auto &v : v1)
	//{
	//	cout << v << " ";
	//}
	//cout << endl;
	//cout << FindInVec(v1.begin(), v1.end(), 4) << endl;
	//vector<int>::iterator i1=FindInVec1(v1.begin(), v1.end(), 5);
	//if (i1 < v1.end())
	//	cout << *i1 << endl;


	////9.6
	////list<int> lst1;
	////list<int>::iterator iter1 = lst1.begin(), iter2 = lst1.end();
	////while(iter1<iter2)       //list������Ƚϵ�����

	//vector<int> v10(10, 1);
	//const vector<int> v102(10,1);
	//auto it101 = v10.begin();
	//auto it102 = v102.begin();
	//auto it103 = v10.cbegin();
	//auto it104 = v102.cbegin();
	////��Ӧ����Ϊ��
	//vector<int>::iterator;
	//vector<int>::const_iterator;
	//vector<int>::const_iterator;
	//vector<int>::const_iterator;
	//cout << (++ (*(it101++)))<< endl;
	//cout << ((*(it102++)) )<< endl;  
	//cout << (*(it103++)) << endl;  
	//cout << (*(it104++)) << endl; 

	////9.13
	//vector<int> v13(10, 1);
	//vector<double> v131(10, 2);
	//
	//vector<double> v132(v13.begin(), v13.end());
	//for (auto v : v132)
	//	cout << v << endl;
	//vector<int> v134(v131.begin(), v131.end());
	//for (auto v : v132)
	//	cout << v << endl;
	////û���⣬double��int�����Ի����ʼ��
	//array<int, 5> a1 = { 1,2,3,4,5 };
	//array<int, 5> a2 = { 0 };
	//a1 = a2;
	//a2 = { 0 };
	//cout << a2[3]<<endl;
	////9.14
	//list<char *> l14 = { "hello","world","love" };
	//vector<string> v14(l14.begin(),l14.end());
	////v14.assign(l14.begin(), l14.end());
	////�����ַ���������
	//for (auto v : v14)
	//	cout << v << " ";
	//cout << endl;
	////9.16
	//list<int> l16{ 1,2,3,4 };
	//vector<int> v161{ 1,2,3,4 };
	//vector<int> v162{ 1,2,3,4,5 };
	//cout << (vector<int>(l16.begin(), l16.end()) == v161 ? "ture":"false") << endl;
	//cout << (vector<int>(l16.begin(), l16.end()) == v162 ? "ture" : "false") << endl;
	////����ᴴ��һ����ʱ��vector������v161��v162�Ƚ�
	////9.18
	//deque<string>  d18;
	//string s18;
	//while (cin>>s18)
	//{
	//	if (s18 == "end")
	//		break;
	//	else d18.push_back(s18);
	//}
	//for (deque<string>::iterator it = d18.begin(); it != d18.end(); it++)
	//	cout << *it << " ";
	//cout << endl;
	////9.19
	//deque<string>  d19;
	//string s19;
	//while (cin >> s19)
	//{
	//	if (s19 == "end")
	//		break;
	//	else d19.push_back(s19);
	//}
	//for (deque<string>::iterator it = d19.begin(); it != d19.end(); it++)
	//	cout << *it << " ";

	////9.20
	//list<int> l20 = { 1,2,3,4,5,6,7,8,9,10 };
	//deque<int> odd, even;   //��������
	//for (auto l : l20)
	//{
	//	(l & 0x1? odd : even).push_back(l);
	//}//�����һλ��֪������������ż����
	//for (auto d : odd)
	//	cout << d << " ";
	//cout << endl;

	//for (auto e : even)
	//	cout << e << " ";
	//cout << endl;

	////9.22
	//vector<int> v22{ 1,1,1,9,1,9,9,1,1,9 };
	//double_and_insert(v22, 1);    
	//for (auto v : v22)
	//	cout << v << " ";
	////9.27
	//cout << "9.27:" << endl;
	//forward_list<int> l27 = { 1,2,3,4,5,6,7,8,9,10 };   //û���б��ʼ���Ĺ��캯��
	//auto prev = l27.before_begin();     //��ǰԪ��
	//auto curr = l27.begin();     //��Ԫ��
	//while (curr != l27.end())     //���������һ��Ԫ��
	//{
	//	if (*curr % 2)   //����
	//		curr = l27.erase_after(prev); //ɾ�����Ԫ��
	//	else
	//	{
	//		prev = curr;
	//		curr++;
	//	}
	//}
	//for (auto l : l27)
	//	cout << l << " ";
	//cout << endl;
	////9.28
	//forward_list<string> l28 = { "would","you","me" };
	//string s1 = "you";
	//string s2 = "love";
	//string s3 = "can";
	//Insert_string(l28, s3, s2);
	//for (auto l : l28)
	//	cout << l << " ";
	//cout << endl;

	////9.31
	//list<int> l31 = { 1,2,3,4,5,6,7,8,9,10 };
	//auto end = l31.end();
	//auto beg = l31.begin();
	//for (beg; beg != end;)
	//{
	//	if (*beg % 2)
	//	{
	//		l31.insert(beg, *beg);
	//		beg++;     //�������֮ǰ���Ԫ�أ���ʱ������������ʧЧ�����ԾͿ������ƶ�����һ��û�д���ĵ�����
	//	}
	//	else
	//		
	//		beg=l31.erase(beg);  
	//	//ɾ����ǰԪ��,��ǰָ��ͻ�ʧЧ���᷵�����֮��ĵ�����,��������ǡ�ÿ��԰������������ֵ��beg
	//		
	//}
	//for (auto l : l31)
	//	cout << l << " ";
	//cout << endl;


	//9.34
	vector<int> v34 = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };
	for (auto v : v34)
		cout << v << " ";
	cout << endl;
	auto iter34 = v34.begin();
	while (iter34 != v34.end()-1)
	{
		if (*iter34 % 2)
		{
			iter34 = v34.insert(iter34, *iter34);   //���صĵ�������������ӵ�Ԫ�����ڵ�λ�ã������������ѭ��
		}
		iter34+=1;
	}
	for (auto v : v34)
		cout << v << " ";
	cout << endl;

	return 0;
}

void Insert_string(forward_list<string> &fl, string &s1, string &s2)
{
	auto prev = fl.before_begin();
	for (auto beg=fl.begin(); beg!=fl.end(); prev=beg++)
	{
		if (*beg == s1)
		{
			fl.insert_after(beg,s2);
			return;
		}
	}
	fl.insert_after(prev,s2); 
	//��Ϊforward_listû��--�ĳ�Ա������һ��������β����޷���β�����Ԫ�أ�
	//����һ��Ҫ�����һ��Ԫ�صĵ������������������������ڲ��Ҳ������������������Ԫ�أ��������������һ����������ԭ��
	//�����������һ����̳��õļ��ɡ�
	return;
}




//���������д����¥��������Ĵ𰸣��׳˵�����������̫���ˣ�int����hold��ס
unsigned long long jiecheng(int n)
{
	if (n == 0)
	{
		return 1;
	}
	unsigned long long res = 1;
	for (int i = 1; i <= n; i++)
		res *= i;
	return res;
}

unsigned long long climbStairs(int n) 
{
	if (n ==0 || n == 1)
		return 1;
	int index = n / 2;
	unsigned long long res = 1;
	for (int i = 0; i <= index; i++)
	{
		res += (jiecheng(n - (i * 2) + i) / jiecheng(i)/jiecheng(n-2*i));
	}
	return res;
	// write your code here
}




bool FindInVec(vector<int>::iterator &i1, vector<int>::iterator &i2, int i)
{
	while (i1!=i2)
	{
		if (*i1 == i)
			return true;
		i1++;
	}
	return false;
}

vector<int>::iterator& FindInVec1(vector<int>::iterator &i1, vector<int>::iterator &i2, int i)
{
	while(i1!=i2)
	{
		if (*i1 == i)
		{
			return i1;
		}
		i1++;
	}
	cout<<"û�ҵ�"<<endl;
	return i1;           //һ���ǵ��������ֵ��Ҫ�����û�ҵ��Ļ���û�з���ֵ�������������鷳
}

//9.22
void double_and_insert(vector<int> &v, int some_val)
{
	auto mid = [&] {return v.begin() + v.size() / 2; };
	for (auto curr = v.begin(); curr != mid(); curr++)
		if (*curr == some_val)
			(curr = v.insert(curr, 2 * some_val))++;   
	//�Բ���һֱ��Ϊ�᷵�ر���������begin��ԭ��ÿ�η��صĶ���ָ���²���Ԫ�صĵ�������������ʵ������ÿ�ζ����ص���ǰ��
	//��������������ˣ�һ��ʼ��Ϊ��ÿ�ζ�����begin��������ͺܿ�����һ����ѭ���ˡ�
}
