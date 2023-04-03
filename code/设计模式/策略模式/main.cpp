#include <iostream>

using namespace std;

class Strategy
{
public:
	virtual int execute(int left, int right) = 0;
};

// �����㷨
// �ӷ�
class Add : public Strategy
{
public:
	int execute(int left, int right)
	{
		return left + right;
	}
};

// ����
class Sub : public Strategy
{
public:
	int execute(int left, int right)
	{
		return left - right;
	}
};

// ����������
class Context
{
public:
	// ����ʹ���㷨��ʽ
	void SetStrategy(Strategy* ps)
	{
		this->ps = ps;
	}
	// �����ض����㷨
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
			pcontext->SetStrategy(new Add);   // �������new����
			break;
		case '-':
			pcontext->SetStrategy(new Sub);
			break;
		}

		cout << pcontext->executeStrategy(left, right) << endl;
	}
	return 0;
}