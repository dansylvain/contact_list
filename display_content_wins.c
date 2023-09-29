#include "headerfile.h"

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

void	display_content_input_win(WINDOW *input_win, enum left_or_right side, int left_item_selected, int right_item_selected)
{
	char	*menu_items[] = {
		"Name: ",
		"E-mail: ",
		"Stone skipping record: ",
		"favourite Pokemon: "
	};
	Contact *contact;
	int		menu_items_nbr;
	int		i;

	contact = head;
	mvwprintw(input_win, 0, 0, ". Contact details ");
	i = 0;
	menu_items_nbr = sizeof(menu_items) / sizeof(char *);
	mvwprintw(input_win, 2, 8, "%s", get_field(get_contact(right_item_selected), i));

	while (i < menu_items_nbr)
	{
		if (i == left_item_selected - 3 && side == left)
		{
			wattron(input_win, COLOR_PAIR(1));
			mvwprintw(input_win, i + 4, 4, "%s%s", menu_items[i], get_field(get_contact(right_item_selected), i));
			wattroff(input_win, COLOR_PAIR(1));
		}
		else
			mvwprintw(input_win, i + 4, 4, "%s%s", menu_items[i], get_field(get_contact(right_item_selected), i));
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

