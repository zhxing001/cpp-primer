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
	//	cout << *pp << endl;      //�����൱�ڰ�ָ�뵱�����������á�

	//int *beg = std::begin(b);
	//int *end = std::end(b);
	//for (; beg != end; beg++)
	//	cout << *beg << endl;        //�����÷��͵���������


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
	////�ȱȽϴ�С�Ƿ���ȣ��ٱȽ�ÿ��Ԫ���Ƿ���ͬ��
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
	//vector<int> b362(a36, a36 + 8);   //���ֳ�ʼ����ʽ������ָ�룬����ָ�뵱�е�������int���롣
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
	//	for (auto &col : row)   //Ҫ�ı�ֵ�Ļ�Ҫ������
	//	{
	//		cnt++;
	//		col = cnt;
	//	}

	//for (auto &row : at)        //�õ�ÿһ�е�����
	//{
	//	//cout << row << " ";
	//	for (auto col : row)
	//	{
	//		cout << col << " ";
	//	}
	//	cout << endl;
	//}

	//cout << at << endl;     //���Ƕ�ά����ĵ�ַ��

	
	int ia[3][4] = { 0 };
	for (auto p = ia; p != ia + 3; p++)   
	{
		for (auto q = *p; q != *p + 4; q++)  //����һ��Ҫ���
		{
			*q = cnt;
			cnt++;
		}
	}

	//3.43
	for (auto &p : ia)          //����õ���p��һ��ָ�룬ָ�������һ��Ԫ��
	{
		for (auto q : p)        //����õ�����int�͵���
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

	for (int(*p)[4] = ia; p != ia + 3; p++)      //����һ����ia+3,����д��p+3����Ϊpÿ�ζ��Ǳ�ġ�
	{
		for (int *q = *p; q != *p + 4; q++)      //����һ����*p+4������д����q+4����Ϊqÿ���Ǳ�ġ�
		{
			cout << *q << " ";
		}
		cout << endl;
	}
	//���Ҫ�����һ�㣬������һ��int (*p)[4]��ָ��ָ���ά���飬�����õ���p��һ��int *[4]�͵�ָ�룬������ָ�룬����
	//��ѭ�����������ָ������þͻ�õ����飬��������ʹ�õ�ʱ���ת����Ϊָ���һ��Ԫ�ص�ָ�룬���Ի���Ҫ��ָ��ָ��




	return 0;
}