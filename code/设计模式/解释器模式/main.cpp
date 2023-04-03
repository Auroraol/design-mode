#include <iostream>
#include <string>
#include <map>
#include <stack>

using namespace std;
//������ʽ
class Expression
{
public:
	//a+b-c
	virtual int Interpreter(map<string, int>& var) = 0;
};

//����������  // a, b, c
class VarExpression : public Expression
{
public:
	VarExpression(string key) : key(key) {}
	int Interpreter(map<string, int>& var)
	{// �õ�ֵ
		return var[key];
	}
private:
	string key;
};

//�����������
//������
class SymbolExpression : public Expression
{
public:
	SymbolExpression(Expression* left, Expression* right) :left(left), right(right) {}
	Expression* GetLeft() { return left; }   // �õ���ֵ
	Expression* GetRight() { return right; }
protected:
	Expression* left;   // ������
	Expression* right;
};

//��������
//�������
//��������
class AddExpression :public SymbolExpression
{// �ӷ�
public:
	AddExpression(Expression* left, Expression* right) :SymbolExpression(left, right) {}
	int Interpreter(map<string, int>& var)
	{
		return left->Interpreter(var) + right->Interpreter(var);
	}
};

class SubExpression :public SymbolExpression
{// ����
public:
	SubExpression(Expression* left, Expression* right) :SymbolExpression(left, right) {}
	int Interpreter(map<string, int>& var)
	{
		return left->Interpreter(var) - right->Interpreter(var);
	}
};

// ��װ���ýӿ�
class Calculator
{
private:
	Expression* expression;  //���ʽ
public:
	Calculator(string expstr)  // a+b-c
	{
		expression = NULL;
		stack<Expression*> stkexp;  // ջ
		Expression* left = NULL;
		Expression* right = NULL;
		for (int i = 0; i < expstr.size(); i++)
		{
			switch (expstr[i])
			{
			case'+':
				//��ջ��ȡ���������
				left = stkexp.top();
				stkexp.pop();
				//���ķ��ַ���ȡ��+������Ҳ�����
				right = new VarExpression(expstr.substr(++i, 1));
				//���µĽ������ջ
				stkexp.push(new AddExpression(left, right));
				break;
			case '-':
				//��ջ��ȡ���������
				left = stkexp.top();
				stkexp.pop();
				//���ķ��ַ���ȡ��-������Ҳ�����
				right = new VarExpression(expstr.substr(++i, 1));
				//���µĽ������ջ
				stkexp.push(new SubExpression(left, right));
				break;
			default:
				stkexp.push(new VarExpression(expstr.substr(i, 1)));  //a,b����ֱ����ջ
				break;
			}
		}
		////ջ�б�����������﷨���ĸ�
		if (!stkexp.empty())
		{
			expression = stkexp.top();
			stkexp.pop();
		}
	}

	int Run(map<string, int>& var)
	{
		return (expression == NULL) ? 0 : expression->Interpreter(var);
	}
};

int main()
{
	string expstr = "a+b-c";
	map<string, int> var;
	var["a"] = 10;
	var["b"] = 50;
	var["c"] = 10;
	Calculator ca1(expstr);
	cout << ca1.Run(var) << endl;
	return 0;
}