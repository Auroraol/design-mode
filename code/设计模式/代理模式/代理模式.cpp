#include <iostream>
using namespace std;
//1.提供一个抽象主题角色:真实主题与代理主题的共同接口
//2.提供一个真实主题角色 : 定义了代理角色所代表的真实对象
//3.提供一个代理主题角色 : 含有对真实主题角色的引用

class Abstractsubject
{
public:
	virtual void BuyTicket() = 0;
	~Abstractsubject();
};

class User : public Abstractsubject
{
public:
	void BuyTicket()
	{
		cout << "用户买票" << endl;
	}
};

class Ctrip : public Abstractsubject
{
public:
	Ctrip(Abstractsubject* Pbase)
	{
		this->pBase = Pbase;
	}

	void BuyTicket()
	{
		cout << "携程购票" << endl;
	}
private:
	Abstractsubject* pBase;
};

#if 1
int main(void)
{
	// 用户自己买票
	Abstractsubject* pBase = new User;
	pBase->BuyTicket();

	// 代理对象购票
	Ctrip* proxy = new Ctrip(pBase);
	proxy->BuyTicket();

	return 0;
}
#endif // 0