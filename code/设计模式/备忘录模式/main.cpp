#include <iostream>
#include <string>
#include <vector>

using namespace std;

// 备忘录类
class Memento
{
public:
	Memento(string name, pair<int, int> pos) : name(name), pos(pos) {}
	string GetName()
	{
		return name;
	}
	pair<int, int> GetPos()
	{
		return pos;
	}
	void Show()
	{
		cout << name << ":(" << pos.first << "," << pos.second << ")";
	}
private:
	string name;
	pair<int, int> pos;
};

//原生对象类
class Chess
{
public:
	Chess(string name, pair<int, int> pos) : name(name), pos(pos) {}
	// 下棋操作:
	//
	//走一下
	void SetChess(string name, pair<int, int> pos)
	{
		this->name = name;
		this->pos = pos;
	}
	//保存
	Memento* saveState()
	{
		return new Memento(name, pos);
	}

	//回退
	void Restore(Memento* memento)
	{
		name = memento->GetName();
		pos = memento->GetPos();
	}

protected:
	string name;
	pair<int, int> pos;
};

// 综合管理类
//管理类
class Caretaker
{
public:
	// 存档
	void AddMemento(Memento* memento)
	{
		//处理一下回退操作
		if (step < mem.size())
		{
			mem[step] = memento;
		}
		else
		{
			mem.push_back(memento);
		}
		step++;
	}
	// 读档
	Memento* GetMemento(int index)
	{
		// 步数要满足条件
		step = index;
		return mem[step]; //访问到
	}
	void Show()
	{
		for (int i = 0; i < step; i++)
		{
			cout << "step:" << i + 1 << "手" << endl;
			mem[i]->Show();
		}
	}
protected:
	vector<Memento*> mem;
	static int step;  // 只是声明没有定义
};
int Caretaker::step = 0; //定义

int main(void)
{
	Chess* pc = new Chess("车", {4,3});
	Caretaker* pcaretaker = new Caretaker;
	pcaretaker->AddMemento(pc->saveState());
	pcaretaker->Show();
	cout << endl;
	pc->SetChess("马", {3,3});
	pcaretaker->AddMemento(pc->saveState());
	pcaretaker->Show();

	cout << endl;
	pc->SetChess("炮", {6,6});
	pcaretaker->AddMemento(pc->saveState());
	pcaretaker->Show();

	// 回退
	cout << endl;
	cout << "回退" << endl;
	pc->Restore(pcaretaker->GetMemento(1));
	pcaretaker->Show();

	while (1);
	return 0;
}