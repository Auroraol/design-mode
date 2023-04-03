#include <iostream>

using namespace std;
//1. �ṩһ��������:  ����ʵ�ִ�������ʵ�����ڲ��߼����ɱ����ֱ�ӵ��ã���������Ĳ�Ʒ����
//2. �ṩһ�������Ʒ�� : �򵥹���ģʽ�����������ж���ĸ��࣬��������������ʵ�������еĹ����ӿڡ�
//3. �ṩһ�������Ʒ�� : �򵥹���ģʽ�������ľ���ʵ������

// ��һ��������(+-*/)
//1. �ṩһ��������:      ������ͬ��Ʒ
//2. �ṩһ�������Ʒ�� :  ����� + ��������,�õ����
//3. �ṩһ�������Ʒ�� :  �����

//�����Ʒ��
class Operator
{
public:
	double m_leftValue;
	double m_rightValue;
	virtual double GetResult() = 0;
};

//�����Ʒ��
class AddOperator : public Operator
{
	double GetResult()
	{
		return m_leftValue + m_rightValue;
	}
};

class SubOperator : public Operator
{
	double GetResult()
	{
		return m_leftValue - m_rightValue;
	}
};

class MulOperator : public Operator
{
	double GetResult()
	{
		return m_leftValue * m_rightValue;
	}
};

class DivOperator : public Operator
{
	double GetResult()
	{
		return m_leftValue / m_rightValue; //�����ǳ���Ϊ0
	}
};

//������: �����Ʒ����
class OperatorFatory
{
public:
	static Operator* createOperator(char c)
	{
		switch (c)
		{
		case'+':
			return new AddOperator;
			break;
		case'-':
			return new SubOperator;
			break;
		case'*':
			return new MulOperator;
			break;
		case'/':
			return new DivOperator;
			break;
		}
	}
};

#if 1

int main(void)
{
	Operator* add = OperatorFatory::createOperator('+');
	add->m_leftValue = 1;
	add->m_rightValue = 2;
	cout << add->GetResult() << endl;
	return 0;
}

#endif // 0