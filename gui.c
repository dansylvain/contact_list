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
	return (popup_win);
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

	mvwprintw(func_win, 0, 0, ". Functions ");
	i = 0;
	menu_items_nbr = sizeof(menu_items) / sizeof(char *);
	while (i < menu_items_nbr)
	{
		if (i == left_item_selected && side == left)
		{
			wattron(func_win, COLOR_PAIR(1));
			mvwprintw(func_win, i + 2, 4, "%s", menu_items[i]);
			wattroff(func_win, COLOR_PAIR(1));
		}
		else
			mvwprintw(func_win, i + 2, 4, "%s", menu_items[i]);
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

	mvwprintw(input_win, 0, 0, ". Contact details ");
	i = 0;
	menu_items_nbr = sizeof(menu_items) / sizeof(char *);
	while (i < menu_items_nbr)
	{
		if (i == left_item_selected - 3 && side == left)
		{
			wattron(input_win, COLOR_PAIR(1));
			mvwprintw(input_win, i + 2, 4, "%s%i", menu_items[i], i);
			wattroff(input_win, COLOR_PAIR(1));
		}
		else
			mvwprintw(input_win, i + 2, 4, "%s%i", menu_items[i], i);
		i++;
	}
}

void	display_content_display_win(WINDOW *display_win, enum left_or_right side, int right_item_selected)
{
	Contact	*current;
	int	i;
	
	mvwprintw(display_win, 0, 0, ". Contacts list ");
	current = head;
	i = 0;
	while (current)
	{
		if (i == right_item_selected && side == right)
		{
			wattron(display_win, COLOR_PAIR(1));
			mvwprintw(display_win, i + 2, 4, "%s", current->name);
			wattroff(display_win, COLOR_PAIR(1));
		}
		else
			mvwprintw(display_win, i + 2, 4, "%s", current->name);
		current = current->next;
		i++;
	}
	
}

void	add_contact()
{
	char	name[21];
	char	phone_number[21];
	char	email[31];
	char 	stone_skipping_record[10];
	char	favourite_pokemon[15];
	WINDOW	*popup_win;
	popup_win = newwin(LINES / 2, COLS / 2 - 1, LINES / 2, 1);
	box(popup_win, 0, 0);
	wrefresh(popup_win);

	
	
	echo();
	curs_set(1);

	mvwprintw(popup_win, 0, 0, ". Contact details ");
	mvwprintw(popup_win, 2, 4, "Name: ");
	mvwgetnstr(popup_win, 2, 10, name, 20);
	mvwprintw(popup_win, 3, 4, "E-mail: ");
	mvwgetnstr(popup_win, 3, 12, email, 20);
	mvwprintw(popup_win, 4, 4, "Stone skipping record: ");
	mvwgetnstr(popup_win, 4, 27	, stone_skipping_record, 9);
	mvwprintw(popup_win, 5, 4, "Favourite Pokémon: ");
	mvwgetnstr(popup_win, 5, 24	, favourite_pokemon, 14);
	mvwprintw(stdscr, LINES-1, 1, "%s added to contacts\n", name);

	create_contact_node(name, email, stone_skipping_record, favourite_pokemon);
}

void	display_content_popup_win(WINDOW *popup_win, int left_item_selected)
{
	box(popup_win, 0, 0);
	if (left_item_selected == 0)
	{
		add_contact();
	}
	if (left_item_selected == 1)
		wprintw(popup_win, ". Search Contact");
	if (left_item_selected == 2)
		wprintw(popup_win, ". Delete Contact");
	wrefresh(popup_win);
}



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
	display_content_input_win(input_win, side, left_item_selected);
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