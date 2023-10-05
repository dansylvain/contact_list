#include "headerfile.h"

Contact *tail = NULL;
Contact *head = NULL;

void	create_dummy_content(void)
{
	create_contact_node("Dan", "danmail@blabla.com", "42", "Pikachu");
	create_contact_node("Seb", "sebtheman@ouioui.fr", "007", "Charizard");
	create_contact_node("Mary", "mariamaria@pouet.pouet", "66", "Bulbasaur");
	create_contact_node("Vlad", "warnomore@end.slash", "76", "Squirtle");
	create_contact_node("Tom", "c'estpasbientôtfini?@nul.c", "01", "Eevee");
	create_contact_node("Beth", "sausage@gmail.com", "88", "Jigglypuff");
	create_contact_node("Pug", "noway@hotmail.com", "32", "Meowth");
	create_contact_node("Liam", "wtf@yahoo.com", "118", "Snorlax");
}

void finish() {
    endwin();
}

int	main(void)
{
	if (atexit(finish) != 0) {
        perror("atexit");
        exit(EXIT_FAILURE);
    }
	create_dummy_content();
	//start_ncurses_ui();
	// prompt_command();	

	gui();

	free_list();
    endwin();
	return (0);
}