#include <iostream>
#include <vector>

using namespace std;

// ��ʦ��
class Cook
{
public:
	void makeVegetalbe()
	{
		cout << "�߲�ɳ��" << endl;
	}

	void makeSteak()
	{
		cout << "ţ��һ��" << endl;
	}

	void unVegetalbe()
	{
		cout << "�߲�ɳ����Ҫ��" << endl;
	}

	void unSteak()
	{
		cout << "ţ��һ�ݲ�Ҫ��" << endl;
	}
};

// ����������
class Command
{
public:
	Command(Cook* pCook = nullptr) : pCook(pCook) {}
	virtual void executeCommand() = 0;  // ������
	virtual void unCommand() = 0;       // ��������

protected:
	Cook* pCook;
};

// ��������
class MakeVegetableCommand :public Command
{
public:
	MakeVegetableCommand(Cook* pCook) : Command(pCook) {}
	void executeCommand()
	{
		pCook->makeVegetalbe();
	}
	void unCommand()
	{
		pCook->unVegetalbe();
	}
};

// ��������
class MakeSteakCommand :public Command
{
public:
	MakeSteakCommand(Cook* pCook) : Command(pCook) {}
	void executeCommand()
	{
		pCook->makeSteak();
	}
	void unCommand()
	{
		pCook->unSteak();
	}
};

// �ͻ����
class Order
{
public:
	void setOrder(Command* command)
	{
		commandQueue.push_back(command);
		cout << "��һ����" << endl;
	}
	void UnOrder()
	{
		commandQueue.pop_back();
		cout << "��Ҫһ����" << endl;
	}
	// ��ӡ
	void Notify()
	{
		for (auto v : commandQueue)
		{
			v->executeCommand();
		}
	}
private:
	vector<Command*> commandQueue;
};
int main(void)
{
	//���ɳ�ʦ����
	Cook* pcook = new Cook;
	//��˶���
	Command* pvegetable = new MakeVegetableCommand(pcook);
	Command* psteak = new MakeSteakCommand(pcook);
	//��������
	Order* porder = new Order;

	//�������͵��������
	porder->setOrder(pvegetable); // ���
	porder->setOrder(psteak);
	porder->Notify();
	cout << "----------" << endl;
	porder->UnOrder();  // �˲�
	porder->Notify();

	return 0;
}