#include<windows.h>
#include<stdlib.h>
#include<ctime>
#include<tchar.h>
#include<string.h>
#include "resource.h"

LRESULT CALLBACK WndProc(HWND hWnd, UINT iMessage, UINT wParam, LONG lParam);
BOOL InitWindowsClass(HINSTANCE hInstance);
BOOL InitWindows(HINSTANCE hInstance, int nCmdShow);
BOOL CALLBACK ModalDlgProc(HWND hdlg, UINT message, WPARAM wParam, LPARAM lParam);
HWND hdlg;
HINSTANCE hInst;
HACCEL hAccel;
static int c = 0;
static BOOL AutoRun = FALSE;//自动模式
int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow) {
	MSG Message;
	if (!InitWindowsClass(hInstance))
		return FALSE;
	if (!InitWindows(hInstance, nCmdShow))
		return FALSE;
	hInst = hInstance;
	hAccel = LoadAccelerators(hInst, L"MENU");
	while (GetMessage(&Message, 0, 0, 0)) {
		if (!IsDialogMessage(hdlg, &Message)) {
			TranslateMessage(&Message);
			DispatchMessage(&Message);
		}
	}
	return Message.wParam;
}

LRESULT CALLBACK WndProc(HWND hWnd, UINT iMessage, UINT wParam, LONG lParam) {
	HDC hDC;
	PAINTSTRUCT ps;
	static int i = 0;
	HBRUSH hb;
	static BOOL nUpKeyDown = FALSE, nDownKeyDown = FALSE, nLeftKeyDown = FALSE, nRightKeyDown = FALSE;
	static int keydown = 0;//上下左右初始化为false
	static BOOL Start = FALSE;
	RECT rect = { 0,0,0,0 };
	LPRECT lpRect = &rect;
	GetClientRect(hWnd, lpRect);
	static int CentreX = 10, CentreY = 10, Radious = 10;
	static int PointCentreX[10] = { 0 }, PointCentreY[10] = { 0 }, PointRadius = 3;
	static int ObstacleCentreX[10] = { 0 }, ObstacleCentreY[10] = { 0 };
	static int count = 0, Direction = 0;
	TCHAR str[20] = L"您的本次得分为：";
	TCHAR strResult[10];
	_itot_s(c, strResult, 10);
	lstrcat(str, strResult);
	switch (iMessage) {
	case WM_COMMAND:
		switch (LOWORD(wParam)) {
		case IDM_BEGIN:
			CentreX = 10, CentreY = 10;
			c = 0;
			Start = TRUE;
			PostMessage(hWnd, WM_CREATE, 0, 0);
			break;
		case IDM_MODEL:
			DialogBox(hInst, MAKEINTRESOURCE(Select), hWnd, (DLGPROC)ModalDlgProc);
			if (AutoRun == TRUE)
				SetTimer(hWnd, 1111, 1000, NULL);
			else
				KillTimer(hWnd, 1111);
			break;
		case IDM_EXIT:
			if (Start) {
				MessageBox(hWnd, str, L"游戏结束", MB_OK);
				SendMessage(hWnd, WM_DESTROY, 0, 0);
			}
			else
				SendMessage(hWnd, WM_DESTROY, 0, 0);
			break;
		case IDM_ABOUT:
			MessageBox(hWnd, L"Version: Game-PAC-MAN(吃豆豆) 2.0\nAuthor: 19160209刘明玉", L"关于", MB_OK);
		}
		break;
	case WM_KEYDOWN: {//上下左右的移动设置
		switch (wParam) {
		case VK_UP:
			nLeftKeyDown = FALSE; nRightKeyDown = FALSE; nDownKeyDown = FALSE; nUpKeyDown = TRUE;
			InvalidateRect(hWnd, NULL, 1);
			break;
		case VK_DOWN:
			nLeftKeyDown = FALSE; nUpKeyDown = FALSE; nRightKeyDown = FALSE; nDownKeyDown = TRUE;
			InvalidateRect(hWnd, NULL, 1);
			break;
		case VK_LEFT:
			nRightKeyDown = FALSE; nUpKeyDown = FALSE; nDownKeyDown = FALSE; nLeftKeyDown = TRUE;
			InvalidateRect(hWnd, NULL, 1);
			break;
		case VK_RIGHT:
			nLeftKeyDown = FALSE; nUpKeyDown = FALSE; nDownKeyDown = FALSE; nRightKeyDown = TRUE;
			InvalidateRect(hWnd, NULL, 1);
			break;
		default:
			break;
		}
	}
					 break;
	case WM_CREATE:
		SetTimer(hWnd, 1, 50, NULL);
		srand((unsigned)time(NULL));
		for (int i = 0; i < 10; i++)
		{
			ObstacleCentreX[i] = (rand() % (lpRect->right / 10 - 1) + Radious / 10) * 10;
			ObstacleCentreY[i] = (rand() % (lpRect->bottom / 10 - 1) + Radious / 10) * 10;
		}
		for (int i = 0; i < 10; i++) {
			PointCentreX[i] = (rand() % (lpRect->right / 10 - 1) + Radious / 10) * 10;
			PointCentreY[i] = (rand() % (lpRect->bottom / 10 - 1) + Radious / 10) * 10;
		}
		break;
	case WM_KEYUP:
		InvalidateRect(hWnd, NULL, 1);
		break;
	case WM_LBUTTONDOWN:
		DialogBox(hInst, MAKEINTRESOURCE(Select), hWnd, (DLGPROC)ModalDlgProc);
		if (AutoRun == TRUE)
			SetTimer(hWnd, 1111, 1000, NULL);
		else
			KillTimer(hWnd, 1111);
		break;
	case WM_RBUTTONDOWN:
		if (Start) {
			MessageBox(hWnd, str, L"游戏结束", MB_OK);
			SendMessage(hWnd, WM_DESTROY, 0, 0);
		}
		break;
	case WM_TIMER:
		if (wParam == 1111)
			InvalidateRect(hWnd, NULL, 1);
		if (wParam == 1) {
			InvalidateRect(hWnd, NULL, 1);
			count++;
			if (count == 50) {
				count = 0;
				srand((unsigned)time(NULL));
				Direction = rand() % 40;
				for (int i = 0; i < 10; i++)
				{
					if (Direction / 10 == 0) {
						if (ObstacleCentreX[i] - 10 >= lpRect->left + Radious)
							ObstacleCentreX[i] -= 10;
					}
					else if (Direction / 10 == 1) {
						if (ObstacleCentreX[i] + 10 <= lpRect->right - Radious)
							ObstacleCentreX[i] += 10;
					}
					else if (Direction / 10 == 2) {
						if (ObstacleCentreY[i] - 10 >= lpRect->top + Radious)
							ObstacleCentreY[i] -= 10;
					}
					else {
						if (ObstacleCentreY[i] + 10 <= lpRect->bottom - Radious)
							ObstacleCentreY[i] += 10;
					}
				}
			}
		}
		break;
	case WM_PAINT:
		hDC = BeginPaint(hWnd, &ps);
		hb = CreateSolidBrush(RGB(255, 0, 255));
		SelectObject(hDC, hb);
		if (AutoRun&&Start) {
			if (nRightKeyDown == TRUE) {
				nLeftKeyDown = FALSE;
				nUpKeyDown = FALSE;
				nDownKeyDown = FALSE;
				if (CentreX + 10 <= lpRect->right - Radious)
					CentreX = CentreX + 10;
			}
			else if (nLeftKeyDown == TRUE) {
				nRightKeyDown = FALSE;
				nUpKeyDown = FALSE;
				nDownKeyDown = FALSE;
				if (CentreX - 10 >= lpRect->left + Radious)
					CentreX = CentreX - 10;
			}
			else if (nDownKeyDown == TRUE) {
				nLeftKeyDown = FALSE;
				nUpKeyDown = FALSE;
				nRightKeyDown = FALSE;
				if (CentreY + 10 <= lpRect->bottom - Radious)
					CentreY = CentreY + 10;
			}
			else if (nUpKeyDown == TRUE) {
				nLeftKeyDown = FALSE;
				nDownKeyDown = FALSE;
				nRightKeyDown = FALSE;
				if (CentreY - 10 >= lpRect->top + Radious)
					CentreY = CentreY - 10;
			}
			if (nRightKeyDown == TRUE)
				Ellipse(hDC, CentreX - Radious, CentreY - Radious, CentreX + Radious, CentreY + Radious);
			else if (nDownKeyDown == TRUE)
				Ellipse(hDC, CentreX - Radious, CentreY - Radious, CentreX + Radious, CentreY + Radious);
			else if (nLeftKeyDown == TRUE)
				Ellipse(hDC, CentreX - Radious, CentreY - Radious, CentreX + Radious, CentreY + Radious);
			else if (nUpKeyDown == TRUE)
				Ellipse(hDC, CentreX - Radious, CentreY - Radious, CentreX + Radious, CentreY + Radious);
			else
				Ellipse(hDC, CentreX - Radious, CentreY - Radious, CentreX + Radious, CentreY + Radious);
		}
		else if (Start) {
			if (nRightKeyDown == TRUE) {
				keydown = 0;
				nLeftKeyDown = FALSE; nUpKeyDown = FALSE; nDownKeyDown = FALSE;
				if (CentreX + 10 <= lpRect->right - Radious)
					CentreX = CentreX + 10;
			}
			else if (nLeftKeyDown == TRUE) {
				keydown = 1;
				nRightKeyDown = FALSE; nUpKeyDown = FALSE; nDownKeyDown = FALSE;
				if (CentreX - 10 >= lpRect->left + Radious)
					CentreX = CentreX - 10;
			}
			else if (nUpKeyDown == TRUE) {
				keydown = 2;
				nLeftKeyDown = FALSE; nDownKeyDown = FALSE; nRightKeyDown = FALSE;
				if (CentreY - 10 >= lpRect->top + Radious)
					CentreY = CentreY - 10;
			}
			else if (nDownKeyDown == TRUE) {
				keydown = 3;
				nLeftKeyDown = FALSE; nUpKeyDown = FALSE; nRightKeyDown = FALSE;
				if (CentreY + 10 <= lpRect->bottom - Radious)
					CentreY = CentreY + 10;
			}
			if (keydown == 0)

				Ellipse(hDC, CentreX - Radious, CentreY - Radious, CentreX + Radious, CentreY + Radious);
			else if (keydown == 3)
				Ellipse(hDC, CentreX - Radious, CentreY - Radious, CentreX + Radious, CentreY + Radious);
			else if (keydown == 1)
				Ellipse(hDC, CentreX - Radious, CentreY - Radious, CentreX + Radious, CentreY + Radious);
			else if (keydown == 2)
				Ellipse(hDC, CentreX - Radious, CentreY - Radious, CentreX + Radious, CentreY + Radious);
			else
				Ellipse(hDC, CentreX - Radious, CentreY - Radious, CentreX + Radious, CentreY + Radious);
			nLeftKeyDown = nRightKeyDown = nUpKeyDown = nDownKeyDown = FALSE;
		}
		for (int i = 0; i < 10; i++) {
			if (PointCentreX[i] == CentreX&&PointCentreY[i] == CentreY) {
				srand((unsigned)time(NULL));
				PointCentreX[i] = (rand() % (lpRect->right / 10 - 1) + Radious / 10) * 10;
				PointCentreY[i] = (rand() % (lpRect->bottom / 10 - 1) + Radious / 10) * 10;
				c++;
			}
		}
		for (int i = 0; i < 10; i++) {
			Ellipse(hDC, PointCentreX[i] - PointRadius, PointCentreY[i] - PointRadius, PointCentreX[i] + PointRadius, PointCentreY[i] + PointRadius);
		}
		hb = CreateSolidBrush(RGB(0, 0, 0));
		SelectObject(hDC, hb);
		if (Start) {
			for (int i = 0; i < 10; i++)
				Ellipse(hDC, ObstacleCentreX[i] - Radious, ObstacleCentreY[i] - Radious,
					ObstacleCentreX[i] + Radious, ObstacleCentreY[i] + Radious);
			for (int i = 0; i < 10; i++)
			{
				if (ObstacleCentreX[i] == CentreX&&ObstacleCentreY[i] == CentreY) {
					KillTimer(hWnd, 1);
					KillTimer(hWnd, 1111);
					MessageBox(hWnd, str, L"游戏结束", MB_OK);
					SendMessage(hWnd, WM_DESTROY, 0, 0);
					break;
				}
			}
		}
		DeleteObject(hb);
		EndPaint(hWnd, &ps);
		break;
	case WM_DESTROY:
		KillTimer(hWnd, 1);
		PostQuitMessage(0);
		return 0;
	default:
		return DefWindowProc(hWnd, iMessage, wParam, lParam);
	}
	return 0;
}

