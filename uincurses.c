#include "headerfile.h"

void	print_main_menu(WINDOW *main_menu, char *str)
{
	mvwprintw(main_menu, 1, 1, "%s", str);
}

void	display_main_menu_content(WINDOW *main_menu, int item_selected)
{
	int		i;
	char	*menu_items[] = {
		"Add contact",
		"Display contacts",
		"Browse contacts"
	};
	int		menu_items_nbr;
	box(main_menu, 0, 0);
	keypad(stdscr, TRUE);
	menu_items_nbr = sizeof(menu_items) / sizeof(char *);
	i = 0;
	while (i < menu_items_nbr)
	{
		if (i == item_selected)
		{
			wattron(main_menu, COLOR_PAIR(1));
			mvwprintw(main_menu, i + 1, 1, "%s", menu_items[i]);
			wattroff(main_menu, COLOR_PAIR(1));
		}
		else
			mvwprintw(main_menu, i + 1, 1, "%s", menu_items[i]);

		i++;
	}
	wrefresh(main_menu);
}

void	call_chosen_func(int chosen_func)
{
	if (chosen_func == 0)
	{
		mvwprintw(stdscr, LINES - 1, 0, "add_contact      ");
		//add_contact();
	}
	if (chosen_func == 1)
	{
		mvwprintw(stdscr, LINES - 1, 0, "display_contacts");
		display_contacts();
	}
	if (chosen_func == 2)
		mvwprintw(stdscr, LINES - 1, 0, "browse_contacts  ");

}

void	start_ncurses_ui(void)
{
	int	ch;

	
	int chosen_func;
	initscr();
    cbreak();
	noecho();
	start_color();
	use_default_colors();
	init_pair(1, COLOR_WHITE, COLOR_BLACK);
	refresh();
	WINDOW	*main_menu;
	main_menu = newwin(LINES / 2, COLS / 2, 1, 2);
	
	chosen_func = 0;
	while (42)
	{
		curs_set(0);

		refresh();
		display_main_menu_content(main_menu, chosen_func);
		display_contacts();
		ch = getch();
		if (ch == KEY_UP && chosen_func > 0)
			chosen_func--;
		else if (ch == KEY_DOWN && chosen_func < 2)
			chosen_func++;
		else if (ch == 'q')
			break;
		else if (ch == '\n' || ch == KEY_ENTER)
			call_chosen_func(chosen_func);
		else
			mvwprintw(stdscr, LINES, 0, "Impossible");
	}

	getch();
}