#include "text_colour.h"

void set_text_color(int text) {
	HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(hStdOut, (WORD)(WHITE << 4 | text));
}