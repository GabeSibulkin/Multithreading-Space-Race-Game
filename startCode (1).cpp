// GT_HelloWorldWin32.cpp  
// compile with: /D_UNICODE /DUNICODE /DWIN32 /D_WINDOWS /c  

// https://msdn.microsoft.com/en-us/library/bb384843.aspx

#include <windows.h>  
#include <stdlib.h>  
#include <string.h>  
#include <tchar.h>  
#include <objidl.h>
#include <thread> 
#include <atomic> 
#include <list> 
#include <iostream>

// If you want GDI+
#include <gdiplus.h>
using namespace Gdiplus;

#include <gdiplusgraphics.h>



#pragma comment(lib, "gdiplus.lib")


// Global variables  
HDC hdc;
// The main window class name.  
static TCHAR szWindowClass[] = _T("win32app");

// The string that appears in the application's title bar.  
static TCHAR szTitle[] = _T("Space Race");

HINSTANCE hInst;

// Forward declarations of functions included in this code module:  
LRESULT CALLBACK WndProc(HWND, UINT, WPARAM, LPARAM);

std::atomic_bool run = true; 

const DWORD FIXED_SIZED_WINDOW = (WS_OVERLAPPED | WS_CAPTION | WS_SYSMENU | WS_MINIMIZEBOX | WS_MAXIMIZEBOX);
const int HEIGHT = 1000;
const int WIDTH = 1100;

int P1score = 0;
int P2score = 0;

std::atomic_int D1x = 500;
std::atomic_int D1y = 40;

std::atomic_int D2x = 1000;
std::atomic_int D2y = 200;

std::atomic_int D3x = 45;
std::atomic_int D3y = 500;

std::atomic_int D4x = 400;
std::atomic_int D4y = 400;

std::atomic_int D5x = 700;
std::atomic_int D5y = 250;

std::atomic_int D6x = 100;
std::atomic_int D6y = 550;

std::atomic_int D7x = 800;
std::atomic_int D7y = 220;

std::atomic_int D8x = 300;
std::atomic_int D8y = 280;

std::atomic_int D9x = 450;
std::atomic_int D9y = 300;

std::atomic_int D10x = 120;
std::atomic_int D10y = 330;

std::atomic_int D11x = 200;
std::atomic_int D11y = 360;

std::atomic_int D12x = 100;
std::atomic_int D12y = 380;

std::atomic_int D13x = 900;
std::atomic_int D13y = 420;

std::atomic_int D14x = 750;
std::atomic_int D14y = 60;

std::atomic_int D15x = 50;
std::atomic_int D15y = 80;

std::atomic_int D16x = 100;
std::atomic_int D16y = 100;

std::atomic_int D17x = 200;
std::atomic_int D17y = 120;

std::atomic_int D18x = 20;
std::atomic_int D18y = 140;

std::atomic_int D19x = 600;
std::atomic_int D19y = 160;

std::atomic_int D20x = 350;
std::atomic_int D20y = 180;

std::atomic_int X = 200;
std::atomic_int Y = 600;

std::atomic_int X2 = 700;
std::atomic_int Y2 = 600;



