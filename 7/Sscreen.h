#ifndef Screen_h
#define Screen_h

#include<string>
#include<iostream>
#include<vector>
class Screen
{
public:
	using pos = std::string::size_type;         //string::Size_type����
	
	inline Screen &Screen::set(char c);
	inline Screen &Screen::set(pos r, pos col, char ch);
	
	Screen() = default;
	Screen(pos ht, pos wd, char c):height(ht),width(wd),contents(ht*wd,c){}  //contents()�õ���string�Ĺ��캯��
	Screen(pos ht,pos wd):height(ht),width(wd),contents(ht*wd,' '){}  //�հ�
	char get() const
	{
		return contents[cursor];    //��������ַ�
	}
	char get(pos r, pos c)
	{
		return contents[r*width + c];
	}
	inline Screen &move(pos r, pos c);
	Screen &display(std::ostream &os)
	{
		do_display(os);
		return *this; //���ص�������
	}
	const Screen &display(std::ostream &os) const  //�����ڲ����б���const��ʾ����һ��������Ա������
		//��������ͳ��������ָ��������ö�ֻ�ܵ��ó�����Ա���������ﶨ��������const����
	{
		do_display(os);
		return *this;
	}
private:
	pos cursor = 0;
	pos height = 0, width = 0;
	std::string contents;
	void do_display(std::ostream &os) const
	{
		os << contents;
	}
};

inline Screen& Screen::move(pos r, pos c) 
{
	cursor = r*width + c;
	return *this;
}


inline Screen &Screen::set(char c)
{
	contents[cursor] = c;
	return *this;
}

inline Screen &Screen::set(pos r, pos col, char ch)
{
	contents[r*width+col] = ch;
	return *this;
}

class window_mgr {
private:
	std::vector<Screen> screens{Screen(24, 80, ' ')};
};

#endif
