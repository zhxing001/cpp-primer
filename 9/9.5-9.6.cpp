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
		if (string(cur, cur + olds.size()) == olds)   //������
		{ 
			s1.erase(cur, cur + olds.size());        //ɾ��ԭ���ĵ���
			s1.insert(cur, news.begin(), news.end());  //�����µ�
			cur+= news.size();     //�����µ��ʱ���
		}
		else
		cur++;        //����
 	}
}
//9.44
void replace_OldVal1(string &s1, const string &olds, const string &news)
{
	for (auto cur = s1.begin(); cur <= s1.end() - olds.size();)
	{
		if (string(cur, cur + olds.size()) == olds)   //������
		{
			s1.replace(cur, cur + olds.size(), news);
			cur += news.size();     //�����µ��ʱ���
		}
		else
			cur++;        //����
	}
}

void addMr_Ms(string &s,  const string &mr="Mr.", const string &jr=" JR")
{
	s.append(jr);  
	s.insert(s.begin(),mr.begin(),mr.end());
	//insert�����ܵ�����string������Ϊ����������Ҫ���亯��������ɶ��ȥд
}

void addMr_Ms1(string &s, const string &mr = "Mr.", const string &jr = " JR")
{
	s.reserve(s.size() + 5);
	s.insert(s.end(),jr.begin(),jr.end());      //�������֮�����
	s.insert(s.begin(), mr.begin(), mr.end());  //�������֮ǰ���룬����Ĳ���
	//insert�����ܵ�����string������Ϊ����������Ҫ���亯��������ɶ��ȥд
}

void Find_Num(const string &s)
{
	string nums = "0123456789";
	string::size_type pos = 0;
	while ((pos = s.find_first_of(nums, pos)) != s.npos)   
		//npos��size+1ô�������ǣ�npos��һ���ܴ������int�����ֵ����������������Χ�󣬷��ص�pos�������ֵ�����������ֵ��������϶��ᳬ��Χ��
	{
		cout << "λ���ǣ�" << pos
			<< " �����ǣ�" << s[pos] << endl;
		pos++;
	}
}

void Find_Letter(const string &s)
{
	string nums = "0123456789";
	string::size_type pos = 0;
	while ((pos = s.find_first_not_of(nums, pos)) != s.npos)
		//npos��size+1ô�������ǣ�npos��һ���ܴ������int�����ֵ����������������Χ�󣬷��ص�pos�������ֵ�����������ֵ��������϶��ᳬ��Χ��
	{
		cout << "λ���ǣ�" << pos
			<< " ��ĸ�ǣ�" << s[pos] << endl;
		pos++;
	}
}

auto find_noUpDown(const string &s)
{
	string up_dowm = "acenmorsuvwxz";
	unsigned pos1=0;   //��ǰλ�ò���
	unsigned pos2=0;
	unsigned length = 0;
	unsigned pos3 = 0;

	while((pos1 = s.find_first_of(up_dowm, pos1))!= string::npos)   //��pos1��ʼ�ҵ�һ������ͷ�ַ�
	{
		
		pos2 = pos1;   //�Ȱ����������������Ҫ�ã���Ҫ�ı���
		if ((pos2 = s.find_first_not_of(up_dowm, pos2)))      //�Ӳ���ͷ�ģ��ҵ���һ����ͷ�ַ�
		{
			if (pos2 == string::npos)  
			{
				if (s.size() - 1 - pos1 > length)
				{
					pos3 = pos1;
					length = pos2 - pos1;

				}
				break;   
				//Ҫ�����������һ����ԭ����û�д������ȫ�ǲ���ͷ��ĸ��ͳ�ƣ������һ��ѭ��������Ϊԭ���ĳ���ֻҪ�жϵ��Ҳ�����ͷ
				//��ĸ���ͻ�����ѭ���ˣ���û���ټ��������һ���ǲ������ģ�
				//�����Ҫ����ע�⣬�ڲ��ҵ�ʱ��ܶ�ʱ����ж����������Թ�����һ���֣��ر��������ж��������̵������
			}
			if (pos2 - pos1 >= length)
			{
				length = pos2 - pos1;   //�������ǰ��ͳ�Ƶĳ��ȣ������������ȡ�
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
	auto curr=s.begin();   //��λ������
	for (auto it = s.begin(); it != s.end();it++)       //�Ȱ�����ַ����ָ�� 
	{
		if (!isalnum(*it))     //������ĸ������,
		{
			
			v[i] = string(curr, it);      //��������,������ʱ����ǰ�պ����䣬ǧ��ע��
			curr = it+1; 
			i++;
		}
	}
	
	v[i] = string(curr, s.end());
	cout << v[0] << " " << v[1] << " " << v[2] << endl;       //����ǲ���
	
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
	cout << "���캯��������,����Ϊ" << endl;
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
	cout << "�滻ǰ�� " << s << endl;
	replace_OldVal(s, "love", "LOVE");
	cout << "�滻�� " << s << endl;
	replace_OldVal(s, "me", "ME");
	cout << "�滻�� " << s << endl;
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
			stk.push(s);   //�����������Ȼ��ѹ��ջ��
	}
	string restring;   //������ַ���
	while (!stk.empty())
	{
		restring += stk.top();
		stk.pop();  
		//���ϣ���ɾ��
	}

	express.replace(express.find('(') + 1, restring.size(),restring);
	cout << express << endl;

	return 0;
}