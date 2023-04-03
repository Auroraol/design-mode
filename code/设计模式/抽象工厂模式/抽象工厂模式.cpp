#include <iostream>

using namespace std;

// 抽象产品
class Product
{
public:
	virtual void show() = 0;
};

// 抽象产品族1:
class KeyBoard : public Product
{
};
//具体产品
class LogiKeyBoard : public KeyBoard
{
	void show()
	{
		cout << "罗技键盘......" << endl;
	}
};

class RazerKeyBoard :public KeyBoard
{
	void show()
	{
		cout << "雷蛇键盘..." << endl;
	}
};

//抽象产品族2:
class Mouse : public Product
{
};
// 具体产品
class  LogiMouse : public Mouse
{
	void show()
	{
		cout << "罗技鼠标......" << endl;
	}
};

class RazerMouse :public Mouse
{
	void show()
	{
		cout << "雷蛇鼠标..." << endl;
	}
};

// 抽象工厂
class Factory
{
public:
	virtual KeyBoard* createKeyBoard() = 0;
	virtual Mouse* createMouse() = 0;
};

// 具体工厂:
// 罗技工厂
class LogiFactory : public Factory
{
	KeyBoard* createKeyBoard()
	{
		return new LogiKeyBoard;
	}
	Mouse* createMouse()
	{
		return new LogiMouse;
	}
};

//雷蛇工厂
class RazerFactory :public Factory
{
	KeyBoard* createKeyBoard()
	{
		return new RazerKeyBoard;
	}
	Mouse* createMouse()
	{
		return new  RazerMouse;
	}
};

#if 1
int main(void)
{
	Factory* factory = new LogiFactory;  // 罗技工厂
	KeyBoard* keyBoard = factory->createKeyBoard();
	Mouse* mouse = factory->createMouse();
	keyBoard->show();
	mouse->show();
	delete factory;
	delete keyBoard;
	delete mouse;

	factory = new RazerFactory;    // 雷蛇工厂
	keyBoard = factory->createKeyBoard();
	mouse = factory->createMouse();
	keyBoard->show();
	mouse->show();
	delete factory;
	delete keyBoard;
	delete mouse;

	return 0;
}
#endif // 0