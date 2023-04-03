#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Boss;

// �۲�����
class Staff
{
public:
	Staff(string name, Boss* pBoss) : name(name), pBoss(pBoss) {}
	void Update(string action)
	{
		cout << name << "�յ�ѶϢ: " << action;
		if (action == "�ϰ�����߽���")
			cout << "--->�������湤��ģʽ" << endl;
		if (action == "�ϰ��߳�����")
			cout << "--->��������ģʽ" << endl;
	}
private:
	string name;
	Boss* pBoss;
};

//���۲���
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
			v->Update(action);  // ����״̬
		}
	}

	// ������Ϊ
	void SetAction(string action)
	{
		this->action = action;
		Notify(action);
	}
private:
	string action;
	vector<Staff*> staff;  //�۲��߶���
};

int main(void)
{
	// �������۲���
	Boss* pBoss = new Boss;

	// �����۲���
	Staff* p1 = new Staff("LL", pBoss);
	Staff* p2 = new Staff("FF", pBoss);
	Staff* p3 = new Staff("jj", pBoss);

	// ��������
	pBoss->Addobserver(p1);
	pBoss->Addobserver(p2);
	pBoss->Addobserver(p3);
	pBoss->SetAction("�ϰ�����߽���");
	pBoss->SetAction("�ϰ��߳�����");

	return 0;
}