#include <iostream>
using namespace std;

class CSyntaxParser
{
public:
	void syntaxParser()
	{
		cout << "语法分析中...." << endl;
	}
};

class MidCode
{
public:
	void midCode()
	{
		cout << "生成中间代码..." << endl;
	}
};

class CAssemblyCode
{
public:
	void assemblyCode()
	{
		cout << "生成汇编文件..." << endl;
	}
};

class Clink
{
public:
	void linkSystem()
	{
		cout << "链接成可执行文件..." << endl;
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

		cout << "程序运行中" << endl;
	}
};
int main(void)
{
	Fade f;
	f.build();
	return 0;
}