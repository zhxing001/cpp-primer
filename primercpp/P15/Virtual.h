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
		cout << "inline ���캯�������ã�" << endl;
	}
	~Mammal() { cout << "inline������ ����������" << endl; }

	virtual void Speak() const { cout << "mammal�Ľ�����" << endl; }
	void Sleep() const { cout << "shh,i am sleeping!" << endl; }
	void Move() const { cout << "Mammal move one step!" << endl; }
	void Move(int distance) const
	{
		cout << "Mammal move " << distance << " steps" << endl;
	}

	virtual Mammal* clone() { return new Mammal(*this); }   //�������¡һ�ݣ����ǰ��䶨������
protected:
	int itsAge;
	int itsWeight;
};


class Dog :public Mammal {
public:
	Dog() { cout << "dOG�Ĺ��캯�������ã���" << endl; }
	~Dog() { cout << "Dog����������������" << endl; }
	void WagTail() const { cout << "Tail wagging!" << endl; }
	void begFood() const { cout << "i am begging for food!" << endl; }
	virtual void Speak() const { cout << "woof!!!woof!!" << endl; }        //�����о�����ģ����������Ǽ̳���
	void Move() const { cout << "DOG Move 5 steps!" << endl; }       //��mammal���move�����ǵ���
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
	virtual void Speak() const { cout << "lalala����" << endl; }
	virtual Mammal* Clone() {
		return new Pig(*this);
	}
};

class base {

public:
	virtual void print() const { cout << "Base PRINT �����ã�" << endl; }
};
class Derivedl :public base
{
	virtual void print() const { cout << "�������print������" << endl; }
};

void fun(const base &ba)   //�������ܻ��������
{
	ba.print();
}

void ValueFunc(Mammal Ma)
{
	Ma.Speak();
}