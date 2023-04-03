// ��ƽ̨ͨѶ
#include <iostream>
#include <string>

using namespace std;

//ת��Э��
enum class Message   // �±�׼��ö����
{
	ATW_MESSAGE, //App-->Win
	ATM_MESSAGE, //App-->Mac
	WTM_MESSAGE  //Win-->Mac
};

class AbstractModule;
//�ṩת���ӿڸ���
class AbstractMediator
{//�н���
public:
	virtual void Transmit(Message message, AbstractModule* pm) = 0;
};

//ģ��ĸ���
class AbstractModule
{
public:
	AbstractModule(AbstractMediator* pm) : pm(pm) {}
	void SendMessage(Message message)
	{
		pm->Transmit(message, this);  // �麯���Զ�ƥ��
	}
	// �������������
	virtual void AcceptMessage(Message message) = 0;

protected:
	AbstractMediator* pm; // �м�
};

// ����
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

//�н�����ʵ��
class ConcreteMediaton :public AbstractMediator
{
public:
	// Ϊ�н����趨��
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
	// ת������ʵ��
	void Transmit(Message message, AbstractModule* pm)
	{
		switch (message)
		{
		case Message::ATW_MESSAGE:
		{
			App* app = dynamic_cast<App*> (pm);  // ǿת����
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
			App* app = dynamic_cast<App*> (pm);  // ǿת����
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
			Win* win = dynamic_cast<Win*> (pm);  // ǿת����
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
	//ָ���н���
	AbstractModule* app = new App(pM);
	AbstractModule* win = new Win(pM);
	AbstractModule* mac = new Mac(pM);

	//Ϊ�н����趨ģ��
	ConcreteMediaton* pC = dynamic_cast<ConcreteMediaton*>(pM);
	pC->SetModuleApp(app);
	pC->SetModuleMac(mac);
	pC->SetModuleWin(win);
	//��ͬģ������ͨ��

	app->SendMessage(Message::ATW_MESSAGE);
	app->SendMessage(Message::ATW_MESSAGE);
	win->SendMessage(Message::WTM_MESSAGE);
	win->SendMessage(Message::ATM_MESSAGE);
	mac->SendMessage(Message::ATW_MESSAGE);
	return 0;
}