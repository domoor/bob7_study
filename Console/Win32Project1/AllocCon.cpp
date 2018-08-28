#include "stdafx.h"
#include <stdio.h>
#include <tchar.h>

LRESULT CALLBACK WndProc(HWND hWnd, UINT iMessage, WPARAM wParam, LPARAM lParam)
{
	HDC hdc;
	PAINTSTRUCT ps;
	DWORD dw;
	TCHAR *str = "New Console is created";
	TCHAR *Mes = TEXT("���콺 ���� ��ư�� ������ ���ο� �ܼ� �����츦 ����ϴ�");

	switch (iMessage) {
	case WM_LBUTTONDOWN:
		if (AllocConsole() == FALSE) {
			//�ܼ� ���� ����
			puts("");
		}
		// ����ϴ� �Լ� //
		/* �ڵ鰪, ���ڿ� ���� ����, ���ڿ��� ����, �Լ� ȣ�� �� ������ ���� ����, NULL */
		WriteFile(GetStdHandle(STD_OUTPUT_HANDLE), str, lstrlen(str), &dw, NULL);
		Sleep(3000);
		FreeConsole();
		break;
	case WM_PAINT:
		// GUI â ����
		hdc = BeginPaint(hWnd, &ps);
		// GUI ���� 50, 50 ��ġ�� �޼��� ���
		TextOut(hdc, 50, 50, Mes, lstrlen(Mes));
		EndPaint(hWnd, &ps);
		return 0;
	case WM_DESTROY:
		PostQuitMessage(0);
		return 0;
	}
	return(DefWindowProc(hWnd, iMessage, wParam, lParam));
}