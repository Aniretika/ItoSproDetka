#include <windows.h> // ���������� �������� � ��������� API
#include "Resource.h"

// �������� ����:
HINSTANCE hInst; 	//���������� ��������	
LPCTSTR szWindowClass = "Stas Pisarenko Aleksandr Ignatiev Katerina Soroka";
LPCTSTR szTitle = "Our Program";

// ��������� ���� �������
CHAR s_text_1[256] = { 0 };




ATOM MyRegisterClass(HINSTANCE hInstance);
BOOL InitInstance(HINSTANCE, int);
BOOL CALLBACK AboutDlgProc(HWND, UINT, WPARAM, LPARAM);  //��������� �������� ������� ��������� ����������� ���� 
BOOL CALLBACK AboutDlgProc1(HWND, UINT, WPARAM, LPARAM);
BOOL CALLBACK AboutDlgProc2(HWND, UINT, WPARAM, LPARAM);
BOOL CALLBACK AboutDlgProc3(HWND, UINT, WPARAM, LPARAM);
BOOL CALLBACK AboutDlgProc18(HWND, UINT, WPARAM, LPARAM);
LRESULT CALLBACK WndProc(HWND, UINT, WPARAM, LPARAM);

// ������� �������� 
int APIENTRY WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine,
	int nCmdShow)
{
	MSG msg;

	// ��������� ����� ���� 
	MyRegisterClass(hInstance);

	// ��������� ���� ��������
	if (!InitInstance(hInstance, nCmdShow))
	{
		return FALSE;
	}
	// ���� ������� ����������
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
	wcex.style = CS_HREDRAW | CS_DBLCLKS | CS_NOCLOSE; 		//����� ���� redraw/doubleclick/non close winow
	wcex.lpfnWndProc = (WNDPROC)WndProc; 		            //������ ���������
	wcex.cbClsExtra = 0;
	wcex.cbWndExtra = 0;
	wcex.hInstance = hInstance; 			              //���������� ��������
	wcex.hIcon = LoadIcon(NULL, IDI_INFORMATION); 		  //���������� ������
	wcex.hCursor = LoadCursor(NULL, IDC_WAIT); 	          //���������� �������
	wcex.hbrBackground = GetSysColorBrush(COLOR_WINDOW + 1); //��������� ����
	wcex.lpszMenuName = MAKEINTRESOURCE(IDR_MENU1); 	    //���������� ����
	
	wcex.lpszClassName = szWindowClass; 		           //��� �����
	wcex.hIconSm = NULL;
	return RegisterClassEx(&wcex); 			              //��������� ����� ����
}
	

// FUNCTION: InitInstance (HANDLE, int)
// ������� ���� �������� � ������ ���������� �������� � ����� hInst

BOOL InitInstance(HINSTANCE hInstance, int nCmdShow)
{
	HWND hWnd;
	hInst = hInstance;          //������ ���������� ������� � ����� hInst
	hWnd = CreateWindow(szWindowClass, 	// ��� ����� ����
		szTitle, 				// ����� ��������
		WS_CAPTION | WS_BORDER |WS_MINIMIZEBOX | WS_VSCROLL | WS_SYSMENU | WS_SIZEBOX,  //������� ���� � �������� ������� ��������, ����� ����, �������� ����
		750,                    // ��������� �� �
		400,                    // ��������� �� Y
		400,                    // ����� �� �
		250,                    // ����� �� Y
		NULL, 					// ���������� ������������ ����	
		NULL, 					// ���������� ���� ����
		hInstance, 				// ���������� ��������
		NULL); 				    // ��������� ���������.

	if (!hWnd) 	                //���� ���� �� ���������, ������� ������� FALSE
	{
		return FALSE;
	}
	ShowWindow(hWnd, SW_SHOWMINIMIZED);  //�������� ����
	UpdateWindow(hWnd); 		 //������� ����
	return TRUE;
}

// FUNCTION: WndProc (HWND, unsigned, WORD, LONG)
// ³����� ���������. ������ � �������� �� �����������, �� ��������� � �������

BOOL CALLBACK AboutDlgProc(HWND hDlg, UINT iMsg, WPARAM wParam, LPARAM lParam)  // 1 �������� ����
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
}//���������� ����������� ����


BOOL CALLBACK AboutDlgProc1(HWND hDlg, UINT iMsg, WPARAM wParam, LPARAM lParam)  // ���������
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
BOOL CALLBACK AboutDlgProc2(HWND hDlg, UINT iMsg, WPARAM wParam, LPARAM lParam)  //  ���������
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
BOOL CALLBACK AboutDlgProc3(HWND hDlg, UINT iMsg, WPARAM wParam, LPARAM lParam)  //  ���������
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
BOOL CALLBACK AboutDlgProc18(HWND hDlg, UINT iMsg, WPARAM wParam, LPARAM lParam)  //  ���������
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
LRESULT CALLBACK WndProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam)  //������ ���������
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
			DialogBoxParam(hInst, MAKEINTRESOURCE(IDD_DIALOG1), 0, (AboutDlgProc), 0);//������� ��������� ����, ����� �������� �� ���������
			break;
		case ID_DIALOGMESSAGE_MESSAGEBOX:
			DialogBoxParam(hInst, MAKEINTRESOURCE(IDD_DIALOG4), 0, (AboutDlgProc3), 0);//������� ��������� ����, ����� �������� �� ���������
			break;
		case ID_MENU2_OP:/*IDR_MENU2*/
			SetMenu(hWnd, hMenu1);
		break;
	    }
	case WM_CREATE: 				    //����������� ��������� ��� �������� ����
		
		break;

	case WM_PAINT: 				        //������������ ����
		hdc = BeginPaint(hWnd, &ps); 	//������ ��������� ����	
		GetClientRect(hWnd, &rt); 		//������� ���� ��� ���������
		DrawText(hdc, "������ ����!", -1, &rt, DT_SINGLELINE | DT_CENTER | DT_VCENTER);
		EndPaint(hWnd, &ps); 		    //�������� ��������� ����	
		break;

	case WM_DESTROY: 				    //���������� ������
		PostQuitMessage(0);
		break; 


	case WM_LBUTTONDBLCLK:
		MessageBox(hWnd, "� ��� � �!", "HNURE", MB_OK);
		break;
	default:
		//������� ����������, �� �� �������� ������������
		return DefWindowProc(hWnd, message, wParam, lParam);
	}
	return 0;
}
