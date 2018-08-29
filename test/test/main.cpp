// 本题为考试多行输入输出规范示例，无需提交，不计分。
#pragma warning (disable:4996);
// 本题为考试多行输入输出规范示例，无需提交，不计分。


#include <iostream>
#include <cstdio>
#include <vector>
using namespace std;

//int min(int x, int y)
//{
//	if (x < y)
//		return x;
//	else
//		return y;
//}
//int max(int x, int y)
//{
//	if (x < y)
//		return y;
//	else
//		return x;
//}
//
////复数类，只定义了构造函数，为了简单数据也公有了
//class FuShu {
//public:
//	FuShu(int x, int y) :a(x), b(y) {}
//	int a;
//	int b;
//};
//
////复数乘法
//FuShu  multiply(FuShu x, FuShu y)
//{
//	FuShu res(0, 0);
//	res.a = x.a*y.a - x.b*y.b;
//	res.b = x.a*y.b + y.a*x.b;
//	return res;
//}
////复数加法
//FuShu add(FuShu x, FuShu y)
//{
//	FuShu res(0, 0);
//	res.a = x.a + y.a;
//	res.b = x.b + y.b;
//	return res;
//}
//
//int main() {
//	//freopen("1.in","r",stdin);
//	vector<FuShu> data;
//	FuShu tmp(0, 0);
//	int x;
//	for (int i = 0; i < 20; i++) {
//		scanf("%d", &x);
//		if (i % 2 == 0)   //实部
//			tmp.a = x;
//		else 
//			tmp.b = x;    
//		if (i>=1 && i % 2 == 1)
//			data.push_back(tmp);
//	}
//	vector<FuShu> a = vector<FuShu>(data.begin(), data.begin() + 5);
//	vector<FuShu> b = vector<FuShu>(data.begin() + 5, data.end());
//	int m = a.size();
//	int n = b.size();
//	cout << m <<" -- " <<n << endl;
//	FuShu cnt(0, 0);
//	vector<FuShu> res;
//	for (int i = 0; i<m+n-1; i++)
//	{
//		for (int k =max(0,i+1-5); k <= min(i,4); k++)
//		{
//			cnt = add(cnt, multiply(a[k], b[i - k]));
//		}
//		res.push_back(cnt);
//		cout << i << ": " << cnt.a << " " << cnt.b << endl;
//		cnt = FuShu(0, 0);
//	}
//	
//}

int feibo(int n)
{
	if (n == 0)  return 0;
	else if (n == 1) return 1;
	else
		return feibo(n - 1)+feibo(n-2);
}
int feibo1(int n)
{
	if (n == 0)  return 0;
	if (n == 1)  return 1;
	int first = 0;
	int second = 1;
	int tmp;
	for (int i = 1; i < n; i++)
	{
		tmp = second;
		second = first + second;
		first = tmp;
	}

	return second;
}


int numOfTriangle(vector<int> &numbers)
{
	int cnt = 0;
	int sz = numbers.size();
	for (int i = sz; i > 1; i--)
	{
		int left = 0;
		int right = i-1;
		while (left <= right)
		{
			if (numbers[left] + numbers[right] > numbers[i])
			{
				cnt += (right - left);
				right--;
			}
			else
				left++;
		}
	}
	return cnt;

}

int main()
{
	//string str = "AB1d--2Bd12";
	//int sz = str.size();
	//int i = 0;
	//bool isPositive;
	//int cnt = 0;
	//int res = 0;
	//while(i<sz)
	//{
	//	isPositive = true;
	//	while (i < sz&&str[i] == '-')
	//	{
	//		isPositive = !isPositive;
	//		i++;
	//	}
	//	while (i < sz&&str[i] >= '0'&&str[i] <= '9')
	//	{
	//		cnt = cnt * 10 + (str[i] - '0');
	//		i++;
	//	}
	//	if (!isPositive) cnt = -cnt;   //查看累计，如果是正的，就是正的，如果是负的，那么要变号
	//	
	//	res += cnt;
	//	cnt = 0;   //清零
	//	i++;
	//}
	//cout << res << endl;
	//for (int i = 0; i < 50; i++)
	//	cout << feibo1(i) << " ";

	vector<int>  sum = { 2, 2, 3, 4, 5 };
	cout << numOfTriangle(sum) << endl;

	return 0;

}



