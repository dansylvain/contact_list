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


typedef struct Contact {
	char	name[21];
	char	phone_number[21];
	char	email[31];
    struct Contact *next;
	struct Contact *previous;
	
} Contact;

extern	Contact	*head;
extern	Contact	*tail;

void	create_contact_node(char *name, char *phone_number, char *email);
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


#endif