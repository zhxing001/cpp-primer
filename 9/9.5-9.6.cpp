#include<iostream>
#include<vector>
#include<string>
#include<cctype>
#include<stack>
using std::stack;
using std::vector;
using std::string;
using std::cout;
using std::cin;
using std::endl;

void replace_OldVal(string &s1, const string &olds, const string &news)
{
	for (auto cur = s1.begin(); cur <= s1.end() - olds.size();)
	{
		if (string(cur, cur + olds.size()) == olds)   //如果相等
		{ 
			s1.erase(cur, cur + olds.size());        //删除原来的单词
			s1.insert(cur, news.begin(), news.end());  //插入新的
			cur+= news.size();     //跳过新单词遍历
		}
		else
		cur++;        //遍历
 	}
}
//9.44
void replace_OldVal1(string &s1, const string &olds, const string &news)
{
	for (auto cur = s1.begin(); cur <= s1.end() - olds.size();)
	{
		if (string(cur, cur + olds.size()) == olds)   //如果相等
		{
			s1.replace(cur, cur + olds.size(), news);
			cur += news.size();     //跳过新单词遍历
		}
		else
			cur++;        //遍历
	}
}

void addMr_Ms(string &s,  const string &mr="Mr.", const string &jr=" JR")
{
	s.append(jr);  
	s.insert(s.begin(),mr.begin(),mr.end());
	//insert不接受单独的string对象作为参数，还是要看其函数定义是啥再去写
}

void addMr_Ms1(string &s, const string &mr = "Mr.", const string &jr = " JR")
{
	s.reserve(s.size() + 5);
	s.insert(s.end(),jr.begin(),jr.end());      //这个是在之后插入
	s.insert(s.begin(), mr.begin(), mr.end());  //这个是在之前插入，神奇的不行
	//insert不接受单独的string对象作为参数，还是要看其函数定义是啥再去写
}

void Find_Num(const string &s)
{
	string nums = "0123456789";
	string::size_type pos = 0;
	while ((pos = s.find_first_of(nums, pos)) != s.npos)   
		//npos是size+1么？并不是，npos是一个很大的数（int的最大值），当超出索引范围后，返回的pos就是这个值。但是用这个值索引对象肯定会超范围的
	{
		cout << "位置是：" << pos
			<< " 数字是：" << s[pos] << endl;
		pos++;
	}
}

void Find_Letter(const string &s)
{
	string nums = "0123456789";
	string::size_type pos = 0;
	while ((pos = s.find_first_not_of(nums, pos)) != s.npos)
		//npos是size+1么？并不是，npos是一个很大的数（int的最大值），当超出索引范围后，返回的pos就是这个值。但是用这个值索引对象肯定会超范围的
	{
		cout << "位置是：" << pos
			<< " 字母是：" << s[pos] << endl;
		pos++;
	}
}

auto find_noUpDown(const string &s)
{
	string up_dowm = "acenmorsuvwxz";
	unsigned pos1=0;   //当前位置查找
	unsigned pos2=0;
	unsigned length = 0;
	unsigned pos3 = 0;

	while((pos1 = s.find_first_of(up_dowm, pos1))!= string::npos)   //从pos1开始找第一个不出头字符
	{
		
		pos2 = pos1;   //先把这个存下来，下面要用，不要改变它
		if ((pos2 = s.find_first_not_of(up_dowm, pos2)))      //从不出头的，找到下一个出头字符
		{
			if (pos2 == string::npos)  
			{
				if (s.size() - 1 - pos1 > length)
				{
					pos3 = pos1;
					length = pos2 - pos1;

				}
				break;   
				//要单独处理最后一步，原程序没有处理最后全是不出头字母的统计，这里加一个循环来，因为原来的程序只要判断到找不到出头
				//字母，就会跳出循环了，并没有再计算最后那一段是不是最大的，
				//这个坑要经常注意，在查找的时候很多时候的判断条件都会略过最后的一部分，特别是这种判断最长或者最短的情况。
			}
			if (pos2 - pos1 >= length)
			{
				length = pos2 - pos1;   //如果大于前面统计的长度，则更新这个长度。
				pos3 = pos1;
				
			}
		}
	  
		pos1++;	
	}
	
	
	cout << length << endl;
	string max=s.substr(pos3, length);
	cout << max << endl;	
}

class date {

public:
	date(const string &s);
private:
	unsigned year;
	unsigned mon;
	unsigned day;
};

date::date(const string &s)
{
	vector<string> v(3);
	size_t i = 0;
	auto curr=s.begin();   //首位迭代器
	for (auto it = s.begin(); it != s.end();it++)       //先把这个字符串分割开来 
	{
		if (!isalnum(*it))     //不是字母和数字,
		{
			
			v[i] = string(curr, it);      //拷贝过来,拷贝的时候是前闭后开区间，千万注意
			curr = it+1; 
			i++;
		}
	}
	
	v[i] = string(curr, s.end());
	cout << v[0] << " " << v[1] << " " << v[2] << endl;       //这个是测试
	
	if (v[0] == "January")  mon = 1;
	if (v[0] == "February")  mon = 2;
	if (v[0] == "March")  mon = 3;
	if (v[0] == "April")  mon = 4;
	if (v[0] == "May")  mon = 5;
	if (v[0] == "June")  mon = 6;
	if (v[0] == "July")  mon = 7;
	if (v[0] == "August")  mon =8;
	if (v[0] == "September")  mon = 9;
	if (v[0] == "Octomber")  mon = 10;
	if (v[0] == "November")  mon = 11;
	if (v[0] == "December")  mon = 12;
	
	day = std::stoi(v[1]);
	year = std::stoi(v[2]);
	cout << "构造函数被调用,日期为" << endl;
	cout << year << ":" << mon << ":" << day << endl;
	
}

int main()
{
	//9.41
	vector<char>  v41 = { 'h','e','l','l','o' };
	string s41(v41.begin(), v41.end());
	cout << s41 << endl;
	//9.43
	string s{ "if you love me for the reason,let the reason be love" };
	cout << "替换前： " << s << endl;
	replace_OldVal(s, "love", "LOVE");
	cout << "替换后： " << s << endl;
	replace_OldVal(s, "me", "ME");
	cout << "替换后： " << s << endl;
	//9.45
	string s45("smith");
	addMr_Ms(s45, "Mr.");
	cout << s45 << endl;

	string s46("smith");
	addMr_Ms1(s46, "Mr.");
	cout << s46 << endl;
	//9.47
	string s47 = "ab2c3d4R4SAH2";
	Find_Num(s47);
	
	
	Find_Letter(s47);
    string 	num1 = "0123456789";
	cout<<s47.find(num1)<<endl;

	//9.49
	string s49 = "aaabbbcccccccccccccdddddeeeedasdeeeeeeeeeeeeeeeeeeeeeeeeeesses";
	
	find_noUpDown(s49);
	

	date d("February/23/1992");

	//9.52
	string express{ "this is (prey)" };
	bool bSeen = false;
	stack<char> stk;
	for (const auto &s : express)
	{
		if (s == '(')
		{
			bSeen = true; 
			continue;
		}
		if (s == ')')
		{
			bSeen = false;
		}
		if (bSeen)
			stk.push(s);   //如果是左括号然后压入栈中
	}
	string restring;   //代替的字符串
	while (!stk.empty())
	{
		restring += stk.top();
		stk.pop();  
		//加上，并删除
	}

	express.replace(express.find('(') + 1, restring.size(),restring);
	cout << express << endl;

	return 0;
}