void game(HWND hWnd)
{
	while (run)
	{
		
		// update game logic here 
		//x += 10;

		if (P1score == 3 || P2score == 3)
		{
			Sleep(5000);
			P1score = 0;
			P2score = 0;
		}

		if (Y == 0)
		{
			P1score++;
			Y = 600;
		}

		if (Y2 == 0)
		{
			P2score++;
			Y2 = 600;
		}


		// draw game
		InvalidateRect(hWnd, NULL, TRUE);

		if (D1x < 0) // R2L
		{
			D1x = 1000;
		}

		if (D2x < 0) // R2L
		{
			D2x = 1000;
		}

		if (D3x > 1000) //L2R
		{
			D3x = 0;
		}

		if (D4x < 0)//R2L
		{
			D4x = 1000;
		}

		if (D5x > 1000)//L2R
		{
			D5x = 0;
		}

		if (D6x > 1000)//L2R
		{
			D6x = 0;
		}

		if (D7x > 1000)//L2R
		{
			D7x = 0;
		}

		if (D8x > 1000)//L2R
		{
			D8x = 0;
		}

		if (D9x > 1000)//L2R
		{
			D9x = 0;
		}

		if (D10x > 1000)//L2R
		{
			D10x = 0;
		}

		if (D11x < 0)//R2L
		{
			D11x = 1000;
		}

		if (D12x < 0)//R2L
		{
			D12x = 1000;
		}

		if (D13x < 0)//R2L
		{
			D13x = 1000;
		}

		if (D14x > 1000)//L2R
		{
			D14x = 0;
		}

		if (D15x > 1000)//L2R
		{
			D15x = 0;
		}

		if (D16x > 1000)//L2R
		{
			D16x = 0;
		}

		if (D17x < 0)//R2L
		{
			D17x = 1000;
		}

		if (D18x < 0)//R2L
		{
			D18x = 1000;
		}

		if (D19x < 0)//R2L
		{
			D19x = 1000;
		}

		if (D20x < 0)//R2L
		{
			D20x = 1000;
		}

		if (X < 0 || X > 1000) //Map bounds checking for ship
		{
			if (X < 0)
			{
				X = 1;
			}
			if (X > 1000)
			{
				X = 999;
			}
		}

		if (Y > 600) //Backwards checking
		{
			Y = 600;
		}

		if (X2 < 0 || X2 > 1000) //Map bounds checking for ship
		{
			if (X2 < 0)
			{
				X2 = 1;
			}
			if (X2 > 1000)
			{
				X2 = 999;
			}
		}

		if (Y2 > 600) //Backwards checking
		{
			Y2 = 600;
		}

		if (X == D1x && (Y + 20) == D1y) // Asteroid collision resets
		{
			PlaySound(TEXT("ExplosionSound.wav"), NULL, SND_ASYNC);
			
			X = 200;
			Y = 600;

		}

		if (X == D2x && (Y + 20) == D2y) // Asteroid collision resets
		{
			PlaySound(TEXT("ExplosionSound.wav"), NULL, SND_ASYNC);
			X = 200;
			Y = 600;
		}

		if (X == D3x && (Y + 20) == D3y) // Asteroid collision resets
		{
			PlaySound(TEXT("ExplosionSound.wav"), NULL, SND_ASYNC);
			X = 200;
			Y = 600;
		}

		if (X == D4x && (Y + 20) == D4y) // Asteroid collision resets
		{
			PlaySound(TEXT("ExplosionSound.wav"), NULL, SND_ASYNC);
			X = 200;
			Y = 600;
		}

		if (X == D5x && (Y + 20) == D5y) // Asteroid collision resets
		{
			PlaySound(TEXT("ExplosionSound.wav"), NULL, SND_ASYNC);
			X = 200;
			Y = 600;
		}

		if (X == D6x && (Y + 20) == D6y) // Asteroid collision resets
		{
			PlaySound(TEXT("ExplosionSound.wav"), NULL, SND_ASYNC);
			X = 200;
			Y = 600;
		}

		if (X == D7x && (Y + 20) == D7y) // Asteroid collision resets
		{
			PlaySound(TEXT("ExplosionSound.wav"), NULL, SND_ASYNC);
			X = 200;
			Y = 600;
		}

		if (X == D8x && (Y + 20) == D8y) // Asteroid collision resets
		{
			PlaySound(TEXT("ExplosionSound.wav"), NULL, SND_ASYNC);
			X = 200;
			Y = 600;
		}

		if (X == D9x && (Y + 20) == D9y) // Asteroid collision resets
		{
			PlaySound(TEXT("ExplosionSound.wav"), NULL, SND_ASYNC);
			X = 200;
			Y = 600;
		}

		if (X == D10x && (Y + 20) == D10y) // Asteroid collision resets
		{
			PlaySound(TEXT("ExplosionSound.wav"), NULL, SND_ASYNC);
			X = 200;
			Y = 600;
		}

		if (X == D11x && (Y + 20) == D11y) // Asteroid collision resets
		{
			PlaySound(TEXT("ExplosionSound.wav"), NULL, SND_ASYNC);
			X = 200;
			Y = 600;
		}

		if (X == D12x && (Y + 20) == D12y) // Asteroid collision resets
		{
			PlaySound(TEXT("ExplosionSound.wav"), NULL, SND_ASYNC);
			X = 200;
			Y = 600;
		}

		if (X == D13x && (Y + 20) == D13y) // Asteroid collision resets
		{
			PlaySound(TEXT("ExplosionSound.wav"), NULL, SND_ASYNC);
			X = 200;
			Y = 600;
		}

		if (X == D14x && (Y + 20) == D14y) // Asteroid collision resets
		{
			PlaySound(TEXT("ExplosionSound.wav"), NULL, SND_ASYNC);
			X = 200;
			Y = 600;
		}

		if (X == D15x && (Y + 20) == D15y) // Asteroid collision resets
		{
			PlaySound(TEXT("ExplosionSound.wav"), NULL, SND_ASYNC);
			X = 200;
			Y = 600;
		}

		if (X == D16x && (Y + 20) == D16y) // Asteroid collision resets
		{
			PlaySound(TEXT("ExplosionSound.wav"), NULL, SND_ASYNC);
			X = 200;
			Y = 600;
		}

		if (X == D17x && (Y + 20) == D17y) // Asteroid collision resets
		{
			PlaySound(TEXT("ExplosionSound.wav"), NULL, SND_ASYNC);
			X = 200;
			Y = 600;
		}

		if (X == D18x && (Y + 20) == D18y) // Asteroid collision resets
		{
			PlaySound(TEXT("ExplosionSound.wav"), NULL, SND_ASYNC);
			X = 200;
			Y = 600;
		}

		if (X == D19x && (Y + 20) == D19y) // Asteroid collision resets
		{
			PlaySound(TEXT("ExplosionSound.wav"), NULL, SND_ASYNC);
			X = 200;
			Y = 600;
		}

		if (X == D20x && (Y + 20) == D20y) // Asteroid collision resets
		{
			PlaySound(TEXT("ExplosionSound.wav"), NULL, SND_ASYNC);
			X = 200;
			Y = 600;
		}



		if (X2 == D1x && (Y2 + 20) == D1y) // Asteroid collision resets
		{
			PlaySound(TEXT("ExplosionSound.wav"), NULL, SND_ASYNC);

			X2 = 700;
			Y2 = 600;

		}

		if (X2 == D2x && (Y2 + 20) == D2y) // Asteroid collision resets
		{
			PlaySound(TEXT("ExplosionSound.wav"), NULL, SND_ASYNC);
			X2 = 700;
			Y2 = 600;
		}

		if (X2 == D3x && (Y2 + 20) == D3y) // Asteroid collision resets
		{
			PlaySound(TEXT("ExplosionSound.wav"), NULL, SND_ASYNC);
			X2 = 700;
			Y2 = 600;
		}

		if (X2 == D4x && (Y2 + 20) == D4y) // Asteroid collision resets
		{
			PlaySound(TEXT("ExplosionSound.wav"), NULL, SND_ASYNC);
			X2 = 700;
			Y2 = 600;
		}

		if (X2 == D5x && (Y2 + 20) == D5y) // Asteroid collision resets
		{
			PlaySound(TEXT("ExplosionSound.wav"), NULL, SND_ASYNC);
			X2 = 700;
			Y2 = 600;
		}

		if (X2 == D6x && (Y2 + 20) == D6y) // Asteroid collision resets
		{
			PlaySound(TEXT("ExplosionSound.wav"), NULL, SND_ASYNC);
			X2 = 700;
			Y2 = 600;
		}

		if (X2 == D7x && (Y2 + 20) == D7y) // Asteroid collision resets
		{
			PlaySound(TEXT("ExplosionSound.wav"), NULL, SND_ASYNC);
			X2 = 700;
			Y2 = 600;
		}

		if (X2 == D8x && (Y2 + 20) == D8y) // Asteroid collision resets
		{
			PlaySound(TEXT("ExplosionSound.wav"), NULL, SND_ASYNC);
			X2 = 700;
			Y2 = 600;
		}

		if (X2 == D9x && (Y2 + 20) == D9y) // Asteroid collision resets
		{
			PlaySound(TEXT("ExplosionSound.wav"), NULL, SND_ASYNC);
			X2 = 700;
			Y2 = 600;
		}

		if (X2 == D10x && (Y2 + 20) == D10y) // Asteroid collision resets
		{
			PlaySound(TEXT("ExplosionSound.wav"), NULL, SND_ASYNC);
			X2 = 700;
			Y2 = 600;
		}

		if (X2 == D11x && (Y2 + 20) == D11y) // Asteroid collision resets
		{
			PlaySound(TEXT("ExplosionSound.wav"), NULL, SND_ASYNC);
			X2 = 700;
			Y2 = 600;
		}

		if (X2 == D12x && (Y2 + 20) == D12y) // Asteroid collision resets
		{
			PlaySound(TEXT("ExplosionSound.wav"), NULL, SND_ASYNC);
			X2 = 700;
			Y2 = 600;
		}

		if (X2 == D13x && (Y2 + 20) == D13y) // Asteroid collision resets
		{
			PlaySound(TEXT("ExplosionSound.wav"), NULL, SND_ASYNC);
			X2 = 700;
			Y2 = 600;
		}

		if (X2 == D14x && (Y2 + 20) == D14y) // Asteroid collision resets
		{
			PlaySound(TEXT("ExplosionSound.wav"), NULL, SND_ASYNC);
			X2 = 700;
			Y2 = 600;
		}

		if (X2 == D15x && (Y2 + 20) == D15y) // Asteroid collision resets
		{
			PlaySound(TEXT("ExplosionSound.wav"), NULL, SND_ASYNC);
			X2 = 700;
			Y2 = 600;
		}

		if (X2 == D16x && (Y2 + 20) == D16y) // Asteroid collision resets
		{
			PlaySound(TEXT("ExplosionSound.wav"), NULL, SND_ASYNC);
			X2 = 700;
			Y2 = 600;
		}

		if (X2 == D17x && (Y2 + 20) == D17y) // Asteroid collision resets
		{
			PlaySound(TEXT("ExplosionSound.wav"), NULL, SND_ASYNC);
			X2 = 700;
			Y2 = 600;
		}

		if (X2 == D18x && (Y2 + 20) == D18y) // Asteroid collision resets
		{
			PlaySound(TEXT("ExplosionSound.wav"), NULL, SND_ASYNC);
			X2 = 700;
			Y2 = 600;
		}

		if (X2 == D19x && (Y2 + 20) == D19y) // Asteroid collision resets
		{
			PlaySound(TEXT("ExplosionSound.wav"), NULL, SND_ASYNC);
			X2 = 700;
			Y2 = 600;
		}

		if (X2 == D20x && (Y2 + 20) == D20y) // Asteroid collision resets
		{
			PlaySound(TEXT("ExplosionSound.wav"), NULL, SND_ASYNC);
			X2 = 700;
			Y2 = 600;
		}
	
	D1x -= 5;//R2L
	D2x -= 10;
	D3x += 20;//L2R
	D4x -= 20;
	D5x += 10;
	D6x += 10;
	D7x += 5;
	D8x += 10;
	D9x += 20;
	D10x += 10;
	D11x -= 20;
	D12x -= 10;
	D13x -= 5;
	D14x += 10;
	D15x += 20;
	D16x += 10;
	D17x -= 5;
	D18x -= 20;
	D19x -= 10;
	D20x -= 5;

		// update resolution
		Sleep(70);

	}// end game loop
}

