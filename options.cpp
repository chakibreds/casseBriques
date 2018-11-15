#include "options.h"
#include "window.h"
//hauteurJeu(10) , longeurJeu(50) , longeurPlatf(8)
options::options(){
  int x, y;
  getmaxyx(stdscr,y,x);
  hauteurJeu = y;
  longeurJeu = x;
  longeurPlatf = 8;
}

options::options(int h , int l , int longp) : hauteurJeu(h), longeurJeu(l) , longeurPlatf(longp){}

int options::getH() const { return hauteurJeu; }
int options::getL() const { return longeurJeu; }
int options::getLongPla() const { return longeurPlatf; }

void options::setHauteurJeu(int x){hauteurJeu = x;}
void options::setLongPla(int x){longeurJeu = x;}
void options::setLongJeu(int x){longeurPlatf = x;}

void options::menu() {
  //meter un char en el .h
  Window menu(hauteurJeu , longeurJeu , 0 , 0 , 0);
  menu.keypadon();

  //    y  x
  std::string T[5][3];
  std::string choices[5] = {"option 1","Longeur fenetre","Hauteur fenetre","longeur plataforme","Exit"};
  
  
  for(int i = 0 ; i<5 ; i++)
    {
      
      for(int j = 0 ; j<3 ; j++)
	{
	  
	  if(! (i==4))
	    {
	      switch(j)
		{
		case 0:
		  T[i][j] = "<--";
		  break;
		case 1:
		  T[i][j] = choices[i];
		  break;
		case 2:
		  T[i][j] = "-->";
		  break;
		}
	    }
	  else
	    {
	      switch(j)
		{
		case 0:
		  T[i][j] = "---";
		  break;
		case 1:
		  T[i][j] = choices[i];
		  break;
		case 2:
		  T[i][j] = "---";
		  break;
		}  
	    }
	}
      
    }
  int choice;
  int highlight = 0;
  int highlight2 = 0;
  while(1)
    {
      for(int i = 0 ; i<5 ; i++)
	{
	  for(int j = 0 ; j<3 ; j++)
	    {
	     if(i==highlight && j == highlight2)
	       wattron(menu.getwin() , A_REVERSE);

	     switch(j)
	       {
	       case 0:
		 mvwprintw( menu.getwin() , i+1 , j+1 , T[i][j].c_str());
		 wattroff(menu.getwin() , A_REVERSE);
		 break;
	       case 1:
		 //4 car "<--" = 4
		 mvwprintw( menu.getwin() , i+1 , 4 , T[i][j].c_str());
		 wattroff(menu.getwin() , A_REVERSE);
		 break;
	       case 2:
		 mvwprintw( menu.getwin() , i+1 , 4+choices[i].length() , T[i][j].c_str());
		 wattroff(menu.getwin() , A_REVERSE);
		 break;
	       }
	   }
	  
	}
      
      

      
      choice = wgetch(menu.getwin());
      
      switch(choice)
	{
	case KEY_UP:
	  highlight--;
	  if (highlight == -1)
	    highlight = 0;
	  break;
	case KEY_DOWN:
	  highlight++;
	  if (highlight == 5)
	    highlight = 4;
	  break;
	case KEY_LEFT:
	  highlight2--;
	  if (highlight2 == -1)
	    highlight2 = 0;
	  break;
	  
	case KEY_RIGHT:
	  highlight2++;
	  if (highlight2 == 3)
	    highlight2 = 2;
	  break;
	default:
	  break;
	}
      
      if(choice == 10)
	{
	  switch(highlight)
	    {
	    case 0:
	      break;
	    case 1:
	      {
		menu.print(0 , 0 , "longeur");
		switch(highlight2)
		  {
		  case 0:
		    longeurJeu=longeurJeu-1;
		    break;
		  case 1:
		    break;
		  case 2:
		    longeurJeu=longeurJeu+1;
		    break;
		  }
		break;
	      }
	    case 2:
	      {
		menu.print(1 , 6 , "hauteur");
		switch(highlight2)
		  {
		  case 0:
		    hauteurJeu=hauteurJeu-1;
		    break;
		  case 1:
		    break;
		  case 2:
		    hauteurJeu=hauteurJeu+1;
		    break;
		  }
		break;
	      }
	    case 3:
	      {
		menu.print(2 , 9 , "longeurplat");
		switch(highlight2)
		  {
		  case 0:
		    longeurPlatf=longeurPlatf-1;
		    break;
		  case 1:
		    break;
		  case 2:
		    longeurPlatf = longeurPlatf+1;
		    break;
		  }
		break;
	      }
	    }
	}
      if(choice == 10){
	if(highlight == 4)
	  break;
      }
    }
  
  
  
}
