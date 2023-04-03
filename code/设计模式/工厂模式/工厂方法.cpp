#include <iostream>

using namespace std;

//造火箭造飞机

// 抽象产品类
class AbstractProduct
{
public:
	virtual void makeProduct() = 0;
	virtual ~AbstractProduct() {}
};

// 抽象工厂
class AbstractFavtor
{
public:
	virtual AbstractProduct* createProduct() = 0;
	virtual ~AbstractFavtor() {}
};

//具体产品类
//飞机
class PlaneProduct : public AbstractProduct
{
public:
	void makeProduct()
	{
		cout << "飞机\n";
	}
};

class PlaneFactory : public AbstractFavtor
{
	AbstractProduct* createProduct()
	{
		return new PlaneProduct;
	}
};

//火箭
class RocketProduct : public AbstractProduct
{
public:
	void makeProduct()
	{
		cout << "火箭\n";
	}
};

class RocketFactory : public AbstractFavtor
{
	AbstractProduct* createProduct()
	{
		return new RocketProduct;
	}
};

void test(AbstractFavtor* factor, AbstractProduct* product)
{
	factor->createProduct();
	product->makeProduct();
}

#if 1

int main(void)
{
	AbstractFavtor* factor = new PlaneFactory;   // 工厂
	AbstractProduct* product = factor->createProduct();  // 创建产品
	product->makeProduct();

	factor = new RocketFactory;
	product = factor->createProduct();
	product->makeProduct();

	return 0;
}

#endif // 0