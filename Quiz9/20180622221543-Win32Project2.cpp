// Win32Project2.cpp : ���� ���α׷��� ���� �������� �����մϴ�.
//

#include "stdafx.h"
#include "Win32Project2.h"

#define MAX_LOADSTRING 100

// ���� ����:
HINSTANCE hInst;                                // ���� �ν��Ͻ��Դϴ�.
WCHAR szTitle[MAX_LOADSTRING];                  // ���� ǥ���� �ؽ�Ʈ�Դϴ�.
WCHAR szWindowClass[MAX_LOADSTRING];            // �⺻ â Ŭ���� �̸��Դϴ�.

// �� �ڵ� ��⿡ ��� �ִ� �Լ��� ������ �����Դϴ�.
ATOM                MyRegisterClass(HINSTANCE hInstance);
BOOL                InitInstance(HINSTANCE, int);
LRESULT CALLBACK    WndProc(HWND, UINT, WPARAM, LPARAM);
INT_PTR CALLBACK    About(HWND, UINT, WPARAM, LPARAM);

int APIENTRY wWinMain(_In_ HINSTANCE hInstance,
                     _In_opt_ HINSTANCE hPrevInstance,
                     _In_ LPWSTR    lpCmdLine,
                     _In_ int       nCmdShow)
{
    UNREFERENCED_PARAMETER(hPrevInstance);
    UNREFERENCED_PARAMETER(lpCmdLine);

    // TODO: ���⿡ �ڵ带 �Է��մϴ�.

    // ���� ���ڿ��� �ʱ�ȭ�մϴ�.
    LoadStringW(hInstance, IDS_APP_TITLE, szTitle, MAX_LOADSTRING);
    LoadStringW(hInstance, IDC_WIN32PROJECT2, szWindowClass, MAX_LOADSTRING);
    MyRegisterClass(hInstance);

    // ���� ���α׷� �ʱ�ȭ�� �����մϴ�.
    if (!InitInstance (hInstance, nCmdShow))
    {
        return FALSE;
    }

    HACCEL hAccelTable = LoadAccelerators(hInstance, MAKEINTRESOURCE(IDC_WIN32PROJECT2));

    MSG msg;

    // �⺻ �޽��� �����Դϴ�.
    while (GetMessage(&msg, nullptr, 0, 0))
    {
        if (!TranslateAccelerator(msg.hwnd, hAccelTable, &msg))
        {
            TranslateMessage(&msg);
            DispatchMessage(&msg);
        }
    }

    return (int) msg.wParam;
}



//
//  �Լ�: MyRegisterClass()
//
//  ����: â Ŭ������ ����մϴ�.
//
ATOM MyRegisterClass(HINSTANCE hInstance)
{
    WNDCLASSEXW wcex;

    wcex.cbSize = sizeof(WNDCLASSEX);

    wcex.style          = CS_HREDRAW | CS_VREDRAW;
    wcex.lpfnWndProc    = WndProc;
    wcex.cbClsExtra     = 0;
    wcex.cbWndExtra     = 0;
    wcex.hInstance      = hInstance;
    wcex.hIcon          = LoadIcon(hInstance, MAKEINTRESOURCE(IDI_WIN32PROJECT2));
    wcex.hCursor        = LoadCursor(nullptr, IDC_ARROW);
    wcex.hbrBackground  = (HBRUSH)(COLOR_WINDOW+1);
    wcex.lpszMenuName   = MAKEINTRESOURCEW(IDC_WIN32PROJECT2);
    wcex.lpszClassName  = szWindowClass;
    wcex.hIconSm        = LoadIcon(wcex.hInstance, MAKEINTRESOURCE(IDI_SMALL));

    return RegisterClassExW(&wcex);
}

//
//   �Լ�: InitInstance(HINSTANCE, int)
//
//   ����: �ν��Ͻ� �ڵ��� �����ϰ� �� â�� ����ϴ�.
//
//   ����:
//
//        �� �Լ��� ���� �ν��Ͻ� �ڵ��� ���� ������ �����ϰ�
//        �� ���α׷� â�� ���� ���� ǥ���մϴ�.
//
BOOL InitInstance(HINSTANCE hInstance, int nCmdShow)
{
   hInst = hInstance; // �ν��Ͻ� �ڵ��� ���� ������ �����մϴ�.

   HWND hWnd = CreateWindowW(szWindowClass, szTitle, WS_OVERLAPPEDWINDOW,
      CW_USEDEFAULT, 0, CW_USEDEFAULT, 0, nullptr, nullptr, hInstance, nullptr);

   if (!hWnd)
   {
      return FALSE;
   }

   ShowWindow(hWnd, nCmdShow);
   UpdateWindow(hWnd);

   return TRUE;
}

