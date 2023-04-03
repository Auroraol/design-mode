#include <iostream>
#include <string>
#include <vector>

using namespace std;

// ����¼��
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

//ԭ��������
class Chess
{
public:
	Chess(string name, pair<int, int> pos) : name(name), pos(pos) {}
	// �������:
	//
	//��һ��
	void SetChess(string name, pair<int, int> pos)
	{
		this->name = name;
		this->pos = pos;
	}
	//����
	Memento* saveState()
	{
		return new Memento(name, pos);
	}

	//����
	void Restore(Memento* memento)
	{
		name = memento->GetName();
		pos = memento->GetPos();
	}

protected:
	string name;
	pair<int, int> pos;
};

// �ۺϹ�����
//������
class Caretaker
{
public:
	// �浵
	void AddMemento(Memento* memento)
	{
		//����һ�»��˲���
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
	// ����
	Memento* GetMemento(int index)
	{
		// ����Ҫ��������
		step = index;
		return mem[step]; //���ʵ�
	}
	void Show()
	{
		for (int i = 0; i < step; i++)
		{
			cout << "step:" << i + 1 << "��" << endl;
			mem[i]->Show();
		}
	}
protected:
	vector<Memento*> mem;
	static int step;  // ֻ������û�ж���
};
int Caretaker::step = 0; //����

int main(void)
{
	Chess* pc = new Chess("��", {4,3});
	Caretaker* pcaretaker = new Caretaker;
	pcaretaker->AddMemento(pc->saveState());
	pcaretaker->Show();
	cout << endl;
	pc->SetChess("��", {3,3});
	pcaretaker->AddMemento(pc->saveState());
	pcaretaker->Show();

	cout << endl;
	pc->SetChess("��", {6,6});
	pcaretaker->AddMemento(pc->saveState());
	pcaretaker->Show();

	// ����
	cout << endl;
	cout << "����" << endl;
	pc->Restore(pcaretaker->GetMemento(1));
	pcaretaker->Show();

	while (1);
	return 0;
}