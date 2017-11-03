#include<iostream>
#include<string>
#include<map>
#include<set>
#include<vector>
#include<algorithm>
#include<iterator>
#include<utility>
#include<fstream>
#include<sstream>
using namespace std;

map<string, size_t> count_num(const vector<string> &s);   //统计每个单词出现的次数
void addname(map<string, vector<string>>&family, const string &family_name,const string &name);
void addfamily_name(map<string, vector<string>>&family,const string family_name);

map<string, string> bulidMap(ifstream &mapfile);
void transform_word(ifstream &map_file, ifstream &word);
//11.14
class Falimy
{
public:
	using Child = pair<string, string>;   //孩子，保存其名和生日
	using Chileren = vector<Child>;        //好多孩子
	using data = map<string, Chileren>;    //map保存不同家庭的孩子
	auto add(const string &last_name, const string &first_name, const string birthday)
	{
		_data[last_name].push_back(make_pair(first_name, birthday)); 
	}
	auto print() const    //这声名是一个常量函数，不会改变类的数据成员的值
	{
		for (auto fa : _data)
		{
			cout << fa.first << "：   \n";
			for (auto c : fa.second)
			{
				cout << "name:" << c.first << "     birthday:" << c.second << endl;
			}
		}
	}

private:
	data _data;  // 数据保存在这里
};


int main()
{
	/*map<string, size_t> word_count;
	string word;
	while (cin >> word)
	{
		if (word == "end")
			break;
		++word_count[word];
	}
		
	for (const auto &w : word_count)
		cout << w.first << " " << w.second << endl;*/
	
	//11.4
	//vector<string> s4 = { "would","you","love,","LOV,,E","woulD","can","YOU" };
	//map<string, size_t> num4 = count_num(s4);
	//for (auto n : num4)
	//	cout << n.first << "   " << n.second << endl;
	//cout << endl;

	////11.7
	//map<string, vector<string>> family;
	//addfamily_name(family, "zhang");
	//cout << family.size() << endl;
	//addname(family, "zhang", "xing");
	//addname(family, "zhang", "huang");
	//addfamily_name(family, "huang");
	//addname(family, "huang", "zikun");
	//addname(family, "huang", "app");
	//cout<< family.size() << endl;
	//for (auto f : family)
	//{
	//	cout << f.first << "：";
	//	for (auto n : f.second)
	//		cout << n << " ";
	//	cout << endl;
	//}
	////11.8  
	//string word8;
	//vector<string> s8;
	//while (cin >> word8)
	//{
	//	if (word8 == "end")
	//		break;
	//	if ((find(s8.begin(), s8.end(), word8)) == s8.end())  //没有的话再添加
	//			s8.push_back(word8);
	//}

	//for (auto v:s8)
	//	cout << v << " ";
	//cout << endl;

	//11.12
	vector<string> s12 = { "would","you","love","me","for" };
	int s[] = { 1,2,3,4,5 };
	vector<pair<string,int>> p12;
	for (rsize_t i = 0; i < s12.size(); i++)
	{
		//p12.push_back({ s12[i],s[i] });   //也可以先定义一个pair再进行赋值和push_back
		p12.push_back(make_pair(s12[i], s[i]));
	}
	for (auto p : p12)
		cout << p.first << " " << p.second << endl;

	//11.14
	Falimy family;
	family.add("zhang", "xing", "0219");
	family.add("zhang", "xing1", "0329");
	family.add("huang", "a", "3029");
	family.print();

	//11.31
	multimap<string, string> library;
	string author1 = "zhxing";
	string author2 = "huang";
	string author3 = "xing";
	string book1 = "aaa";
	string book2 = "bbb";
	library.insert(make_pair(author1, book1));
	library.insert(make_pair(author2, book1));
	library.insert(make_pair(author3, book1));
	library.insert(make_pair(author1, book2));
	library.insert(make_pair(author2, book2));
	library.insert(make_pair(author3, book2));
	for (auto l : library)
		cout << l.first << ":  " << l.second << endl;
	auto range = library.equal_range("zhxing");
	library.erase(range.first, range.second);
	cout << "删除后：" << endl;
	for (auto l : library)
		cout << l.first << ":  " << l.second << endl;

	//11.33
	ifstream maprule("map_rule.txt");
	ifstream word("word.txt");
	auto map = bulidMap(maprule);
	for (auto i : map)
		cout << i.first << "--" << i.second << endl;  //测试，这个没问题

	transform_word(maprule, word);
	return 0;

}

void addfamily_name(map<string, vector<string>>&family, const string family_name)
{
	family[family_name];
}

void addname(map<string, vector<string>>&family,const string &family_name,const string &name)
{
	family[family_name].push_back(name);
}




map<string, size_t> count_num(const vector<string> &s)   //统计每个单词出现的次数
{
	map<string, size_t>  string_num;
	vector<string> s_copy;   //拷贝一份s，因为想把所有的都转换为小写,不想改变原来的值
	copy(s.begin(), s.end(), inserter(s_copy, s_copy.begin()));   
	string::iterator is_bd;   //是否是标点，如果是，返回它的迭代器，然后删掉
	for (auto &ss : s_copy)
	{
		string::iterator is_bd=ss.begin();   //是否是标点，如果是，返回它的迭代器，然后删掉
		for (auto &char_s : ss)
		{
			char_s = tolower(char_s);  //如果是大写字母，都变成小写的
			
		}
		//while (is_bd != ss.end())     //只要找到了标点，这个就为真
		//{
		//	is_bd=find(ss.begin(), ss.end(), ',');
		//	ss.erase(is_bd-ss.begin(), 1);
		//}
		//有专门的一个函数remove_if来做这个事情，remove_if会把符合条件的字符移动到string的末尾，
		//但并没有删除，要删除还是要调用erase函数来做这个事情,返回的是一个指向移动后符合条件开始的迭代器
		//这种方式是一个通用的技巧，ispunct函数包含在了iostream之中,并且可以这样直接作为一个谓词使用。
		ss.erase(remove_if(ss.begin(), ss.end(), ispunct),ss.end());
		string_num[ss]++;
	}
	return string_num;
}

map<string, string> bulidMap(ifstream &mapfile)
{
	map<string, string> transMap;   //建立空的map转换规则
	string key;
	string value;   //键值和实值，
	while (mapfile >> key&&getline(mapfile, value))  
		//第一个字存入key，本行剩余的存入value
	{
		if(value.size()>1)   //检查是否有转换规则，要求后面不能是空格什么都没有
		//transMap[key] = value.substr(1);  //存入，且跳过前导空格，要不就会建立的时候会有一个空格出来，很蛋疼
		transMap.insert({ key,value.substr(1) });   //用这两个都是可以的
	}
	return transMap;
}

void transform_word(ifstream &map_file, ifstream &word)  //第一个是规则，第二个是文字
{
	auto transMap = bulidMap(map_file);    //建立转换规则
	string text; //保存每一行的内容
	while (getline(word, text))
	{
		istringstream stream(text);
		string ss;
		while (stream >> ss)
		{
			//cout << ss << endl;
			if (transMap.find(ss) == transMap.end())
				cout << ss << " ";   //如果没有在表格中的就原样输出
			else
			{
				cout << transMap[ss] << " ";  //否则就输出对应的值
			}
			
		}
		cout << endl;  //每一行输出一个回车
	}
}