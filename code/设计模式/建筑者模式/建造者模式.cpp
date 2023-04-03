#include <iostream>
#include <string>
#include <vector>

using namespace std;

//电脑组装:显示器、鼠标、键盘、主机(主机又包括cpu、显卡、主板等)
// 1. 找到店铺老板告诉需求
// 2. 客服安排技术员工组装1
// 3. 产品组装完成

// 抽象产品类
class AbstractProduct
{
public:
	virtual void SetDisplayer(string displayer) = 0;
	virtual void SetMouse(string mouse) = 0;
	virtual void SetKeyBoard(string keyBoard) = 0;
	virtual void SetHost(string host) = 0;
	virtual void Show() = 0;
};

// 具体产品类
class computer : public AbstractProduct
{
public:
	void SetDisplayer(string displayer)
	{
		m_list.push_back(displayer);
	}

	void SetMouse(string mouse)
	{
		m_list.push_back(mouse);
	}

	void SetKeyBoard(string keyBoard)
	{
		m_list.push_back(keyBoard);
	}

	void SetHost(string host)
	{
		m_list.push_back(host);
	}

	void Show()
	{
		cout << "电脑配置结果: " << endl;
		for (auto v : m_list)
		{
			cout << v << endl;
		}
	}

public:
	vector<string> m_list;
};

// 抽象建造者类
class AbatractBuilder
{
public:
	AbatractBuilder() : product(new computer)
	{
	}
	// 抽象从建造过程
	virtual void BuildDisplaye(string displayer) = 0;
	virtual void BuildMouse(string mouse) = 0;
	virtual void BuildKeyBoard(string keyBoard) = 0;
	virtual void BuildHost(string host) = 0;

	AbstractProduct* getProduct()
	{
		return product;
	}

protected:
	AbstractProduct* product;
};

// 具体的建造者类--->组装电脑的技术员
class ConcreteBuilder :public AbatractBuilder
{
public:
	void BuildDisplaye(string displayer)
	{
		product->SetDisplayer(displayer);
	}
	void BuildMouse(string mouse)
	{
		product->SetMouse(mouse);
	}
	void BuildKeyBoard(string keyBoard)
	{
		product->SetKeyBoard(keyBoard);
	}
	void BuildHost(string host)
	{
		product->SetHost(host);
	}
};

// 指挥者类--> 具体的完成
class Director
{
public:
	Director(AbatractBuilder* pBuilder) :pBuilder(pBuilder)
	{
	}
	AbstractProduct* createProduct(string displayer, string mouse, string keyBoard, string host)
	{
		pBuilder->BuildDisplaye(displayer);
		pBuilder->BuildMouse(mouse);
		pBuilder->BuildKeyBoard(keyBoard);
		pBuilder->BuildHost(host);
		return pBuilder->getProduct();
	}

private:
	AbatractBuilder* pBuilder;
};

#if 1

int main(void)
{
	AbatractBuilder* pb = new ConcreteBuilder;
	Director* pD = new Director(pb);
	AbstractProduct* computer = pD->createProduct("华为显示器", "牧马人鼠标", "雷蛇键盘", "外星人");
	computer->Show();

	return 0;
}
#endif