#include <windows.h>
#include <iostream>
#include <stdio.h>

//void main() {
void ConOut() {
	HANDLE hOut;
	TCHAR *str = "Console Test\n";
	DWORD dwWritten;

	printf("%s", str);

	std::cout << str;

	hOut = GetStdHandle(STD_OUTPUT_HANDLE);
	/* dwWritten = �Լ� ȣ�� �Ϸ� �� ���۵� ���� ������ ũ�Ⱑ ���� ���� */
	WriteFile(hOut, str, lstrlen(str), &dwWritten, NULL);

	WriteConsole(hOut, str, lstrlen(str), &dwWritten, NULL);
}