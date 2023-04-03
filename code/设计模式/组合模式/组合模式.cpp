#include <iostream>
#include <list>
#include <string>

using namespace std;

class Root
{
public:
	virtual void display() = 0;
	virtual void add(Root* file) = 0;
	virtual void remove(Root* file) = 0;
	virtual list<Root*> getChild() = 0;
};

class File : public Root
{
public:
	File(string name) : name(name) {}
	void display()
	{
		cout << name << endl;
	}
	void add(Root* file) {}
	void remove(Root* file) {}
	list<Root*> getChild() { return m_list; }

protected:
	string name;
	list<Root* > m_list;
};

class Floder : public Root
{
public:
	Floder(string name) : name(name) {}
	void display()
	{
		cout << name << endl;
	}
	void add(Root* file)
	{
		m_list.push_back(file);
	}
	void remove(Root* file)
	{
		m_list.pop_back();
	}
	list<Root*> getChild() { return m_list; }

private:
	string name;
	list<Root*> m_list;
};

void showTree(Root* file, int level)
{
	list<Root*> root;
	int i = 0;
	for (int i = 0; i < level; i++)
	{
		cout << "--";
	}
	file->display();
	root = file->getChild();
	if (!root.empty())
	{
		for (auto v : root)
		{
			if (v->getChild().empty())
			{
				for (int i = 0; i <= level; i++)
				{
					cout << "--";
				}
				v->display();
			}
			else
			{
				showTree(v, level + 1);
			}
		}
	}
}

int main(void)
{
	Floder* root = new Floder("C:");
	Floder* d1 = new Floder("din1");
	File* t1 = new File("t1.txt");
	//
	Floder* d2 = new Floder("dir2");
	File* t2 = new File("t2.txt");
	root->add(d1);
	root->add(d2);
	//
	d1->add(t1);
	d2->add(t2);
	d2->add(t1);
	showTree(root, 0);
	return 0;
}