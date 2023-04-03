#include <iostream>

using namespace std;

class Context;
// 抽象状态
class AbstractState
{
public:
	virtual void Handle(Context* p) = 0;
};

// 两个具体的状态类
class ConcreteStateNone : public AbstractState
{
	void Handle(Context* p)
	{
		cout << "没有......" << endl;
	}
};

class ConcreteStateExist : public AbstractState
{
	void Handle(Context* p)
	{
		cout << "有了....." << endl;
	}
};

//操作类(上下文类)
class Context
{
public:
	Context(AbstractState* pstate) : pstate(pstate) {}
	void requst()
	{
		if (pstate)
		{
			pstate->Handle(this);
		}
	}
	// 状态改变
	void ChangeState(AbstractState* pstate)
	{
		this->pstate = pstate;
	}

private:
	AbstractState* pstate;
};

int main(void)
{
	AbstractState* pNo = new ConcreteStateNone;  //有
	AbstractState* pExist = new ConcreteStateExist; // 无
	Context* pc = new Context(pNo);
	pc->requst();  //
	pc->ChangeState(pExist); // 状态改变
	pc->requst();  //

	return 0;
}