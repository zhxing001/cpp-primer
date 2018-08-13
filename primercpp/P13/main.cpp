#pragma warning(disable:4996)
#include<iostream>
#include<string>
#include<vector>
 
using  namespace std;

class sales_item {
public:
	sales_item() :units_sold(0),revenue(0.0) {}
	sales_item(const string &book) :isbn(book), units_sold(0) { cout << "���캯�������ã�" << endl; }
	//�������캯���������Ǹ��ƹ��캯��
	sales_item(const sales_item &orig)
		:isbn(orig.isbn),
		units_sold(orig.units_sold),
		revenue(orig.revenue) {
		cout << "�������������ã���" << endl; //ͨ����˵���������캯���ǲ���д�������
	}
	//���ƹ��������
	sales_item& operator = (const sales_item &rhs)
	{
		isbn = rhs.isbn;
		units_sold = rhs.units_sold;
		revenue = rhs.revenue;
		cout << "��ֵ������������" << endl;
		return *this;
	}

private:
	std::string isbn;
	unsigned units_sold;
	double revenue;
};

void func(sales_item s)
{
	cout << "������ֵ" << endl;
}


class NoName {
public:
	NoName():pstring(new std::string),i(0),d(0.0){}  //�޲ι��캯����ָ��ָ��һ����̬�������ַ���
	NoName(const NoName &other):pstring(new string(*(other.pstring))),   //ȡ����������newһ���ַ�����Ȼ���ٿ���
										i(other.i),
										d(other.d){
		cout << "NoName �Ŀ������캯��������" << endl;
	} 
	NoName &operator=(const NoName &rhs)
	{
		pstring = new string(*rhs.pstring);
		i = rhs.i;
		d = rhs.d;
		cout << "��ֵ�����������ã�" << endl;
		return *this;
	}
private:
	std::string *pstring;
	int i;
	double d;
};


class NoName1 {
public:
	NoName1() :pstring(new std::string), i(0), d(0.0) { cout << "���캯����������" << endl; }    //�޲ι��캯����ָ��ָ��һ����̬�������ַ���
	~NoName1();
	NoName1(const NoName1 &other) :pstring(new string(*(other.pstring))),   //ȡ����������newһ���ַ�����Ȼ���ٿ���
		i(other.i),
		d(other.d) {
		cout << "NoName �Ŀ������캯��������" << endl;
	}
	NoName1 &operator=(const NoName1 &rhs)
	{
		pstring = new string(*rhs.pstring);
		i = rhs.i;
		d = rhs.d;
		cout << "��ֵ�����������ã�" << endl;
		return *this;
	}
private:
	std::string *pstring;
	int i;
	double d;
};

NoName1::~NoName1()
{
	cout << "����������������" << endl;
	delete pstring;
}

class Cdemo {

public:
	Cdemo(int pa, char *str)
	{
		this->a = pa;
		this->str = new char[100];   //��̬����ռ�
		strcpy(this->str, str);      //Ȼ����ַ�����������
	}
	Cdemo(const Cdemo & cd)
	{
		this->a = cd.a;
		this->str = new char[100];
		if (str != 0)
			strcpy(this->str, cd.str);
	}
	~Cdemo()
	{
		delete str;
	}
	//private:  Ӧ����˽�еģ�Ϊ�˲��Է��㣬���Ϊ���е�
	//��д�������캯���Ļ����ͻ�����һ���������캯��
public:
	int a;
	char *str;
};


int main()
{
	//sales_item a("1234");   //���캯��
	//sales_item b = a;       //��������
	//sales_item c(a);        //��������
	//sales_item e;
	//e = a;                  //��ֵ������
	//sales_item *p = new sales_item(a);   //�������캯��������
	//
	//cout << "��������" << endl;
	//func(a);          //�������캯��������

	//cout << "vector������" << endl;
	//vector<sales_item> v_sales(5, a);   //����ʹ��������ʱ��Ҳ�ᷢ����������

	//cout << "����" << endl;            //�������ù��캯����������ÿ�������
	//sales_item primes_eds[] = { string("dasjkhjfka"),
	//						string("dajgakdfasf"),
	//						string("dasdasfdfsd") };


	//NoName1 x;  
	//NoName1 *y=new NoName1;
	//cout << "hello!" << endl;
	//delete y;   //����delete��ʱ��ͻ��ͷ���Դ


	Cdemo A(10, "hello");
	Cdemo B(A);     //ʹ��Ĭ�ϵĹ��캯��
	cout << A.a << "," << A.str << endl;
	cout << B.a << "," << B.str << endl;

	cout << "�޸ĺ�" << endl;
	B.a = 8;
	B.str[0] = 'k';
	cout << A.a << "," << A.str << endl;
	cout << B.a << "," << B.str << endl;
	return 0;
}


