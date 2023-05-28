#include <iostream>
#include "Excel.h"
#include <conio.h>
#ifdef __cplusplus
extern "C" {
#endif
	BOOL WINAPI GetCurrentConsoleFont(HANDLE hConsoleOutput, BOOL bMaximumWindow, PCONSOLE_FONT_INFO lpConsoleCurrentFont);
#ifdef __cplusplus
}
#endif
using namespace std;

int main()
{
	POINT C;
	CONSOLE_FONT_INFO ConsoleFontInfo;

	while (true)
	{
		cout << char(-37);
		GetCursorPos(&C);
		HWND hWnd = GetConsoleWindow();
		ScreenToClient(hWnd, &C);
		GetCurrentConsoleFont(GetStdHandle(STD_OUTPUT_HANDLE), false, &ConsoleFontInfo);
		gotoRowCol(10, 10);
		cout << C.y / ConsoleFontInfo.dwFontSize.Y << endl;
		cout << C.x / ConsoleFontInfo.dwFontSize.X;
		system("cls");
	}
}

int mains()
{
    //chars();
    Excel C("sheet.txt");
    C.Main();
    return 0;
}