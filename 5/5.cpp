#include<iostream>
#include<string>
#include<vector>

using namespace std;

int main()
{

	//5.9,10,11
	//char c5;
	//int aCnt = 0, eCnt = 0, iCnt = 0, oCnt = 0, uCnt = 0, nCnt = 0, spaceCnt = 0, TabCnt = 0, cnt = 0; //��¼������Ŀ
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
	//cout << "a������ " << aCnt << endl;
	//cout << "e������ " << eCnt << endl;
	//cout << "i������ " << iCnt << endl;
	//cout << "o������ " << oCnt << endl;
	//cout << "u������ " << uCnt << endl;
	//cout << "��Ԫ��������" << cnt << endl;
	//cout << "�ո������ " << spaceCnt << endl;
	//cout << "tab������ " << TabCnt << endl;

	//5.14
	
	//int cnt141 = 1;         //��¼��ǰ����������ֵĴ�����
	//int cnt142 = 1;         //��¼�ܵ���������Ĵ���
	//vector<string>  v14;      //������ĵ��ʴ�������
	//string vv14;
	//string   max;
	//decltype(v14.begin())  maxp;   //��¼��������������ڵ�ָ��
	//while (cin >> vv14)
	//{
	//	if (vv14 == "end")
	//		break;               //����end������ǰѭ��
	//	v14.push_back(vv14);     //��д��vector��
	//}
	//for(auto vvv:v14)
	//cout << vvv<<"  ";
	//cout << endl;

	//auto beg = v14.begin();
	//auto end = v14.end();
	//for (;beg<end-1;beg++)     //�ӵ�һ�������������ڶ���
	//{
	//	
	//	if ((*(beg+1)) == *(beg))
	//	{
	//		cnt141++;
	//		cout << cnt141 <<" ";
	//		if ((cnt141 > cnt142)&&(beg==end-2))          //������Ҫ�Ǵ���������ʽ����Ϊ������û�к�ǰ�治ͬ��Ԫ�أ�
	//									//��ʱָ��ͼ�������Ҫ���µ�
	//		{
	//			cnt142 = cnt141;
	//			maxp = beg;
	//		}              
	//		
	//	}
	//	if (*(beg+1) != *(beg))       //��������ǰ��Ĳ����
	//	{
	//		if (cnt141 >= cnt142)
	//		{
	//			cnt142 = cnt141;
	//			maxp = beg;
	//			cnt141 = 1;   //��λcnt141
	//		}
	//		
	//	}
	//}

	//if (cnt142 == 1)
	//	cout << "û���������ʣ���" << endl;
	//else
	//	cout << "�������ĵ���Ϊ��" << *maxp << "  ����Ϊ��" << cnt142 << endl;
	////�����Ϳ����ˣ��������뵽һ����΢�򵥵ķ��������ǿ��԰���������ź�string�ֱ�������������ȥ���������ҵ�Ƶ��
	////���ģ��Ϳ����ˡ�
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
	//	cout <<"��һ����"<<"  ��"<<flag<<"����ͬԪ��"<<endl ;
	//}
	

	//5.19
//string v191, v192;
//do {
//	cout << "�����������ַ���" << endl;
//	cin >> v191 >> v192;
//	if (v191.size() < v192.size())
//		cout << v191 << endl;
//	else
//		cout << v192 << endl;
//	
//} while (cin);

//5.20
//string v201, v202;      //ÿ���ַ����ûس����
//while(cin)
//{
//	cout << "������һ���ַ�����" << endl;
//	cin >> v201;
//	if (v201 == v202)
//	{
//		cout << "�����ַ�����" << v201 << endl;
//		break;
//	}
//	else
//		cout << "�������ַ���" << endl;
//
//	v202 = v201;
//}

//5.21  ��5.20�Ļ����ϼ��޸�
//string v201, v202;      //ÿ���ַ����ûس����
//while (cin)
//{
//	cout << "������һ���ַ�����" << endl;
//	cin >> v201;
//	if (v201[0] > 'Z' || v201[0] < 'A')
//		continue;
//	if (v201 == v202)
//	{
//		cout << "�����ַ�����" << v201 << endl;
//		break;
//	}
//	else
//		cout << "�������ַ���" << endl;
//
//	v202 = v201;
//}

//5.25
int a, b;
cout << "���������������������" << endl;
while (cin >> a >> b)
{
	try
	{
		if (b == 0) throw runtime_error("������������0");
		cout << static_cast<double>(a) / b << endl;      //�������������
	}
	catch (runtime_error err)
	{
		cout << err.what();
		cout << "�Ƿ���Ҫ�������룿Enter y or n:" << endl;
		char c;
		cin >> c;
		if (!cin || c == 'n')    //��������������yes�Ļ����൱�ڽ�����һ��whileѭ���ˡ�����һ��Ҫ�������y��c������
			break;
	}
}

	return 0;
}