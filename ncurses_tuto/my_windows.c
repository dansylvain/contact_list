#include <ncurses.h>

int	main(void)
{
	WINDOW *win1;
	WINDOW *win2;
	initscr();
	cbreak();
	keypad(stdscr, TRUE);
	refresh();
	win1 = newwin(20, 40, 0, 10);
	win2 = newwin(20, 40, 0, 60);
	box(win1, 0, 0);
	box(win2, 0, 0);
	mvwprintw(win1, 1, 1, "Window1");
	mvwprintw(win2, 1, 1, "Window2");
	wrefresh(win1);
	wrefresh(win2);
	
	getch();


	endwin();
	return (0);

}