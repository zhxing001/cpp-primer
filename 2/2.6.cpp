#include<iostream>
#include<string>
struct foo
{

};        //这里如果不加分号就会把后面的当作前面类的对象来处理，自然报错

struct Sales_data
{
	std::string bookNo;
	unsigned uints_sold = 0;
	double price = 0;
	double revenue = 0;      //这里赋初值可以进行对象定义的时候初始化，c++11之后功能
};

decltype(Sales_data::revenue) add(Sales_data d1, Sales_data d2)
{
	decltype(Sales_data::revenue) total;
	unsigned total_num;
	if (d1.bookNo == d2.bookNo)
	{
		total_num = d1.uints_sold + d2.uints_sold;
		total = d1.revenue + d2.revenue;
		std::cout << "册数为：" << total_num << std::endl;
		std::cout << "总结为：" << total << std::endl;
		return total;
		
	}
	
}

int main()
{
	Sales_data data1, data2;
	std::cout << "请输入第一笔交易信息：书号，数量，单价" << std::endl;
	std::cin >> data1.bookNo >> data1.uints_sold >> data1.price;
	data1.revenue = data1.price*data1.uints_sold;
	std::cout << "请输入第二笔交易信息：" << std::endl;
	std::cin >> data2.bookNo >> data2.uints_sold >> data2.price;
	data2.revenue = data2.price*data2.uints_sold;
	add(data1, data2);
	return 0;
}