#include <Windows.h>
#include <stdio.h>

//void main()
void CharAttr()
{
	HANDLE hOut;
	TCHAR *str = "Console Test";
	COORD Size, Coor;
	DWORD dw;

	hOut = GetStdHandle(STD_OUTPUT_HANDLE);

	// �����ִ� ���ڸ� ������ ��ġ�� ���
	WORD Attr[] = { 0x81, 0xa2, 0x74, 0x24, 0x08, 0x09, 0x34, 0xff, 0xd1, 0xe1, 0x0d, 0x75 };
	Coor.X = 50;
	Coor.Y = 10;
	printf("%d\n", lstrlen(str));
	WriteConsoleOutputCharacter(hOut, str, lstrlen(str), Coor, &dw);
	WriteConsoleOutputAttribute(hOut, Attr, lstrlen(str), Coor, &dw);

	// ���ڿ� �Ӽ��� �Ѳ����� ���
	SMALL_RECT rt = {50, 12, 55, 12};
	Size.X = 5;
	Size.Y = 1;
	Coor.X = 0;
	Coor.Y = 0;
	CHAR_INFO arCh[5] = { {'K', 0x07}, {'O', 0x70}, {'R', 0x93}, {'E', 0x67}, {'A', 0xe8} };
	WriteConsoleOutput(hOut, arCh, Size, Coor, &rt);

	// ä��
	Coor.X = 5;
	Coor.Y = 14;
	FillConsoleOutputCharacter(hOut, '*', 10*5, Coor, &dw);
	FillConsoleOutputAttribute(hOut, 0xe4, 10*5, Coor, &dw);
}