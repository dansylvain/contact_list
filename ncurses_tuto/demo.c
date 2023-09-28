#include <ncurses.h>

int	main(void)
{
	int	ch;

	initscr();
	raw();
	keypad(stdscr, TRUE);
	noecho();

	printw("Press any key, it will show up in bold...\n");
	ch = getch();

	if (ch == KEY_F(1))
		printf("you presses F1?");
	else
	{
		printw("you pressed ");
		attron(A_BOLD);
		printw("%c", ch);
		attroff(A_BOLD);
	}
	refresh();
	getch();
	endwin();
	return(0);
}