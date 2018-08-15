#include<iostream>
#include<string>
#include"Virtual.h"


//狗的品种
//enum BREED
//{
//	GOLDEN,
//	CAIRN,
//	DANDIE,
//	SHETLAND,
//	LAB
//};
//
////雇员类
//class employee {
//
//
//};
//
////经理类，继承雇员类，继承可以继承多个类
//class Manage :public employee {
//
//};
//
//class Animal {
//public:
//	Animal() :itsAge(2), itsWeight(5) {};
//	~Animal() {};
//	int getAge() const { return itsAge; }
//	void setAge(int age) { this->itsAge = age; }
//	int getWeight() const { return itsWeight; }
//	void setWeight(int Wei) { this->itsWeight = Wei; }
//
//	void Speak() const {
//		std::cout << "Animal sound!\n";
//	}
//	void Sleep() const
//	{
//		std::cout << "sleeping!!\n";
//	}
//
//protected:
//	int itsAge;
//	int itsWeight;
//};
//
//
////从Animal继承过来
//class Dog :public Animal {
//public:
//	Dog() :itsBreed(GOLDEN) {};
//	~Dog() {};
//
//	BREED getBreed() const { return itsBreed; }
//	void setBreed(BREED breed) {
//		this->itsBreed = breed;
//	}
//
//	void WagTail() const {
//		std::cout << "Tail Wagging\n";
//	}
//	void BegFood() const {
//		std::cout << "begging for food!\n";
//	}
//protected:
//	BREED itsBreed;
//};
//
//
//class Point {
//public:
//	void InitPoint(int x, int y);
//	void Move(int xOFF, int yOFF);
//protected:
//	int GetX()
//	{
//		return X;
//	}
//	int GetY()
//	{
//		return Y;
//	}
//private:
//	int X, Y;
//};
//
//class Rectange :public Point
//{
//	//公有继承：所有的成员都被继承，都被copy下来
//	//私有继承：基类的公有成员和保护成员都变成私有的了。
//	//保护继承：公有的和protected的变成protected的，私有的还是私有的
//	//最常用的是公有继承。
//};
//
//
//class 老子 {
//
//public:
//	int X;
//};
//
//class 小子:public 老子 {
//public: 
//	int Y;
//
//};

int main()
{

	shape *s;
	s = new Square(5);
	Square ss(5);
	ss.test();

	dog dd(4, red);


	//int choice;
	//bool fQuit = false;
	//shape *sp=nullptr;     //新标准不允许这里不做初始化直接用！
	//while (fQuit == false)
	//{
	//	cout << "(1)circle  (2)rectangle  (3)square  (0)quit" << endl;
	//	cout << "请输入选项;" << endl;
	//	cin >> choice;
	//	switch (choice)
	//	{
	//	case 1:
	//		sp = new Circle(5);
	//		break;
	//	case 2:
	//		sp = new Rectangle(4, 6);
	//		break;
	//	case 3:
	//		sp = new Square(5);
	//		break;
	//	case 0:
	//		fQuit = true;
	//	default:
	//		break;
	//	}
	//	if (fQuit == false)
	//	{
	//		sp->draw();       //多态
	//		delete sp;       //指针是通过new创建的对象的话，一定要用delete把对象删除
	//	}
	//}
	//std::cout << "开始测试！！" << std::endl;

	//Dog A;
	//A.Speak();   //这个speak就是继承过来的，Dog本身没有定义这个成员
	//A.WagTail();  //这个是自己的，不是继承的
	//std::cout << A.getAge() << std::endl;   //这个也是继承下来的，


	//小子 a;
	//a.X = 1;
	//a.Y = 2;
	//Mammal *theArray[5];
	//theArray[0] = new Dog;
	//theArray[1] = new Cat;
	//theArray[2] = new Pig;
	//theArray[3] = new Horse;
	//theArray[4] = new Mammal;

	//Mammal *otherArray[5];

	//for (int i = 0; i < 5; i++)
	//{
	//	otherArray[i]=theArray[i]->clone();
	//}

	//for (int i = 0; i < 5; i++)
	//{
	//	theArray[i]->Speak();
	//}

	//for (int i = 0; i < 5; i++)
	//{
	//	cout << "clone之后的:";
	//	otherArray[i]->Speak();
	//}
	//
	//ValueFunc(*theArray[1]);


	//base ba;
	//fun(ba);
	//Derivedl zi;
	//fun(zi);           //这个函数接受的是基类，传入派生类也可以，但是在print的时候却是基类的print

	//ba = zi;           //这两个是可以相等的。可以用派生类赋值基类
	//
	//base &ref = zi;    //可以用基类的引用来引用派生类


	//测试多继承
	//cout << "\n\n\n多继承测试" << endl;
	//flyHorse *peg = new flyHorse(red,5, true,10,20);   //构造函数
	//peg->Fly();    //从鸟那里继承来的
	//peg->chirp();   //自己的
	//peg->Whinny();   //从马那里继承的
	//cout << "有" << peg->gerNumberBelievers() << " 人相信世界上有飞马" << endl;
	//cout << peg->bird::getcolor() << endl;

	//peg->getAge();
	//delete peg;
	return 0;
}