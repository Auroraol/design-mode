#include <iostream>
#include <string>

using namespace std;

// ��Դ��ͷ: ����ͷ������ͷ������
class TreeOuttlet
{
public:
	TreeOuttlet() {}
	~TreeOuttlet() {}
	void ThreeOutletCharge()
	{
		cout << "��ʼ����ͷ���....." << endl;
	}
private:
};

//
class AbstractTwoOutlet
{
public:
	virtual void TwoOutletCharge() = 0;
};

class TowOutlet : public AbstractTwoOutlet
{
public:
	void TwoOutletCharge()
	{
		cout << "��ʼ����ͷ���...." << endl;
	};
};

// ��ʽ1: ���ڶ���������(����ͷ��������ͷ)
#if 0

class OutletAdapterObject : public AbstractTwoOutlet
{
public:
	OutletAdapterObject(TreeOuttlet* pOut)
	{
		this->pOut = pOut;
	}

	void TwoOutletCharge()
	{
		Convertor();
		pOut->ThreeOutletCharge();
	}
	void Convertor()
	{
		cout << "����ͷת��Ϊ����ͷ" << endl;
	}

protected:
	TreeOuttlet* pOut;
};

#endif // 0

// ������������(��̳еķ�ʽ)
class OutletAdapterObject : public AbstractTwoOutlet, public TreeOuttlet
{
public:
	void TwoOutletCharge()
	{
		Convertor();
		ThreeOutletCharge();
	}

	void Convertor()
	{
		cout << "����ͷת��Ϊ����ͷ:" << endl;
	}
};

int main(void)
{
#if 0

	//���ڶ���������
	TreeOuttlet* pThree = new TreeOuttlet;
	pThree->ThreeOutletCharge();
	AbstractTwoOutlet* pTwo = new OutletAdapterObject(pThree);
	pTwo->TwoOutletCharge();
#endif // 0
	//

	TreeOuttlet* pThree = new TreeOuttlet;
	pThree->ThreeOutletCharge();
	AbstractTwoOutlet* pTwo = new OutletAdapterObject;
	pTwo->TwoOutletCharge();

	return 0;
}