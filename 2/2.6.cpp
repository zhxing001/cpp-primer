#include<iostream>
#include<string>
struct foo
{

};        //����������ӷֺžͻ�Ѻ���ĵ���ǰ����Ķ�����������Ȼ����

struct Sales_data
{
	std::string bookNo;
	unsigned uints_sold = 0;
	double price = 0;
	double revenue = 0;      //���︳��ֵ���Խ��ж������ʱ���ʼ����c++11֮����
};

decltype(Sales_data::revenue) add(Sales_data d1, Sales_data d2)
{
	decltype(Sales_data::revenue) total;
	unsigned total_num;
	if (d1.bookNo == d2.bookNo)
	{
		total_num = d1.uints_sold + d2.uints_sold;
		total = d1.revenue + d2.revenue;
		std::cout << "����Ϊ��" << total_num << std::endl;
		std::cout << "�ܽ�Ϊ��" << total << std::endl;
		return total;
		
	}
	
}

int main()
{
	Sales_data data1, data2;
	std::cout << "�������һ�ʽ�����Ϣ����ţ�����������" << std::endl;
	std::cin >> data1.bookNo >> data1.uints_sold >> data1.price;
	data1.revenue = data1.price*data1.uints_sold;
	std::cout << "������ڶ��ʽ�����Ϣ��" << std::endl;
	std::cin >> data2.bookNo >> data2.uints_sold >> data2.price;
	data2.revenue = data2.price*data2.uints_sold;
	add(data1, data2);
	return 0;
}