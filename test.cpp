#include <ncurses.h>

int main(){
initscr();
raw();
printw("hello world");
getch();
endwin();

return 0;

}

