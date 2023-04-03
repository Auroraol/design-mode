#include <iostream>
#include <string>

using namespace std;

// 电源插头: 三插头和两插头的适配
class TreeOuttlet
{
public:
	TreeOuttlet() {}
	~TreeOuttlet() {}
	void ThreeOutletCharge()
	{
		cout << "开始三插头充电....." << endl;
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
		cout << "开始两插头充电...." << endl;
	};
};

// 方式1: 对于对象做适配(两插头适配三插头)
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
		cout << "三插头转换为两插头" << endl;
	}

protected:
	TreeOuttlet* pOut;
};

#endif // 0

// 对于类做适配(多继承的方式)
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
		cout << "三插头转换为两插头:" << endl;
	}
};

int main(void)
{
#if 0

	//对于对象做适配
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