#include "headerfile.h"

void	display_contacts()
{
	WINDOW *contact_win;
	Contact *current;
	int	i;
	contact_win = newwin(LINES - 2, COLS / 2 - 4, 1, COLS / 2 + 3);
	box(contact_win, 0, 0);

	current = head;
	i = 0;
	while (current)
	{
		mvwprintw(contact_win, i + 1, 1, "%s", current->name);
		current = current->next;
		i++;
	}

	wrefresh(contact_win);
}

void	add_contact()
{
	char	name[21];
	char	phone_number[21];
	char	email[31];
	WINDOW	*add_contact_win;
	add_contact_win = newwin(LINES / 2 - 1, COLS / 2, LINES / 2 + 1, 2);
	box(add_contact_win, 0, 0);
	wrefresh(add_contact_win);
	echo();
	curs_set(1);


	mvwprintw(add_contact_win, 1, 1, "Name: ");
	mvwgetnstr(add_contact_win, 1, 7, name, 20);
	mvwprintw(add_contact_win, 2, 1, "Phone number: ");
	mvwgetnstr(add_contact_win, 2, 15, phone_number, 20);
	mvwprintw(add_contact_win, 3, 1, "E-mail address: ");
	mvwgetnstr(add_contact_win, 3, 17	, email, 30);

	mvprintw(LINES, 1, "%s added to contacts\n", name);

	create_contact_node(name, phone_number, email);

	delwin(add_contact_win);
	clear();
}