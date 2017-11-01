#include<iostream>
#include<vector>
#include<string>
#include<list>
#include<algorithm>
#include<numeric>
#include<functional>
#include<iterator>
using namespace std;
using namespace std::placeholders;

bool IsShorter(const string &s1, const string &s2);
void elimDups(vector<string> &v);
void sort_shorter(vector<string> &v);
bool size_below5(string &s);
void biggies(vector<string> &words, vector<string>::size_type sz);
void biggies1(vector<string> &words, vector<string>::size_type sz);
void biggies2(vector<string> &words, vector<string>::size_type sz);
bool check6(string &s1, string::size_type sz);

auto check_size(string &s1, string::size_type sz)
{
	return s1.size() <= sz;
}
auto count_size_exceed4(vector<string> &v)
{
	auto count = count_if(v.begin(), v.end(), [](const string &s) {return s.size() > 4; });
	return count;
}

int main()
{
	//10.1
	vector<int> v1 = { 1,2,3,4,5,6,7,2,4,54,5,6,7,5,4,4,56,7,8,5,4,3,5,3,8,9 };
	auto count1 = count(v1.begin(), v1.end(), 5);
	cout << "5在v2中出现的次数为:" << count1 << endl;
	//10.2
	list<string> l2 = { "would","you","love","me","for","the","reason","love","can","the" };
	auto count2 = count(l2.begin(), l2.end(), "love");
	cout << "love在l2中出现的次数为：" << count2 << endl;
	//10.3
	auto sum1 = accumulate(v1.cbegin(), v1.cend(), 0);
	cout << "v1中所有数的和为：" << sum1 << endl;
	//10.4
	vector<double> v4 = { 1,2,3,5,6,7,8,6,7 };
	auto sum2 = accumulate(v4.cbegin(), v4.cend(), 0);
	cout << "v4中所有数的和为：" << sum2 << endl;
	char p[] = "woulu you";
	char p2[] = "coule you";
	auto a=equal(p,p+4, p2);
	cout << a << endl;
	//10.6
	fill(v1.begin(), v1.end(), 0);
	for (auto v : v1)
		cout << v << " ";
	cout << endl;
	//10.7
	vector<string> l8 = { "would","you","love","me","for","the","reason","love","can","the","afhahg","fkhakh" };
	sort(l8.begin(), l8.end());
	cout << "排序后：";
	for (auto l : l8)
		cout << l << " ";
	cout << endl;

	auto end=unique(l8.begin(), l8.end());
	//unique排序玩之后通过auto就只能访问到前面不重复的了,但是最后一个迭代器确实还是指向原来的尾后
	cout << l8.end() - l8.begin() << endl;
	for (auto l : l8)
		cout << l << " ";
	cout << endl;

	
	for (auto l = l8.begin(); l != end; l++)
		cout << *l << " ";
	cout << endl;

	l8.erase(end, l8.end());
	for (auto l : l8)
		cout << l << " ";
	cout << endl;

	sort_shorter(l8);
	auto end13=partition(l8.begin(), l8.end(), size_below5);
	cout << "大于等于5的元素：";
	for (auto l = end13; l!= l8.end();l++)
		cout << *l << " ";
	cout << endl;

	cout << "大于三个元素：";
	biggies(l8, 3);
	biggies1(l8, 3);
	biggies2(l8, 3);
    //10.14
	auto sum14 = [](int s1, int s2) {return s1 + s2; };  //lamda表达式和matlab的函数有点像
	cout << sum14(1, 2) << endl;
	
	int i = 5;
	auto f = [&i]()mutable {return ++i; };
	//这里i用引用和不用引用完全是不同的结果，
	//看p353
	i = 10;
	auto x = f();
	cout << x << endl;
	cout << i << endl;
	cout<<"长度大于4的字符有："<<count_size_exceed4(l8)<<"个"<<endl;

	//10.21
	auto f1 = [&i]()->bool {
		if (i > 0)
		{
			i--;
			return false;
		}
		if (i == 0)
		{
			return true;
		}
	};
	cout<<f1()<<endl;
	string::size_type sz22 = 4;
	auto cnt22=count_if(l8.begin(), l8.end(), bind(check6,_1,sz22));
	cout <<"大于等于4的字符有："<< cnt22 << endl;

	//10.24
	string s24("hello");
	vector<int>  v24 = { 1, 1, 3, 4, 5, 6, 7, 8, 9, 7, 6, 6, 7, 8, 9 };
	auto length24 = s24.size();
	auto Tfirst=find_if(v24.begin(), v24.end(), bind(check_size, s24, _1));
	cout << *Tfirst << endl;

	//testp358
	list<int> l358 = { 1,2,3,4,4,4,6,6,6,6,3,4,5,6,7,5,4,3,47,8,8 };
	list<int> l11, l22;
	//copy(l358.begin(), l358.end(), front_inserter(l11));
	//copy(l358.begin(), l358.end(), inserter(l22, l22.end()));
	l358.sort();   //list不能用泛型的sort，但是可以用自己的成员函数sort
	for (auto l : l358)
		cout << l << " ";
	cout << endl;
	unique_copy(l358.begin(), l358.end(), back_inserter(l22));
	//这个copy只是不重复
	for(auto l:l22)
		cout << l << " ";
	cout << endl;
	

	return 0;
}

