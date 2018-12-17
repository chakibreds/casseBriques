#include "options.h"
#include "window.h"
#include <exception>
#include <fstream>
//hauteurJeu(10) , longeurJeu(50) , longeurPlatf(8)
options::options(){
  //int x, y;
  //getmaxyx(stdscr,y,x);
  //on va faire static
  hauteurJeu = 24;
  longeurJeu = 80;
  longeurPlatf = 14;
  vitesseJeu = 17;
}

options::options(unsigned int h , unsigned int l , unsigned int longp) : hauteurJeu(h), longeurJeu(l) , longeurPlatf(longp){}

//----------------------lecture fichier config------------------------//
void options::nettoie(std::string &str){
  //position du premier #
  size_t pos = str.find_first_of("#");

  //str devient le subString de 0 jusqu'a le premier #
  str = str.substr(0,pos);

  int beg = 0, end = str.size()-1;
  //enlever les vides avant la mot clef
  //'\t' = tab
  while(beg<end+1 && (str[beg]==' ' || str[beg]=='\t' )) beg++;
  //idem pour la fin
  while(end>beg-1 && (str[end]==' ' || str[end]=='\t' )) end--;

  //substr(deb , longeur)
  str = str.substr(beg , end - beg + 1);
  
}

bool options::findCleVal(std::string &line , std::string &cle , std::string &valeur){
  nettoie(line);
  if(line == "")
    return false;

  size_t pos=line.find_first_of(":");
  //npos plus ou moins la meme chose que EOF pour les strings
  if(pos == std::string::npos){
    //a finir, exemple im maque des ':'
   

    Window w(hauteurJeu , longeurJeu , 0 , 0 , 0 );
    w.popup("ERREUR Le fichier est mal formé, TERMINATE");
    stopProgramX(); 
    
    std::terminate();
  }

  cle = line.substr(0,pos);
  //de pos+1 jusqu'a la fin
  valeur = line.substr(pos + 1);
  nettoie(cle);
  nettoie(valeur);
  
  return true;

}
void options::TraiteOption(const std::string &cle , const std::string &valeur, size_t num_ligne){
  
  //atoi str to int
  if (cle == "longeurPlatf")
    {
      longeurPlatf = atoi(valeur.c_str());
    }
  else if (cle == "vitesseJeu")
    {
      vitesseJeu = atoi(valeur.c_str());
    }
}

void options::loadConfig(std::string file){

  //ifstream: Stream class to read from files
  //ifstream monfich("nomfich");
  std::ifstream input(file.c_str());
  std::string cle , valeur;
  size_t num_ligne = 0;

  //a changer avec n curses aussi
  if (!input.is_open()) {
    Window w(hauteurJeu , longeurJeu , 0 , 0 , 0 );
    w.popup("ERREUR avec le fichier de configuration, TERMINATE");
    stopProgramX();
    std::terminate();
  }

  std::string line;

  while(!input.eof())
    {
      //getline() augment automatique
      getline(input , line);
      if(!input.eof())
	{
	  if(findCleVal(line , cle , valeur))
	    TraiteOption(cle,valeur,num_ligne);
	}
      
      num_ligne++;
    }
  input.close();
}



//------------------------------fin lecture fichier config------------//

unsigned int options::getH() const { return hauteurJeu; }
unsigned int options::getL() const { return longeurJeu; }
unsigned int options::getLongPla() const { return longeurPlatf; }
unsigned int options::getVitesse()const{return vitesseJeu;}

void options::setVitesse(unsigned int x) {vitesseJeu = x;}
void options::setHauteurJeu(unsigned int x){hauteurJeu = x;}
void options::setLongPla(unsigned int x){longeurJeu = x;}
void options::setLongJeu(unsigned int x){longeurPlatf = x;}



