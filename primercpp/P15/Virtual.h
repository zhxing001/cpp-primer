#pragma once
#include<iostream>
using std::cout;
using std::endl;


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

};

class Circle :public shape
{

	
};

class Rectangle :public shape {

};