BOOL InitWindowsClass(HINSTANCE hInstance) {
	WNDCLASS WndClass;
	WndClass.style = 0;
	WndClass.cbClsExtra = 0;
	WndClass.cbWndExtra = 0;
	WndClass.hbrBackground = (HBRUSH)(GetStockObject(WHITE_BRUSH));
	WndClass.hCursor = LoadCursor(NULL, IDC_ARROW);
	WndClass.hIcon = LoadIcon(NULL, IDI_APPLICATION);
	WndClass.hInstance = hInstance;
	WndClass.lpfnWndProc = WndProc;
	WndClass.lpszClassName = L"Game";
	WndClass.lpszMenuName = L"MENU";
	WndClass.style = CS_HREDRAW | CS_VREDRAW;
	return RegisterClass(&WndClass);
}

BOOL InitWindows(HINSTANCE hInstance, int nCmdShow) {
	HWND hWnd;
	hWnd = CreateWindow(L"Game",
		L"PACMAN",
		WS_OVERLAPPEDWINDOW,
		CW_USEDEFAULT, CW_USEDEFAULT,
		CW_USEDEFAULT, CW_USEDEFAULT,
		NULL,
		NULL,
		hInstance,
		NULL);
	if (!hWnd)
		return FALSE;
	ShowWindow(hWnd, nCmdShow);
	UpdateWindow(hWnd);
	return TRUE;
}

BOOL CALLBACK ModalDlgProc(HWND hdlg, UINT message, WPARAM wParam, LPARAM lParam)
{
	switch (message) {
	case WM_COMMAND:
		switch (LOWORD(wParam)) {
		case IDOK:
			AutoRun = TRUE;
			SendMessage(hdlg, WM_CLOSE, 0, 0);
			break;
		case IDCANCEL:
			AutoRun = FALSE;
			SendMessage(hdlg, WM_CLOSE, 0, 0);
			break;
		}
		break;
	case WM_CLOSE:
		EndDialog(hdlg, 0);
		break;
	}
	return 0;
}