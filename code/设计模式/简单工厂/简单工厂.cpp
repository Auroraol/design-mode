#include <iostream>

using namespace std;
//1. 提供一个工厂类:  负责实现创建所有实例的内部逻辑。可被外界直接调用，创建所需的产品对象。
//2. 提供一个抽象产品类 : 简单工厂模式所创建的所有对象的父类，它负责描述所有实例所共有的公共接口。
//3. 提供一个具体产品类 : 简单工厂模式所创建的具体实例对象

// 做一个计算器(+-*/)
//1. 提供一个工厂类:      产生不同产品
//2. 提供一个抽象产品类 :  运算符 + 负责运算,得到结果
//3. 提供一个具体产品类 :  运算符

//抽象产品类
class Operator
{
public:
	double m_leftValue;
	double m_rightValue;
	virtual double GetResult() = 0;
};

//具体产品类
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
		return m_leftValue / m_rightValue; //不考虑除数为0
	}
};

//工厂类: 负责产品创建
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