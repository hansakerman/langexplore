
/* ncurses2 */
#include<ncurses.h>

int main()
  {
    int x, y;

    initscr();
    clear();

    getyx(stdscr, y, x);
    printw(          "x = %d\ny = %d",x, y);
    refresh();

    y = 5;
    x = 10;

    move(x, y);
    printw("Over here");
    refresh();
    
    getch();
    endwin();

    return 0;
  }
