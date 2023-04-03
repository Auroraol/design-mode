#include <iostream>
#include <string>
using namespace std;

class Color
{// ��ɫ
public:
	virtual void FillColor() = 0;
};

class Red : public Color
{
public:
	Red() : colorType("RED") {}
	void FillColor()
	{
		cout << "�����ɫ:" << colorType;
	}

private:
	string colorType;
};

class Blue : public Color
{
public:
	Blue() : colorType("Blue") {}
	void FillColor()
	{
		cout << "�����ɫ:" << colorType;
	}

private:
	string colorType;
};

class Shape
{// ��״
public:
	virtual void ShowShape() = 0;
	virtual void SetColor(Color* color) = 0;
protected:
	virtual void DrawShape() = 0;
	virtual void DrawColor() = 0;
	Color* color;
};
// ��׼����
class Circle : public Shape
{// Բ
public:
	Circle() : shapeType("Cricle") {}
	void ShowShape()
	{
		DrawShape();
		DrawColor();
	};

	void SetColor(Color* color)
	{
		this->color = color;
	};
private:
	void DrawShape()
	{
		cout << "����:  " << shapeType << endl;
	}

	void DrawColor()
	{
		this->color->FillColor();
	}
	string shapeType;
};

class Rect : public Shape
{// ����
public:
	Rect() : shapeType("Rect") {}
	void ShowShape()
	{
		DrawShape();
		DrawColor();
	};

	void SetColor(Color* color)
	{
		this->color = color;
	};
private:
	void DrawShape()
	{
		cout << "����:  " << shapeType << endl;
	}

	void DrawColor()
	{
		this->color->FillColor();
	}
	string shapeType;
};

int main(void)
{
	cout << "����Բ:" << endl;
	Shape* shape = new Circle;
	shape->SetColor(new Red);
	shape->ShowShape();
	shape->SetColor(new Blue);
	shape->ShowShape();
	delete shape;
	/*----------------------*/
	cout << "���ƾ���:" << endl;
	Shape* shape2 = new Rect;
	shape2->SetColor(new Red);
	shape2->ShowShape();
	shape2->SetColor(new Blue);
	shape2->ShowShape();
	delete shape2;

	while (1);
	return 0;
}