#include <iostream>
using namespace std;

class CSyntaxParser
{
public:
	void syntaxParser()
	{
		cout << "�﷨������...." << endl;
	}
};

class MidCode
{
public:
	void midCode()
	{
		cout << "�����м����..." << endl;
	}
};

class CAssemblyCode
{
public:
	void assemblyCode()
	{
		cout << "���ɻ���ļ�..." << endl;
	}
};

class Clink
{
public:
	void linkSystem()
	{
		cout << "���ӳɿ�ִ���ļ�..." << endl;
	}
};

class Fade
{
public:
	void build()
	{
		CSyntaxParser p;
		MidCode m;
		CAssemblyCode a;
		Clink c;
		p.syntaxParser();
		m.midCode();
		a.assemblyCode();
		c.linkSystem();

		cout << "����������" << endl;
	}
};
int main(void)
{
	Fade f;
	f.build();
	return 0;
}