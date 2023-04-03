#include <iostream>
#include <string>
using namespace std;
/*
1.提供个抽象组件类:  抽象被装饰者的行为
2.提供─个或多个具体组件类:  被装饰者的行为具体实现.提供一个抽象装饰器类:抽象组件指针与抽象组件—致接口I
4.提供一个具体的装饰器类:  为具体组件附加责任
*/

// 抽象组件类
class AbstractCompent
{
public:
	virtual void show() = 0;
	string pstr;
};

//具体组件类
class Girl : public AbstractCompent
{
public:
	Girl()
	{
		this->pstr = "没穿衣服";
	}
	void show()
	{
		cout << this->pstr << endl;
	}
};

// 抽象装饰器类
class AbstractDecorate : public AbstractCompent
{
public:
	virtual void show() = 0;
protected:
	AbstractCompent* pBase;
};

// 装饰器类
//穿超短裙
class Miniskirt :public AbstractDecorate
{
public:
	Miniskirt(AbstractCompent* pBase)
	{
		this->pBase = pBase;
	}
	void show()
	{
		this->pstr = this->pBase->pstr + "穿裙子";
		cout << this->pstr << endl;
	}
};

class BlackSilk :public AbstractDecorate
{
public:
	BlackSilk(AbstractCompent* pBase)
	{
		this->pBase = pBase;
	}
	void show()
	{
		this->pstr = this->pBase->pstr + "穿黑丝";
		cout << this->pstr << endl;
	}
};

#if 1

int main()
{
	Girl* pg = new Girl;
	pg->show();

	Miniskirt* pm = new Miniskirt(pg);
	pm->show();

	BlackSilk* pb = new BlackSilk(pm);
	pb->show();

	BlackSilk* pb2 = new BlackSilk(pg);
	pb2->show();

	return 0;
}
#endif // 0