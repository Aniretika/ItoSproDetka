#include <windows.h> // підключення бібліотеки з функціями API
#include "Resource.h"

// Глобальні змінні:
HINSTANCE hInst; 	//Дескриптор програми	
LPCTSTR szWindowClass = "Stas Pisarenko Aleksandr Ignatiev Katerina Soroka";
LPCTSTR szTitle = "Our Program";

// Попередній опис функцій
CHAR s_text_1[256] = { 0 };




ATOM MyRegisterClass(HINSTANCE hInstance);
BOOL InitInstance(HINSTANCE, int);
BOOL CALLBACK AboutDlgProc(HWND, UINT, WPARAM, LPARAM);  //объявляем прототип функции процедуры диалогового окна 
BOOL CALLBACK AboutDlgProc1(HWND, UINT, WPARAM, LPARAM);
BOOL CALLBACK AboutDlgProc2(HWND, UINT, WPARAM, LPARAM);
BOOL CALLBACK AboutDlgProc3(HWND, UINT, WPARAM, LPARAM);
BOOL CALLBACK AboutDlgProc18(HWND, UINT, WPARAM, LPARAM);
LRESULT CALLBACK WndProc(HWND, UINT, WPARAM, LPARAM);

// Основна програма 
int APIENTRY WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine,
	int nCmdShow)
{
	MSG msg;

	// Реєстрація класу вікна 
	MyRegisterClass(hInstance);

	// Створення вікна програми
	if (!InitInstance(hInstance, nCmdShow))
	{
		return FALSE;
	}
	// Цикл обробки повідомлень
	while (GetMessage(&msg, NULL, 0, 0))
	{
		TranslateMessage(&msg);
		DispatchMessage(&msg);
	}
	return msg.wParam;
}

ATOM MyRegisterClass(HINSTANCE hInstance)
{
	WNDCLASSEX wcex;
	wcex.cbSize = sizeof(WNDCLASSEX);
	wcex.style = CS_HREDRAW | CS_DBLCLKS | CS_NOCLOSE; 		//стиль вікна redraw/doubleclick/non close winow
	wcex.lpfnWndProc = (WNDPROC)WndProc; 		            //віконна процедура
	wcex.cbClsExtra = 0;
	wcex.cbWndExtra = 0;
	wcex.hInstance = hInstance; 			              //дескриптор програми
	wcex.hIcon = LoadIcon(NULL, IDI_INFORMATION); 		  //визначення іконки
	wcex.hCursor = LoadCursor(NULL, IDC_WAIT); 	          //визначення курсору
	wcex.hbrBackground = GetSysColorBrush(COLOR_WINDOW + 1); //установка фону
	wcex.lpszMenuName = MAKEINTRESOURCE(IDR_MENU1); 	    //визначення меню
	
	wcex.lpszClassName = szWindowClass; 		           //ім’я класу
	wcex.hIconSm = NULL;
	return RegisterClassEx(&wcex); 			              //реєстрація класу вікна
}
	

// FUNCTION: InitInstance (HANDLE, int)
// Створює вікно програми і зберігає дескриптор програми в змінній hInst

BOOL InitInstance(HINSTANCE hInstance, int nCmdShow)
{
	HWND hWnd;
	hInst = hInstance;          //зберігає дескриптор додатка в змінній hInst
	hWnd = CreateWindow(szWindowClass, 	// ім’я класу вікна
		szTitle, 				// назва програми
		WS_CAPTION | WS_BORDER |WS_MINIMIZEBOX | WS_VSCROLL | WS_SYSMENU | WS_SIZEBOX,  //створює вікно з активною кнопкою мінімізації, стиль вікна, системне меню
		750,                    // положення по Х
		400,                    // положення по Y
		400,                    // розмір по Х
		250,                    // розмір по Y
		NULL, 					// дескриптор батьківського вікна	
		NULL, 					// дескриптор меню вікна
		hInstance, 				// дескриптор програми
		NULL); 				    // параметри створення.

	if (!hWnd) 	                //Якщо вікно не творилось, функція повертає FALSE
	{
		return FALSE;
	}
	ShowWindow(hWnd, SW_SHOWMINIMIZED);  //Показати вікно
	UpdateWindow(hWnd); 		 //Оновити вікно
	return TRUE;
}

