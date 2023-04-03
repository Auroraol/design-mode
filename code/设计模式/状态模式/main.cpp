#include <iostream>

using namespace std;

class Context;
// ����״̬
class AbstractState
{
public:
	virtual void Handle(Context* p) = 0;
};

// ���������״̬��
class ConcreteStateNone : public AbstractState
{
	void Handle(Context* p)
	{
		cout << "û��......" << endl;
	}
};

class ConcreteStateExist : public AbstractState
{
	void Handle(Context* p)
	{
		cout << "����....." << endl;
	}
};

//������(��������)
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
	// ״̬�ı�
	void ChangeState(AbstractState* pstate)
	{
		this->pstate = pstate;
	}

private:
	AbstractState* pstate;
};

int main(void)
{
	AbstractState* pNo = new ConcreteStateNone;  //��
	AbstractState* pExist = new ConcreteStateExist; // ��
	Context* pc = new Context(pNo);
	pc->requst();  //
	pc->ChangeState(pExist); // ״̬�ı�
	pc->requst();  //

	return 0;
}