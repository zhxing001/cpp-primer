#ifndef Screen_h
#define Screen_h

#include<string>
#include<iostream>
#include<vector>
class Screen
{
public:
	using pos = std::string::size_type;         //string::Size_type类型
	
	inline Screen &Screen::set(char c);
	inline Screen &Screen::set(pos r, pos col, char ch);
	
	Screen() = default;
	Screen(pos ht, pos wd, char c):height(ht),width(wd),contents(ht*wd,c){}  //contents()用的是string的构造函数
	Screen(pos ht,pos wd):height(ht),width(wd),contents(ht*wd,' '){}  //空白
	char get() const
	{
		return contents[cursor];    //返回这个字符
	}
	char get(pos r, pos c)
	{
		return contents[r*width + c];
	}
	inline Screen &move(pos r, pos c);
	Screen &display(std::ostream &os)
	{
		do_display(os);
		return *this; //返回的是引用
	}
	const Screen &display(std::ostream &os) const  //紧跟在参数列表后的const表示这是一个常量成员函数，
		//常量对象和常量对象的指针或者引用都只能调用常量成员函数。这里定义了两个const函数
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