// FUNCTION: WndProc (HWND, unsigned, WORD, LONG)
// Віконна процедура. Приймає і обробляє всі повідомлення, що приходять в додаток

BOOL CALLBACK AboutDlgProc(HWND hDlg, UINT iMsg, WPARAM wParam, LPARAM lParam)  // 1 діалогове вікно
{
	switch (iMsg)
	{
	case WM_INITDIALOG:
		return TRUE;
	case WM_COMMAND:
		switch (LOWORD(wParam))
		{
		case IDOK:
			EndDialog(hDlg, 0);
			return TRUE;
		case IDCANCEL2:
			DialogBoxParam(hInst, MAKEINTRESOURCE(IDD_DIALOG2), 0, (AboutDlgProc1), 0);
			break;
		case IDCANCEL:
			DialogBoxParam(hInst, MAKEINTRESOURCE(IDD_DIALOG3), 0, (AboutDlgProc2), 0);
			break;
		}
	}
	return FALSE;
}//реализация диалогового окна


BOOL CALLBACK AboutDlgProc1(HWND hDlg, UINT iMsg, WPARAM wParam, LPARAM lParam)  // докладніше
{
	switch (iMsg)
	{
	case WM_INITDIALOG:
		return TRUE;
	case WM_COMMAND:
		switch (LOWORD(wParam))
		{
		case IDOK:
			EndDialog(hDlg, 0);
			return TRUE;
			break;
		}
	}
	return FALSE;
}
BOOL CALLBACK AboutDlgProc2(HWND hDlg, UINT iMsg, WPARAM wParam, LPARAM lParam)  //  запитання
{
	switch (iMsg)
	{
	case WM_INITDIALOG:
		return TRUE;
	case WM_COMMAND:
		switch (LOWORD(wParam))
		{
		case IDOK:
			PostQuitMessage(0);
			break;
		case IDCANCEL3:
			EndDialog(hDlg, 0);
			break;
		}
		break;
	}
	return FALSE;
}
BOOL CALLBACK AboutDlgProc3(HWND hDlg, UINT iMsg, WPARAM wParam, LPARAM lParam)  //  запитання
{
	HWND hEdit1 = GetDlgItem(hDlg, IDC_EDIT1);
	switch (iMsg)
	{
	case WM_INITDIALOG:
		return TRUE;
		
	case WM_COMMAND:
		switch (LOWORD(wParam))
		{
		case IDOK:

			SendMessage(hEdit1, WM_GETTEXT, (WPARAM)255, (LPARAM)s_text_1);
			MessageBox(hDlg, s_text_1, "HNURE", MB_OK);
			return TRUE;
			break;
		case IDCANCEL:
			DialogBoxParam(hInst, MAKEINTRESOURCE(IDD_DIALOG5), 0, (AboutDlgProc18), 0);
			break;
		}
		break;
	}
	return FALSE;
}
BOOL CALLBACK AboutDlgProc18(HWND hDlg, UINT iMsg, WPARAM wParam, LPARAM lParam)  //  запитання
{
	switch (iMsg)
	{
	case WM_INITDIALOG:
		return TRUE;
	case WM_COMMAND:
		switch (LOWORD(wParam))
		{
		case IDOK:
			PostQuitMessage(0);
			break;
		case IDCANCEL:
			DialogBoxParam(hInst, MAKEINTRESOURCE(IDD_DIALOG4), 0, (AboutDlgProc3), 0);
			break;
		}
		break;
	}
	return FALSE;
}
LRESULT CALLBACK WndProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam)  //віконна процедура
{
	PAINTSTRUCT ps;
	HDC hdc;
	RECT rt;
	HMENU hMenu1;
	hMenu1 = LoadMenu(hInst, MAKEINTRESOURCE(IDR_MENU2));

	//AppendMenu(hmenu1, MF_STRING, 0, "&File");
	//AppendMenu(hmenu1, MF_STRING, 0, "&Edit");
	//AppendMenu(hmenu1, MF_STRING, 0, "&Help");


	switch (message)
	{
	case WM_COMMAND:
		switch (LOWORD(wParam))
		{
		case ID_CHANGE_:
			SetClassLong(hWnd, GCLP_HCURSOR, (LONG)LoadCursor(hInst, MAKEINTRESOURCE(IDC_CURSOR1)));
			break;
		case ID_CHANGE_CURSOR2:
			SetClassLong(hWnd, GCLP_HCURSOR, (LONG)LoadCursor(hInst, MAKEINTRESOURCE(IDC_CURSOR2)));
			break;
		case ID_CHANGE_CURSOR3:
			SetClassLong(hWnd, GCLP_HCURSOR, (LONG)LoadCursor(hInst, MAKEINTRESOURCE(IDC_CURSOR3)));
			break;


		case ID_FILE_CURSOR:
			SetClassLong(hWnd, GCLP_HCURSOR, (LONG)LoadCursor(hInst, MAKEINTRESOURCE(IDC_CURSOR4)));
			break;
		case ID_FILE_CURSOR1:
			SetClassLong(hWnd, GCLP_HCURSOR, (LONG)LoadCursor(hInst, MAKEINTRESOURCE(IDC_CURSOR5)));
			break; 
		case ID_FILE_CURSOR3:
			SetClassLong(hWnd, GCLP_HCURSOR, (LONG)LoadCursor(hInst, MAKEINTRESOURCE(IDC_CURSOR6)));
			break;


		case ID_Menu:
			SetClassLong(hWnd, GCLP_HCURSOR, (LONG)LoadCursor(hInst, MAKEINTRESOURCE(IDC_NODROP)));
			break;
		case ID_NEWMENUITEM1_CURSOR2:
			SetClassLong(hWnd, GCLP_HCURSOR, (LONG)LoadCursor(hInst, MAKEINTRESOURCE(IDC_POINTER)));
			break;
		case ID_NEWMENUITEM1_CURSOR3:
			SetClassLong(hWnd, GCLP_HCURSOR, (LONG)LoadCursor(hInst, MAKEINTRESOURCE(IDC_POINTER_COPY)));
			break;


		case ID_NEWMENUITEM2_CURSOR1:
			SetClassLong(hWnd, GCLP_HCURSOR, (LONG)LoadCursor(hInst, MAKEINTRESOURCE(IDC_POINTER_COPY1)));
			break;
		case ID_NEWMENUITEM2_CURSOR2:
			SetClassLong(hWnd, GCLP_HCURSOR, (LONG)LoadCursor(hInst, MAKEINTRESOURCE(IDC_POINTER1)));
			break;
		case ID_NEWMENUITEM2_CURSOR3:
			SetClassLong(hWnd, GCLP_HCURSOR, (LONG)LoadCursor(hInst, MAKEINTRESOURCE(IDC_CURSOR1)));
			break;


		case ID_ABOUTUS_ABOUTSTUDENTS:
			DialogBoxParam(hInst, MAKEINTRESOURCE(IDD_DIALOG1), 0, (AboutDlgProc), 0);//создает диалговое окно, когда нажимаем на студентов
			break;
		case ID_DIALOGMESSAGE_MESSAGEBOX:
			DialogBoxParam(hInst, MAKEINTRESOURCE(IDD_DIALOG4), 0, (AboutDlgProc3), 0);//создает диалговое окно, когда нажимаем на студентов
			break;
		case ID_MENU2_OP:/*IDR_MENU2*/
			SetMenu(hWnd, hMenu1);
		break;
	    }
	case WM_CREATE: 				    //Повідомлення приходить при створенні вікна
		
		break;

	case WM_PAINT: 				        //Перемалювати вікно
		hdc = BeginPaint(hWnd, &ps); 	//Почати графічний вивід	
		GetClientRect(hWnd, &rt); 		//Область вікна для малювання
		DrawText(hdc, "Добрий день!", -1, &rt, DT_SINGLELINE | DT_CENTER | DT_VCENTER);
		EndPaint(hWnd, &ps); 		    //Закінчити графічний вивід	
		break;

	case WM_DESTROY: 				    //Завершення роботи
		PostQuitMessage(0);
		break; 


	case WM_LBUTTONDBLCLK:
		MessageBox(hWnd, "А ось і я!", "HNURE", MB_OK);
		break;
	default:
		//Обробка повідомлень, які не оброблені користувачем
		return DefWindowProc(hWnd, message, wParam, lParam);
	}
	return 0;
}
