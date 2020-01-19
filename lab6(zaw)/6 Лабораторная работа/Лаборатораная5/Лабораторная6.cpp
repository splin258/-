 //Лаборатораная5.cpp: 

#include "stdafx.h"
#include "laba6.h"
#include "house.h"


#define MAX_LOADSTRING 100

 // Global Variables:
HINSTANCE hInst;								// current instance
TCHAR szTitle[MAX_LOADSTRING];					// The title bar text
TCHAR szWindowClass[MAX_LOADSTRING];			// the main window class name

												// Forward declarations of functions included in this code module:
ATOM				MyRegisterClass(HINSTANCE hInstance);
BOOL				InitInstance(HINSTANCE, int);
LRESULT CALLBACK	WndProc(HWND, UINT, WPARAM, LPARAM);
INT_PTR CALLBACK	About(HWND, UINT, WPARAM, LPARAM);
 
int APIENTRY _tWinMain(HINSTANCE hInstance,
	HINSTANCE hPrevInstance,
	LPTSTR    lpCmdLine,
	int       nCmdShow)
{
	UNREFERENCED_PARAMETER(hPrevInstance);
	UNREFERENCED_PARAMETER(lpCmdLine);

	// TODO: Place code here.
	MSG msg;
	HACCEL hAccelTable;

	// Initialize global strings
	LoadString(hInstance, IDS_APP_TITLE, szTitle, MAX_LOADSTRING);
	LoadString(hInstance, IDC_MY5, szWindowClass, MAX_LOADSTRING);
	MyRegisterClass(hInstance);

	// Perform application initialization:
	if (!InitInstance(hInstance, nCmdShow))
	{
		return FALSE;
	}

	hAccelTable = LoadAccelerators(hInstance, MAKEINTRESOURCE(IDC_MY5));

	// Main message loop:
	while (GetMessage(&msg, NULL, 0, 0))
	{
		if (!TranslateAccelerator(msg.hwnd, hAccelTable, &msg))
		{
			TranslateMessage(&msg);
			DispatchMessage(&msg);
		}
	}

	return (int)msg.wParam;
}

ATOM MyRegisterClass(HINSTANCE hInstance)
{
	WNDCLASSEX wcex;

	wcex.cbSize = sizeof(WNDCLASSEX);

	wcex.style			= CS_HREDRAW | CS_VREDRAW;
	wcex.lpfnWndProc	= WndProc;
	wcex.cbClsExtra		= 0;
	wcex.cbWndExtra		= 0;
	wcex.hInstance		= hInstance;
	wcex.hIcon			= LoadIcon(hInstance, MAKEINTRESOURCE(IDI_MY5));
	wcex.hCursor		= LoadCursor(NULL, IDC_ARROW);
	wcex.hbrBackground	= (HBRUSH)(COLOR_WINDOW+5);
	wcex.lpszMenuName	= MAKEINTRESOURCE(IDC_MY5);
	wcex.lpszClassName	= szWindowClass;
	wcex.hIconSm		= LoadIcon(wcex.hInstance, MAKEINTRESOURCE(IDI_SMALL));

	return RegisterClassEx(&wcex);
}


BOOL InitInstance(HINSTANCE hInstance, int nCmdShow)
{
   HWND hWnd;

   hInst = hInstance; // Сохранить дескриптор экземпляра в глобальной переменной

   hWnd = CreateWindow(szWindowClass, szTitle, WS_OVERLAPPEDWINDOW,
      CW_USEDEFAULT, 0, CW_USEDEFAULT, 0, NULL, NULL, hInstance, NULL);

   if (!hWnd)
   {
      return FALSE;
   }

   ShowWindow(hWnd, nCmdShow);
   UpdateWindow(hWnd);

   return TRUE;
}


