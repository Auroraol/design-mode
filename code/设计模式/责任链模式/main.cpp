#include <iostream>

using namespace std;

// ����һ��������
class Handler
{
public:
	Handler() : pnext(nullptr) {}
	// ת����һλ
	void setNextHandler(Handler* pnext)
	{
		this->pnext = pnext;
	}
	// ��������
	virtual void handlerRequst(int days) = 0;
protected:
	Handler* pnext;  // ��һλ������
};

// ���崦����
// ����
class Director :public Handler
{
public:
	void handlerRequst(int days)
	{
		cout << "���ܻظ�:";
		if (days <= 1)
		{
			cout << "����ͬ�����" << endl;
		}
		else
		{
			cout << "���ʱ��̫��, �Ҿ���" << endl;
			pnext->handlerRequst(days);
		}
	}
};

class Manager :public Handler
{
public:
	void handlerRequst(int days)
	{
		cout << "����ظ�:";
		if (days <= 3)
		{
			cout << "����ͬ�����" << endl;
		}
		else
		{
			cout << "���ʱ��̫��, ���ϰ�" << endl;
			pnext->handlerRequst(days);
		}
	}
};

class Boss :public Handler
{
public:
	void handlerRequst(int days)
	{
		cout << "�ϰ�ظ�:";
		if (days <= 30)
		{
			cout << "�ϰ�ͬ�����" << endl;
		}
		else
		{
			cout << "���ʱ��̫��, ����׼" << endl;
		}
	}
};

int main(void)
{
	//��װ��
	Handler* director = new Director;
	Handler* manager = new Manager;
	Handler* boss = new Boss;
	director->setNextHandler(manager);
	manager->setNextHandler(boss);

	cout << "���1����......" << endl;
	director->handlerRequst(1);
	cout << "���3����........" << endl;
	director->handlerRequst(3);
	cout << "���15����......." << endl;
	director->handlerRequst(15);

	return 0;
}