#include <ncurses.h>

int main(){
initscr();
raw();
printw("hello");
getch();
endwin();

return 0;

}

