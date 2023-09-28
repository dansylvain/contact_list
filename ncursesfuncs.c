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

