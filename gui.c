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

void	display_content_func_win(WINDOW *func_win, enum left_or_right side, int left_item_selected)
{
	char	*menu_items[] = {
		"Add contact",
		"Search contact",
		"Delete contact"
	};
	int		menu_items_nbr;
	int		i;

	mvwprintw(func_win, 0, 0, ". func_win ");
	if (side == 0)
		mvwprintw(func_win, 0, 15,  "test %i %i", side, left_item_selected);
	i = 0;
	menu_items_nbr = sizeof(menu_items) / sizeof(char *);
	while (i < menu_items_nbr)
	{
		if (i == left_item_selected && side == left)
		{
			wattron(func_win, COLOR_PAIR(1));
			mvwprintw(func_win, i + 1, 1, "%s", menu_items[i]);
			wattroff(func_win, COLOR_PAIR(1));
		}
		else
			mvwprintw(func_win, i + 1, 1, "%s", menu_items[i]);
		i++;
	}
	
}

void	display_content_input_win(WINDOW *input_win, enum left_or_right side, int left_item_selected)
{
	char	*menu_items[] = {
		"Name: ",
		"E-mail: ",
		"Stone skipping record: ",
		"favourite Pokemon: "
	};
	int		menu_items_nbr;
	int		i;

	mvwprintw(input_win, 0, 0, ". input win ");
	if (side == 0)
		mvwprintw(input_win, 0, 15,  "test %i %i", side, left_item_selected);
	i = 0;
	menu_items_nbr = sizeof(menu_items) / sizeof(char *);
	while (i < menu_items_nbr)
	{
		if (i == left_item_selected - 3 && side == left)
		{
			wattron(input_win, COLOR_PAIR(1));
			mvwprintw(input_win, i + 1, 1, "%s", menu_items[i]);
			wattroff(input_win, COLOR_PAIR(1));
		}
		else
			mvwprintw(input_win, i + 1, 1, "%s", menu_items[i]);
		i++;
	}
}

void	display_content_display_win(WINDOW *display_win, enum left_or_right side, int right_item_selected)
{
	Contact	*current;
	int	i;
	
	mvwprintw(display_win, 0, 0, ". display win ");
	if (side == 1)
		mvwprintw(display_win, 0, 15, "test %i %i", side, right_item_selected);
	current = head;
	i = 0;
	while (current)
	{
		if (i == right_item_selected && side == right)
		{
			wattron(display_win, COLOR_PAIR(1));
			mvwprintw(display_win, i + 1, 1, "%s", current->name);
			wattroff(display_win, COLOR_PAIR(1));
		}
		else
			mvwprintw(display_win, i + 1, 1, "%s", current->name);
		current = current->next;
		i++;
	}
	
}

void	refresh_wins(WINDOW	*func_win, WINDOW *input_win, WINDOW *display_win, enum left_or_right side, int left_item_selected, int right_item_selected)
{
	mvprintw(LINES - 1, COLS - 19, "Press 'q' to exit ");
	werase(func_win);
	box(func_win, 0, 0);
	display_content_func_win(func_win, side, left_item_selected);
	wrefresh(func_win);
	werase(input_win);
	box(input_win, 0, 0);
	display_content_input_win(input_win, side, left_item_selected);
	wrefresh(input_win);
	werase(display_win);
	box(display_win, 0, 0);

	display_content_display_win(display_win, side, right_item_selected);
	wrefresh(display_win);
}

void	prompting_loop(WINDOW	*func_win, WINDOW *input_win, WINDOW *display_win)
{
	int	ch;
	while (42)
	{
		static	enum left_or_right side  = left;
		static int	left_item_selected = 0;
		static int	right_item_selected = 0;
		int	contacts_qtty;

		refresh_wins(func_win, input_win, display_win, side, left_item_selected, right_item_selected);
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
			mvprintw(LINES - 1, 0, "DOWN  ");
		}
		if (ch == KEY_UP)
		{
			if (left_item_selected > 0 && side == left)
				left_item_selected--;
			else if (right_item_selected > 0 && side == right)
				right_item_selected--;
			mvprintw(LINES - 1, 0, "UP    ");
		}
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