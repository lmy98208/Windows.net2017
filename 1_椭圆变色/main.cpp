#include<Windows.h>
LRESULT CALLBACK WndProc(HWND, UINT, WPARAM, LPARAM);
int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInst, LPSTR lpszCmdLine, int nCmdShow)
{
	HWND hwnd;
	MSG msg;
	WNDCLASS wndclass;
	TCHAR lpszClassName[] = L"My_Drawing";
	TCHAR lpszTitle[] = L"»ù±¾»æÍ¼";
	wndclass.style = 0;
	wndclass.lpfnWndProc = WndProc;
	wndclass.cbClsExtra = 0;
	wndclass.cbWndExtra = 0;
	wndclass.hInstance = hInstance;
	wndclass.hIcon = LoadIcon(NULL, IDI_APPLICATION);
	wndclass.hCursor = LoadCursor(NULL, IDC_ARROW);
	wndclass.hbrBackground = (HBRUSH)GetStockObject(WHITE_BRUSH);
	wndclass.lpszMenuName = NULL;
	wndclass.lpszClassName = lpszClassName;
	if (!RegisterClass(&wndclass))
	{
		MessageBeep(0);
		return FALSE;
	}
	hwnd = CreateWindow(lpszClassName, lpszTitle, WS_OVERLAPPEDWINDOW, CW_USEDEFAULT, CW_USEDEFAULT, CW_USEDEFAULT, CW_USEDEFAULT, NULL, NULL, hInstance, NULL);
	ShowWindow(hwnd, nCmdShow);
	UpdateWindow(hwnd);
	while (GetMessage(&msg, NULL, 0, 0))
	{
		TranslateMessage(&msg);
		DispatchMessage(&msg);
	}
	return msg.wParam;
}
LRESULT CALLBACK WndProc(HWND hwnd, UINT message, WPARAM wParam, LPARAM lParam)
{
	HDC hdc;
	PAINTSTRUCT ps;
	HBRUSH hb = CreateSolidBrush(RGB(0, 0, 0));
	RECT rect = { 0,0,0,0 };
	LPRECT lpRect = &rect;
	static int dispMode = -1;
	switch (message)
	{
	case WM_RBUTTONDOWN:
		InvalidateRect(hwnd, NULL, TRUE);
		break;
	case WM_PAINT:
		hdc = BeginPaint(hwnd, &ps);
		SetMapMode(hdc, MM_TEXT);
		GetClientRect(hwnd, lpRect);
		dispMode = (dispMode + 1) % 6;
		switch (dispMode)
		{
		case 0:
			hb = CreateSolidBrush(RGB(255, 0, 0));
			SelectObject(hdc, hb);
			Ellipse(hdc, lpRect->left, lpRect->top, lpRect->right, lpRect->bottom);
			break;
		case 1:
			hb = CreateSolidBrush(RGB(0, 255, 0));
			SelectObject(hdc, hb);
			Ellipse(hdc, lpRect->left, lpRect->top, lpRect->right, lpRect->bottom);
			break;
		case 2:
			hb = CreateSolidBrush(RGB(0, 0, 255));
			SelectObject(hdc, hb);
			Ellipse(hdc, lpRect->left, lpRect->top, lpRect->right, lpRect->bottom);
			break;
		case 3:
			hb = CreateSolidBrush(RGB(0, 225, 255));
			SelectObject(hdc, hb);
			Ellipse(hdc, lpRect->left, lpRect->top, lpRect->right, lpRect->bottom);
			break;
		case 4:
			hb = CreateSolidBrush(RGB(225, 0, 255));
			SelectObject(hdc, hb);
			Ellipse(hdc, lpRect->left, lpRect->top, lpRect->right, lpRect->bottom);
			break;
		case 5:
			hb = CreateSolidBrush(RGB(225, 225, 0));
			SelectObject(hdc, hb);
			Ellipse(hdc, lpRect->left, lpRect->top, lpRect->right, lpRect->bottom);
			break;
		}
		EndPaint(hwnd, &ps);
		DeleteObject(hb);
		break;
	case WM_DESTROY:
		PostQuitMessage(0);
		break;
	default:
		return DefWindowProc(hwnd, message, wParam, lParam);
	}
	return 0;
}