#include <iostream>
#include <string>

using namespace std;

//1.����ԭ����
class Monkey
{
public:
	Monkey() = default;
	virtual ~Monkey()
	{
	}
	virtual Monkey* Clone() = 0;
	virtual void Play() = 0;
};

//2.�仯
class SunwuKong :public Monkey
{
public:
	SunwuKong(string name) : m_name(name)
	{
	}
	SunwuKong(const SunwuKong& other)
	{
		//��ǳ����
		m_name = other.m_name;  // ǳ����
		// һ�������Ķ����к���ָ�룬���������ڴ����룬����������
	}

	void Play()
	{
		cout << "name: " << m_name << " ����𹿰�" << endl;
	}

	Monkey* Clone()
	{
		//���ÿ������캯��
		return new SunwuKong(*this);
	}
private:
	string m_name;
};

#if 1

int main()
{
	Monkey* monkey = new SunwuKong("�����ʥ");
	Monkey* monkey1 = monkey->Clone();
	Monkey* monkey2 = monkey->Clone();
	monkey1->Play();
	monkey2->Play();

	delete monkey;
	delete monkey1;
	delete monkey2;
	return 0;
}
#endif // 0