//--------------------------le menu d'options----------------------//
void options::menu() {
  //meter un char en el .h
  Window menu(hauteurJeu-2 , longeurJeu-2 , 0 , 0 , 0);
  menu.keypadon();

  //    y  x
  std::string T[5][3];
  std::string choices[5] = {"option1","Load Fichier config","Vitesse : plus petit = plus vite","longeur plataforme","Exit"};
  
  //faire le tab pour me menu
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
     
      //print le tab
      for(int i = 0 ; i<5 ; i++)
	{
	  for(int j = 0 ; j<3 ; j++)
	    {
	     if(i==highlight && j == highlight2)
	       wattron(menu.getwin() , A_REVERSE);

	     switch(j)
	       {
	       case 0:
		 mvwprintw( menu.getwin() , (hauteurJeu/(2.5))+i ,(longeurJeu/(2.5))+j , T[i][j].c_str());
		 wattroff(menu.getwin() , A_REVERSE);
		 break;
	       case 1:
		 //4 car "<--" = 4
		 mvwprintw( menu.getwin() , (hauteurJeu/(2.5))+i ,(longeurJeu/(2.5))+3 , T[i][j].c_str());
		 wattroff(menu.getwin() , A_REVERSE);
		 break;
	       case 2:
		 mvwprintw( menu.getwin() , (hauteurJeu/(2.5))+i ,(longeurJeu/(2.5))+3+choices[i].length() , T[i][j].c_str());
		 wattroff(menu.getwin() , A_REVERSE);
		 break;
	       }
	   }
	  
	}
      
      

      
      choice = wgetch(menu.getwin());
      //changer le highlight  c-a-d changer l'indice
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
      //actions a faire si enter
      if(choice == 10)
	{
	  switch(highlight)
	    {
	    case 0:
	      break;
	    case 1:
	      {
	
		switch(highlight2)
		  {
		  case 0:
		    //longeurJeu=longeurJeu-1;
		    break;
		  case 1:
		    loadConfig("config.txt");
		    menu.popupTimer("Le fichier de config a été bien chargé " , 1500);
		    break;
		  case 2:
		    //longeurJeu=longeurJeu+1;
		    break;
		  }
		break;
	      }
	    case 2:
	      {
		
		switch(highlight2)
		  {
		  case 0:
		    {
		      
		      if(vitesseJeu == 1)
			{
			  std::string message = "Vitesse maximal \n vitesse = " + std::to_string(vitesseJeu);
			  menu.popupTimer(message , 1500);
			}
		      else
			{
			  vitesseJeu = vitesseJeu - 1;
			  std::string message = "Vitesse augmenté \n nouvelle vitesse = " + std::to_string(vitesseJeu);
			  menu.popupTimer(message , 1500);
			}
		      
		    }
		    break;
		  case 1:
		    break;
		  case 2:
		    {
		      vitesseJeu = vitesseJeu + 1;
		      std::string message = "Vitesse diminueé \n nouvelle vitesse = " + std::to_string(vitesseJeu);
		      menu.popupTimer(message , 1500);
		    }
		     break;
		  }
		break;
	      }
	    case 3:
	      {
		
		switch(highlight2)
		  {
		  case 0:
		    {
		      if(longeurPlatf-1 <= 0)
			{
			  std::string message = "Valeur Minimal = 1 \n Longeur Plataforme = " + std::to_string(longeurPlatf);
			  menu.popupTimer(message , 1500);
			}
		      else
			{
			  longeurPlatf=longeurPlatf-1;
			  std::string message = "Longeur de plataforme diminue \n nouvelle longeur = " + std::to_string(longeurPlatf);
			  menu.popupTimer(message , 1500);
			}
		    }
		    break;
		  case 1:
		    break;
		  case 2:
		    {
		      longeurPlatf = longeurPlatf+1;
		      std::string message = "Longeur de plataforme augmenté \n nouvelle longeur = " + std::to_string(longeurPlatf);
		      menu.popupTimer(message , 1500);
		    }
		    break;
		  }
		break;
	      }
	    }
	}
      werase(menu.getwin());
      if(choice == 10){
	if(highlight == 4)
	  break;
      }
    }
  
  
  
}
//-------------------------------------fin menu----------------------//
