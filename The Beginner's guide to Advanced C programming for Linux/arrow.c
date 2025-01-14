
/* arrow.c */
#include <ncurses.h>

int main()
{
  int key, x, y;

  initscr();
  keypad(stdscr,TRUE);
  noecho(); // does not type out stuff??
  x = y = 5;

  curs_set(0);
  
  while (key != 'q')
    {
      clear();
      move(0,0);
      printw("Press left or right arrow - exit by pressing q");
  
      move(y, x);
      printw("OPPA");
      refresh();

      key=getch();
      if (key == KEY_LEFT)
	{
	  x--;
	  if (x<0) x=0;
	}
      else if (key == KEY_RIGHT)
	{
	  x++;
	  if (x > 30) x=30;
	}
    }
  refresh();
  endwin();
  return 0;
  
}
	



