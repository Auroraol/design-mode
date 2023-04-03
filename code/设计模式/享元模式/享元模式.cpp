#include <iostream>
#include <string>
#include <sstream>
#include <map>
#include <initializer_list>  // �б�

using namespace std;

// �������Գ���, ��Ϊ������
class SharaState
{
public:
	SharaState(const string brand, const string model, const string color) :
		brand(brand), model(model), color(color)
	{
	}

	const string getBrand() const
	{
		return brand;
	}
	const string getModel() const
	{
		return model;
	}
	const string getColor() const
	{
		return color;
	}

	friend ostream& operator<<(ostream& out, const SharaState ss)
	{
		return out << "" << ss.brand << " " << ss.model << " " << ss.color << endl;
	}

private:
	string brand; //Ʒ��
	string model; //�ͺ�
	string color; //��ɫ
};

class UniqueState
{
public:
	UniqueState(const string owner, const string plates) : owner(owner), plates(plates) {}
	const string getOwner() const
	{
		return owner;
	}
	const string getPlates() const
	{
		return plates;
	}
	friend ostream& operator<<(ostream& os, const UniqueState ss)
	{
		return os << "[" << ss.owner << "," << ss.plates << "]";
	}

private:
	string owner;   // ����
	string plates;  // ���ź�
};

// ��Ԫ��
class FlyWeight
{
private:
	SharaState* sharedstate;
public:
	// ��������
	FlyWeight(const SharaState* shardstate) : sharedstate(new SharaState(*shardstate))
	{
	}
	// ��������
	// ���Թ���
	FlyWeight(const FlyWeight& other) : sharedstate(new SharaState(*other.sharedstate))
	{
	}
	//
	SharaState* GetSharedState()const
	{
		return sharedstate;
	}
	void Show(const UniqueState& uniquestate)const
	{
		cout << "��������:" << *sharedstate << endl;
		cout << "ר������:" << uniquestate << endl;
	}
};

// ��Ԫ����,�ۺϹ�������
class FlyweightFactory
{
private:
	map <string, FlyWeight> flyweight;  // ��������
	string GetKey(const SharaState& s) const
	{
		return 	s.getBrand() + '_' + s.getModel() + '_' + s.getColor();
	}

public:
	// ���б��ʼ��
	FlyweightFactory(initializer_list<SharaState> shardstate)
	{
		for (auto v : shardstate)
		{
			this->flyweight.insert(pair<string, FlyWeight>(this->GetKey(v), FlyWeight(&v)));
		}
	}

	FlyWeight getFlyWeight(const SharaState& sharedstate)
	{
		string key = this->GetKey(sharedstate);
		if (this->flyweight.find(key) == this->flyweight.end())
		{
			cout << "����δ�ҵ������ʽ" << endl;
			this->flyweight.insert(pair<string, FlyWeight>(key, FlyWeight(&sharedstate)));
			cout << "��һ�����ɹ�" << endl;
		}
		else
		{// ��ֱ�ӹ������
			cout << "�����ҵ������ʽ" << endl;
		}
		return this->flyweight.at(key);
	}

	// ��ӡ
	void ListFlyweights() const
	{
		int count = this->flyweight.size();
		cout << "��������Ϣ:" << endl;
		for (auto pair : this->flyweight)
		{
			cout << pair.first << "\n";
		}
	}
};

void addCar(FlyweightFactory& ff, const string& plates, const string& owner, const string& brand, const string& model, const string& color)
{
	cout << "����ƥ����:" << endl;
	auto flyweight = ff.getFlyWeight({brand, model,color});
	flyweight.Show({owner,plates});
}

int main(void)
{
	FlyweightFactory* f = new FlyweightFactory(
		{
			{"ѩ","Camaro2020","pink"},
			{ "��","C43","black" },
			{ "��","C63","red" },
			{ "��","M6","red" },
			{ "��","X7", "white" },
		});
	addCar(*f, "DK88888", "ʯ", "��", "M6", "red");
	addCar(*f, "DK66666", "��", "��", "X7", "red");
	f->ListFlyweights();
	delete f;

	while (1);
	return 0;
}