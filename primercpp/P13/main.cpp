#include<iostream>
#include<string>
 
using  namespace std;

class HasPtr
{
public:
	HasPtr(const string &s = string()) :ps(new string(s)),i(0){};  //¹¹Ôìº¯Êý
	HasPtr(const HasPtr& hp) :ps(new string(*hp.ps)), i(hp.i) {};
private:
	string *ps;
	int i;
};

int mian()
{
	cout << "gun!" << endl;
	return 0;
}