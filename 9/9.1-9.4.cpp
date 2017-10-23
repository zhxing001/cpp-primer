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
	//for (auto &v : v1)    //这里要用引用才能修改到容器本身的内容
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
	////while(iter1<iter2)       //list不允许比较迭代器

	//vector<int> v10(10, 1);
	//const vector<int> v102(10,1);
	//auto it101 = v10.begin();
	//auto it102 = v102.begin();
	//auto it103 = v10.cbegin();
	//auto it104 = v102.cbegin();
	////对应类型为：
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
	////没问题，double和int都可以互相初始化
	//array<int, 5> a1 = { 1,2,3,4,5 };
	//array<int, 5> a2 = { 0 };
	//a1 = a2;
	//a2 = { 0 };
	//cout << a2[3]<<endl;
	////9.14
	//list<char *> l14 = { "hello","world","love" };
	//vector<string> v14(l14.begin(),l14.end());
	////v14.assign(l14.begin(), l14.end());
	////这两种方法都可以
	//for (auto v : v14)
	//	cout << v << " ";
	//cout << endl;
	////9.16
	//list<int> l16{ 1,2,3,4 };
	//vector<int> v161{ 1,2,3,4 };
	//vector<int> v162{ 1,2,3,4,5 };
	//cout << (vector<int>(l16.begin(), l16.end()) == v161 ? "ture":"false") << endl;
	//cout << (vector<int>(l16.begin(), l16.end()) == v162 ? "ture" : "false") << endl;
	////这里会创建一个临时的vector对象与v161和v162比较
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
	//deque<int> odd, even;   //两个队列
	//for (auto l : l20)
	//{
	//	(l & 0x1? odd : even).push_back(l);
	//}//看最后一位就知道是奇数还是偶数，
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
	//forward_list<int> l27 = { 1,2,3,4,5,6,7,8,9,10 };   //没有列表初始化的构造函数
	//auto prev = l27.before_begin();     //首前元素
	//auto curr = l27.begin();     //首元素
	//while (curr != l27.end())     //遍历到最后一个元素
	//{
	//	if (*curr % 2)   //奇数
	//		curr = l27.erase_after(prev); //删除这个元素
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
	//		beg++;     //这个是在之前添加元素，此时迭代器并不会失效，所以就可以再移动到下一个没有处理的迭代器
	//	}
	//	else
	//		
	//		beg=l31.erase(beg);  
	//	//删除当前元素,当前指针就会失效，会返回这个之后的迭代器,这样我们恰好可以把这个迭代器赋值给beg
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
			iter34 = v34.insert(iter34, *iter34);   //返回的迭代器就是新添加的元素所在的位置，所以这个会死循环
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
	//因为forward_list没有--的成员，所以一旦遍历到尾后就无法向尾后添加元素，
	//所以一定要把最后一个元素的迭代器保存下来，这样才能在查找不到的情况下链表后添加元素，所以这里多用了一个迭代器，原因
	//就在这里，这是一个编程常用的技巧。
	return;
}




//下面这个是写的爬楼梯两个题的答案，阶乘的数量级还是太高了，int根本hold不住
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
	cout<<"没找到"<<endl;
	return i1;           //一定记得这个返回值，要不如果没找到的话就没有返回值，处理起来很麻烦
}

//9.22
void double_and_insert(vector<int> &v, int some_val)
{
	auto mid = [&] {return v.begin() + v.size() / 2; };
	for (auto curr = v.begin(); curr != mid(); curr++)
		if (*curr == some_val)
			(curr = v.insert(curr, 2 * some_val))++;   
	//卧槽我一直以为会返回被插容器的begin，原来每次返回的都是指向新插入元素的迭代器，所以其实并不是每次都返回到最前面
	//这样就容易理解了，一开始以为是每次都返回begin（），这就很可能是一个死循环了。
}
