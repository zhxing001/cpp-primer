#pragma warning(disable:4996)
#include<iostream>
#include<string>
#include<vector>
 
using  namespace std;

class sales_item {
public:
	sales_item() :units_sold(0),revenue(0.0) {}
	sales_item(const string &book) :isbn(book), units_sold(0) { cout << "构造函数被调用！" << endl; }
	//拷贝构造函数，或者是复制构造函数
	sales_item(const sales_item &orig)
		:isbn(orig.isbn),
		units_sold(orig.units_sold),
		revenue(orig.revenue) {
		cout << "拷贝函数被调用！！" << endl; //通常来说，拷贝构造函数是不用写函数体的
	}
	//复制构造操作符
	sales_item& operator = (const sales_item &rhs)
	{
		isbn = rhs.isbn;
		units_sold = rhs.units_sold;
		revenue = rhs.revenue;
		cout << "赋值操作符被调用" << endl;
		return *this;
	}

private:
	std::string isbn;
	unsigned units_sold;
	double revenue;
};

void func(sales_item s)
{
	cout << "函数传值" << endl;
}


class NoName {
public:
	NoName():pstring(new std::string),i(0),d(0.0){}  //无参构造函数，指针指向一个动态创建的字符串
	NoName(const NoName &other):pstring(new string(*(other.pstring))),   //取出内容用其new一个字符串，然后再拷贝
										i(other.i),
										d(other.d){
		cout << "NoName 的拷贝构造函数被调用" << endl;
	} 
	NoName &operator=(const NoName &rhs)
	{
		pstring = new string(*rhs.pstring);
		i = rhs.i;
		d = rhs.d;
		cout << "赋值操作符被调用！" << endl;
		return *this;
	}
private:
	std::string *pstring;
	int i;
	double d;
};


class NoName1 {
public:
	NoName1() :pstring(new std::string), i(0), d(0.0) { cout << "构造函数被调用了" << endl; }    //无参构造函数，指针指向一个动态创建的字符串
	~NoName1();
	NoName1(const NoName1 &other) :pstring(new string(*(other.pstring))),   //取出内容用其new一个字符串，然后再拷贝
		i(other.i),
		d(other.d) {
		cout << "NoName 的拷贝构造函数被调用" << endl;
	}
	NoName1 &operator=(const NoName1 &rhs)
	{
		pstring = new string(*rhs.pstring);
		i = rhs.i;
		d = rhs.d;
		cout << "赋值操作符被调用！" << endl;
		return *this;
	}
private:
	std::string *pstring;
	int i;
	double d;
};

NoName1::~NoName1()
{
	cout << "析构函数被调用了" << endl;
	delete pstring;
}

class Cdemo {

public:
	Cdemo(int pa, char *str)
	{
		this->a = pa;
		this->str = new char[100];   //动态分配空间
		strcpy(this->str, str);      //然后把字符串拷贝过来
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
	//private:  应该是私有的，为了测试方便，设计为共有的
	//不写拷贝构造函数的话，就会生成一个拷贝构造函数
public:
	int a;
	char *str;
};


int main()
{
	//sales_item a("1234");   //构造函数
	//sales_item b = a;       //拷贝构造
	//sales_item c(a);        //拷贝构造
	//sales_item e;
	//e = a;                  //赋值操作符
	//sales_item *p = new sales_item(a);   //拷贝构造函数被调用
	//
	//cout << "函数调用" << endl;
	//func(a);          //拷贝构造函数被调用

	//cout << "vector容器：" << endl;
	//vector<sales_item> v_sales(5, a);   //这样使用容器的时候也会发生拷贝构造

	//cout << "数组" << endl;            //这里会调用构造函数而不会调用拷贝构造
	//sales_item primes_eds[] = { string("dasjkhjfka"),
	//						string("dajgakdfasf"),
	//						string("dasdasfdfsd") };


	//NoName1 x;  
	//NoName1 *y=new NoName1;
	//cout << "hello!" << endl;
	//delete y;   //调用delete的时候就会释放资源


	Cdemo A(10, "hello");
	Cdemo B(A);     //使用默认的构造函数
	cout << A.a << "," << A.str << endl;
	cout << B.a << "," << B.str << endl;

	cout << "修改后：" << endl;
	B.a = 8;
	B.str[0] = 'k';
	cout << A.a << "," << A.str << endl;
	cout << B.a << "," << B.str << endl;
	return 0;
}


