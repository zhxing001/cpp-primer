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

map<string, size_t> count_num(const vector<string> &s);   //ͳ��ÿ�����ʳ��ֵĴ���
void addname(map<string, vector<string>>&family, const string &family_name,const string &name);
void addfamily_name(map<string, vector<string>>&family,const string family_name);

map<string, string> bulidMap(ifstream &mapfile);
void transform_word(ifstream &map_file, ifstream &word);
//11.14
class Falimy
{
public:
	using Child = pair<string, string>;   //���ӣ���������������
	using Chileren = vector<Child>;        //�öຢ��
	using data = map<string, Chileren>;    //map���治ͬ��ͥ�ĺ���
	auto add(const string &last_name, const string &first_name, const string birthday)
	{
		_data[last_name].push_back(make_pair(first_name, birthday)); 
	}
	auto print() const    //��������һ����������������ı�������ݳ�Ա��ֵ
	{
		for (auto fa : _data)
		{
			cout << fa.first << "��   \n";
			for (auto c : fa.second)
			{
				cout << "name:" << c.first << "     birthday:" << c.second << endl;
			}
		}
	}

private:
	data _data;  // ���ݱ���������
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
	//	cout << f.first << "��";
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
	//	if ((find(s8.begin(), s8.end(), word8)) == s8.end())  //û�еĻ������
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
		//p12.push_back({ s12[i],s[i] });   //Ҳ�����ȶ���һ��pair�ٽ��и�ֵ��push_back
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
	cout << "ɾ����" << endl;
	for (auto l : library)
		cout << l.first << ":  " << l.second << endl;

	//11.33
	ifstream maprule("map_rule.txt");
	ifstream word("word.txt");
	auto map = bulidMap(maprule);
	for (auto i : map)
		cout << i.first << "--" << i.second << endl;  //���ԣ����û����

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




map<string, size_t> count_num(const vector<string> &s)   //ͳ��ÿ�����ʳ��ֵĴ���
{
	map<string, size_t>  string_num;
	vector<string> s_copy;   //����һ��s����Ϊ������еĶ�ת��ΪСд,����ı�ԭ����ֵ
	copy(s.begin(), s.end(), inserter(s_copy, s_copy.begin()));   
	string::iterator is_bd;   //�Ƿ��Ǳ�㣬����ǣ��������ĵ�������Ȼ��ɾ��
	for (auto &ss : s_copy)
	{
		string::iterator is_bd=ss.begin();   //�Ƿ��Ǳ�㣬����ǣ��������ĵ�������Ȼ��ɾ��
		for (auto &char_s : ss)
		{
			char_s = tolower(char_s);  //����Ǵ�д��ĸ�������Сд��
			
		}
		//while (is_bd != ss.end())     //ֻҪ�ҵ��˱�㣬�����Ϊ��
		//{
		//	is_bd=find(ss.begin(), ss.end(), ',');
		//	ss.erase(is_bd-ss.begin(), 1);
		//}
		//��ר�ŵ�һ������remove_if����������飬remove_if��ѷ����������ַ��ƶ���string��ĩβ��
		//����û��ɾ����Ҫɾ������Ҫ����erase���������������,���ص���һ��ָ���ƶ������������ʼ�ĵ�����
		//���ַ�ʽ��һ��ͨ�õļ��ɣ�ispunct������������iostream֮��,���ҿ�������ֱ����Ϊһ��ν��ʹ�á�
		ss.erase(remove_if(ss.begin(), ss.end(), ispunct),ss.end());
		string_num[ss]++;
	}
	return string_num;
}

map<string, string> bulidMap(ifstream &mapfile)
{
	map<string, string> transMap;   //�����յ�mapת������
	string key;
	string value;   //��ֵ��ʵֵ��
	while (mapfile >> key&&getline(mapfile, value))  
		//��һ���ִ���key������ʣ��Ĵ���value
	{
		if(value.size()>1)   //����Ƿ���ת������Ҫ����治���ǿո�ʲô��û��
		//transMap[key] = value.substr(1);  //���룬������ǰ���ո�Ҫ���ͻὨ����ʱ�����һ���ո�������ܵ���
		transMap.insert({ key,value.substr(1) });   //�����������ǿ��Ե�
	}
	return transMap;
}

void transform_word(ifstream &map_file, ifstream &word)  //��һ���ǹ��򣬵ڶ���������
{
	auto transMap = bulidMap(map_file);    //����ת������
	string text; //����ÿһ�е�����
	while (getline(word, text))
	{
		istringstream stream(text);
		string ss;
		while (stream >> ss)
		{
			//cout << ss << endl;
			if (transMap.find(ss) == transMap.end())
				cout << ss << " ";   //���û���ڱ���еľ�ԭ�����
			else
			{
				cout << transMap[ss] << " ";  //����������Ӧ��ֵ
			}
			
		}
		cout << endl;  //ÿһ�����һ���س�
	}
}