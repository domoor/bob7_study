#include <windows.h>

//void main()
void GotoXy()
{
	HANDLE hOut;
	TCHAR str[50];
	CONSOLE_SCREEN_BUFFER_INFO BufInfo;
	COORD Cur;
	DWORD dw;

	hOut = GetStdHandle(STD_OUTPUT_HANDLE);

	// ������ Ŀ�� ��ġ Ȯ��
	GetConsoleScreenBufferInfo(hOut, &BufInfo);
	wsprintf(str, "X=%d,y=%d", BufInfo.dwCursorPosition.X, BufInfo.dwCursorPosition.Y);

	// ������ ��ġ ����
	Cur.X = 50;
	Cur.Y = 10;
	SetConsoleCursorPosition(hOut, Cur);
	// ������ ��ġ�� ���ڿ� ���
	WriteFile(hOut, str, lstrlen(str), &dw, NULL);
}