bool IsShorter(const string &s1, const string &s2)
{
	return s1.size() < s2.size();
}

void elimDups(vector<string> &v)
{
	sort(v.begin(), v.end());
	auto end = unique(v.begin(), v.end());
	v.erase(end, v.end());  //这区间的全部删去
}

void sort_shorter(vector<string> &v)
{
	elimDups(v);
	stable_sort(v.begin(), v.end(), IsShorter);
	cout << "按照长度排序结束后为：" << endl;
	for (auto i : v)
		cout << i << " ";
	cout << endl;

}

bool size_below5(string &s)
{
	return s.size() < 5;
}

void biggies(vector<string> &words, vector<string>::size_type sz)
{
	elimDups(words);  //按字典顺序排序
	stable_sort(words.begin(), words.end(),
		[](const string &s1, const string &s2) {return s1.size() <s2.size(); });
	//这里用了一个lamda表达式排序的条件是长度小的在前
	auto wc = find_if(words.begin(), words.end(), [sz](const string s1) {return s1.size() > sz; });
	//函数局部变量只有捕获之后才能用
	auto count = words.end() - wc;
	for (auto beg = wc; beg != words.end(); beg++)
		cout << *beg << " ";
	cout << endl;
}

void biggies1(vector<string> &words, vector<string>::size_type sz)
{
	elimDups(words);  //按字典顺序排序
	stable_sort(words.begin(), words.end(),
		[](const string &s1, const string &s2) {return s1.size() <s2.size(); });
	//这里用了一个lamda表达式排序的条件是长度小的在前
	auto wc = partition(words.begin(), words.end(), [sz](const string s1) {return s1.size() <=sz; });
	//函数局部变量只有捕获之后才能用
	auto count = words.end() - wc;
	for (auto beg = wc; beg != words.end(); beg++)
		cout << *beg << " ";
	cout << endl;
}

void biggies2(vector<string> &words, vector<string>::size_type sz)
{
	elimDups(words);  //按字典顺序排序
	stable_sort(words.begin(), words.end(),
		[](const string &s1, const string &s2) {return s1.size() <s2.size(); });
	//这里用了一个lamda表达式排序的条件是长度小的在前
	auto wc = stable_partition(words.begin(), words.end(), [sz](const string s1) {return s1.size() <= sz; });
	//函数局部变量只有捕获之后才能用
	auto count = words.end() - wc;
	for (auto beg = wc; beg != words.end(); beg++)
		cout << *beg << " ";
	cout << endl;
}



bool check6(string &s1, string::size_type sz)
{
	return s1.size() <=sz;
}