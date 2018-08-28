#include <windows.h> 
#include <stdio.h> 

BOOL CtrlHandler(DWORD fdwCtrlType)
{
	switch (fdwCtrlType)
	{
		// Handle the CTRL-C signal. 
	case CTRL_C_EVENT:
		printf("Ctrl-C event\n\n");
		Beep(750, 300);
		return(TRUE);

		// CTRL-CLOSE: confirm that the user wants to exit. 
	case CTRL_CLOSE_EVENT:
		Beep(600, 200);
		printf("Ctrl-Close event\n\n");
		return(TRUE);

		// Pass other signals to the next handler. 
	case CTRL_BREAK_EVENT:
		Beep(900, 200);
		printf("Ctrl-Break event\n\n");
		return FALSE;

	case CTRL_LOGOFF_EVENT:
		Beep(1000, 200);
		printf("Ctrl-Logoff event\n\n");
		return FALSE;

	case CTRL_SHUTDOWN_EVENT:
		Beep(750, 500);
		printf("Ctrl-Shutdown event\n\n");
		return FALSE;

	default:
		return FALSE;
	}
}

//void main()
void Handler()
{
	if (SetConsoleCtrlHandler((PHANDLER_ROUTINE)CtrlHandler, TRUE))
	{
		printf("\nThe Control Handler is installed.\n");
		printf("\n -- Now try pressing Ctrl+C or Ctrl+Break, or");
		printf("\n    try logging off or closing the console...\n");
		printf("\n(...waiting in a loop for events...)\n\n");

		while (1) {}
	}
	else
	{
		printf("\nERROR: Could not set control handler");
		exit(1);
	}
}

/*
#include <windows.h>
#include <stdio.h>

BOOL Handler(DWORD dwEvent)
{
	switch(dwEvent) {
	case CTRL_C_EVENT:
		return true;
	case CTRL_BREAK_EVENT:
		return false;
	}
	return FALSE;
}

void main()
{
	HANDLE hIn, hOut;
	TCHAR str[11];
	TCHAR *Mes = "Input Success";
	DWORD dw;

	hIn = GetStdHandle(STD_INPUT_HANDLE);
	hOut = GetStdHandle(STD_OUTPUT_HANDLE);

	BOOL check = SetConsoleCtrlHandler((PHANDLER_ROUTINE)Handler, FALSE);
	memset(str, 0, sizeof(str));
	ReadFile(hIn, str, 10, &dw, NULL);
	WriteFile(hOut, Mes, lstrlen(Mes), &dw, NULL);
}
*/