int CALLBACK WinMain( _In_ HINSTANCE hInstance, _In_ HINSTANCE hPrevInstance, _In_ LPSTR     lpCmdLine, _In_ int       nCmdShow)
{

	WNDCLASSEX wcex;

	wcex.cbSize = sizeof(WNDCLASSEX);
	wcex.style = CS_HREDRAW | CS_VREDRAW;
	wcex.lpfnWndProc = WndProc;
	wcex.cbClsExtra = 0;
	wcex.cbWndExtra = 0;
	wcex.hInstance = hInstance;
	wcex.hIcon = LoadIcon(hInstance, MAKEINTRESOURCE(IDI_APPLICATION));
	wcex.hCursor = LoadCursor(NULL, IDC_ARROW);
	wcex.hbrBackground = (HBRUSH)GetStockObject(4);
	wcex.lpszMenuName = NULL;
	wcex.lpszClassName = szWindowClass;
	wcex.hIconSm = LoadIcon(wcex.hInstance, MAKEINTRESOURCE(IDI_APPLICATION));

	if (!RegisterClassEx(&wcex))
	{
		MessageBox(NULL,
			_T("Call to RegisterClassEx failed!"),
			_T("Win32 Guided Tour"),
			NULL);

		return 1;
	}

	hInst = hInstance; // Store instance handle in our global variable  

	// The parameters to CreateWindow explained:  
	// szWindowClass: the name of the application  
	// szTitle: the text that appears in the title bar  
	// WS_OVERLAPPEDWINDOW: the type of window to create  
	// CW_USEDEFAULT, CW_USEDEFAULT: initial position (x, y)  
	// 500, 100: initial size (width, length)  
	// NULL: the parent of this window  
	// NULL: this application does not have a menu bar  
	// hInstance: the first parameter from WinMain  
	// NULL: not used in this application  
	HWND hWnd = CreateWindow(
		szWindowClass,
		szTitle,
		FIXED_SIZED_WINDOW,
		CW_USEDEFAULT, CW_USEDEFAULT,
		WIDTH, HEIGHT,
		NULL,
		NULL,
		hInstance,
		NULL
	);

	// if you want GDI+
	// Initialize GDI+
	ULONG_PTR m_gdiplusToken = 0;
	Gdiplus::GdiplusStartupInput gdiplusStartupInput;
	Gdiplus::GdiplusStartup(&m_gdiplusToken, &gdiplusStartupInput, NULL);


	if (!hWnd)
	{
		MessageBox(NULL,
			_T("Call to CreateWindow failed!"),
			_T("Win32 Guided Tour"),
			NULL);

		return 1;
	}

	// The parameters to ShowWindow explained:  
	// hWnd: the value returned from CreateWindow  
	// nCmdShow: the fourth parameter from WinMain  
	ShowWindow(hWnd, nCmdShow);
	UpdateWindow(hWnd);

	// start game thread
	run = true;
	std::thread t{ game, hWnd };

	// Main message loop:  
	MSG msg;
	while (GetMessage(&msg, NULL, 0, 0))
	{
		TranslateMessage(&msg);
		DispatchMessage(&msg);
	}
	
	// kill game thread
	run = false;
	t.join();
	GdiplusShutdown(m_gdiplusToken);
	return (int)msg.wParam;
	
	
}


