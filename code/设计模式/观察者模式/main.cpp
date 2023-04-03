#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Boss;

// 观察者类
class Staff
{
public:
	Staff(string name, Boss* pBoss) : name(name), pBoss(pBoss) {}
	void Update(string action)
	{
		cout << name << "收到讯息: " << action;
		if (action == "老板大门走进来")
			cout << "--->开启认真工作模式" << endl;
		if (action == "老板走出大门")
			cout << "--->开启摸鱼模式" << endl;
	}
private:
	string name;
	Boss* pBoss;
};

//被观察者
class Boss
{
public:
	void Addobserver(Staff* pstaff)
	{
		staff.push_back(pstaff);
	}
	// each
	void Notify(string action)
	{
		for (auto v : staff)
		{
			v->Update(action);  // 更新状态
		}
	}

	// 设置行为
	void SetAction(string action)
	{
		this->action = action;
		Notify(action);
	}
private:
	string action;
	vector<Staff*> staff;  //观察者队列
};

int main(void)
{
	// 创建被观察者
	Boss* pBoss = new Boss;

	// 创建观察者
	Staff* p1 = new Staff("LL", pBoss);
	Staff* p2 = new Staff("FF", pBoss);
	Staff* p3 = new Staff("jj", pBoss);

	// 建立关联
	pBoss->Addobserver(p1);
	pBoss->Addobserver(p2);
	pBoss->Addobserver(p3);
	pBoss->SetAction("老板大门走进来");
	pBoss->SetAction("老板走出大门");

	return 0;
}