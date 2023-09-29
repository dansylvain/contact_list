#ifndef HEADERFILE_H
#define HEADERFILE_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <termios.h>
#include <unistd.h>
#include <ncurses.h>

enum	left_or_right {
	left,
	right
};

enum Pokemon
{
	Pikachu,
	Charizard,
	Bulbasaur,
	Squirtle,
	Eevee,
	Jigglypuff,
	Meowth,
	Snorlax,
	Mewtwo,
	Psyduck
};



typedef struct Contact {
	char	name[21];
	char	email[31];
	char	stone_skipping_record[10];
	char	favourite_pokemon[15];
    struct Contact *next;
	struct Contact *previous;
	
} Contact;

extern	Contact	*head;
extern	Contact	*tail;

void	create_contact_node(char *name, char *email, char *stone_skipping_record, char *favourite_pokemon);
Contact	*get_node(char	*name);
void	free_node(Contact *ptr);
void	free_list(void);
void	prompt_command(void);
void	remove_contact(Contact *node);
Contact	*search_contact(void);
void	display_contact(void);
void	swap_nodes(Contact *node1, Contact *node2);
void	sort_list(int	(sort_func)(Contact *current));
int	sort_by_name(Contact *current);
int	sort_by_email(Contact *current);
int	sort_by_phone(Contact *current);
void	reset_pointers_before_removal(Contact *ptr);
void	reset_pointers_for_swapping(Contact *node1, Contact *node2);
void	traverse_list(Contact *node);
void	start_ncurses_ui(void);
void	display_contacts();
void	add_contact();
void	gui(void);
int	get_contacts_qtty(void);
WINDOW	*create_func_win();
WINDOW	*create_input_win();
WINDOW	*create_display_win();
WINDOW	*create_popup_win();
void	display_content_func_win(WINDOW *func_win, enum left_or_right side, int left_item_selected);
void	display_content_input_win(WINDOW *input_win, enum left_or_right side, int left_item_selected, int right_item_selected);
void	display_content_display_win(WINDOW *display_win, enum left_or_right side, int right_item_selected);
void	display_content_popup_win(WINDOW *popup_win, int left_item_selected);
char	*get_field(Contact *contact, int i);
Contact	*get_contact(int i);



#endif