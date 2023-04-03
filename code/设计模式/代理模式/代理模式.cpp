#include <iostream>
using namespace std;
//1.�ṩһ�����������ɫ:��ʵ�������������Ĺ�ͬ�ӿ�
//2.�ṩһ����ʵ�����ɫ : �����˴����ɫ���������ʵ����
//3.�ṩһ�����������ɫ : ���ж���ʵ�����ɫ������

class Abstractsubject
{
public:
	virtual void BuyTicket() = 0;
	~Abstractsubject();
};

class User : public Abstractsubject
{
public:
	void BuyTicket()
	{
		cout << "�û���Ʊ" << endl;
	}
};

class Ctrip : public Abstractsubject
{
public:
	Ctrip(Abstractsubject* Pbase)
	{
		this->pBase = Pbase;
	}

	void BuyTicket()
	{
		cout << "Я�̹�Ʊ" << endl;
	}
private:
	Abstractsubject* pBase;
};

#if 1
int main(void)
{
	// �û��Լ���Ʊ
	Abstractsubject* pBase = new User;
	pBase->BuyTicket();

	// �������Ʊ
	Ctrip* proxy = new Ctrip(pBase);
	proxy->BuyTicket();

	return 0;
}
#endif // 0