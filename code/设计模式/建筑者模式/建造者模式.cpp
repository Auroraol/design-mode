#include <iostream>
#include <string>
#include <vector>

using namespace std;

//������װ:��ʾ������ꡢ���̡�����(�����ְ���cpu���Կ��������)
// 1. �ҵ������ϰ��������
// 2. �ͷ����ż���Ա����װ1
// 3. ��Ʒ��װ���

// �����Ʒ��
class AbstractProduct
{
public:
	virtual void SetDisplayer(string displayer) = 0;
	virtual void SetMouse(string mouse) = 0;
	virtual void SetKeyBoard(string keyBoard) = 0;
	virtual void SetHost(string host) = 0;
	virtual void Show() = 0;
};

// �����Ʒ��
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
		cout << "�������ý��: " << endl;
		for (auto v : m_list)
		{
			cout << v << endl;
		}
	}

public:
	vector<string> m_list;
};

// ����������
class AbatractBuilder
{
public:
	AbatractBuilder() : product(new computer)
	{
	}
	// ����ӽ������
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

// ����Ľ�������--->��װ���Եļ���Ա
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

// ָ������--> ��������
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
	AbstractProduct* computer = pD->createProduct("��Ϊ��ʾ��", "���������", "���߼���", "������");
	computer->Show();

	return 0;
}
#endif