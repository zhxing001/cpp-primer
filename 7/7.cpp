#include"Sala_data.h"
#include"person.h"
#include"Sscreen.h"

//7.35

class Tree 
{
public:
	Tree(string s, double d) :color(s), height(d) { cout << "Ĭ�Ϲ��캯������" << endl; }
	Tree(double d) :Tree("", d) { cout << "ί�й��캯������" << endl; };    //����һ��ί�й��캯�������������˴�����
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
//	person p4(cin);       //������ķ�ʽ����ʼ����
//	pp.push_back(p4);
//	pp.push_back(p1);
//	pp.push_back(p2);
//	pp.push_back(p3);
//	for(auto p:pp)
//	p.show_ifo();
//	
//	vector<person> px;
//	cout << "����5λ��Ϣ�����ּӵ�ַ!" << endl;
//	for (decltype(px.size()) i = 0; i < 5; i++)
//	{
//		px.push_back(person(cin));       //�������һ����ʼ��һ����ʱperson��ʱ���������Կ���������+���캯����ʼ��һ����ʱ����
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
	Tree t2(2.5);  //�����Ȼ��ί�й��캯���������ڵ��õ�ʱ����ȵ���Ĭ�Ϲ��캯�����Ӳ��Խ��Ҳ���Կ������

	double d = 2.5;
	Tree d2 = d;   //�������������������ת���������Եģ�

	Sale_data i("zhangxing",5,6);
	string s = "zhxing";   //��������һ��ĳ�ʼ��
							//string &s="xx";           //������ʼ�����ǲ��Եģ�����ֵֻ�ܳ�ʼ���ɳ���������
														//Ӧ����:  const string &s="xx";

	i.combine(s);    //��������ֻ��һ�������Ĺ��캯����ʽ��string����ת��Ϊsale_data����(��ʱ�ģ�s�����ı�)��
					 //������ֵ���ʼ����һ��const����
	i.showIfo();    

	//7/58
	Example::rate;
	Example::vec;
	
	
	return 0;
}


