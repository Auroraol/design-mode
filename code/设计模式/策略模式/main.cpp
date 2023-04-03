#include <iostream>

using namespace std;

class Strategy
{
public:
	virtual int execute(int left, int right) = 0;
};

// 具体算法
// 加法
class Add : public Strategy
{
public:
	int execute(int left, int right)
	{
		return left + right;
	}
};

// 减法
class Sub : public Strategy
{
public:
	int execute(int left, int right)
	{
		return left - right;
	}
};

// 策略容器类
class Context
{
public:
	// 设置使用算法方式
	void SetStrategy(Strategy* ps)
	{
		this->ps = ps;
	}
	// 调用特定的算法
	int executeStrategy(int left, int right)
	{
		return ps->execute(left, right);
	}

private:
	Strategy* ps;
};

int main(void)
{
	Context* pcontext = new Context;
	int left, right;
	char key;
	while (1)
	{
		cin >> left >> right >> key;
		switch (key)
		{
		case '+':
			pcontext->SetStrategy(new Add);   // 子类对象new父类
			break;
		case '-':
			pcontext->SetStrategy(new Sub);
			break;
		}

		cout << pcontext->executeStrategy(left, right) << endl;
	}
	return 0;
}