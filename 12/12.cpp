#include<iostream>
#include<vector>
#include<string>
#include<memory>
#include<new>
#include<istream>
#include<fstream>
#include"StrBlob.h"
#include"TextQuery.h"
#include<string.h>
#include<map>
#include<utility>
#include<algorithm>
using std::istream;
using std::cout;
using std::cin;
using std::endl;

//
//class StrBolb {
//public:
//	typedef std::vector<std::string>::size_type size_type;
//	StrBolb();      //Ĭ�Ϲ��캯��
//	StrBolb(std::initializer_list<std::string> il);  //ʹ�ó�ʼ���б������쵱ǰ�࣬���صĹ��캯��
//	size_type size() {
//		return data->size();
//	}
//	bool empty()
//	{
//		return data->empty();
//	}
//	void push_back(std::string &v1)
//	{
//		data->push_back(v1);
//	}
//	void pop_back();    //ɾ�����һ��Ԫ��
//	std::string & front();
//	std::string & back();
//private:
//	std::shared_ptr<std::vector<std::string>> data;
//	void check(size_type i, const std::string &msg) const;    //���Ԫ���Ƿ���ڣ������const�����������޸Ķ���
//};
//
//StrBolb::StrBolb():data(std::make_shared<std::vector<std::string>>()) {}   //����һ����ָ��
//
//StrBolb::StrBolb(std::initializer_list<std::string> il)
//{
//	std::make_shared<std::vector<std::string>>(il);    //ֱ�ӹ���������һ������ָ�룬������il����ġ�
//}
//
//void StrBolb::pop_back()
//{
//	check(0, "back on empty StrBlob!!");
//	data->pop_back();
//}
//
//std::string & StrBolb::front()
//{
//	
//	check(0, "front on empty StrBlob");
//	return data->front();
//}
//std::string & StrBolb::back()
//{
//
//	check(0, "front on empty StrBlob");
//	return data->back();
//}
//
//void StrBolb::check(size_type i, const std::string & msg) const
//{
//	if (i >= data->size())
//		throw std::out_of_range(msg);   
//}
//
//std::vector<int>* read_int(std::ifstream &in)
//{
//	int i;
//	std::vector<int> *p = new std::vector<int>;
//	while (in >> i)
//	{
//		p->push_back(i);
//	}
//	return p;
//}
//
//void print_int(std::vector<int>*p)
//{
//   if (p->size() > 0)
//	{
//		for (auto s : *p) //�����õõ�����vector����
//		{
//			std::cout << s << " ";
//		}
//		std::cout << std::endl;
//	}
//
//}


int main()
{
	/*std::ifstream in6("1.txt");
	auto p=read_int(in6);
	print_int(p);*/
	//delete p;   //��Ϊ�����p��һ��new�����ģ���read_int���������������Ҫɾ��������ͻ�һ��ռ��̬�ڴ�

	//std::unique_ptr<std::string>  p1(new std::string("hello"));   
	//std::unique_ptr<std::string> p2(p1.release());       //p1������ָ��Ŀ���Ȩ������ָ�룬���ҽ�p1�ÿ�
	//std::cout << *p2 << std::endl;             //����p2����ָ��hello��
	//std::unique_ptr<std::string>  p3(new std::string("would"));
	//p2.reset(p3.release());
	//std::cout << *p2 << std::endl;

	//12.16
	//std::unique_ptr<int> p16(new int(2));   //��ʼ��p
	//std::unique_ptr<int> p162(p16);         //����������ʼ��
	//auto p163 = p16;                        //������ֵ 
	//����������unique_ptr������
	//12.17
	//int ix = 1024;
	//int *p = &ix;
	//int *p2 = new int(2048);
	//typedef std::unique_ptr<int> Intp;
	////Intp p170(ix);       //���ָ�ֵ�ǲ��ӵģ�������int����ʼ��unique_ptr<int> 
	//Intp p171(&ix);     //�����ǿ��Ա���ģ���ix�ĵ�ַ��ֵ��һ��unique_ptr,��
	//Intp p172(p2);      //��Ҳ�ǿ��Եģ�p2������һ��new����ֵ��p2�Ϳ���
	//Intp p173(p);       //��һ����ָͨ��ȥ��ʼ��һ��ָ�룬��ôp����ͳ�Ϊһ������ָ����
	//Intp p174(new int(2048));
	//Intp p5(p172.get());  
	StrBlob str({ "hello","would","love","me" });
	std::cout << str.empty() << std::endl;
	std::cout << str.size() << std::endl;
	str.print();
	 

	//12.21
	StrBlobPtr StrPtr(str,0);
	
	for (size_t i = 0; i < str.size(); i++)
	{
		if (i == 0)
			std::cout << StrPtr.deref() << " ";
		else
		{
			std::cout << StrPtr.incr().deref() << " ";
		}
		
	}
	std::cout << std::endl;

	const StrBlob str22({ "can"," you", "give"," me" });
	constStrBlobPtr const_strPtr(str22, 0);
	for (size_t i = 0; i < str22.size(); i++)
	{
		if (i == 0)
			std::cout << const_strPtr.deref() << " ";
		else
		{
			std::cout << const_strPtr.incr().deref() << " ";
		}

	}
	std::cout << std::endl;
	//12.24
	const char* p241 = "would";
	const char* p242 = "you";
	
	//char *sumchar = new char[20];  //Ҫ��һ��\n
	////strcat(sumchar, "hello");
	////strcat(sumchar, "world");
	//  
	////vs2015�в������������������
	//strcat_s(sumchar, 5,"hello");
	////strcat_s(sumchar, 0,"hello");
	////std::cout << sumchar<<std::endl;
	//12.24
	/*char *p24 = new char[20];
	std::cin.get(p24, 20 + 1);
	std::cout << p24 << std::endl;
	delete[]p24;*/

	std::allocator<string> ss;
	auto const p = ss.allocate(20);   //���Ƿ���Ķ���Ϊn��string�������ڴ棬�������
	auto q = p;
	ss.construct(q, "x");
	cout << *q << endl;
	ss.construct(q++, "would");
	cout << *(q-1) << endl;   
	ss.construct(q++, "me");
	cout << *(q-1)<< endl;
	ss.construct(q++, "you");
	cout << *(q-1) << endl;
	ss.construct(q++, "love");
	cout << *(q-1) << endl;
	//�ǵ�����һ����Ҫq-1�Ժ���ܽ����ã�ʵ�������ֵ�Ǹ���qָ����ڴ�ģ�Ȼ���++
	//����֮������destory�������Ȼ������deallocate���ͷ��ڴ�
	

	map<string, string*> m1;
	string s1 = "hello";
	//m1.insert(std::make_pair("world", "hello"));
	m1.insert(std::make_pair(s1,&s1));


	ifstream file("test.txt");   //����û�����⣬�Ѿ����Թ���
	TextQuery t1(file);
	QueryResult q1 = t1.query("the");
	q1.print();


	



	return 0;
}






