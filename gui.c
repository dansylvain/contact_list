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

void	display_content_func_win(WINDOW *func_win, enum left_or_right side)
{
	mvwprintw(func_win, 0, 0, ". func_win ");
	if (side == 0)
		wprintw(func_win, "test %i", side);
}

void	display_content_input_win(WINDOW *input_win, enum left_or_right side)
{
	mvwprintw(input_win, 0, 0, ". input win ");
	if (side == 0)
		wprintw(input_win, "test %i", side);
}

void	display_content_display_win(WINDOW *display_win, enum left_or_right side)
{
	mvwprintw(display_win, 0, 0, ". display win ");
	
	if (side == 1)
		wprintw(display_win, "test %i", side);
	
	
}

void	refresh_wins(WINDOW	*func_win, WINDOW *input_win, WINDOW *display_win, enum left_or_right side)
{
	mvprintw(LINES - 1, COLS - 19, "Press 'q' to exit ");
	werase(func_win);
	box(func_win, 0, 0);
	display_content_func_win(func_win, side);
	wrefresh(func_win);
	werase(input_win);
	box(input_win, 0, 0);
	display_content_input_win(input_win, side);
	wrefresh(input_win);
	werase(display_win);
	box(display_win, 0, 0);

	display_content_display_win(display_win, side);
	wrefresh(display_win);
}

void	prompting_loop(WINDOW	*func_win, WINDOW *input_win, WINDOW *display_win)
{
	int	ch;
	while (42)
	{
		static	enum left_or_right side  = left; 
		refresh_wins(func_win, input_win, display_win, side);
		ch = getch();
		if (ch == 'q' || ch == 27)
			break;
		if (ch == KEY_DOWN)
			mvprintw(LINES - 1, 0, "DOWN  ");
		if (ch == KEY_UP)
			mvprintw(LINES - 1, 0, "UP    ");
		if (ch == KEY_LEFT)
		{
			if (side == right)
				side = left;
			mvprintw(LINES - 1, 0, "LEFT %i", side);
		}
		if (ch == KEY_RIGHT)
		{
			if (side == left)
				side = right;
			mvprintw(LINES - 1, 0, "RIGHT%i", side);
		}
		if (ch == '\n' || ch == KEY_ENTER)
			mvprintw(LINES - 1, 0, "ENTER ");
	}
}

void	gui(void)
{	
	WINDOW *func_win;
	WINDOW *input_win;
	WINDOW *display_win;
	initscr();
	cbreak();
	noecho();
	start_color();
	keypad(stdscr, TRUE);
	nodelay(stdscr, TRUE);
	curs_set(0);
	use_default_colors();
	init_pair(1, COLOR_WHITE, COLOR_BLACK);
	refresh();
	func_win = create_func_win();
	input_win = create_input_win();
	display_win = create_display_win();
	prompting_loop(func_win, input_win, display_win);
}