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
	//���캯�����ǽ����������ڶ�Ӧ�����ݳ�Ա�С�
private:
	string  word_tofind;      //��Ҫ���ҵĵ���
	std::shared_ptr<vector<string>> file; //�����ļ�
	std::shared_ptr <set<vector<string>::size_type>> line_no; //�к�
};

void QueryResult::print()
{
	cout << "Ҫ���ҵĵ���Ϊ��" << word_tofind << endl;
	cout << "��������" << (*line_no).size() << "  ��." << endl;
	cout << "���ֵ��к��Լ�����Ϊ��" << endl;
	for (auto word : *line_no)
	{
		cout << "lines  " << word+1 << ":";
		cout << (*file)[word] << endl;
	}
	
}


class TextQuery {
public:
	TextQuery(ifstream &file);  //����һ���ļ�������ʼ������
	QueryResult query(const string &) const;   //�����������ѯ����
private:
	std::shared_ptr<vector<string>> input;
	map<string, std::shared_ptr<std::set<vector<string>::size_type>>> result;
	//ÿ�����ʺ��кŵ�һ��ӳ��,һ��dancing�����кܶ��кţ�����Щ�кŴ���һ��set��
};

TextQuery::TextQuery(ifstream &file):input(new vector<string>)    
//���캯������������壬�����input����newǧ���������ˣ���Ȼ�ͻ�����һ�������ڵ�vector<String>��������ݣ��ڴ����
{
	string text;  //����ÿһ�е�����
	while (std::getline(file, text))
	{
		input->push_back(text);  //��һ�д���vector
		int n = input->size() - 1;   //��ǰ�У�Ӧ���ǵ�0�У������ǽ���һ�������������ʱ����Ը�����ټ�1
		std::istringstream EvetyLine(text);   //��ÿһ�в���
		string word;   //����
		while (EvetyLine >> word)     //����ÿһ�����ʴ���
		{
			auto &lines = result[word];   //��ǰ�ĵ��ʼ���map�������һ�γ��֣��ղ��룬��ͻ���һ����ָ�룬
			if (!lines)     //���ָ��Ϊ�գ�˵�����ǵ�һ�������������
				lines.reset(new set<vector<string>::size_type>);   //�ʹ���һ��set
			lines->insert(n);   //�ѵ�ǰ�кŲ�������
		}
	}
}

inline QueryResult TextQuery::query(const string &word) const
{
	std::shared_ptr<set<vector<string>::size_type>> nodata(new set<vector<string>::size_type>);
	//���û�ҵ��Ļ����Ͷ���������һ��ָ�롣��ʱ�򷵻�ȥ
	auto location = result.find(word);    //����ָ���λ�õ�һ��������
	if (location == result.end())  //���û�ҵ��Ļ�
		return QueryResult(word, nodata, input);
	else
		return QueryResult(word, location->second, input);   //����ҵ����ͷ���ȥ���set
}




#endif