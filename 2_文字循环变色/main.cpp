#include<windows.h>
#include<tchar.h>
BOOLEAN InitWindowsClass(HINSTANCE hInstance, int nCmdShow);
LRESULT CALLBACK WndProc(HWND, UINT, WPARAM, LPARAM);
//HFONT CreateFont(HDC hDC, int nCharHeight, BOOL bItalic);
//HWND hWndMain;
int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance,
	LPSTR lpCmdLine, int nCmdShow)
{
	MSG msg;
	if (!InitWindowsClass(hInstance, nCmdShow))
	{
		MessageBox(NULL, L"创建失败", _T("创建窗口"), NULL);
		return 1;
	}
	while (GetMessage(&msg, NULL, 0, 0))
	{
		TranslateMessage(&msg);
		DispatchMessage(&msg);
	}
	return (int)msg.wParam;
}

LRESULT CALLBACK WndProc(HWND hWnd, UINT message, UINT wParam, LONG lParam)
{
	HDC hDC;
	PAINTSTRUCT ps;
	TEXTMETRIC tm;
	LPCWSTR lpsz = L"学好数理化，走遍天下都不怕！";
	int X = 0, Y = 0;
	static int count=0;
	int i = 0;
	i = count % 6;
	count++;
	switch(message)
	{
	case WM_CREATE:
		SetTimer(hWnd, 1, 1000, NULL);
		break;
	case WM_TIMER:
		if (wParam == 1)
			InvalidateRect(hWnd,NULL,true);
		break;
	case WM_PAINT:
		hDC = BeginPaint(hWnd, &ps);	
		switch (i)
		{
		case 0: {
			SetTextColor(hDC, RGB(255, 255, 0));
			SetBkColor(hDC, RGB(255, 0, 0));
			GetTextMetrics(hDC, &tm);
			TextOut(hDC, X, Y, lpsz, _tcsclen(lpsz));
			EndPaint(hWnd, &ps);
			break; }
		case 1: {
			SetTextColor(hDC, RGB(128, 42, 42));
			SetBkColor(hDC, RGB(11, 23, 70));
			GetTextMetrics(hDC, &tm);
			TextOut(hDC, X, Y, lpsz, _tcsclen(lpsz));
			EndPaint(hWnd, &ps);
			break; }
		case 2: {
			SetTextColor(hDC, RGB(218, 112, 214));
			SetBkColor(hDC, RGB(0, 0, 255));
			GetTextMetrics(hDC, &tm);
			TextOut(hDC, X, Y, lpsz, _tcsclen(lpsz));
			EndPaint(hWnd, &ps);
			break; }
		case 3: {
			SetTextColor(hDC, RGB(255, 0, 0));
			SetBkColor(hDC, RGB(255, 255, 0));
			GetTextMetrics(hDC, &tm);
			TextOut(hDC, X, Y, lpsz, _tcsclen(lpsz));
			EndPaint(hWnd, &ps);
			break; }
		case 4: {
			SetTextColor(hDC, RGB(138, 43, 226));
			SetBkColor(hDC, RGB(250, 240, 230));
			GetTextMetrics(hDC, &tm);
			TextOut(hDC, X, Y, lpsz, _tcsclen(lpsz));
			EndPaint(hWnd, &ps);
			break; }
		default: {
			SetTextColor(hDC, RGB(34, 139, 34));
			SetBkColor(hDC, RGB(210, 180, 140));
			GetTextMetrics(hDC, &tm);
			TextOut(hDC, X, Y, lpsz, _tcsclen(lpsz));
			EndPaint(hWnd, &ps);
			break; }
		}
		/*GetTextMetrics(hDC, &tm);
		TextOut(hDC, X, Y, lpsz, _tcsclen(lpsz));
		EndPaint(hWnd, &ps);*/
		break;
	case WM_DESTROY:
		PostQuitMessage(0);
		break;
	default:
		return DefWindowProc(hWnd, message, wParam, lParam);
		break;
	}
	return 0;
}

BOOLEAN InitWindowsClass(HINSTANCE hInstance, int nCmdShow)
{
	WNDCLASSEX wcex;
	HWND hWnd;
	TCHAR szWindowClass[] = L"窗口示例";
	TCHAR szTitle[] = L"填充";
	wcex.cbSize = sizeof(WNDCLASSEX);
	wcex.style = 0;
	wcex.lpfnWndProc = WndProc;
	wcex.cbClsExtra = 0;
	wcex.cbWndExtra = 0;
	wcex.hInstance = hInstance;
	wcex.hIcon = LoadIcon(hInstance, MAKEINTRESOURCE(IDI_APPLICATION));
	wcex.hCursor = LoadCursor(NULL, IDC_ARROW);
	wcex.hbrBackground = (HBRUSH)GetStockObject(WHITE_BRUSH);
	wcex.lpszMenuName = NULL;
	wcex.lpszClassName= szWindowClass;
	wcex.hIconSm = LoadIcon(wcex.hInstance, MAKEINTRESOURCE(IDI_APPLICATION));
	if (!RegisterClassEx(&wcex))
		return FALSE;
	hWnd = CreateWindow(szWindowClass,
		szTitle,

		WS_OVERLAPPEDWINDOW,
		CW_USEDEFAULT, CW_USEDEFAULT,
		CW_USEDEFAULT, CW_USEDEFAULT,
		NULL, NULL,
		hInstance,
		NULL
	);
	if (!hWnd)
		return FALSE;
	ShowWindow(hWnd, nCmdShow);
	UpdateWindow(hWnd);
	return TRUE;
}