#include <iostream>
#include <string>

using namespace std;

//1.抽象原型类
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

//2.变化
class SunwuKong :public Monkey
{
public:
	SunwuKong(string name) : m_name(name)
	{
	}
	SunwuKong(const SunwuKong& other)
	{
		//深浅拷贝
		m_name = other.m_name;  // 浅拷贝
		// 一旦拷贝的对象当中含有指针，并且做了内存申请，必须采用深拷贝
	}

	void Play()
	{
		cout << "name: " << m_name << " 在玩金箍棒" << endl;
	}

	Monkey* Clone()
	{
		//调用拷贝构造函数
		return new SunwuKong(*this);
	}
private:
	string m_name;
};

#if 1

int main()
{
	Monkey* monkey = new SunwuKong("齐天大圣");
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