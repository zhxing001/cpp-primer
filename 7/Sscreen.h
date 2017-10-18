#ifndef Screen_h
#define Screen_h

#include<string>
#include<iostream>
#include<vector>

class Screen;

class window_mgr
{
public:
	using ScreenIndex = std::vector<Screen>::size_type;
	void clear(ScreenIndex &i);  //只能声名不能定义，定义应该都
	window_mgr() = default;
private:
	//std::vector<Screen>  screens{ Screen(24,80,' ') };   //这里也不能这样初始化
	std::vector<Screen>  screens;
};

class Screen
{
public:
	friend class window_mgr;
	friend void window_mgr::clear(ScreenIndex &i); 
	//这个clear要用到Screen这个类，所以要提前声名（在定义的window_mgr中），定义必须放在Screen的定义后面才可。
	//zai声名某个函数作为友元时，一定要仔细组织程序的结构以便满足声名和定义的彼此依赖关系。
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



void window_mgr::clear(ScreenIndex&i)
{
	Screen &s=screens[i];
	s.contents = string(s.width*s.height, ' ');
}

//本程序中把window_mgr声名成为screen的友元类，这样的结果就是window_mgr可以访问screen类的成员及成员函数。





#endif
