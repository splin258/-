#pragma once
#include"stdafx.h"
class Grafobject // класс в которм хранятся основные функции (перемещение объекта, скрытие и показ объектаи прочее) и основные данные (координаты, фширина линии окантовки фигуры, цвет фигуры и её окантовки)
{
protected:
	int x_center;
	int y_center;
	int lineWidth;
	COLORREF lineCol;
	COLORREF fillCol;
	COLORREF drawLineColor;
	COLORREF drawFillColor;
public:
	 Grafobject(int x, int y)// в конструкторе класса задаём координаты
	{
		x_center = x;
		y_center = y;
	}
	void move(HWND hWnd, RECT rect)// перемещаем объект вправо на 50 единиц
	{
		x_center = x_center + 50;
		InvalidateRect(hWnd, &rect, TRUE);
	}
	void moveleft(HWND hWnd, RECT rect)// перемещаем объект влево на 50 единиц
	{
		x_center = x_center - 50;
		InvalidateRect(hWnd, &rect, TRUE);
	}
	void moveup(HWND hWnd, RECT rect)// перемещаем объект вверх на 50 единиц
	{
		y_center = y_center - 50;
		InvalidateRect(hWnd, &rect, TRUE);
	}
	void movedown(HWND hWnd, RECT rect)// перемещаем объект вниз на 50 единиц
	{
		y_center = y_center + 50;
		InvalidateRect(hWnd, &rect, TRUE);
	}
	void setWidth(int width)// задаём толщину линии
	{
		lineWidth = width;
	}
	void setLineColor(COLORREF color)// задаём цвет линии
	{
		lineCol = color;
	}
	void setFillColor(COLORREF color)// задаём цвет фигуры
	{
		fillCol = color;
	}
	void setCenter(int x, int y)// задаём центральные координаты
	{
		x_center = x;
		y_center = y;
	}
	void hide(HWND hWnd, RECT rect)// скрываем объект
	{
		drawLineColor = COLORREF(RGB(0, 0, 150));
		drawFillColor = COLORREF(RGB(0, 0, 150));
		InvalidateRect(hWnd, &rect, TRUE);
		
	}
	void show(HWND hWnd, RECT rect)// делаем объект видимым
	{
		drawLineColor = lineCol;
		drawFillColor = fillCol;
		InvalidateRect(hWnd, &rect, TRUE);
	}
	virtual void drawObject(HDC hdc) = 0;//виртьуальная функция отрисовки объекта
};


class Triangle :public Grafobject // это производный класс класса grafobject
{
	int width;
	int height;
	public:
		Triangle(int x , int y , int w , int h, int LineCol, int fill) :Grafobject(x, y)//задаём парамметры фигуры
		{
			x_center = x;
			y_center = y;
			width = w;
			height = h;
			lineCol = LineCol;
			fillCol = fill;
			drawLineColor = LineCol;
			drawFillColor = fill;
		}

		void drawObject(HDC hdc)//отрисовка объекта
		{
			HPEN hPen = CreatePen(PS_SOLID, 2, drawLineColor);
			HPEN holdPen = (HPEN)SelectObject(hdc, hPen);

			MoveToEx(hdc, x_center, y_center - height / 2, NULL);
			LineTo(hdc, x_center - width / 2, y_center + height / 2);
			LineTo(hdc, x_center + width / 2, y_center + height / 2);
			LineTo(hdc, x_center, y_center - height / 2);
			LOGBRUSH lb;
			lb.lbColor = drawFillColor;
			lb.lbStyle = BS_SOLID;
			HBRUSH hBrush;

			hBrush = CreateBrushIndirect(&lb);
			HBRUSH holdBrush = (HBRUSH)(SelectObject(hdc, hBrush));

			FloodFill(hdc, x_center, y_center, drawLineColor);
			DeleteObject(SelectObject(hdc, holdBrush));
			DeleteObject(SelectObject(hdc, holdPen));
		}
		
};



class
	rectangle : public Grafobject// это производный класс класса grafobject 
{
	int width; 
	int height; 
public:

	rectangle(int x, int y, int w, int h, int LineCol, int fill) :Grafobject(x, y)//задаём парамметры фигуры
	{
		x_center = x;
		y_center = y;
		width = w;
		height = h;

		lineCol = LineCol;
		fillCol = fill;
		drawLineColor = LineCol;
		drawFillColor = fill;
	}
	void drawObject(HDC hdc)//отрисовка объекта
	{
		HPEN hPen = CreatePen(PS_SOLID, 2, drawLineColor);
		HPEN holdPen = (HPEN)SelectObject(hdc, hPen);


		MoveToEx(hdc, x_center - width / 2, y_center + height / 2, NULL);
		LineTo(hdc, x_center - width / 2, y_center - height / 2);
		LineTo(hdc, x_center + width / 2, y_center - height / 2);
		LineTo(hdc, x_center + width / 2, y_center + height / 2);
		LineTo(hdc, x_center - width / 2, y_center + height / 2);

		LOGBRUSH lb;
		lb.lbColor = drawFillColor;
		lb.lbStyle = BS_SOLID;
		HBRUSH hBrush;

		hBrush = CreateBrushIndirect(&lb);
		HBRUSH holdBrush = (HBRUSH)(SelectObject(hdc, hBrush));

		FloodFill(hdc, x_center, y_center, drawLineColor);
		DeleteObject(SelectObject(hdc, holdBrush));
		DeleteObject(SelectObject(hdc, holdPen));

	}
};

class circle : public Grafobject// это производный класс класса grafobject 
{
	int radius;
public:

	circle(int x, int y, int r, int LineCol, int fill) :Grafobject(x, y)//задаём парамметры фигуры
	{
		x_center = x;
		y_center = y;
		radius = r;
		lineCol = LineCol;
		fillCol = fill;
		drawLineColor = LineCol;
		drawFillColor = fill;
	}
	void drawObject(HDC hdc)//отрисовка объекта
	{
		HPEN hPen = CreatePen(PS_SOLID, 2, drawLineColor);
		HPEN holdPen = (HPEN)SelectObject(hdc, hPen);
		Ellipse(hdc, x_center - radius, y_center - radius, x_center + radius, y_center + radius);
		LOGBRUSH lb;
		lb.lbColor = drawFillColor;
		lb.lbStyle = BS_SOLID;
		HBRUSH hBrush;

		hBrush = CreateBrushIndirect(&lb);
		HBRUSH holdBrush = (HBRUSH)(SelectObject(hdc, hBrush));

		FloodFill(hdc, x_center, y_center, drawLineColor);
		DeleteObject(SelectObject(hdc, holdBrush));
		DeleteObject(SelectObject(hdc, holdPen));
	}
};