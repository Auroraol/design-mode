#include <iostream>
#include <string>
#include <map>
#include <stack>

using namespace std;
//抽象表达式
class Expression
{
public:
	//a+b-c
	virtual int Interpreter(map<string, int>& var) = 0;
};

//变量解析器  // a, b, c
class VarExpression : public Expression
{
public:
	VarExpression(string key) : key(key) {}
	int Interpreter(map<string, int>& var)
	{// 得到值
		return var[key];
	}
private:
	string key;
};

//运算符解析器
//抽象父类
class SymbolExpression : public Expression
{
public:
	SymbolExpression(Expression* left, Expression* right) :left(left), right(right) {}
	Expression* GetLeft() { return left; }   // 得到左值
	Expression* GetRight() { return right; }
protected:
	Expression* left;   // 操作数
	Expression* right;
};

//具体子类
//运算规则
//具体子类
class AddExpression :public SymbolExpression
{// 加法
public:
	AddExpression(Expression* left, Expression* right) :SymbolExpression(left, right) {}
	int Interpreter(map<string, int>& var)
	{
		return left->Interpreter(var) + right->Interpreter(var);
	}
};

class SubExpression :public SymbolExpression
{// 减法
public:
	SubExpression(Expression* left, Expression* right) :SymbolExpression(left, right) {}
	int Interpreter(map<string, int>& var)
	{
		return left->Interpreter(var) - right->Interpreter(var);
	}
};

// 封装调用接口
class Calculator
{
private:
	Expression* expression;  //表达式
public:
	Calculator(string expstr)  // a+b-c
	{
		expression = NULL;
		stack<Expression*> stkexp;  // 栈
		Expression* left = NULL;
		Expression* right = NULL;
		for (int i = 0; i < expstr.size(); i++)
		{
			switch (expstr[i])
			{
			case'+':
				//从栈中取出左操作数
				left = stkexp.top();
				stkexp.pop();
				//从文法字符串取出+后面的右操作数
				right = new VarExpression(expstr.substr(++i, 1));
				//将新的结果存入栈
				stkexp.push(new AddExpression(left, right));
				break;
			case '-':
				//从栈中取出左操作数
				left = stkexp.top();
				stkexp.pop();
				//从文法字符串取出-后面的右操作数
				right = new VarExpression(expstr.substr(++i, 1));
				//将新的结果存入栈
				stkexp.push(new SubExpression(left, right));
				break;
			default:
				stkexp.push(new VarExpression(expstr.substr(i, 1)));  //a,b这种直接入栈
				break;
			}
		}
		////栈中保存就是最终语法树的根
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