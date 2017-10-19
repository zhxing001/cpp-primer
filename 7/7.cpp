#include<iostream>

using namespace std;


int gloabl;
int i = 100;
int main()
{
	//p34
	unsigned u =10;
	int v = -42;
	cout << v + v << endl;
	cout << "u+v" << u + v << endl;

	unsigned u1 = 42, u2 = 10;
	cout << u1 - u2 << endl;
	cout << u2 - u1 << endl;


	//p35
	unsigned v1 = 10, v2 = 42;
	cout << v1 - v2 << endl;
	cout << v2 - v1 << endl;

	int i = 10, i2 = 42;
	cout << i - i2 << endl;
	cout << i2 - i << endl;
	cout << i - v1 << endl;
	cout << v1 - i << endl;

	//p36
	cout << "hello world"
		<< "bye world" << endl;
	//while(1)
	//cout << "\a" << endl;

	//p39  四种初始化  c++11之后，大括号这种初始化方式得到了全面应用
 	int x = 0;
	int x1 = { 0 };
	int x2(0);
	int x3{ 0 };


	double a = 3.245;
	//int a1={ a };
	//int a2{ a };    //这两种情况都会报错，会丢失数据，而通过花括号的方式是没有转换类型的。
	int a3 = a;
	int a4(a);   //这两种方式都可以，因为执行了类型转换
	cout << x << " " << x1 << " " << x2 << " " << x3 << endl;

	//p40  
	int gloab2=1;
	cout << gloabl << endl;        //gloab1是定义在函数外部的，默认初始化为0
	cout << gloab2 << endl;        //这里VS会报错，不允许函数内未被初始化或者赋值的变量被使用。

	//int i= 1;              //VS2015不支持重定义，会报错。
	int j = i;
	cout << i << endl;
	cout << j << endl;


	return 0;

}