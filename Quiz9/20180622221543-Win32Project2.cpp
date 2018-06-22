// Win32Project2.cpp : 응용 프로그램에 대한 진입점을 정의합니다.
//

#include "stdafx.h"
#include "Win32Project2.h"

#define MAX_LOADSTRING 100

// 전역 변수:
HINSTANCE hInst;                                // 현재 인스턴스입니다.
WCHAR szTitle[MAX_LOADSTRING];                  // 제목 표시줄 텍스트입니다.
WCHAR szWindowClass[MAX_LOADSTRING];            // 기본 창 클래스 이름입니다.

// 이 코드 모듈에 들어 있는 함수의 정방향 선언입니다.
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

    // TODO: 여기에 코드를 입력합니다.

    // 전역 문자열을 초기화합니다.
    LoadStringW(hInstance, IDS_APP_TITLE, szTitle, MAX_LOADSTRING);
    LoadStringW(hInstance, IDC_WIN32PROJECT2, szWindowClass, MAX_LOADSTRING);
    MyRegisterClass(hInstance);

    // 응용 프로그램 초기화를 수행합니다.
    if (!InitInstance (hInstance, nCmdShow))
    {
        return FALSE;
    }

    HACCEL hAccelTable = LoadAccelerators(hInstance, MAKEINTRESOURCE(IDC_WIN32PROJECT2));

    MSG msg;

    // 기본 메시지 루프입니다.
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
//  함수: MyRegisterClass()
//
//  목적: 창 클래스를 등록합니다.
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
//   함수: InitInstance(HINSTANCE, int)
//
//   목적: 인스턴스 핸들을 저장하고 주 창을 만듭니다.
//
//   설명:
//
//        이 함수를 통해 인스턴스 핸들을 전역 변수에 저장하고
//        주 프로그램 창을 만든 다음 표시합니다.
//
BOOL InitInstance(HINSTANCE hInstance, int nCmdShow)
{
   hInst = hInstance; // 인스턴스 핸들을 전역 변수에 저장합니다.

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
//  함수: WndProc(HWND, UINT, WPARAM, LPARAM)
//
//  목적:  주 창의 메시지를 처리합니다.
//
//  WM_COMMAND  - 응용 프로그램 메뉴를 처리합니다.
//  WM_PAINT    - 주 창을 그립니다.
//  WM_DESTROY  - 종료 메시지를 게시하고 반환합니다.
//
//

#define RAD 20 //원의 반지름, 큰 수를 주면 원이 커짐.
//fuction isSelect : 중심점이 center이고 반지름이 rad인
//원의 내부에 pt라는 좌표가 있는지 판별하는 함수

int isSelect(POINT center, POINT pt, int rad)
{
	int disSquar = (center.x - pt.x) *(center.x - pt.x) +
		(center.y - pt.y)*(center.y - pt.y);
	if (rad*rad >= disSquar)
	{	//pt가 원내부에 있음
		return 1;
	}
	else
	{	//pt가 원외부에 있음
		return 0;
	}
}
LRESULT CALLBACK WndProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam)
{
	static POINT ptC = { 20, 20 }; //원의 중심좌표, 원의 반지름에 따라 변환.
	static POINT ptDest;
	static POINT ptCur;

	static int tx, ty;
	static RECT r;
	static int state = 0;
	static POINT ptStart, ptEnd;
	static int clk; // 마우스 클릭여부
	static int z; // 직선의 시작점이 원안에 있는지
	GetClientRect(hWnd, &r);

	switch (message)
	{
	case WM_LBUTTONDOWN:  //직선의 시작점을 얻어온다.

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

	case WM_LBUTTONUP: //목적지의 좌표를 받아온다.
		state = 0;
		clk = 0;
		if (z)
		{
			if (state == 0)
			{
				ptDest.x = LOWORD(lParam);
				ptDest.y = HIWORD(lParam);
				tx = (ptDest.x - ptC.x) / RAD; //이동할 방향과 속도 계산
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
				//원이 윈도우 밖으로 나가려할때.
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
		if (clk)// 좌버튼이 눌려 졌을때 직선의 끝점을 얻어온다.
		{
			ptEnd.x = LOWORD(lParam);
			ptEnd.y = HIWORD(lParam);
			InvalidateRgn(hWnd, NULL, TRUE); //그림을 그려준다.
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

// 정보 대화 상자의 메시지 처리기입니다.
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