LRESULT CALLBACK WndProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam)
{
	int wmId, wmEvent;
	PAINTSTRUCT ps;
	HDC hdc;

	static circle circle1(510, 431, 20, RGB(105, 105, 105), RGB(105, 105, 105)); // отрисовка левого колеса
	static circle circle2(720, 431, 20, RGB(105, 105, 105), RGB(105, 105, 105)); // отрисовка правого колеса
	static Triangle triangl(600, 210, 40, 40, RGB(0, 0, 0), RGB(0, 0, 0));// это нам не нужно
	static rectangle rectangle4(773, 370, 10, 10, RGB(255, 255, 150), RGB(255, 255, 150));//отрисовка фары
	static rectangle rectangle3(642, 350, 83, 120, RGB(255, 0, 0), RGB(255, 0, 0));//отрисовка кабины
	static rectangle rectangle2(724,380,90,60, RGB(255, 0, 0), RGB(255, 0, 0));//отрисовка переда
	static rectangle rectangle(500, 370,200, 80, RGB(90, 180, 0), RGB(90, 180, 0));//отрисовка кузова
	Grafobject* shapes[7] = { &rectangle4, &triangl, &rectangle3, &rectangle2,  &rectangle,&circle1,&circle2 }; // массив графических объектов, которые образуют машину, с которыми мы будем выполнять всякие манипуляции  
	HBRUSH hBrush; // объявляем объект перо
	LOGBRUSH lb;
	HBRUSH holdBrush;
	static RECT rect;
	//выбор метода в зависимости от нажатой кнопки
	switch (message)
	{
	case WM_COMMAND:
		wmId    = LOWORD(wParam);
		wmEvent = HIWORD(wParam);
		// Разобрать выбор в меню:
		switch (wmId)
		{
		case IDM_ABOUT:
			DialogBox(hInst, MAKEINTRESOURCE(IDD_ABOUTBOX), hWnd, About);
			break;
		case ID_HIDE://скрыть объект

			for (int i = 0; i < 7; i++)
			{
				if (i!=1)
				shapes[i]->hide(hWnd, rect);
			}
			break;
		case ID_SHOW://сделать объект видимым

			for (int i = 0; i < 7; i++)
			{
				shapes[i]->show(hWnd, rect);
			}

			break;
		case ID_MOVE://передвинуть  объект вправо

			for (int i = 0; i < 7; i++)
			{
				shapes[i]->move(hWnd, rect);
			}
			break;
		case ID_LEFT://передвинуть объект влево 
			for (int i = 0; i <7; i++)
			{
				shapes[i]->moveleft(hWnd, rect);
			}
			break;
		case ID_UP://передвинуть объект выше
			for (int i = 0; i <7; i++)
			{
				shapes[i]->moveup(hWnd, rect);
			}
			break;
		case ID_DOWN://передвинуть объект ниже
			for (int i = 0; i < 7; i++)
			{
				shapes[i]->movedown(hWnd, rect);
			}
			break;
		case IDM_EXIT://выход
			DestroyWindow(hWnd);
			break;
		default:
			return DefWindowProc(hWnd, message, wParam, lParam);
		}
		break;
	case WM_PAINT:
		hdc = BeginPaint(hWnd, &ps);
		GetClientRect(hWnd, &rect);


		lb.lbColor = RGB(153, 255, 153);
		lb.lbStyle = BS_SOLID;


		hBrush = CreateBrushIndirect(&lb);
		holdBrush = (HBRUSH)(SelectObject(hdc, hBrush));

		FloodFill(hdc, 0, 0, RGB(0, 0, 0));
		DeleteObject(SelectObject(hdc, holdBrush));


		for (int i = 0; i < 7; i++)
		{
			shapes[i]->drawObject(hdc);
		}


		EndPaint(hWnd, &ps);
		break;
	case WM_DESTROY:
		PostQuitMessage(0);
		break;
	default:
		return DefWindowProc(hWnd, message, wParam, lParam);
	}
	return 0;
}

// Обработчик сообщений для окна "О программе".
INT_PTR CALLBACK About(HWND hDlg, UINT message, WPARAM wParam, LPARAM lParam)
{
	UNREFERENCED_PARAMETER(lParam);
	switch (message)
	{
	case WM_INITDIALOG:
		return (INT_PTR)TRUE;

	case WM_COMMAND:
		if (LOWORD(wParam) == IDOK || LOWORD(wParam) == IDCANCEL)
		{
			EndDialog(hDlg, LOWORD(wParam));
			return (INT_PTR)TRUE;
		}
		break;
	}
	return (INT_PTR)FALSE;
}



