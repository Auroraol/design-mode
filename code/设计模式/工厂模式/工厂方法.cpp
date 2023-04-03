#include <iostream>

using namespace std;

//������ɻ�

// �����Ʒ��
class AbstractProduct
{
public:
	virtual void makeProduct() = 0;
	virtual ~AbstractProduct() {}
};

// ���󹤳�
class AbstractFavtor
{
public:
	virtual AbstractProduct* createProduct() = 0;
	virtual ~AbstractFavtor() {}
};

//�����Ʒ��
//�ɻ�
class PlaneProduct : public AbstractProduct
{
public:
	void makeProduct()
	{
		cout << "�ɻ�\n";
	}
};

class PlaneFactory : public AbstractFavtor
{
	AbstractProduct* createProduct()
	{
		return new PlaneProduct;
	}
};

//���
class RocketProduct : public AbstractProduct
{
public:
	void makeProduct()
	{
		cout << "���\n";
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
	AbstractFavtor* factor = new PlaneFactory;   // ����
	AbstractProduct* product = factor->createProduct();  // ������Ʒ
	product->makeProduct();

	factor = new RocketFactory;
	product = factor->createProduct();
	product->makeProduct();

	return 0;
}

#endif // 0