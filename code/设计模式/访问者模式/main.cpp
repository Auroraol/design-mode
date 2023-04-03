//��ͬ�˹乫԰
//��:   ����Ů
//��Ů: ���羰
//����: Լ��
#include <iostream>
#include <string>
#include <list>

using namespace std;

class ParkElement;

// ����
class Visitor
{
public:
	virtual void Visit(ParkElement* park) = 0;
protected:
	string name;
};

// ��԰
class ParkElement
{
public:
	virtual void Accept(Visitor* visitor) = 0;
	string GetAddr() { return addr; }

protected:
	string addr;
};

//С����
class Grove : public ParkElement
{
public:
	Grove()
	{
		this->addr = "С����";
	}
	void Accept(Visitor* visitor)
	{
		visitor->Visit(this);
	}
};

//��
class Lake :public ParkElement
{
public:
	Lake()
	{
		this->addr = "����  ";
	}
	void Accept(Visitor* visitor)
	{
		visitor->Visit(this);
	}
};

// ��
class Preson : public Visitor
{
public:
	Preson() { this->name = "��"; }
	void Visit(ParkElement* park)
	{
		cout << name << "�� " << park->GetAddr() << " ����Ů" << endl;
	}
};

class MM : public Visitor
{
public:
	MM() { this->name = "��Ů"; }
	void Visit(ParkElement* park)
	{
		cout << name << "�� " << park->GetAddr() << " ���ͷ羰" << endl;
	}
};

class Lover : public Visitor
{
public:
	Lover() { this->name = "����"; }
	void Visit(ParkElement* park)
	{
		cout << name << "�� " << park->GetAddr() << "Լ��" << endl;
	}
};

//�ṹ������:��Ϲ�����ʵ�
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
	//��ʽ1:
	cout << "ֱ�ӷ���:" << endl;
	//������
	Preson* pMy = new Preson;
	MM* pMM = new MM;
	Lover* pLove = new Lover;
	//���ʶ���
	Grove* pGrove = new Grove;
	Lake* pLake = new Lake;

	pLake->Accept(pMy);
	pGrove->Accept(pMy);
	pLake->Accept(pMM);
	pGrove->Accept(pMM);
	pLake->Accept(pLove);
	pGrove->Accept(pLove);
	cout << endl;
	//��ʽ2 ͨ���ṹ������:
	cout << "�ṹ����������" << endl;
	Park* p = new Park;
	p->SetPark(pLake);
	p->SetPark(pGrove);
	p->Accept(pMy);
	p->Accept(pMM);
	p->Accept(pLove);

	return 0;
}