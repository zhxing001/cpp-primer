#pragma once

#include<iostream>
#include<string>
#include<vector>
#include<iomanip>

using std::string;
using std::vector;
using std::cout;
using std::endl;
using std::cin;
class Sale_data;    //声名下，下面read要用
std::istream  &read(std::istream &, Sale_data &);

class Sale_data
{
public:
	Sale_data() = default;
	Sale_data(string s, unsigned u, double d) :BookNo(s), Uints_sold(u), revenue(d) {}  //初始化列表构造函数
	Sale_data(std::istream &is)
	{
		read(is, *this);
	}
	std::string BookNo;
	unsigned Uints_sold = 0;
	double revenue = 0;
	Sale_data & combine(const Sale_data &rhs);
	
	void showIfo() const
	{
		cout << std::left << std::setw(20) << "BookNo: " << std::left << std::setw(8) << BookNo << endl;
		cout << std::left << std::setw(20) << "Uints_sold: " << std::left << std::setw(8) << Uints_sold << endl;
		cout << std::left << std::setw(20) << "revenue:" << std::left << std::setw(8) << revenue << endl;
		//对其的一种输出模板
	}
	std::string isbn()
	{
		return BookNo;
	}

};

std::istream &read(std::istream &is, Sale_data &item)  //IO类型也是不可拷贝的类型，这里传入引用
{
	double price = 0;
	is >> item.BookNo >> item.Uints_sold >> price;
	item.revenue = price*item.Uints_sold*price;
	return is;
}

std::ostream &print(std::ostream &os, Sale_data &item)
{
	os << item.isbn() << " " << item.Uints_sold << " " << item.revenue << endl;
	return os;
}

Sale_data & Sale_data::combine(const Sale_data & rhs)
{
	Uints_sold += rhs.Uints_sold;   //数量加起来
	revenue += rhs.revenue;      //总价加起来
	return *this;
}

