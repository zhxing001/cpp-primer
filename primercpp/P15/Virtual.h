#pragma once
#include<iostream>
using std::cout;
using std::endl;
using std::cin;

enum BREED
{
	GOLDEN,
	CAIRN,
	LAB,
	TADI
};

class Mammal {
public:
	Mammal() {
		cout << "inline 构造函数被调用！" << endl;
	}
	~Mammal() { cout << "inline的析构 函数被调用" << endl; }

	virtual void Speak() const { cout << "mammal的叫声！" << endl; }
	void Sleep() const { cout << "shh,i am sleeping!" << endl; }
	void Move() const { cout << "Mammal move one step!" << endl; }
	void Move(int distance) const
	{
		cout << "Mammal move " << distance << " steps" << endl;
	}

	virtual Mammal* clone() { return new Mammal(*this); }   //把自身克隆一份，我们把其定义成虚的
protected:
	int itsAge;
	int itsWeight;
};


class Dog :public Mammal {
public:
	Dog() { cout << "dOG的构造函数被调用！！" << endl; }
	~Dog() { cout << "Dog的析构函数被调用" << endl; }
	void WagTail() const { cout << "Tail wagging!" << endl; }
	void begFood() const { cout << "i am begging for food!" << endl; }
	virtual void Speak() const { cout << "woof!!!woof!!" << endl; }        //基类中就是虚的，所以这里是继承了
	void Move() const { cout << "DOG Move 5 steps!" << endl; }       //把mammal里的move给覆盖掉了
	virtual Mammal* clone() {
		return new Dog(*this);
	}
private:
	BREED itsBreed;
};

class Cat :public Mammal {
public:
	virtual void Speak() const { cout << "miao-miao!!!" << endl; }
	virtual Mammal* clone() {
		return new Cat(*this);
	}
};

class Horse :public Mammal {
public:
	virtual void Speak() const { cout << "Winnie!!!" << endl; }
	virtual Mammal* clone() {
		return new Horse(*this);
	}
};

class Pig :public Mammal {
public:
	virtual void Speak() const { cout << "lalala！！" << endl; }
	virtual Mammal* clone() {
		return new Pig(*this);
	}
};

class base {

public:
	virtual void print() const { cout << "Base PRINT 被调用！" << endl; }
};
class Derivedl :public base
{
	virtual void print() const { cout << "派生类的print被调用" << endl; }
};

void fun(const base &ba)   //函数接受基类的引用
{
	ba.print();
}

void ValueFunc(Mammal Ma)
{
	Ma.Speak();
}




//多继承，虚基类示例。


enum color {
	red,
	blue,
	black,
	yellow
};

class Animal
{
public:
	Animal(int);
	virtual ~Animal() { cout << "Animal的析构函数被调用---\n"; }
	virtual int getAge() { return itsAge; }
	virtual void setAge(int age) { itsAge = age; }

private:
	int itsAge;
};
Animal::Animal(int age) :itsAge(age)
{
	cout << "Animal的构造函数被调用------"<<endl;
}

class horse:virtual public Animal      //马
{
public:
	horse(int height,color col,int age);
	virtual ~horse() { cout << "马的析构函数被调用" << endl; };    //析构函数是虚的
	virtual void Whinny() const { cout << "Whinny!!" << endl; }
	virtual int getHeight() const { return this->height; }
	virtual color getcolor() const { return itsColor; }
private:
	int height;
	color itsColor;
};

horse::horse(int height,color col,int age) :height(height),itsColor(col),Animal(age)
{
	cout << "马的构造函数被调用" << endl;
}

class bird:virtual public Animal       //鸟
{
public:
	bird(bool migrat,color col,int age);
	virtual ~bird() { cout << "鸟的析构函数被调用！" << endl;}
	virtual void chirp() const { cout << "chirp!" << endl; }
	virtual void Fly() const { cout << "i believe i can fly" << endl; }
	virtual bool gerMigration() const { return itsMigration; }
	virtual color getcolor() const { return itsColor; }
private:
	bool itsMigration;   //是否是候鸟
	color itsColor;

};

bird::bird(bool migrat,color col,int age):itsMigration(migrat),itsColor(col),Animal(age)
{
	cout << "鸟的构造函数被调用！" << endl;
}

class flyHorse:public horse,public bird    //继承了马和鸟
{
public:
	void chirp() const { Whinny();}
	flyHorse(color,int, bool, long,int age);
	~flyHorse() { cout << "flyhorse的析构函数被调用！" << endl; }
	virtual long gerNumberBelievers() const
	{
		return itsNumberBelieves;
	}
private:
	long itsNumberBelieves;
};

flyHorse::flyHorse(color Col, int height, bool migra,long numberBelieve,int age)
	:horse(height, Col,age), bird(migra, Col,age), itsNumberBelieves(numberBelieve),Animal(age)  //构造的时候必须把基类的先构造出来
{
	cout << "飞马的构造函数被调用" << endl;
}


