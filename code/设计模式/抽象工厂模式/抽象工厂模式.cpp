#include <iostream>

using namespace std;

// �����Ʒ
class Product
{
public:
	virtual void show() = 0;
};

// �����Ʒ��1:
class KeyBoard : public Product
{
};
//�����Ʒ
class LogiKeyBoard : public KeyBoard
{
	void show()
	{
		cout << "�޼�����......" << endl;
	}
};

class RazerKeyBoard :public KeyBoard
{
	void show()
	{
		cout << "���߼���..." << endl;
	}
};

//�����Ʒ��2:
class Mouse : public Product
{
};
// �����Ʒ
class  LogiMouse : public Mouse
{
	void show()
	{
		cout << "�޼����......" << endl;
	}
};

class RazerMouse :public Mouse
{
	void show()
	{
		cout << "�������..." << endl;
	}
};

// ���󹤳�
class Factory
{
public:
	virtual KeyBoard* createKeyBoard() = 0;
	virtual Mouse* createMouse() = 0;
};

// ���幤��:
// �޼�����
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

//���߹���
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
	Factory* factory = new LogiFactory;  // �޼�����
	KeyBoard* keyBoard = factory->createKeyBoard();
	Mouse* mouse = factory->createMouse();
	keyBoard->show();
	mouse->show();
	delete factory;
	delete keyBoard;
	delete mouse;

	factory = new RazerFactory;    // ���߹���
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