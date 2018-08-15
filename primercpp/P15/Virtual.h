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
public:
	shape(){}
	virtual ~shape() {}
	virtual double getArea() = 0;
	virtual double getPerim() = 0;     
	virtual void draw() = 0;     //д�ϵ���0���Ǵ��麯��,��Щ������ʵ��

};
//һ����ԣ����麯���Ķ��壬���Բ�д��һ�������Ҳ��д

//void shape::draw()
//{
//	cout << "-----" << endl;
//}

class Circle :public shape
{
public:
	Circle(double radius):itsRadius(radius) { cout << "circle�Ĺ��캯��������" << endl; }
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
	Rectangle(double h, double w) :height(h), width(w) { cout << "Rectangle�Ĺ��캯�������ã�" << endl; }
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
	Square(double x) :Rectangle(x, x) { cout << "Square �Ĺ��캯��������" << endl; }   //���������Ĺ��캯��
	virtual ~Square() {};
	
	virtual void draw() { cout << "its a square!" << endl; }
	void test() { cout << "�����ָ����Է���������ķǼ̳г�Աô��" << endl; }
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
	virtual void Speak() const = 0;           //������麯��

private:
	int itsage;
};

Animal1::Animal1(int age) :itsage(age) { cout << "animal�Ĺ��캯�������ã�" << endl; }


class mammal1 :public Animal1
{
public:
	mammal1(int age) :Animal1(age)
	{
		cout << "MAMMAL�Ĺ��캯�������ã�" << endl;
	}
	virtual ~mammal1() { cout << "mammal���������������ã�" << endl; }
	virtual void Rproduce() const {
		cout << "mammal reproduction depicted...\n";     //ֻ��д��һ�����麯���������Ĵ��麯�����̳��ˣ�����Ҳ�ǳ�����
	}
};


class fish:public Animal1
{
public:
	fish(int age) :Animal1(age)
	{
		cout << "fish�Ĺ��캯��������" << endl;
	}
	virtual ~fish()
	{
		cout << "fish����������������" << endl;
	}



	virtual void sleep() const { cout << "fish is sleeping" << endl; }
	virtual void eat() const { cout << "fish is eating" << endl; }
	virtual void Rproduce() const { cout << "fish is rproducing!!" << endl; }
	virtual void Move() const { cout << "fish is moving" << endl; }
	virtual void Speak() const { cout << "fish cant speak!!" << endl; }       //������麯����������д����

};



class Horse1 :public mammal1
{
public:
	Horse1(int age, color col) :mammal1(age), itsColor(col) {
		cout << "Horse�Ĺ��캯��������" << endl;
	}
	virtual ~Horse1()
	{
		cout << "Horse����������������" << endl;
	}


	virtual void sleep() const { cout << "Horse is sleeping" << endl; }
	virtual void eat() const { cout << "Horse is eating" << endl; }
	//virtual void Rproduce() const { cout << "fish is rproducing!!" << endl; }   //�����mammal���Ѿ����˸��ǲ��Ǵ�����
	virtual void Move() const { cout << "Horse is moving" << endl; }
	virtual void Speak() const { cout << "Horse is speaking!!" << endl; }       //������麯����������д����
	virtual color GetItsColor() const { return itsColor; }
protected:
	color itsColor;

};


class dog :public mammal1
{
public:
	dog(int age, color col) :mammal1(age), itsColor(col) {
		cout << "dog�Ĺ��캯��������" << endl;
	}
	virtual ~dog()
	{
		cout << "dog����������������" << endl;
	}


	virtual void sleep() const { cout << "dog is sleeping" << endl; }
	virtual void eat() const { cout << "dog is eating" << endl; }
	virtual void Rproduce() const { cout << "dog is rproducing!!" << endl; }    
	virtual void Move() const { cout << "dog is runing fastly!!" << endl; }
	virtual void Speak() const { cout << "dog is speaking!!" << endl; }       //������麯����������д����
	virtual color GetItsColor() const { return itsColor; }
protected:
	color itsColor;
};





