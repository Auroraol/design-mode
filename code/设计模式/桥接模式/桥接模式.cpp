#include <iostream>
#include <string>
using namespace std;

class Color
{// 颜色
public:
	virtual void FillColor() = 0;
};

class Red : public Color
{
public:
	Red() : colorType("RED") {}
	void FillColor()
	{
		cout << "填充颜色:" << colorType;
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
		cout << "填充颜色:" << colorType;
	}

private:
	string colorType;
};

class Shape
{// 形状
public:
	virtual void ShowShape() = 0;
	virtual void SetColor(Color* color) = 0;
protected:
	virtual void DrawShape() = 0;
	virtual void DrawColor() = 0;
	Color* color;
};
// 精准抽象
class Circle : public Shape
{// 圆
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
		cout << "绘制:  " << shapeType << endl;
	}

	void DrawColor()
	{
		this->color->FillColor();
	}
	string shapeType;
};

class Rect : public Shape
{// 矩形
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
		cout << "绘制:  " << shapeType << endl;
	}

	void DrawColor()
	{
		this->color->FillColor();
	}
	string shapeType;
};

int main(void)
{
	cout << "绘制圆:" << endl;
	Shape* shape = new Circle;
	shape->SetColor(new Red);
	shape->ShowShape();
	shape->SetColor(new Blue);
	shape->ShowShape();
	delete shape;
	/*----------------------*/
	cout << "绘制矩形:" << endl;
	Shape* shape2 = new Rect;
	shape2->SetColor(new Red);
	shape2->ShowShape();
	shape2->SetColor(new Blue);
	shape2->ShowShape();
	delete shape2;

	while (1);
	return 0;
}