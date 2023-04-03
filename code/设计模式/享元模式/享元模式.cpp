#include <iostream>
#include <string>
#include <sstream>
#include <map>
#include <initializer_list>  // 列表

using namespace std;

// 事物属性抽象, 分为两部分
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
	string brand; //品牌
	string model; //型号
	string color; //颜色
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
	string owner;   // 车主
	string plates;  // 车排号
};

// 享元类
class FlyWeight
{
private:
	SharaState* sharedstate;
public:
	// 拷贝构造
	FlyWeight(const SharaState* shardstate) : sharedstate(new SharaState(*shardstate))
	{
	}
	// 拷贝构造
	// 属性共享
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
		cout << "共享数据:" << *sharedstate << endl;
		cout << "专有数据:" << uniquestate << endl;
	}
};

// 享元工厂,综合管理数据
class FlyweightFactory
{
private:
	map <string, FlyWeight> flyweight;  // 共享容器
	string GetKey(const SharaState& s) const
	{
		return 	s.getBrand() + '_' + s.getModel() + '_' + s.getColor();
	}

public:
	// 用列表初始化
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
			cout << "车库未找到这个款式" << endl;
			this->flyweight.insert(pair<string, FlyWeight>(key, FlyWeight(&sharedstate)));
			cout << "第一次入库成功" << endl;
		}
		else
		{// 有直接共享就行
			cout << "车库找到这个款式" << endl;
		}
		return this->flyweight.at(key);
	}

	// 打印
	void ListFlyweights() const
	{
		int count = this->flyweight.size();
		cout << "车库总信息:" << endl;
		for (auto pair : this->flyweight)
		{
			cout << pair.first << "\n";
		}
	}
};

void addCar(FlyweightFactory& ff, const string& plates, const string& owner, const string& brand, const string& model, const string& color)
{
	cout << "车型匹配结果:" << endl;
	auto flyweight = ff.getFlyWeight({brand, model,color});
	flyweight.Show({owner,plates});
}

int main(void)
{
	FlyweightFactory* f = new FlyweightFactory(
		{
			{"雪","Camaro2020","pink"},
			{ "奔","C43","black" },
			{ "奔","C63","red" },
			{ "宝","M6","red" },
			{ "宝","X7", "white" },
		});
	addCar(*f, "DK88888", "石", "宝", "M6", "red");
	addCar(*f, "DK66666", "里", "宝", "X7", "red");
	f->ListFlyweights();
	delete f;

	while (1);
	return 0;
}