//  
//  FUNCTION: WndProc(HWND, UINT, WPARAM, LPARAM)  
//  
//  PURPOSE:  Processes messages for the main window.  
//  
//  WM_PAINT    - Paint the main window  
//  WM_DESTROY  - post a quit message and return  
//  
//  
LRESULT CALLBACK WndProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam)
{
	PAINTSTRUCT ps;
	int count;

	switch (message)
	{
	case WM_PAINT:
	{
		hdc = BeginPaint(hWnd, &ps);

		// draw game here 
		
		Gdiplus::Graphics gf(hdc);
		
		Gdiplus::Pen pen(Gdiplus::Color(0, 0, 0));
		Gdiplus::SolidBrush brush(Gdiplus::Color(255, 255, 255));

		Gdiplus::Bitmap P1Ship(L"Spaceship.PNG");
		gf.DrawImage(&P1Ship, X, Y, 40, 40);

		Gdiplus::Bitmap P2Ship(L"PLayer2Ship.png");
		gf.DrawImage(&P2Ship, X2, Y2, 40, 40);

		
		WCHAR string0[] = L"Score = 0 ";
		WCHAR string1[] = L"Score = 1 ";
		WCHAR string2[] = L"Score = 2 ";
		WCHAR string3[] = L"Player 1 Wins! Restarting in 5 seconds. ";

		WCHAR string20[] = L"Score = 0 ";
		WCHAR string21[] = L"Score = 1 ";
		WCHAR string22[] = L"Score = 2 ";
		WCHAR string23[] = L"Player 2 Wins!  Restarting in 5 seconds. ";

		// Initialize arguments.
		Font myFontP1(L"Arial", 16);
		PointF originP1(10, 600);
		SolidBrush blackBrushP1(Color(255, 255, 255, 255));


		Font myFontP2(L"Arial", 16);
		PointF originP2(900, 600);
		SolidBrush blackBrushP2(Color(255, 255, 255, 255));

		if (P1score == 0)
		{
			gf.DrawString(
				string0,
				10,
				&myFontP1,
				originP1,
				&blackBrushP1);
		}
		
		if (P1score == 1)
		{
			gf.DrawString(
				string1,
				10,
				&myFontP1,
				originP1,
				&blackBrushP1);
		}

		if (P1score == 2)
		{
			gf.DrawString(
				string2,
				10,
				&myFontP1,
				originP1,
				&blackBrushP1);
		}

		if (P1score == 3)
		{
			gf.DrawString(
				string3,
				40,
				&myFontP1,
				originP1,
				&blackBrushP1);
		}

		if (P2score == 0)
		{
			gf.DrawString(
				string20,
				10,
				&myFontP2,
				originP2,
				&blackBrushP2);
		}

		if (P2score == 1)
		{
			gf.DrawString(
				string21,
				10,
				&myFontP2,
				originP2,
				&blackBrushP2);
		}

		if (P2score == 2)
		{
			gf.DrawString(
				string22,
				10,
				&myFontP2,
				originP2,
				&blackBrushP2);
		}

		if (P2score == 3)
		{
			gf.DrawString(
				string23,
				15,
				&myFontP2,
				originP2,
				&blackBrushP2);
		}
			
		
		gf.FillEllipse(&brush, D1x, D1y, 7, 3);
		gf.FillEllipse(&brush, D2x, D2y, 7, 3);
		gf.FillEllipse(&brush, D3x, D3y, 7, 3);
		gf.FillEllipse(&brush, D4x, D4y, 7, 3);
		gf.FillEllipse(&brush, D5x, D5y, 7, 3);
		gf.FillEllipse(&brush, D6x, D6y, 7, 3);
		gf.FillEllipse(&brush, D7x, D7y, 7, 3);
		gf.FillEllipse(&brush, D8x, D8y, 7, 3);
		gf.FillEllipse(&brush, D9x, D9y, 7, 3);
		gf.FillEllipse(&brush, D10x, D10y, 7, 3);
		gf.FillEllipse(&brush, D11x, D11y, 7, 3);
		gf.FillEllipse(&brush, D12x, D12y, 7, 3);
		gf.FillEllipse(&brush, D13x, D13y, 7, 3);
		gf.FillEllipse(&brush, D14x, D14y, 7, 3);
		gf.FillEllipse(&brush, D15x, D15y, 7, 3);
		gf.FillEllipse(&brush, D16x, D16y, 7, 3);
		gf.FillEllipse(&brush, D17x, D17y, 7, 3);
		gf.FillEllipse(&brush, D18x, D18y, 7, 3);
		gf.FillEllipse(&brush, D19x, D19y, 7, 3);
		gf.FillEllipse(&brush, D20x, D20y, 7, 3);
		

		EndPaint(hWnd, &ps);
	}
	break;

	case WM_KEYDOWN:

		// Key codes: https://msdn.microsoft.com/en-us/library/windows/desktop/dd375731(v=vs.85).aspx
		// wParam contains key code
		switch (wParam)
		{
			case VK_RIGHT:
			{
				X += 10;

				break;
			}
			case VK_LEFT:
			{

				X -= 10;
				break;
			}
			case VK_UP:
			{
				Y -= 10;
				break;
			}
			case VK_DOWN:
			{
				Y += 10;
				break;
			}
			case 0x57: //W
			{
				Y2 -= 10;
				break;
			}
			case 0x41: //A
			{
				X2 -= 10;
				break;
			}
			case 0x53: //S
			{
				Y2 += 10;
				break;
			}
			case 0x44: //D
			{
				X2 += 10;
				break;
			}
			case VK_BACK:
			{
				PostQuitMessage(0);
			}
			default:
				break;
		}
		
	case WM_KEYUP:


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