/* test */
#include <ncurses.h>

int	main(void)
{
	initscr();
	printw("Hello world!\n");
	printw("test");
	refresh();
	getch();
	endwin();

	return (0);
}


// compile with gcc <prog name> -lncurses !