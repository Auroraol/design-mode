#include <iostream>
#include <vector>

using namespace std;

// 厨师类
class Cook
{
public:
	void makeVegetalbe()
	{
		cout << "蔬菜沙拉" << endl;
	}

	void makeSteak()
	{
		cout << "牛排一份" << endl;
	}

	void unVegetalbe()
	{
		cout << "蔬菜沙拉不要了" << endl;
	}

	void unSteak()
	{
		cout << "牛排一份不要了" << endl;
	}
};

// 抽象命令类
class Command
{
public:
	Command(Cook* pCook = nullptr) : pCook(pCook) {}
	virtual void executeCommand() = 0;  // 做命令
	virtual void unCommand() = 0;       // 不做命令

protected:
	Cook* pCook;
};

// 具体命令
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

// 具体命令
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

// 客户点菜
class Order
{
public:
	void setOrder(Command* command)
	{
		commandQueue.push_back(command);
		cout << "点一道菜" << endl;
	}
	void UnOrder()
	{
		commandQueue.pop_back();
		cout << "不要一道菜" << endl;
	}
	// 打印
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
	//生成厨师对象
	Cook* pcook = new Cook;
	//点菜对象
	Command* pvegetable = new MakeVegetableCommand(pcook);
	Command* psteak = new MakeSteakCommand(pcook);
	//订单对象
	Order* porder = new Order;

	//订单推送到命令队列
	porder->setOrder(pvegetable); // 点菜
	porder->setOrder(psteak);
	porder->Notify();
	cout << "----------" << endl;
	porder->UnOrder();  // 退菜
	porder->Notify();

	return 0;
}