#include <iostream>
#include <string>
using namespace std;
/*
1.�ṩ�����������:  ����װ���ߵ���Ϊ
2.�ṩ�����������������:  ��װ���ߵ���Ϊ����ʵ��.�ṩһ������װ������:�������ָ�������������½ӿ�I
4.�ṩһ�������װ������:  Ϊ���������������
*/

// ���������
class AbstractCompent
{
public:
	virtual void show() = 0;
	string pstr;
};

//���������
class Girl : public AbstractCompent
{
public:
	Girl()
	{
		this->pstr = "û���·�";
	}
	void show()
	{
		cout << this->pstr << endl;
	}
};

// ����װ������
class AbstractDecorate : public AbstractCompent
{
public:
	virtual void show() = 0;
protected:
	AbstractCompent* pBase;
};

// װ������
//������ȹ
class Miniskirt :public AbstractDecorate
{
public:
	Miniskirt(AbstractCompent* pBase)
	{
		this->pBase = pBase;
	}
	void show()
	{
		this->pstr = this->pBase->pstr + "��ȹ��";
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
		this->pstr = this->pBase->pstr + "����˿";
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