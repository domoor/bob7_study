#include <windows.h>
#include <stdio.h>

/* �ܼ�â ��Ŭ�� - �Ӽ�(P) - ���� ���� ���(Q) üũ ���� �ʼ� */

//void main()
void MouseInput()
{
	HANDLE hIn, hOut;
	DWORD dw;
	INPUT_RECORD rec;

	hIn = GetStdHandle(STD_INPUT_HANDLE);
	hOut = GetStdHandle(STD_OUTPUT_HANDLE);

	while(TRUE) {
		ReadConsoleInput(hIn, &rec, 1, &dw);
		// Ű���� �Է� �� �� ���� ���
		if(rec.EventType == KEY_EVENT && rec.Event.KeyEvent.bKeyDown == TRUE) {
			printf("%c", rec.Event.KeyEvent.uChar.AsciiChar);
		}
		// �巹�� �� �� ��ġ�� "." ���
		if(rec.EventType == MOUSE_EVENT) {
			if((rec.Event.MouseEvent.dwButtonState & FROM_LEFT_1ST_BUTTON_PRESSED)
				&& (rec.Event.MouseEvent.dwEventFlags & MOUSE_MOVED)) {
				SetConsoleCursorPosition(hOut, rec.Event.MouseEvent.dwMousePosition);
				printf(".");
			}
		}
		// ���� Ŭ���� ����
		if (rec.Event.MouseEvent.dwEventFlags & DOUBLE_CLICK) {
			break;
		}
	}
}