// 三平台通讯
#include <iostream>
#include <string>

using namespace std;

//转发协议
enum class Message   // 新标准的枚举型
{
	ATW_MESSAGE, //App-->Win
	ATM_MESSAGE, //App-->Mac
	WTM_MESSAGE  //Win-->Mac
};

class AbstractModule;
//提供转发接口父类
class AbstractMediator
{//中介者
public:
	virtual void Transmit(Message message, AbstractModule* pm) = 0;
};

//模块的父类
class AbstractModule
{
public:
	AbstractModule(AbstractMediator* pm) : pm(pm) {}
	void SendMessage(Message message)
	{
		pm->Transmit(message, this);  // 虚函数自动匹配
	}
	// 具体的类具体接受
	virtual void AcceptMessage(Message message) = 0;

protected:
	AbstractMediator* pm; // 中间
};

// 具体
class App :public AbstractModule
{
public:
	App(AbstractMediator* pM) :AbstractModule(pM) {}
	void AcceptMessage(Message message)
	{
		switch (message)
		{
		case Message::ATM_MESSAGE:
			cout << "[App to Mac]\n";
			break;
		case Message::WTM_MESSAGE:
			cout << "[App to Mac]\n";
			break;
		}
	}
};

class Win :public AbstractModule
{
public:
	Win(AbstractMediator* pM) :AbstractModule(pM) {}
	void AcceptMessage(Message message)
	{
		switch (message)
		{
		case Message::ATW_MESSAGE:
			cout << "[App to Win]\n";
			break;
		case Message::WTM_MESSAGE:
			cout << "[Win to Mac]\n";
			break;
		}
	}
};

class Mac :public AbstractModule
{
public:
	Mac(AbstractMediator* pM) :AbstractModule(pM) {}
	void AcceptMessage(Message message)
	{
		switch (message)
		{
		case Message::ATW_MESSAGE:
			cout << "[App to Mac]\n";
			break;
		case Message::WTM_MESSAGE:
			cout << "[Win to Mac]\n";
			break;
		}
	}
};

//中介者类实现
class ConcreteMediaton :public AbstractMediator
{
public:
	// 为中介者设定块
	void SetModuleApp(AbstractModule* app)
	{
		this->app = app;
	}
	void SetModuleWin(AbstractModule* win)
	{
		this->win = win;
	}
	void SetModuleMac(AbstractModule* mac)
	{
		this->mac = mac;
	}
	// 转发具体实现
	void Transmit(Message message, AbstractModule* pm)
	{
		switch (message)
		{
		case Message::ATW_MESSAGE:
		{
			App* app = dynamic_cast<App*> (pm);  // 强转子类
			if (app != NULL)
			{//App-->Win
				win->AcceptMessage(message);
			}
			else
				this->app->AcceptMessage(message);
			break;
		}
		case Message::ATM_MESSAGE:
		{
			App* app = dynamic_cast<App*> (pm);  // 强转子类
			if (app != NULL)
			{ //App-->Mac
				mac->AcceptMessage(message);
			}
			else
				this->app->AcceptMessage(message);
			break;
		}

		case Message::WTM_MESSAGE:
		{
			Win* win = dynamic_cast<Win*> (pm);  // 强转子类
			if (win != NULL)
			{
				mac->AcceptMessage(message);
			}
			else
				this->win->AcceptMessage(message);
			break;
		}
		}
	}

protected:
	AbstractModule* app = nullptr;
	AbstractModule* win = nullptr;
	AbstractModule* mac = nullptr;
};

int main(void)
{
	AbstractMediator* pM = new ConcreteMediaton;
	//指定中介者
	AbstractModule* app = new App(pM);
	AbstractModule* win = new Win(pM);
	AbstractModule* mac = new Mac(pM);

	//为中介者设定模块
	ConcreteMediaton* pC = dynamic_cast<ConcreteMediaton*>(pM);
	pC->SetModuleApp(app);
	pC->SetModuleMac(mac);
	pC->SetModuleWin(win);
	//不同模块间进行通信

	app->SendMessage(Message::ATW_MESSAGE);
	app->SendMessage(Message::ATW_MESSAGE);
	win->SendMessage(Message::WTM_MESSAGE);
	win->SendMessage(Message::ATM_MESSAGE);
	mac->SendMessage(Message::ATW_MESSAGE);
	return 0;
}