#include<iostream>
#include<string>
#include<vector>

using namespace std;

//6.17
bool fun1(const string &s)      //�ж��Ƿ��д�д��Ļ
{
	bool is = false;
	int cnt = 0;       //��д��ĸ���������Ҳ���Է��ڲ��������з���
	for (auto v = s.begin(); v != s.end(); v++)
	{
		if (isalpha(*v) && !(islower(*v)))  //����ĸ�Ҳ���Сд��ĸ
			cnt++;
	}
	return is = cnt ? true : false;
}

void fun2(string &s)     //�����еĴ�д�ĳ�Сд
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
string(&fun(int i))[10]; //����fun��������һ��int�����ص���һ��string���ã����������һ������10��string�������������á�

typedef string s36[10];   //����s36��һ�����ͱ�������ʾ����10��string���������
s36& fun1(int i);       //������������ã�ʵ������Ҳ��һ��ָ��

using s37 = string[10];
s37& fun2(int i);       //����һ��������һ����

auto fun4(int i)->string(*)[10]; //β������ ͬ�ϡ�

string a[10];
decltype(a)* fun_x(int i);    //ͬ�ϣ�decltype�õ�����һ�����飬��������ò��ܵõ���������ָ�������ָ�롣


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
vector<int(*)(int, int)> v54; //v54��Ԫ��Ϊ��һ��������ָ��

using p = int(*)(int, int);
vector<p> v542;        //�������͵Ļ�һ��д��


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
		cout << "�д�д" << endl;
	fun2(s17);
	cout << s17 << endl;

	int a[10] = { 1,2,3,4,5,6,7,8,9,10 };
	myprint(a);

	initializer_list<vector<int>> x = { {1,2} ,{3,4},{5,6},{7,7} };
	//cout << sum(x) << endl;   //Ŷ��������ʱ��������Ҳ����������initializer_list<int>���͵�
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
	v655.push_back(mymul);     //���ĸ�����ָ�����vector

	cout << v655[0](x1, x2) << endl;
	cout << v655[1](x1, x2) << endl;
	cout << v655[2](x1, x2) << endl;
	cout << v655[3](x1, x2) << endl;    //�Ѻ���ָ������������������ã�Ҳ�ǿ��Ե�

	for (auto f : v655)
		cout << f(x1, x2) << endl;       //��������Ҳ��


	return 0;
	
}