#include "window.h"
#include "platf.h"
#include "options.h"
#include <ncurses.h>
//#include <string>
void jeu(options opt){
  
  int ch;
  int h=opt.getH(),w=opt.getL();
  
  Window menu(opt.getH()-2,(opt.getL()/2),(opt.getL()/2)+2,0,0);
  Window plateau(opt.getH()-2,(opt.getL()/2)-2,0,0,0);

  menu.setCouleurBordure(BRED);
  plateau.setCouleurBordure(BBLUE);
  
  menu.print(1,1,"Tapez q pour quitter !!!",WRED);
  
  int x=plateau.getLargeur()/2,y=plateau.getHauteur()-3;
  char p='X';
  Color col=WBLUE;
  plateau.print(x,y,p,col);

  char c  =  '-';
  platf pla1(opt.getLongPla(), x ,y ,c);
  pla1.print(plateau.getwin());
  
  while((ch = getch()) != 'q')
    {
      switch (ch) {
      case '1':
	col=BMAGENTA;
	break;
      case '2':
	col=WCYAN;
	break;
      case 'c':
	plateau.clear();
	break;
      case KEY_UP:
	//	plateau.print(x,y,' ');
	//plateau.print(x,--y,p,col);
	//pla1.sety(--y);
	//	pla1.print(plateau.getwin());
	

	break;
      case KEY_DOWN:
	//	plateau.print(x,y,' ');
	//	plateau.print(x,++y,p,col);
	break;
      case KEY_LEFT:
	//	plateau.print(x,y,' ');
	//	plateau.print(--x,y,p,col);
	pla1.printVide(plateau.getwin());
	if( pla1.contactmurG(w)) {
	pla1.setx(--x);
	}
	pla1.print(plateau.getwin());

	break;
      case KEY_RIGHT:
	//	plateau.print(x,y,' ');
	// plateau.print(++x,y,p,col);
	pla1.printVide(plateau.getwin());
	if( pla1.contactmurD(w)) {
	pla1.setx(++x);
	}
	pla1.print(plateau.getwin());
	break;
      case '\n':
	x=w/2,y=h/2;
	plateau.print(x,y,p,col);
	break;
      case '\t':
    	Color tmp= menu.getCouleurBordure();
	menu.setCouleurBordure(plateau.getCouleurBordure());
	plateau.setCouleurBordure(tmp);
	break;
      }
    }

  
  

}

void myprogram(){

  options opt;

  Window mainmenu(opt.getH()-2 , opt.getL()-2 , 0 , 0 , 0);
  std::string h = std::to_string(opt.getH());
  mainmenu.print(0 , 0 , h);
  std::string w = std::to_string(opt.getL());
  mainmenu.print(20 , 0 , w);
  /*
    WINDOW * mainmenu = newwin(opt.getH(),opt.getL(),0,0);
    //mainmenu.setCouleurBordure(WBLACK);
    box(mainmenu  ,0 , 0);
    refresh();
    wrefresh(mainmenu);
    keypad(mainmenu,true);
  */
  
  std::string choices[3] = {"Jeu","Options","Exit"};

  int choice;
  int highlight = 0;
  mainmenu.keypadon();


  //----------------------------MENU-FIN--------------------------------//

  while(1)
    {
      //   box(mainmenu  ,0 , 0);
      mainmenu.updateframe();
      
      for(int i = 0 ; i<3 ; i++)
	{
	  if(i==highlight)
	    wattron(mainmenu.getwin() , A_REVERSE);
	  mvwprintw(mainmenu.getwin() , i+1 , 1 , choices[i].c_str());
	  wattroff(mainmenu.getwin() , A_REVERSE);
	}
      choice = wgetch(mainmenu.getwin());
      
      switch(choice)
	{
	case KEY_UP:
	  highlight--;
	  if (highlight == -1)
	    highlight = 0;
	  break;
	case KEY_DOWN:
	  highlight++;
	  if (highlight == 3)
	    highlight = 2;
	  break;
	  
	default:
	  break;
	  
	}
      
      if(choice == 10)
	{
	  switch(highlight)
	    {
	    case 0:
	      jeu(opt);
	      break;
	    case 1:
	      opt.menu();
	      break;
	    case 2:
	      break;
	      
	    }
	}
      if(choice == 10){
	if(highlight == 2)
	  break;
      }
      
    }
  
  //----------------------------MENU-FIN--------------------------------//

}

int main(){
  startProgramX();
  myprogram();
  stopProgramX();
  return 0;
}
