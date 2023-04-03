#include <iostream>

using namespace std;

/*
class SingleTon
{
public:
	static SingleTon* m_singleton;   // �ṩ��ָ̬��
	static SingleTon* GetInsance()   // �ṩ��̬����
	{
		if (m_singleton == NULL)
		{
			m_singleton = new SingleTon;
		}
		return m_singleton;
	}

	void testPrint()
	{
		cout << "���� ����...\n";
	}

private:
	SingleTon()                    // ���캯��˽�л�
	{
		cout << "�������...." << endl;
		m_singleton = NULL;
	}
};

SingleTon* SingleTon::m_singleton = NULL;

int main(void)
{
	SingleTon* p1 = SingleTon::GetInsance();
	SingleTon* p2 = SingleTon::GetInsance();
	cout << "p1" << hex << p1 << endl;
	cout << "p2" << hex << p2 << endl;
	p1->testPrint();
	p2->testPrint();
	return 0;
}

*/

#include <iostream>

using namespace std;

class SingleTon
{
public:
	static SingleTon* m_singleton;   // �ṩ��ָ̬��
	static SingleTon* GetInsance()   // �ṩ��̬����
	{
		/*if (m_singleton == NULL)
		{
			m_singleton = new SingleTon;
		}
		*/
		return m_singleton;
	}

	void testPrint()
	{
		cout << "���� ����...\n";
	}

private:
	SingleTon()                    // ���캯��˽�л�
	{
		cout << "�������...." << endl;
		m_singleton = NULL;
	}
};

SingleTon* SingleTon::m_singleton = new SingleTon;

int main(void)
{
	SingleTon* p1 = SingleTon::GetInsance();
	SingleTon* p2 = SingleTon::GetInsance();
	cout << "p1" << hex << p1 << endl;
	cout << "p2" << hex << p2 << endl;
	p1->testPrint();
	p2->testPrint();
	return 0;
}