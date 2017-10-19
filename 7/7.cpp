#include"Sala_data.h"
#include"person.h"
#include"Sscreen.h"

//7.35

class Tree 
{
public:
	Tree(string s, double d) :color(s), height(d) { cout << "默认构造函数调用" << endl; }
	Tree(double d) :Tree("", d) { cout << "委托构造函数调用" << endl; };    //这是一个委托构造函数，不能忘记了大括号
private:
	string color;
	double height;
	
};


class Example {
public:
	static double rate ;      
	static const int vecsize = 20; 
    static  vector<double> vec;

};

int main()

{
//	vector<person> pp;
//	
//	person p1("zhxing","china");
//	person p2("ans", "japan");
//	person p3("ansh2", "canada");
//	person p4(cin);       //用输入的方式来初始化。
//	pp.push_back(p4);
//	pp.push_back(p1);
//	pp.push_back(p2);
//	pp.push_back(p3);
//	for(auto p:pp)
//	p.show_ifo();
//	
//	vector<person> px;
//	cout << "输入5位信息，名字加地址!" << endl;
//	for (decltype(px.size()) i = 0; i < 5; i++)
//	{
//		px.push_back(person(cin));       //这里就是一个初始化一个临时person临时变量，所以可以用类名+构造函数初始化一个临时对象。
//	}
//	for (auto p : px)
//		p.show_ifo();
//
//	Sale_data s1("ISBN", 15, 0);
//	s1.showIfo();
//
//	
//	Sale_data s2(cin);
//	if (cin)
//	{
//		Sale_data trans(cin);
//		do {
//			if (s2.isbn() == trans.isbn())
//				s2.combine(trans);
//			else
//			{
//				print(cout, s2) << endl;
//				s2 = trans;
//			}
//		} while (read(cin, trans));
//		print(cout, s2) << endl;
//	}
//	else
//	{
//		cout<< "no data!" << endl;
//	}

	/*Screen myscreen(5, 5, 'x');
	myscreen.move(4, 4).set('#').display(cout);
	cout << "\n";
	myscreen.display(cout);
	cout << "\n";

	person p("zhxing", "china");
	p.show_ifo();*/

	Tree t1("RED", 2.5);
	Tree t2(2.5);  //这个虽然是委托构造函数，但是在调用的时候会先调用默认构造函数。从测试结果也可以看出这点

	double d = 2.5;
	Tree d2 = d;   //这样可以利用类的类型转换规则（隐性的）

	Sale_data i("zhangxing",5,6);
	string s = "zhxing";   //这样就是一般的初始化
							//string &s="xx";           //这样初始化就是不对的，字面值只能初始化成常量的引用
														//应该是:  const string &s="xx";

	i.combine(s);    //这里会调用只有一个参数的构造函数隐式把string对象转换为sale_data对象，(临时的，s并不改变)，
					 //且字面值会初始化成一个const类型
	i.showIfo();    

	//7/58
	Example::rate;
	Example::vec;
	
	
	return 0;
}