//
//  �Լ�: WndProc(HWND, UINT, WPARAM, LPARAM)
//
//  ����:  �� â�� �޽����� ó���մϴ�.
//
//  WM_COMMAND  - ���� ���α׷� �޴��� ó���մϴ�.
//  WM_PAINT    - �� â�� �׸��ϴ�.
//  WM_DESTROY  - ���� �޽����� �Խ��ϰ� ��ȯ�մϴ�.
//
//

#define RAD 20 //���� ������, ū ���� �ָ� ���� Ŀ��.
//fuction isSelect : �߽����� center�̰� �������� rad��
//���� ���ο� pt��� ��ǥ�� �ִ��� �Ǻ��ϴ� �Լ�

int isSelect(POINT center, POINT pt, int rad)
{
	int disSquar = (center.x - pt.x) *(center.x - pt.x) +
		(center.y - pt.y)*(center.y - pt.y);
	if (rad*rad >= disSquar)
	{	//pt�� �����ο� ����
		return 1;
	}
	else
	{	//pt�� ���ܺο� ����
		return 0;
	}
}
LRESULT CALLBACK WndProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam)
{
	static POINT ptC = { 20, 20 }; //���� �߽���ǥ, ���� �������� ���� ��ȯ.
	static POINT ptDest;
	static POINT ptCur;

	static int tx, ty;
	static RECT r;
	static int state = 0;
	static POINT ptStart, ptEnd;
	static int clk; // ���콺 Ŭ������
	static int z; // ������ �������� ���ȿ� �ִ���
	GetClientRect(hWnd, &r);

	switch (message)
	{
	case WM_LBUTTONDOWN:  //������ �������� ���´�.

		if (isSelect(ptC, ptCur, RAD))
		{
			ptStart.x = ptC.x;
			ptStart.y = ptC.y;
			clk = 1;
			z = 1;
		}

		else
			z = 0;

		break;

	case WM_LBUTTONUP: //�������� ��ǥ�� �޾ƿ´�.
		state = 0;
		clk = 0;
		if (z)
		{
			if (state == 0)
			{
				ptDest.x = LOWORD(lParam);
				ptDest.y = HIWORD(lParam);
				tx = (ptDest.x - ptC.x) / RAD; //�̵��� ����� �ӵ� ���
				ty = (ptDest.y - ptC.y) / RAD;
				SetTimer(hWnd, 1, 10, NULL);
			}
		}
		else
		{
			tx = 0;
			ty = 0;
		}
		break;

	case WM_TIMER:
		if (state == 0)
		{
			switch (wParam)
			{
			case 1:
				ptC.x += tx;
				ptC.y += ty;
				//���� ������ ������ �������Ҷ�.
				if (ptC.x + RAD >= r.right ||
					ptC.x - RAD <= r.left)
				{
					tx = -tx;
				}
				if (ptC.y + RAD >= r.bottom ||
					ptC.y - RAD <= r.top)
				{
					ty = -ty;
				}
				InvalidateRgn(hWnd, NULL, TRUE);
				break;
			}
		}
		break;
	case WM_MOUSEMOVE:
		ptCur.x = LOWORD(lParam);
		ptCur.y = HIWORD(lParam);
		if (clk)// �¹�ư�� ���� ������ ������ ������ ���´�.
		{
			ptEnd.x = LOWORD(lParam);
			ptEnd.y = HIWORD(lParam);
			InvalidateRgn(hWnd, NULL, TRUE); //�׸��� �׷��ش�.
		}
		break;
	case WM_RBUTTONUP:
		state = 1;
		InvalidateRgn(hWnd, NULL, TRUE);
		break;
	case WM_PAINT:
	{
		PAINTSTRUCT ps;
		HDC hdc = BeginPaint(hWnd, &ps);

		Ellipse(hdc, ptC.x - RAD, ptC.y - RAD,
			ptC.x + RAD, ptC.y + RAD);
		if (clk)
		{
			MoveToEx(hdc, ptStart.x, ptStart.y, NULL);
			LineTo(hdc, ptEnd.x, ptEnd.y);
		}

		EndPaint(hWnd, &ps);
	}
	break;

	case WM_DESTROY:
		PostQuitMessage(0);
		break;
	default:
		return DefWindowProc(hWnd, message, wParam, lParam);
	}
	return 0;
}

// ���� ��ȭ ������ �޽��� ó�����Դϴ�.
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
