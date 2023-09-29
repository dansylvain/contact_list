#include "headerfile.h"

void	refresh_wins(WINDOW	*func_win, WINDOW *input_win, WINDOW *display_win, WINDOW *popup_win, enum left_or_right side, int left_item_selected, int right_item_selected)
{
	werase(stdscr);
	refresh();
	mvprintw(LINES - 1, COLS - 19, "Press 'q' to exit ");
	werase(func_win);
	box(func_win, 0, 0);
	display_content_func_win(func_win, side, left_item_selected);
	wrefresh(func_win);
	werase(input_win);
	box(input_win, 0, 0);
	display_content_input_win(input_win, side, left_item_selected, right_item_selected);
	wrefresh(input_win);
	werase(display_win);
	box(display_win, 0, 0);
	display_content_display_win(display_win, side, right_item_selected);
	wrefresh(display_win);
	if (popup_win)
	{
		delwin(popup_win);
	}
}

void	prompting_loop(WINDOW	*func_win, WINDOW *input_win, WINDOW *display_win, WINDOW *popup_win)
{
	int	ch;
	static	enum left_or_right side  = left;
	static int	left_item_selected = 0;
	static int	right_item_selected = 0;
	int	contacts_qtty;
	
	while (42)
	{
		refresh_wins(func_win, input_win, display_win, popup_win, side, left_item_selected, right_item_selected);
		ch = getch();
		contacts_qtty = get_contacts_qtty();
		if (ch == 'q' || ch == 27)
			break;
		if (ch == KEY_DOWN)
		{
			if (left_item_selected < 6 && side == left)
				left_item_selected++;
			else if (right_item_selected < contacts_qtty - 1 && side == right)
				right_item_selected++;
		}
		if (ch == KEY_UP)
		{
			if (left_item_selected > 0 && side == left)
				left_item_selected--;
			else if (right_item_selected > 0 && side == right)
				right_item_selected--;
		}
		if (ch == KEY_LEFT)
		{
			if (side == right)
				side = left;
		}
		if (ch == KEY_RIGHT)
		{
			if (side == left)
				side = right;
		}
		if (ch == '\n' || ch == KEY_ENTER)
		{
			if (side == left && left_item_selected < 3)
			{
				popup_win = create_popup_win();
				
				display_content_popup_win(popup_win, left_item_selected);
			}
			else if (side == left)
				mvprintw(LINES - 1, 0, "%i      ", left_item_selected - 3);
			else
				mvprintw(LINES - 1, 0, "%i      ", right_item_selected);
		}
	}
}

void	gui(void)
{	
	WINDOW *func_win;
	WINDOW *input_win;
	WINDOW *display_win;
	WINDOW *popup_win;
	initscr();
	cbreak();
	noecho();
	start_color();
	keypad(stdscr, TRUE);
	curs_set(0);
	use_default_colors();
	init_pair(1, COLOR_WHITE, COLOR_BLACK);
	refresh();
	func_win = create_func_win();
	input_win = create_input_win();
	display_win = create_display_win();
	popup_win = NULL;
	prompting_loop(func_win, input_win, display_win, popup_win);
}