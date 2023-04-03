#include <iostream>
using namespace std;

class MakeObject
{
public:
	virtual void MakeHead() = 0;
	virtual void MakeBody() = 0;
	virtual void Garb() = 0;
	void Make()
	{
		MakeHead();
		MakeBody();
		Garb();
	}
};

class MakeGinlFriend : public MakeObject
{
public:
	void MakeHead()
	{
		cout << "����Ƶ�ͷ";
	}
	void MakeBody()
	{
		cout << "���ݵ����";
	}
	void Garb()
	{
		cout << "����װ" << endl;
	}
};

class MakeBoyFriend : public MakeObject
{
public:
	void MakeHead()
	{
		cout << "�����ͷ";
	}
	void MakeBody()
	{
		cout << "�����̵����";
	}
	void Garb()
	{
		cout << "����װ" << endl;
	}
};

int main(void)
{
	MakeObject* pobject = new MakeGinlFriend;
	pobject->Make();
	delete pobject;
	pobject = new MakeBoyFriend;
	pobject->Make();
	delete pobject;
	return 0;
}