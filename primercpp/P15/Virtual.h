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
	virtual Mammal* Clone() {
		return new Dog(*this);
	}
private:
	BREED itsBreed;
};

class Cat :public Mammal {
public:
	virtual void Speak() const { cout << "miao-miao!!!" << endl; }
	virtual Mammal* Clone() {
		return new Cat(*this);
	}
};

class Horse :public Mammal {
public:
	virtual void Speak() const { cout << "Winnie!!!" << endl; }
	virtual Mammal* Clone() {
		return new Horse(*this);
	}
};

class Pig :public Mammal {
public:
	virtual void Speak() const { cout << "lalala！！" << endl; }
	virtual Mammal* Clone() {
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