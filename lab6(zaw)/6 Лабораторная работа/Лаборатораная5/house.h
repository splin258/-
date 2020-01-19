#pragma once
#include"stdafx.h"
class Grafobject // ����� � ������ �������� �������� ������� (����������� �������, ������� � ����� �������� ������) � �������� ������ (����������, ������� ����� ��������� ������, ���� ������ � � ���������)
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
	 Grafobject(int x, int y)// � ������������ ������ ����� ����������
	{
		x_center = x;
		y_center = y;
	}
	void move(HWND hWnd, RECT rect)// ���������� ������ ������ �� 50 ������
	{
		x_center = x_center + 50;
		InvalidateRect(hWnd, &rect, TRUE);
	}
	void moveleft(HWND hWnd, RECT rect)// ���������� ������ ����� �� 50 ������
	{
		x_center = x_center - 50;
		InvalidateRect(hWnd, &rect, TRUE);
	}
	void moveup(HWND hWnd, RECT rect)// ���������� ������ ����� �� 50 ������
	{
		y_center = y_center - 50;
		InvalidateRect(hWnd, &rect, TRUE);
	}
	void movedown(HWND hWnd, RECT rect)// ���������� ������ ���� �� 50 ������
	{
		y_center = y_center + 50;
		InvalidateRect(hWnd, &rect, TRUE);
	}
	void setWidth(int width)// ����� ������� �����
	{
		lineWidth = width;
	}
	void setLineColor(COLORREF color)// ����� ���� �����
	{
		lineCol = color;
	}
	void setFillColor(COLORREF color)// ����� ���� ������
	{
		fillCol = color;
	}
	void setCenter(int x, int y)// ����� ����������� ����������
	{
		x_center = x;
		y_center = y;
	}
	void hide(HWND hWnd, RECT rect)// �������� ������
	{
		drawLineColor = COLORREF(RGB(0, 0, 150));
		drawFillColor = COLORREF(RGB(0, 0, 150));
		InvalidateRect(hWnd, &rect, TRUE);
		
	}
	void show(HWND hWnd, RECT rect)// ������ ������ �������
	{
		drawLineColor = lineCol;
		drawFillColor = fillCol;
		InvalidateRect(hWnd, &rect, TRUE);
	}
	virtual void drawObject(HDC hdc) = 0;//������������ ������� ��������� �������
};


class Triangle :public Grafobject // ��� ����������� ����� ������ grafobject
{
	int width;
	int height;
	public:
		Triangle(int x , int y , int w , int h, int LineCol, int fill) :Grafobject(x, y)//����� ���������� ������
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

		void drawObject(HDC hdc)//��������� �������
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
	rectangle : public Grafobject// ��� ����������� ����� ������ grafobject 
{
	int width; 
	int height; 
public:

	rectangle(int x, int y, int w, int h, int LineCol, int fill) :Grafobject(x, y)//����� ���������� ������
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
	void drawObject(HDC hdc)//��������� �������
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

class circle : public Grafobject// ��� ����������� ����� ������ grafobject 
{
	int radius;
public:

	circle(int x, int y, int r, int LineCol, int fill) :Grafobject(x, y)//����� ���������� ������
	{
		x_center = x;
		y_center = y;
		radius = r;
		lineCol = LineCol;
		fillCol = fill;
		drawLineColor = LineCol;
		drawFillColor = fill;
	}
	void drawObject(HDC hdc)//��������� �������
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