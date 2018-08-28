#pragma once

#include <SDKDDKVer.h>

#define WIN32_LEAN_AND_MEAN             // ���� ������ �ʴ� ������ Windows ������� �����մϴ�.
// Windows ��� ����:
#include <windows.h>

// C ��Ÿ�� ��� �����Դϴ�.
//#include <stdlib.h>
//#include <malloc.h>
//#include <memory.h>
//#include <tchar.h>
#include <stdio.h>

LRESULT CALLBACK WndProc(HWND hWnd, UINT iMessage, WPARAM wParam, LPARAM lParam)
{
	HDC hdc;
	PAINTSTRUCT ps;
	DWORD dw;
	TCHAR *str = TEXT("New Console is created");
	TCHAR *Mes = TEXT("���콺 ���� ��ư�� ������ ���ο� �ܼ� �����츦 ����ϴ�");

	switch (iMessage) {
	case WM_LBUTTONDOWN:
		if (AllocConsole() == FALSE) {
			//�ܼ� ���� ����
			puts("");
		}
		WriteFile(GetStdHandle(STD_OUTPUT_HANDLE), str, lstrlen(str), &dw, NULL);
		Sleep(3000);
		FreeConsole();
		break;
	case WM_PAINT:
		hdc = BeginPaint(hWnd, &ps);
		TextOut(hdc, 50, 50, Mes, lstrlen(Mes));
		EndPaint(hWnd, &ps);
		return 0;
	case WM_DESTROY:
		PostQuitMessage(0);
		return 0;
	}
	return(DefWindowProc(hWnd, iMessage, wParam, lParam));
}

int APIENTRY wWinMain(_In_ HINSTANCE hInstance,
	_In_opt_ HINSTANCE hPrevInstance,
	_In_ LPWSTR    lpCmdLine,
	_In_ int       nCmdShow)
{
	UNREFERENCED_PARAMETER(hPrevInstance);
	UNREFERENCED_PARAMETER(lpCmdLine);

	// TODO: ���⿡ �ڵ带 �Է��մϴ�.

	return 0;
}