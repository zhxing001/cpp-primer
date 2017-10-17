#ifndef person_h
#define person_h

#include<iostream>
#include<string>
#include<iomanip>
using std::cout;
using std::cin;
using std::string;
using std::endl;

class person;
std::istream &readp(std::istream &is, person &item);
class person
{
	friend std::istream &readp(std::istream &is, person &item);
public:
	person() = default;
	person(const string &s1,const string &s2):Name(s1),Address(s2){} //如果要用字面值初始化的话这里就要定义成const的，字面值可以转换为常量
	person(std::istream &is)
	{
		readp(is, *this);
	}
	string get_name() const
	{
		return Name;
	}
	string get_address() const
	{
		return Address;
	}
	void show_ifo()
	{
		cout <<std::left<<std::setw(15)<< Name << std::left<<std::setw(15) << Address << endl;
	//左对齐，占15个字符
	}
private:

	string Name;
	string Address;
};


std::istream &readp(std::istream &is, person &item)
{
	is >> item.Name >> item.Address;
	return is;
}

std::ostream & printp(std::ostream &os, person &item)
{
	os << item.get_name() <<item.get_address() << endl;
	return os;
}


#endif