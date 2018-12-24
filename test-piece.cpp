#include "window.h"
#include "platf.h"
#include "options.h"
#include <ncurses.h>
#include <string>
#include <cstdlib>
#include <chrono>
#include <thread>
#include "briques.h"
#include "tableauBriques.h"
#include "joueur.h"
#include "highScore.h"
#include "bille.h"


void jeu(options opt){
  using namespace std::this_thread; // sleep_for, sleep_until
  using namespace std::chrono; // nanoseconds, system_clock, seconds




  int ch; //ch = char clavier
  int h=opt.getH(),w=opt.getL();

  unsigned int vitesse = opt.getVitesse();
  //creation de fenetres

  //W(hauteur , longeur , posX , posY , bord?)
  Window menu((opt.getH()/2)-2,(opt.getL()/3)-1,(opt.getL()/(1.5)),0,0);
  Window plateau(opt.getH()-2,(opt.getL()/(1.5))-2,0,0,0);
  Window infoJoueur((opt.getH()/2)-2,(opt.getL()/3)-1,(opt.getL()/(1.5)),opt.getH()/2,0);

  //changer les couleurs des bords
  menu.setCouleurBordure(BRED);
  plateau.setCouleurBordure(BBLUE);
  infoJoueur.setCouleurBordure(BYELLOW);
  //---------------------text menu--------------------//
  menu.print(1,1,"Tapez q pour quitter !!!",WRED);
  //-----------------------fin text menu---------------//

  //-----------------------Joueur----------------------//
  //x,y
  infoJoueur.print(((infoJoueur.getLargeur())/2)-5,0,"---STATS---",WYELLOW);
  joueur J( "Bob", 3 , 1 , 0);
  J.printStats(infoJoueur.getwin());

  //----------------------fin Joueur-----------------------------//



  //---------------------raquette Start------------------------//

  //y=plateau.getHauteur()-3 = 3 pixel sur le sol
  int x=plateau.getLargeur()/2,y=plateau.getHauteur()-3;

  //c = le char de la raquette
  char c  =  '-';

  //creation de la raquette
  platf pla1(opt.getLongPla(), x ,y ,c);

  //print de la raquete
  pla1.print(plateau.getwin());

  //--------------------raquette Fin---------------------------//

  Color col=WBLUE;

  //-----------------------creation tabBriques-----------------//
  tableauBriques tab;
  tab.printTableauBriques(plateau.getwin());
  //-----------------------------fin creation-------------------//

  //-------------------------------instructions-----------------//
  std::string str= "SPACE ou KEY_DOWN pour arreter la plataforme ";
  plateau.popup(str);
  tab.printTableauBriques(plateau.getwin());
  //---------------------------fin instruc------------------------//

  //-----------------------creation Bille-----------------------//
  Bille maBille(pla1.getx()+pla1.getlongr()/2,pla1.gety()-1,0,0,'O',Bille::DROITE);
  maBille.print(plateau.getwin());
  maBille.setDirDepart(Bille::GAUCHE);
  maBille.depart();
  //-----------------------------fin creation-------------------//

  //----------------------boucle de jeu et controls--------------//
  while((ch = getch()) != 'q')
    {
      //tab.printTableauBriques(plateau.getwin());
      maBille.print(plateau.getwin());
      J.printStats(infoJoueur.getwin());
      switch (ch)
	{
	case '1':
	  col=BMAGENTA;
	  break;
	case '2':
	  col=WCYAN;
	  break;
	case 'c':
	  plateau.clear();
	  break;
	case 'v':
	  {

	    maBille.avancer();
	  }
	  break;
	case KEY_DOWN:
	  break;
	case KEY_LEFT:
	  {
	     pla1.printVide(plateau.getwin());
	     //maBille.effacePrintBille(plateau.getwin());
	     if( pla1.contactmurG(plateau.getLargeur()))
	       {
		 //maBille.setX(maBille.getX()-1);
		pla1.setx((pla1.getx())-1);
	       }


	     //maBille.setDirDepart(Bille::DROITE);
	     //prints
	     //maBille.print(plateau.getwin());
	     pla1.print(plateau.getwin());
	  }


	  break;
	case KEY_RIGHT:
	  {

	   pla1.printVide(plateau.getwin());
	   //maBille.effacePrintBille(plateau.getwin());
	     if( pla1.contactmurD(plateau.getLargeur()))
	       {
		 //maBille.setX(maBille.getX()+1);
		pla1.setx((pla1.getx())+1);
	       }


	     //maBille.setDirDepart(Bille::GAUCHE);
	     //prints
	     //maBille.print(plateau.getwin());
	     pla1.print(plateau.getwin());
	  }
	  break;
	case '\n':
	  break;
	case '\t':
	  Color tmp= menu.getCouleurBordure();
	  menu.setCouleurBordure(plateau.getCouleurBordure());
	  plateau.setCouleurBordure(tmp);
	  break;

	}
      J.addScore(1);
      //le delay
      sleep_for(milliseconds(vitesse));
      maBille.effacePrintBille(plateau.getwin());
      maBille.avancer();

      maBille.contactBrique(&tab,plateau.getwin());
      maBille.contactRaquette(pla1.getx() , pla1.getx()+pla1.getlongr() , pla1.gety());
      maBille.contactBords(plateau.getLargeur() ,plateau.getHauteur());
        tab.printTableauBriques(plateau.getwin());

    }

  //---------------------------finBoucle de jeu--------------------------//
  highScore high;
  if(high.estUnHighScore(J.getScore()))
    high.mettreNouveauHighScore(J.getScore(),J.getNomJ());

  high.pop(plateau);

}

void myprogram(){

  options opt;

  Window mainmenu(opt.getH()-2 , opt.getL()-2 , 0 , 0 , 0);

  //print la taille de la fenetre au debut
  std::string h = std::to_string(opt.getH());
  mainmenu.print(0 , 0 , h);
  std::string w = std::to_string(opt.getL());
  mainmenu.print(20 , 0 , w);


  //les trois options du menu
  std::string choices[3] = {"Jeu","Options","Exit"};

  int choice;
  int highlight = 0;
  mainmenu.keypadon();


  //exemple popup
  //std::string str= "hola \n " + std::to_string(m);
  //mainmenu.popup(str);


  //----------------------------MENU-START--------------------------------//

  while(1)
    {
      //   box(mainmenu  ,0 , 0);

      mainmenu.updateframe();


      for(int i = 0 ; i<3 ; i++)
	{
	  if(i==highlight)
	    wattron(mainmenu.getwin() , A_REVERSE);
	  //print menu principal
	  mvwprintw(mainmenu.getwin() , ((opt.getH()/(2)-2))+i , ((opt.getL()/(2))-4)-2 , choices[i].c_str());
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
      werase(mainmenu.getwin());
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
