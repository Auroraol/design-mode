#include <iostream>
#include <vector>
#include <string>

using namespace std;

// 迭代器类
template <class T, class U>
class Iterator
{
public:
	typedef typename vector<T>::iterator iter_type;  // 别名
	Iterator(U* data, bool reverse = false) : m_data(data), iter(data->m_data.begin()) {}
	void Begin()
	{
		iter = m_data->m_data.begin();
	}

	void Next()
	{
		iter++;
	}
	bool End()
	{
		return (iter == m_data->m_data.end());
	}
	iter_type Current()
	{
		return iter;
	}

private:
	U* m_data;
	iter_type iter;
};

// 容器类
template<class T>
class Container
{
	friend class Iterator<T, Container>;
public:
	void Add(T data)
	{
		m_data.push_back(data);
	}
	Iterator<T, Container>* CreateIterator()
	{
		return new Iterator<T, Container>(this);
	}
protected:
	vector<T> m_data;
};

// 自定义数据
class Data
{
public:
	Data(int data = 0) : m_data(data) {}
	void SetData(int data)
	{
		m_data = data;
	}
	int GetData()
	{
		return m_data;
	}
private:
	int m_data;
};

int main(void)
{
	Container<int> intData;
	for (int i = 0; i < 10; i++)
	{
		intData.Add(i);
	}
	Iterator<int, Container<int>>* iter = intData.CreateIterator();

	for (iter->Begin(); !iter->End(); iter->Next())
	{
		cout << *iter->Current();
	}
	cout << endl;

	// 自定义类型
	Container<Data> testData;
	testData.Add(Data(198));
	testData.Add(Data(666));
	testData.Add(Data(888));
	Iterator<Data, Container<Data>>* iter2 = testData.CreateIterator();

	for (iter2->Begin(); !iter2->End(); iter2->Next())
	{
		cout << iter2->Current()->GetData();
	}
	cout << endl;

	return 0;
}