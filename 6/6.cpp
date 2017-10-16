#include<iostream>
#include<string>
#include<vector>

using namespace std;

//6.17
bool fun1(const string &s)      //判断是否有大写字幕
{
	bool is = false;
	int cnt = 0;       //大写字母计数，这个也可以放在参数引用中返回
	for (auto v = s.begin(); v != s.end(); v++)
	{
		if (isalpha(*v) && !(islower(*v)))  //是字母且不是小写字母
			cnt++;
	}
	return is = cnt ? true : false;
}

void fun2(string &s)     //把所有的大写改成小写
{
	for (auto v = s.begin(); v != s.end(); v++)
		*v=tolower(*v);
}


void myprint(const int a[10])
{
	for (size_t t = 0; t != 10; t++)
		cout << a[t] << endl;
}


//6.33
void put(vector<int> x,int index)
{
	if (index != x.size())
	{
		cout << x[index] << " ";
		index++;
		put(x, index);
	}
}

//6.27
int sum(initializer_list<int> x)
{
	int sum = 0;
	for (auto i = x.begin(); i != x.end(); i++)
		sum += (*i);
	return sum;
}

//6.36,37
string(&fun(int i))[10]; //函数fun的输入是一个int，返回的是一个string引用，这个引用是一个包含10个string对象的数组的引用。

typedef string s36[10];   //定义s36是一个类型别名，表示含有10个string对象的数组
s36& fun1(int i);       //返回数组的引用，实际上这也是一个指针

using s37 = string[10];
s37& fun2(int i);       //和上一个声名是一样的

auto fun4(int i)->string(*)[10]; //尾置类型 同上。

string a[10];
decltype(a)* fun_x(int i);    //同上，decltype得到的是一个数组，对其解引用才能得到数组名即指向数组的指针。


void fun_s(int x1, int x2)
{
	cout << x1 + x2<<endl;
};

void fun_s(double x1, double x2)
{
	cout << x1 + x2 << endl;
};


//6.53
void calc(int &x1, int &x2)
{
	cout << x1 + x2 << endl;
}
void calc(const int &x1, const int &x2)
{
	cout << x1 - x2 << endl;
}

int func(char *, char *);
int func(char* const, char* const);

//6.54
int f54(int, int);
vector<int(*)(int, int)> v54; //v54的元素为上一个函数的指针

using p = int(*)(int, int);
vector<p> v542;        //上面类型的换一种写法


//6.55.56
int mysum(int x, int y)
{
	return x + y;
}
int myred(int x, int y)
{
	return x - y;
}
int mydiv(int x, int y)
{
	return x / y;
}
int mymul(int x, int y)
{
	return x*y;
}

vector<int(*)(int, int)> v655;


int main()
{
	//6.17 
	string s17("Hello CUte");
	if (fun1(s17))
		cout << "有大写" << endl;
	fun2(s17);
	cout << s17 << endl;

	int a[10] = { 1,2,3,4,5,6,7,8,9,10 };
	myprint(a);

	initializer_list<vector<int>> x = { {1,2} ,{3,4},{5,6},{7,7} };
	//cout << sum(x) << endl;   //哦，当这样时数据类型也必须声名成initializer_list<int>类型的
	for (const auto &xx : x)
		cout << xx[0]<<" "<<xx[1]<< endl;
	//6.33
	vector<int>  v33(a, a + 9);
	put(v33, 0);

	fun_s(2.0, 42.2);

	const int x1 = 5, x2 = 3;
	calc(x1, x2);

	v655.push_back(mysum);
	v655.push_back(myred);
	v655.push_back(mydiv);
	v655.push_back(mymul);     //把四个函数指针放入vector

	cout << v655[0](x1, x2) << endl;
	cout << v655[1](x1, x2) << endl;
	cout << v655[2](x1, x2) << endl;
	cout << v655[3](x1, x2) << endl;    //把函数指针存入容器再这样调用，也是可以的

	for (auto f : v655)
		cout << f(x1, x2) << endl;       //这样调用也可


	return 0;
	
}