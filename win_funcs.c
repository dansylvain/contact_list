#include "headerfile.h"

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
	mvwprintw(popup_win, 4, 4, "Name: ");
	mvwgetnstr(popup_win, 4, 10, name, 20);
	mvwprintw(popup_win, 5, 4, "E-mail: ");
	mvwgetnstr(popup_win, 5, 12, email, 20);
	mvwprintw(popup_win, 6, 4, "Stone skipping record: ");
	mvwgetnstr(popup_win, 6, 27	, stone_skipping_record, 9);
	mvwprintw(popup_win, 7, 4, "Favourite Pokémon: ");
	mvwgetnstr(popup_win, 7, 24	, favourite_pokemon, 14);
	mvwprintw(stdscr, LINES-1, 1, "%s added to contacts\n", name);
	create_contact_node(name, email, stone_skipping_record, favourite_pokemon);
}

char	*get_field(Contact *contact, int i)
{
	char	*field[] = {
		contact->name,
		contact->email,
		contact->stone_skipping_record,
		contact->favourite_pokemon
	};
	return (field[i]);
}

Contact	*get_contact(int i)
{
	Contact *current;
	current = head;

	while (i && current)
	{
		i--;
		current = current->next;
	}
	return(current);
}