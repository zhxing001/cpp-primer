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

	//p39  ���ֳ�ʼ��  c++11֮�󣬴��������ֳ�ʼ����ʽ�õ���ȫ��Ӧ��
 	int x = 0;
	int x1 = { 0 };
	int x2(0);
	int x3{ 0 };


	double a = 3.245;
	//int a1={ a };
	//int a2{ a };    //������������ᱨ���ᶪʧ���ݣ���ͨ�������ŵķ�ʽ��û��ת�����͵ġ�
	int a3 = a;
	int a4(a);   //�����ַ�ʽ�����ԣ���Ϊִ��������ת��
	cout << x << " " << x1 << " " << x2 << " " << x3 << endl;

	//p40  
	int gloab2=1;
	cout << gloabl << endl;        //gloab1�Ƕ����ں����ⲿ�ģ�Ĭ�ϳ�ʼ��Ϊ0
	cout << gloab2 << endl;        //����VS�ᱨ������������δ����ʼ�����߸�ֵ�ı�����ʹ�á�

	//int i= 1;              //VS2015��֧���ض��壬�ᱨ��
	int j = i;
	cout << i << endl;
	cout << j << endl;


	return 0;

}