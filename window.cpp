#include "window.h"
#include <ncurses.h>
#include <algorithm>
#include <chrono>
#include <thread>

void init_colors(void)
{
  start_color();
  init_pair(WBLACK,   COLOR_WHITE, COLOR_BLACK);
  init_pair(WCYAN,    COLOR_WHITE, COLOR_CYAN);
  init_pair(WBLUE,    COLOR_WHITE, COLOR_BLUE);
  init_pair(WYELLOW,  COLOR_WHITE, COLOR_YELLOW);  
  init_pair(WGREEN,   COLOR_WHITE, COLOR_GREEN); 
  init_pair(WMAGENTA, COLOR_WHITE, COLOR_MAGENTA);
  init_pair(WRED,     COLOR_WHITE, COLOR_RED);  
  init_pair(BWHITE,   COLOR_BLACK, COLOR_WHITE);
  init_pair(BCYAN,    COLOR_BLACK, COLOR_CYAN);
  init_pair(BBLUE,    COLOR_BLACK, COLOR_BLUE);
  init_pair(BYELLOW,  COLOR_BLACK, COLOR_YELLOW);  
  init_pair(BGREEN,   COLOR_BLACK, COLOR_GREEN); 
  init_pair(BMAGENTA, COLOR_BLACK, COLOR_MAGENTA);
  init_pair(BRED,     COLOR_BLACK, COLOR_RED);  
}


void startProgramX() {
  initscr();             // initialize curses
  cbreak();              // pass key presses to program, but not signals
  noecho();              // don't echo key presses to screen
  keypad(stdscr, TRUE);  // allow arrow keys
  timeout(0);            // no blocking on getch()
  curs_set(0);           // set the cursor to invisible
  init_colors();
}

void stopProgramX() {
  refresh();
  getch();    
  endwin();
}



void Window::update() const{
  wrefresh(win);
  wrefresh(frame);
  refresh();
}


Window::Window(int h,int w, int x, int y, char c)
  : height(h), width(w), startx(x), starty(y), bord(c)
{
  colorwin=WBLACK;
  colorframe=WBLACK;
  frame=newwin(h+2,w+2,y,x);
  win=subwin(frame,h,w,y+1,x+1);
  wbkgd(frame,COLOR_PAIR(colorwin));
  wbkgd(win,COLOR_PAIR(colorframe));
  wborder(frame, c,c,c,c,c,c,c,c);
  wattron(win,COLOR_PAIR(colorwin));
  wattron(frame,COLOR_PAIR(colorframe));
  update();
}

Window::~Window(){
  wborder(frame, ' ', ' ', ' ',' ',' ',' ',' ',' ');
  wattroff(win,COLOR_PAIR(colorwin));
  wattroff(win,COLOR_PAIR(colorframe));
  werase(win);
  update();
  delwin(win); 
}

void Window::print(int x, int y, std::string s, Color c) const {
  wattron(win,COLOR_PAIR(c));
  mvwprintw(win,y,x,s.c_str());
  wattroff(win,COLOR_PAIR(c));
  update();  
}
void Window::print(int x, int y, char s, Color c) const{
  wattron(win,COLOR_PAIR(c));
  mvwaddch(win,y,x,s);
  wattroff(win,COLOR_PAIR(c));
  update();
}
void Window::print(int x, int y, std::string s) const{
  mvwprintw(win,y,x,s.c_str());
  update();  
}
void Window::print(int x, int y, char s) const{
  mvwaddch(win,y,x,s);
  update();  
}
WINDOW* Window::getwin() const {return win;}
WINDOW* Window::getframe() const {return frame;}

void Window::updateframe() const {char c = bord;  wborder(frame, c,c,c,c,c,c,c,c); update();}

int Window::getX() const { return startx;} 
int Window::getY() const { return starty;} 
int Window::getHauteur() const { return height;} 
int Window::getLargeur() const { return width;}  
Color Window::getCouleurBordure() const{ return colorframe;}
Color Window::getCouleurFenetre() const{ return colorwin;}
void Window::keypadon() const{ keypad(win , true); }


void Window::setCouleurBordure(Color c){
  colorframe=c;
  wattron(frame,COLOR_PAIR(colorframe));
  wborder(frame, bord,bord,bord,bord,bord,bord,bord,bord);
  update();
}
void Window::setCouleurFenetre(Color c){
  colorwin=c;
  wattron(win,COLOR_PAIR(colorwin));
  wbkgd(win,COLOR_PAIR(colorwin));
  update();  
}

void Window::popup(std::string str) const{
  int longr = str.size();
  if(longr<30)
    longr = 30;

  int hautr = 5;
  hautr = hautr + std::count(str.begin() ,str.end(),'\n');
  
  Window FenetrePop(hautr,longr+1,(width/2)-(longr/2),(height/2)-(hautr-1),0);
  FenetrePop.print(1, 1 , str);
  FenetrePop.print(1, hautr-1 , "ENTER pour continuer");

  int choice = 0;

  while(choice!=10)
    {
      choice = wgetch(FenetrePop.getwin());
    }
}

void Window::popupTimer(std::string str , unsigned int ms)const
{
  using namespace std::this_thread;
  using namespace std::chrono;

  
  int longr = str.size();
  if(longr<30)
    longr = 30;
  
  int hautr = 5;
  hautr = hautr + std::count(str.begin() ,str.end(),'\n');
  
  Window FenetrePop(hautr,longr+1,(width/2)-(longr/2),(height/2)-(hautr-1),0);
  FenetrePop.print(1, 1 , str);
  FenetrePop.print(1, hautr-1 , "ENTER pour continuer");
  
  int choice = 0;
  int i = 0;
  while(choice!=10 && i<ms)
    {
      choice = getch();
      i++;
      sleep_for(milliseconds(1));
    }
  
}



void Window::clear() const{  werase(win); update(); }
