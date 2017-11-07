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
//	StrBolb();      //默认构造函数
//	StrBolb(std::initializer_list<std::string> il);  //使用初始化列表来构造当前类，重载的构造函数
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
//	void pop_back();    //删除最后一个元素
//	std::string & front();
//	std::string & back();
//private:
//	std::shared_ptr<std::vector<std::string>> data;
//	void check(size_type i, const std::string &msg) const;    //检查元素是否存在，定义成const，并不打算修改对象
//};
//
//StrBolb::StrBolb():data(std::make_shared<std::vector<std::string>>()) {}   //构造一个空指针
//
//StrBolb::StrBolb(std::initializer_list<std::string> il)
//{
//	std::make_shared<std::vector<std::string>>(il);    //直接构造这样的一个共享指针，用数据il构造的。
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
//		for (auto s : *p) //解引用得到的是vector本身
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
	//delete p;   //因为这里的p是一个new产生的（在read_int函数里），所以用完要删掉，否则就会一致占动态内存

	//std::unique_ptr<std::string>  p1(new std::string("hello"));   
	//std::unique_ptr<std::string> p2(p1.release());       //p1放弃对指针的控制权，返回指针，并且将p1置空
	//std::cout << *p2 << std::endl;             //这样p2就是指向hello了
	//std::unique_ptr<std::string>  p3(new std::string("would"));
	//p2.reset(p3.release());
	//std::cout << *p2 << std::endl;

	//12.16
	//std::unique_ptr<int> p16(new int(2));   //初始化p
	//std::unique_ptr<int> p162(p16);         //不允许拷贝初始化
	//auto p163 = p16;                        //不允许赋值 
	//这两个都是unique_ptr的特性
	//12.17
	//int ix = 1024;
	//int *p = &ix;
	//int *p2 = new int(2048);
	//typedef std::unique_ptr<int> Intp;
	////Intp p170(ix);       //这种赋值是部队的，不能用int来初始化unique_ptr<int> 
	//Intp p171(&ix);     //这种是可以编译的，把ix的地址赋值给一个unique_ptr,；
	//Intp p172(p2);      //这也是可以的，p2本身是一个new，赋值给p2就可以
	//Intp p173(p);       //用一个普通指针去初始化一个指针，那么p本身就成为一个空悬指针了
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
	
	//char *sumchar = new char[20];  //要给一个\n
	////strcat(sumchar, "hello");
	////strcat(sumchar, "world");
	//  
	////vs2015中不能用这个函数，算逑
	//strcat_s(sumchar, 5,"hello");
	////strcat_s(sumchar, 0,"hello");
	////std::cout << sumchar<<std::endl;
	//12.24
	/*char *p24 = new char[20];
	std::cin.get(p24, 20 + 1);
	std::cout << p24 << std::endl;
	delete[]p24;*/

	std::allocator<string> ss;
	auto const p = ss.allocate(20);   //这是分配的对象，为n个string分配了内存，而且这个
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
	//记得这里一定是要q-1以后才能解引用，实际上这个值是赋给q指向的内存的，然后才++
	//完了之后先用destory销魂对象，然后再用deallocate来释放内存
	

	map<string, string*> m1;
	string s1 = "hello";
	//m1.insert(std::make_pair("world", "hello"));
	m1.insert(std::make_pair(s1,&s1));


	ifstream file("test.txt");   //读入没有问题，已经测试过了
	TextQuery t1(file);
	QueryResult q1 = t1.query("the");
	q1.print();


	



	return 0;
}






