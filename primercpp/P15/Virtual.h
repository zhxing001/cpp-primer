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
	virtual void Speak() const { cout << "lalala����" << endl; }
	virtual Mammal* clone() {
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




//��̳У������ʾ����


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
	virtual ~Animal() { cout << "Animal����������������---\n"; }
	virtual int getAge() { return itsAge; }
	virtual void setAge(int age) { itsAge = age; }

private:
	int itsAge;
};
Animal::Animal(int age) :itsAge(age)
{
	cout << "Animal�Ĺ��캯��������------"<<endl;
}

class horse:virtual public Animal      //��
{
public:
	horse(int height,color col,int age);
	virtual ~horse() { cout << "�����������������" << endl; };    //�������������
	virtual void Whinny() const { cout << "Whinny!!" << endl; }
	virtual int getHeight() const { return this->height; }
	virtual color getcolor() const { return itsColor; }
private:
	int height;
	color itsColor;
};

horse::horse(int height,color col,int age) :height(height),itsColor(col),Animal(age)
{
	cout << "��Ĺ��캯��������" << endl;
}

class bird:virtual public Animal       //��
{
public:
	bird(bool migrat,color col,int age);
	virtual ~bird() { cout << "����������������ã�" << endl;}
	virtual void chirp() const { cout << "chirp!" << endl; }
	virtual void Fly() const { cout << "i believe i can fly" << endl; }
	virtual bool gerMigration() const { return itsMigration; }
	virtual color getcolor() const { return itsColor; }
private:
	bool itsMigration;   //�Ƿ��Ǻ���
	color itsColor;

};

bird::bird(bool migrat,color col,int age):itsMigration(migrat),itsColor(col),Animal(age)
{
	cout << "��Ĺ��캯�������ã�" << endl;
}

class flyHorse:public horse,public bird    //�̳��������
{
public:
	void chirp() const { Whinny();}
	flyHorse(color,int, bool, long,int age);
	~flyHorse() { cout << "flyhorse���������������ã�" << endl; }
	virtual long gerNumberBelievers() const
	{
		return itsNumberBelieves;
	}
private:
	long itsNumberBelieves;
};

flyHorse::flyHorse(color Col, int height, bool migra,long numberBelieve,int age)
	:horse(height, Col,age), bird(migra, Col,age), itsNumberBelieves(numberBelieve),Animal(age)  //�����ʱ�����ѻ�����ȹ������
{
	cout << "����Ĺ��캯��������" << endl;
}


//���麯�������������

class shape {

};

class Circle :public shape
{

	
};

class Rectangle :public shape {

};



