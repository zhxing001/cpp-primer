#include<iostream>
#include<string>
#include"Virtual.h"


//����Ʒ��
//enum BREED
//{
//	GOLDEN,
//	CAIRN,
//	DANDIE,
//	SHETLAND,
//	LAB
//};
//
////��Ա��
//class employee {
//
//
//};
//
////�����࣬�̳й�Ա�࣬�̳п��Լ̳ж����
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
////��Animal�̳й���
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
//	//���м̳У����еĳ�Ա�����̳У�����copy����
//	//˽�м̳У�����Ĺ��г�Ա�ͱ�����Ա�����˽�е��ˡ�
//	//�����̳У����еĺ�protected�ı��protected�ģ�˽�еĻ���˽�е�
//	//��õ��ǹ��м̳С�
//};
//
//
//class ���� {
//
//public:
//	int X;
//};
//
//class С��:public ���� {
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
	//shape *sp=nullptr;     //�±�׼���������ﲻ����ʼ��ֱ���ã�
	//while (fQuit == false)
	//{
	//	cout << "(1)circle  (2)rectangle  (3)square  (0)quit" << endl;
	//	cout << "������ѡ��;" << endl;
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
	//		sp->draw();       //��̬
	//		delete sp;       //ָ����ͨ��new�����Ķ���Ļ���һ��Ҫ��delete�Ѷ���ɾ��
	//	}
	//}
	//std::cout << "��ʼ���ԣ���" << std::endl;

	//Dog A;
	//A.Speak();   //���speak���Ǽ̳й����ģ�Dog����û�ж��������Ա
	//A.WagTail();  //������Լ��ģ����Ǽ̳е�
	//std::cout << A.getAge() << std::endl;   //���Ҳ�Ǽ̳������ģ�


	//С�� a;
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
	//	cout << "clone֮���:";
	//	otherArray[i]->Speak();
	//}
	//
	//ValueFunc(*theArray[1]);


	//base ba;
	//fun(ba);
	//Derivedl zi;
	//fun(zi);           //����������ܵ��ǻ��࣬����������Ҳ���ԣ�������print��ʱ��ȴ�ǻ����print

	//ba = zi;           //�������ǿ�����ȵġ������������ำֵ����
	//
	//base &ref = zi;    //�����û��������������������


	//���Զ�̳�
	//cout << "\n\n\n��̳в���" << endl;
	//flyHorse *peg = new flyHorse(red,5, true,10,20);   //���캯��
	//peg->Fly();    //��������̳�����
	//peg->chirp();   //�Լ���
	//peg->Whinny();   //��������̳е�
	//cout << "��" << peg->gerNumberBelievers() << " �������������з���" << endl;
	//cout << peg->bird::getcolor() << endl;

	//peg->getAge();
	//delete peg;
	return 0;
}