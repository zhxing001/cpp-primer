#pragma once
#ifndef TQ_H
#define TQ_H
#include<vector>
#include<string>
#include<memory>
#include<map>
#include<set>
#include<fstream>
#include<sstream>
using std::vector;
using std::string;
using std::map;
using std::set;
using std::ifstream;
using std::cout;
using std::endl;

class QueryResult
{
public:
	QueryResult(string word,
		std::shared_ptr<set<vector<string>::size_type>> pp,
		std::shared_ptr<vector<string>> ff) :word_tofind(word), file(ff), line_no(pp) {}
	void print();
	//构造函数就是将参数保存在对应的数据成员中。
private:
	string  word_tofind;      //需要查找的单词
	std::shared_ptr<vector<string>> file; //输入文件
	std::shared_ptr <set<vector<string>::size_type>> line_no; //行号
};

void QueryResult::print()
{
	cout << "要查找的单词为：" << word_tofind << endl;
	cout << "共出现了" << (*line_no).size() << "  次." << endl;
	cout << "出现的行号以及句子为：" << endl;
	for (auto word : *line_no)
	{
		cout << "lines  " << word+1 << ":";
		cout << (*file)[word] << endl;
	}
	
}


class TextQuery {
public:
	TextQuery(ifstream &file);  //接受一个文件，来初始化数据
	QueryResult query(const string &) const;   //这个函数来查询单词
private:
	std::shared_ptr<vector<string>> input;
	map<string, std::shared_ptr<std::set<vector<string>::size_type>>> result;
	//每个单词和行号的一个映射,一个dancing可能有很多行号，把这些行号存入一个set中
};

TextQuery::TextQuery(ifstream &file):input(new vector<string>)    
//构造函数，这个是主体，后面的input给个new千万不能忘记了，不然就会是在一个不存在的vector<String>里添加数据，内存出错
{
	string text;  //保存每一行的内容
	while (std::getline(file, text))
	{
		input->push_back(text);  //这一行存入vector
		int n = input->size() - 1;   //当前行，应该是第0行，这里是建立一个索引，输出的时候可以给这个再加1
		std::istringstream EvetyLine(text);   //把每一行拆解掉
		string word;   //单词
		while (EvetyLine >> word)     //对于每一个单词处理
		{
			auto &lines = result[word];   //当前的单词加入map。如果第一次出现，刚插入，这就会是一个空指针，
			if (!lines)     //如果指针为空，说明我们第一次遇到这个单词
				lines.reset(new set<vector<string>::size_type>);   //就创建一个set
			lines->insert(n);   //把当前行号插入其中
		}
	}
}

inline QueryResult TextQuery::query(const string &word) const
{
	std::shared_ptr<set<vector<string>::size_type>> nodata(new set<vector<string>::size_type>);
	//如果没找到的话，就定义这样的一个指针。到时候返回去
	auto location = result.find(word);    //返回指向此位置的一个迭代器
	if (location == result.end())  //如果没找到的话
		return QueryResult(word, nodata, input);
	else
		return QueryResult(word, location->second, input);   //如果找到，就返回去这个set
}




#endif