#include<iostream>
#include<string>
#include<vector>

using namespace std;

int main()
{

	//5.9,10,11
	//char c5;
	//int aCnt = 0, eCnt = 0, iCnt = 0, oCnt = 0, uCnt = 0, nCnt = 0, spaceCnt = 0, TabCnt = 0, cnt = 0; //记录各个数目
	//while (cin >> noskipws >> c5)
	//{
	//	if (c5 == '\n')
	//		break;
	//	switch (c5)
	//	{
	//	case 'a':
	//		aCnt++;
	//		break;
	//	case 'e':
	//		eCnt++;
	//		break;
	//	case 'i':
	//		iCnt++;
	//		break;
	//	case 'o':
	//		oCnt++;
	//		break;
	//	case 'u':
	//		uCnt++;
	//		break;
	//	case ' ':
	//		spaceCnt++;
	//		break;
	//	case '\t':
	//		TabCnt++;
	//		break;
	//	
	//	default:
	//		cnt++;
	//		break;
	//	}
	//}
	//cout << "a个数： " << aCnt << endl;
	//cout << "e个数： " << eCnt << endl;
	//cout << "i个数： " << iCnt << endl;
	//cout << "o个数： " << oCnt << endl;
	//cout << "u个数： " << uCnt << endl;
	//cout << "非元音个数：" << cnt << endl;
	//cout << "空格个数： " << spaceCnt << endl;
	//cout << "tab个数： " << TabCnt << endl;

	//5.14
	
	//int cnt141 = 1;         //记录当前最多连续出现的次数。
	//int cnt142 = 1;         //记录总的最多连续的次数
	//vector<string>  v14;      //把输入的单词存入其中
	//string vv14;
	//string   max;
	//decltype(v14.begin())  maxp;   //记录最大连续次数所在的指针
	//while (cin >> vv14)
	//{
	//	if (vv14 == "end")
	//		break;               //输入end结束当前循环
	//	v14.push_back(vv14);     //都写入vector中
	//}
	//for(auto vvv:v14)
	//cout << vvv<<"  ";
	//cout << endl;

	//auto beg = v14.begin();
	//auto end = v14.end();
	//for (;beg<end-1;beg++)     //从第一个遍历到倒数第二个
	//{
	//	
	//	if ((*(beg+1)) == *(beg))
	//	{
	//		cnt141++;
	//		cout << cnt141 <<" ";
	//		if ((cnt141 > cnt142)&&(beg==end-2))          //这里主要是处理最后的形式，因为最后可能没有和前面不同的元素，
	//									//这时指针和计数还是要更新的
	//		{
	//			cnt142 = cnt141;
	//			maxp = beg;
	//		}              
	//		
	//	}
	//	if (*(beg+1) != *(beg))       //如果这个和前面的不想等
	//	{
	//		if (cnt141 >= cnt142)
	//		{
	//			cnt142 = cnt141;
	//			maxp = beg;
	//			cnt141 = 1;   //置位cnt141
	//		}
	//		
	//	}
	//}

	//if (cnt142 == 1)
	//	cout << "没有连续单词！！" << endl;
	//else
	//	cout << "出现最多的单词为：" << *maxp << "  次数为：" << cnt142 << endl;
	////这样就可以了，后来有想到一种稍微简单的方法，就是可以把连续的序号和string分别存入容器，最后去在容器中找到频数
	////最多的，就可以了。
	//

	////5.17
	//vector<int> v171 = { 1,2,3,4,5,6,7,8,9 };
	//vector<int> v172 = { 1,2,3,4,5,6 };
	//int flag = 0;
	//auto size_v = (v171.size() < v172.size()) ? v171.size() : v172.size();
	//for (auto i = 0; i < size_v; i++)
	//{
	//	if (v171[i] == v172[i])
	//		flag++;
	//}
	//if (flag == size_v)
	//{
	//	cout <<"是一部分"<<"  有"<<flag<<"个相同元素"<<endl ;
	//}
	

	//5.19
//string v191, v192;
//do {
//	cout << "请输入两个字符串" << endl;
//	cin >> v191 >> v192;
//	if (v191.size() < v192.size())
//		cout << v191 << endl;
//	else
//		cout << v192 << endl;
//	
//} while (cin);

//5.20
//string v201, v202;      //每个字符串用回车间隔
//while(cin)
//{
//	cout << "请输入一个字符串：" << endl;
//	cin >> v201;
//	if (v201 == v202)
//	{
//		cout << "连续字符串：" << v201 << endl;
//		break;
//	}
//	else
//		cout << "无连续字符串" << endl;
//
//	v202 = v201;
//}

//5.21  在5.20的基础上简单修改
//string v201, v202;      //每个字符串用回车间隔
//while (cin)
//{
//	cout << "请输入一个字符串：" << endl;
//	cin >> v201;
//	if (v201[0] > 'Z' || v201[0] < 'A')
//		continue;
//	if (v201 == v202)
//	{
//		cout << "连续字符串：" << v201 << endl;
//		break;
//	}
//	else
//		cout << "无连续字符串" << endl;
//
//	v202 = v201;
//}

//5.25
int a, b;
cout << "请输入两个相除的整数：" << endl;
while (cin >> a >> b)
{
	try
	{
		if (b == 0) throw runtime_error("被除数不能是0");
		cout << static_cast<double>(a) / b << endl;      //不能整除的情况
	}
	catch (runtime_error err)
	{
		cout << err.what();
		cout << "是否需要重新输入？Enter y or n:" << endl;
		char c;
		cin >> c;
		if (!cin || c == 'n')    //这里如果输入的是yes的话就相当于进行下一次while循环了。但是一定要输入这个y，c等着呢
			break;
	}
}

	return 0;
}