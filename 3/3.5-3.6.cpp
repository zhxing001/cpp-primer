#include<iostream>
#include<vector>

using std::vector;
using std::cin;
using std::cout;
using std::endl;
using std::begin;
int main()
{
	//3.31
	//int a[10] = { 1,2,3,4,5,5,6,6 };
	//for (size_t i = 0; i < 10; i++)
	//	a[i] = i;

	//for (size_t i = 0; i < 10; i++)
	//	cout << "a[" << i << "]" << "=" << a[i] << endl;

	////3.32
	//int b[10] = {};
	//for (size_t i = 0; i < 10; i++)
	//	b[i] = a[i];
	//for (size_t i = 0; i < 10; i++)
	//	cout << "b[" << i << "]" << "=" << b[i] << endl;

	//int *p =& b[10];
	//for (int *pp = b; pp != p; pp++)
	//	cout << *pp << endl;      //这种相当于把指针当作迭代器来用。

	//int *beg = std::begin(b);
	//int *end = std::end(b);
	//for (; beg != end; beg++)
	//	cout << *beg << endl;        //这种用法和迭代器类似


	////3.34
	//int a1[5] = { 1,2,3,4,5 };
	//int *p1 = a1;
	//int *p2 = &a1[4];
	//p1 += p2 - p1;
	//cout << *p1 << endl;

	////3/35
	//int a35[] = {12,3,4,4};
	//
	//int *end35 = std::end(a35);
	//for (int *beg35 = std::begin(a35); beg35 != end35; beg35++)
	//	*beg35 = 0;
	//for (int *beg35 = std::begin(a35); beg35 != end35; beg35++)
	//	cout << *beg35 << endl;
	//
	////3.36
	////先比较大小是否相等，再比较每个元素是否相同。
	//int a36[] = { 1,2,3,4,5,6,5,6 };
	//int b36[] = { 2,3,4,5,3,4,5,4 };
	//int myflag = 0;
	//int num = sizeof(a36);
	//if (sizeof(a36) == sizeof(b36))
	//{
	//	
	//	for (rsize_t i = 0; i < num; i++)
	//		if (a36[i] == b36[i])
	//			myflag++;
	//}
	//if (myflag == num)
	//	cout << "equal" << endl;
	//else
	//	cout << "not equal" << endl;

	////3.36
	//int a361[] = { 1,2,3,4,5,6,5,6 };
	//int b361[] = { 2,3,4,5,3,4,5,4 };
	//vector<int> a362(10, 5);
	//vector<int> b362(a36, a36 + 8);   //这种初始化方式是两个指针，两个指针当中的内容以int读入。
	//
	//for (auto vv : b362)
	//	cout << vv << "";
	//if (a362==b362)
	//	cout << "equal" << endl;
	//else
	//	cout << "not equal" << endl;

	//int at[5][5] = {0};
	  int cnt = 0;
	//for (auto &row : at)
	//	for (auto &col : row)   //要改变值的话要用引用
	//	{
	//		cnt++;
	//		col = cnt;
	//	}

	//for (auto &row : at)        //得到每一行的引用
	//{
	//	//cout << row << " ";
	//	for (auto col : row)
	//	{
	//		cout << col << " ";
	//	}
	//	cout << endl;
	//}

	//cout << at << endl;     //这是二维数组的地址。

	
	int ia[3][4] = { 0 };
	for (auto p = ia; p != ia + 3; p++)   
	{
		for (auto q = *p; q != *p + 4; q++)  //这里一定要理解
		{
			*q = cnt;
			cnt++;
		}
	}

	//3.43
	for (auto &p : ia)          //这里得到的p是一个指针，指向数组第一个元素
	{
		for (auto q : p)        //这里得到就是int型的了
			cout << q << " ";
		cout << endl;
	}
	
	for (size_t i = 0; i < 3; i++)
	{
		for (size_t j = 0; j < 4; j++)
		{
			cout << ia[i][j] << " ";
		}
		cout << endl;
	}

	for (int(*p)[4] = ia; p != ia + 3; p++)      //这里一定是ia+3,不可写做p+3，因为p每次都是变的。
	{
		for (int *q = *p; q != *p + 4; q++)      //这里一定是*p+4，不可写作是q+4，因为q每次是变的。
		{
			cout << *q << " ";
		}
		cout << endl;
	}
	//这个要难理解一点，首先另一个int (*p)[4]的指针指向二维数组，这样得到的p是一个int *[4]型的指针，即数组指针，里面
	//的循环对这个数组指针解引用就会得到数组，数组名在使用的时候会转换成为指向第一个元素的指针，所以还是要用指针指向。




	return 0;
}