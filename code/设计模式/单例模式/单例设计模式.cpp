#include <iostream>

using namespace std;

/*
class SingleTon
{
public:
	static SingleTon* m_singleton;   // 提供情态指针
	static SingleTon* GetInsance()   // 提供情态方法
	{
		if (m_singleton == NULL)
		{
			m_singleton = new SingleTon;
		}
		return m_singleton;
	}

	void testPrint()
	{
		cout << "测试 调用...\n";
	}

private:
	SingleTon()                    // 构造函数私有化
	{
		cout << "构造对象...." << endl;
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
	static SingleTon* m_singleton;   // 提供情态指针
	static SingleTon* GetInsance()   // 提供情态方法
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
		cout << "测试 调用...\n";
	}

private:
	SingleTon()                    // 构造函数私有化
	{
		cout << "构造对象...." << endl;
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