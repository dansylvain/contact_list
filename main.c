#include "headerfile.h"

Contact *tail = NULL;
Contact *head = NULL;

void	create_dummy_content(void)
{
	create_contact_node("Dan", "0475450135", "danmail@blabla.com");
	create_contact_node("Seb", "8765094356", "sebtheman@ouioui.fr");
	create_contact_node("Marie", "6669997778", "mariamaria@aimemoi.encore");
	create_contact_node("Vlad", "7770009999", "warnomore@end.slash");
	create_contact_node("Tom", "1234567890", "c'estpasbientôtfini?@nul.c");
	create_contact_node("Flo", "8754499", "sausage@gmail.com");
	create_contact_node("Pug", "1245430", "noway@hotmail.com");
	create_contact_node("Liam", "3227689", "wtf@yahoo.com");
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