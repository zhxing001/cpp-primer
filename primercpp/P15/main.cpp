#include<iostream>
#include<string>

//����Ʒ��
enum BREED
{
	GOLDEN,
	CAIRN,
	DANDIE,
	SHETLAND,
	LAB
};

//��Ա��
class employee {


};

//�����࣬�̳й�Ա�࣬�̳п��Լ̳ж����
class Manage :public employee {

};

class Animal {
public:
	Animal() :itsAge(2), itsWeight(5) {};
	~Animal() {};
	int getAge() const { return itsAge; }
	void setAge(int age) { this->itsAge = age; }
	int getWeight() const { return itsWeight; }
	void setWeight(int Wei) { this->itsWeight = Wei; }

	void Speak() const {
		std::cout << "Animal sound!\n";
	}
	void Sleep() const
	{
		std::cout << "sleeping!!\n";
	}

protected:
	int itsAge;
	int itsWeight;
};


//��Animal�̳й���
class Dog :public Animal {
public:
	Dog() :itsBreed(GOLDEN) {};
	~Dog() {};

	BREED getBreed() const { return itsBreed; }
	void setBreed(BREED breed) {
		this->itsBreed = breed;
	}

	void WagTail() const {
		std::cout << "Tail Wagging\n";
	}
	void BegFood() const {
		std::cout << "begging for food!\n";
	}
protected:
	BREED itsBreed;
};


class Point {
public:
	void InitPoint(int x, int y);
	void Move(int xOFF, int yOFF);
protected:
	int GetX()
	{
		return X;
	}
	int GetY()
	{
		return Y;
	}
private:
	int X, Y;
};

class Rectange :public Point
{
	//���м̳У����еĳ�Ա�����̳У�����copy����
	//˽�м̳У�����Ĺ��г�Ա�ͱ�����Ա�����˽�е��ˡ�
	//�����̳У����еĺ�protected�ı��protected�ģ�˽�еĻ���˽�е�
	//��õ��ǹ��м̳С�
};


class ���� {

public:
	int X;
};

class С��:public ���� {
public: 
	int Y;

};

int main()
{
	std::cout << "��ʼ���ԣ���" << std::endl;

	Dog A;
	A.Speak();   //���speak���Ǽ̳й����ģ�Dog����û�ж��������Ա
	A.WagTail();  //������Լ��ģ����Ǽ̳е�
	std::cout << A.getAge() << std::endl;   //���Ҳ�Ǽ̳������ģ�


	С�� a;
	a.X = 1;
	a.Y = 2;
	return 0;
}