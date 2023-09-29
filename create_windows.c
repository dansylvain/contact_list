#include "headerfile.h"

WINDOW	*	create_func_win()
{
	WINDOW	*func_win;
	func_win = newwin(LINES / 2 - 1, COLS / 2 - 1, 1, 1);
	return (func_win);
}

WINDOW	*create_input_win()
{
	WINDOW	*input_win;
	input_win = newwin(LINES / 2, COLS / 2 - 1, LINES / 2, 1);
	return (input_win);
}

WINDOW	*create_display_win()
{
	WINDOW	*display_win;
	display_win = newwin(LINES - 2, COLS / 2 - 2, 1, COLS / 2 + 1);
	return (display_win);
}

WINDOW	*create_popup_win()
{
	WINDOW	*popup_win;
	popup_win = newwin(LINES / 2 - 1, COLS / 2 - 1, LINES / 4, COLS / 4);
	box(popup_win, 0, 0);
	return (popup_win);
}