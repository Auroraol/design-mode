//不同人逛公园
//我:   看美女
//美女: 看风景
//情侣: 约会
#include <iostream>
#include <string>
#include <list>

using namespace std;

class ParkElement;

// 访问
class Visitor
{
public:
	virtual void Visit(ParkElement* park) = 0;
protected:
	string name;
};

// 公园
class ParkElement
{
public:
	virtual void Accept(Visitor* visitor) = 0;
	string GetAddr() { return addr; }

protected:
	string addr;
};

//小树林
class Grove : public ParkElement
{
public:
	Grove()
	{
		this->addr = "小树林";
	}
	void Accept(Visitor* visitor)
	{
		visitor->Visit(this);
	}
};

//湖
class Lake :public ParkElement
{
public:
	Lake()
	{
		this->addr = "湖边  ";
	}
	void Accept(Visitor* visitor)
	{
		visitor->Visit(this);
	}
};

// 人
class Preson : public Visitor
{
public:
	Preson() { this->name = "人"; }
	void Visit(ParkElement* park)
	{
		cout << name << "在 " << park->GetAddr() << " 看美女" << endl;
	}
};

class MM : public Visitor
{
public:
	MM() { this->name = "美女"; }
	void Visit(ParkElement* park)
	{
		cout << name << "在 " << park->GetAddr() << " 欣赏风景" << endl;
	}
};

class Lover : public Visitor
{
public:
	Lover() { this->name = "情侣"; }
	void Visit(ParkElement* park)
	{
		cout << name << "在 " << park->GetAddr() << "约会" << endl;
	}
};

//结构对象类:组合管理访问点
class Park : public ParkElement
{
public:
	Park() {}
	void SetPark(ParkElement* parkElement)
	{
		partList.push_back(parkElement);
	}

	void Accept(Visitor* visitor)
	{
		for (auto v : partList)
		{
			v->Accept(visitor);
		}
	}

protected:
	list<ParkElement*> partList;
};

int main(void)
{
	//方式1:
	cout << "直接访问:" << endl;
	//访问者
	Preson* pMy = new Preson;
	MM* pMM = new MM;
	Lover* pLove = new Lover;
	//访问对象
	Grove* pGrove = new Grove;
	Lake* pLake = new Lake;

	pLake->Accept(pMy);
	pGrove->Accept(pMy);
	pLake->Accept(pMM);
	pGrove->Accept(pMM);
	pLake->Accept(pLove);
	pGrove->Accept(pLove);
	cout << endl;
	//方式2 通过结构对象类:
	cout << "结构体类对象管理：" << endl;
	Park* p = new Park;
	p->SetPark(pLake);
	p->SetPark(pGrove);
	p->Accept(pMy);
	p->Accept(pMM);
	p->Accept(pLove);

	return 0;
}