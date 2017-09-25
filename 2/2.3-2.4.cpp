#include<iostream>



int main()
{
	//int i = 0, &r1 = i;
	//double d = 0, &r2 = d;
	//r2 = 3.14;
	//r2 = r1;
	//i = r2;
	//r1 = d;

	////2.17
	//int x = 0, &rx = x;
	//x= 5;
	//rx = 10;
	//std::cout << "x:  " << x << "  rx: " << rx <<std::endl;
	//

	////2.18
	//int x1 = 6;
	//int *p1 = &x1;
	//*p1 = 6;          //改变指针对象的值
	//p1 = NULL;       //改变指针的值

	////2.19
	////引用即别名，在定义的时候必须初始化，在初始化之后不能再作为别的对象的别名（引用）
	////指针指向地址，可以初始化为空，指针在初始化之后还可以指向其他同类对象。

	////2.20  这种代码好无聊 有这么用的么？
	//int x2 = 42;
	//int *p2 = &x2;
	//*p2= *p2 * *p2;   //这就是一个相乘而已,这样的话x2的值也就改变了
	//std::cout << *p2 << std::endl;
	//std::cout << x2 << std::endl;
	//
	//2.31
	const int v2 = 0;
	int i;
	int v1 = v2;
	int *p1 = &v1, &r1 = v1;
	const int *p2 = &v2, *const p3 = &i, &r2 = v2;
	
	r1 = v2;         //变量赋值给引用，没问题
	//p1 = p2;        //const int 不能赋值给 int *;
	p2 = p1;        //可以，这里我都有点乱了。


	//2.32
	int null = 0, *p = nullptr;   //这样才是对的，可以用0来初始化指针，但不是int型的0.







	return 0;

}