//纯虚函数，抽象类测试
class shape {
public:
	shape(){}
	virtual ~shape() {}
	virtual double getArea() = 0;
	virtual double getPerim() = 0;     
	virtual void draw() = 0;     //写上等于0就是纯虚函数,这些函数的实现

};
//一般而言，纯虚函数的定义，可以不写，一般情况下也不写

//void shape::draw()
//{
//	cout << "-----" << endl;
//}

class Circle :public shape
{
public:
	Circle(double radius):itsRadius(radius) { cout << "circle的构造函数被调用" << endl; }
	virtual ~Circle() {}
	virtual double getArea() { return 3.14*itsRadius*itsRadius; }
	virtual double getPerim() { return 2 * 3.14*itsRadius; }
	virtual void draw() { cout << "it is a circle!" << endl; }
private:
	double itsRadius; 
};

class Rectangle :public shape 
{
public:
	Rectangle(double h, double w) :height(h), width(w) { cout << "Rectangle的构造函数被调用！" << endl; }
	virtual ~Rectangle() {};
	virtual double getArea() { return height*width; }
	virtual double getPerim() { return 2 * (height + width); }
	virtual void draw()
	{ 
		cout << "it is a rectangle!" << endl; 
	}
	virtual double getWidht() { return width; }
	virtual double gerHeight() { return height; }

private:
	double height;
	double width;
};

class Square :public Rectangle
{
public:
	Square(double x) :Rectangle(x, x) { cout << "Square 的构造函数被调用" << endl; }   //调用其基类的构造函数
	virtual ~Square() {};
	
	virtual void draw() { cout << "its a square!" << endl; }
	void test() { cout << "基类的指针可以访问派生类的非继承成员么？" << endl; }
};




class Animal1
{
public:
	Animal1(int age);
	virtual ~Animal1() {}
	virtual int getAge() const { return itsage; }
	virtual void setAge(int age) { this->itsage = age; }
	virtual void sleep() const = 0;
	virtual void eat() const = 0;
	virtual void Rproduce() const = 0;
	virtual void Move() const = 0;
	virtual void Speak() const = 0;           //五个纯虚函数

private:
	int itsage;
};

Animal1::Animal1(int age) :itsage(age) { cout << "animal的构造函数被调用！" << endl; }


class mammal1 :public Animal1
{
public:
	mammal1(int age) :Animal1(age)
	{
		cout << "MAMMAL的构造函数被调用！" << endl;
	}
	virtual ~mammal1() { cout << "mammal的析构函数被调用！" << endl; }
	virtual void Rproduce() const {
		cout << "mammal reproduction depicted...\n";     //只重写了一个纯虚函数，其他的纯虚函数被继承了，所以也是抽象类
	}
};


class fish:public Animal1
{
public:
	fish(int age) :Animal1(age)
	{
		cout << "fish的构造函数被调用" << endl;
	}
	virtual ~fish()
	{
		cout << "fish的析构函数被调用" << endl;
	}



	virtual void sleep() const { cout << "fish is sleeping" << endl; }
	virtual void eat() const { cout << "fish is eating" << endl; }
	virtual void Rproduce() const { cout << "fish is rproducing!!" << endl; }
	virtual void Move() const { cout << "fish is moving" << endl; }
	virtual void Speak() const { cout << "fish cant speak!!" << endl; }       //五个纯虚函数都做了重写覆盖

};



class Horse1 :public mammal1
{
public:
	Horse1(int age, color col) :mammal1(age), itsColor(col) {
		cout << "Horse的构造函数被调用" << endl;
	}
	virtual ~Horse1()
	{
		cout << "Horse的析构函数被调用" << endl;
	}


	virtual void sleep() const { cout << "Horse is sleeping" << endl; }
	virtual void eat() const { cout << "Horse is eating" << endl; }
	//virtual void Rproduce() const { cout << "fish is rproducing!!" << endl; }   //这个在mammal里已经做了覆盖不是纯虚了
	virtual void Move() const { cout << "Horse is moving" << endl; }
	virtual void Speak() const { cout << "Horse is speaking!!" << endl; }       //五个纯虚函数都做了重写覆盖
	virtual color GetItsColor() const { return itsColor; }
protected:
	color itsColor;

};


class dog :public mammal1
{
public:
	dog(int age, color col) :mammal1(age), itsColor(col) {
		cout << "dog的构造函数被调用" << endl;
	}
	virtual ~dog()
	{
		cout << "dog的析构函数被调用" << endl;
	}


	virtual void sleep() const { cout << "dog is sleeping" << endl; }
	virtual void eat() const { cout << "dog is eating" << endl; }
	virtual void Rproduce() const { cout << "dog is rproducing!!" << endl; }    
	virtual void Move() const { cout << "dog is runing fastly!!" << endl; }
	virtual void Speak() const { cout << "dog is speaking!!" << endl; }       //五个纯虚函数都做了重写覆盖
	virtual color GetItsColor() const { return itsColor; }
protected:
	color itsColor;
};





