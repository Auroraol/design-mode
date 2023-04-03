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
		cout << "刘亦菲的头";
	}
	void MakeBody()
	{
		cout << "杨幂的身材";
	}
	void Garb()
	{
		cout << "穿古装" << endl;
	}
};

class MakeBoyFriend : public MakeObject
{
public:
	void MakeHead()
	{
		cout << "胡歌的头";
	}
	void MakeBody()
	{
		cout << "彭于晏的身材";
	}
	void Garb()
	{
		cout << "穿西装" << endl;
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