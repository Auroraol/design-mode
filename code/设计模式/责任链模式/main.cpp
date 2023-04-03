#include <iostream>

using namespace std;

// 抽象一个处理类
class Handler
{
public:
	Handler() : pnext(nullptr) {}
	// 转接下一位
	void setNextHandler(Handler* pnext)
	{
		this->pnext = pnext;
	}
	// 具体请求
	virtual void handlerRequst(int days) = 0;
protected:
	Handler* pnext;  // 下一位处理者
};

// 具体处理者
// 主管
class Director :public Handler
{
public:
	void handlerRequst(int days)
	{
		cout << "主管回复:";
		if (days <= 1)
		{
			cout << "主管同意请假" << endl;
		}
		else
		{
			cout << "请教时间太长, 找经理" << endl;
			pnext->handlerRequst(days);
		}
	}
};

class Manager :public Handler
{
public:
	void handlerRequst(int days)
	{
		cout << "经理回复:";
		if (days <= 3)
		{
			cout << "经理同意请假" << endl;
		}
		else
		{
			cout << "请教时间太长, 找老板" << endl;
			pnext->handlerRequst(days);
		}
	}
};

class Boss :public Handler
{
public:
	void handlerRequst(int days)
	{
		cout << "老板回复:";
		if (days <= 30)
		{
			cout << "老板同意请假" << endl;
		}
		else
		{
			cout << "请假时间太长, 不批准" << endl;
		}
	}
};

int main(void)
{
	//组装链
	Handler* director = new Director;
	Handler* manager = new Manager;
	Handler* boss = new Boss;
	director->setNextHandler(manager);
	manager->setNextHandler(boss);

	cout << "请假1天结果......" << endl;
	director->handlerRequst(1);
	cout << "请假3天结果........" << endl;
	director->handlerRequst(3);
	cout << "请假15天结果......." << endl;
	director->handlerRequst(15);

	return 0;
}