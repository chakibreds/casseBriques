#include <cstdlib>
#include <ncurses.h>
#include <iostream>
#include "briques.h"
#include "tableauBriques.h"


//-------------------------------------constructeurs----------------------//

tableauBriques::tableauBriques() : taille(12) , alloc(12) , decalBriquesX(1) ,decalBriquesY(3) , distanceInterBriques(3) , nbDeLignes(3){
  //creer le tab dynamic
  Brique *tabB = new Brique [alloc];
  data = tabB;


  //ajuster les coordonnes des briques


  //------------------------------fait un rectangle de taille nbDeLignes -------------------//
  //longeur ligne, hauteur
  int longeurLignes = taille / nbDeLignes; // si le modulo != 0 le affichage ne marche pas
  int indice = 0;

  for(int ligne = 0 ; ligne<nbDeLignes ; ligne++)
    {
      for(int i = 0 ; i<longeurLignes; i++)
	{
	  if(i==0)
	    {
	      data[indice].setX(decalBriquesX);
	      data[indice].setY(decalBriquesY * ligne);
	    }
	  else
	    {
	      data[indice].setY(decalBriquesY*ligne);
	      data[indice].setX(data[indice-1].getX() + data[indice-1].getl() + distanceInterBriques);

	    }
	  indice = indice + 1;
	}
    }

  //---------------------------fin createur rectangle--------------------------------------//

}

tableauBriques::tableauBriques(size_t _taille) : taille(_taille) , alloc(_taille) , decalBriquesX(0) ,decalBriquesY(0) , distanceInterBriques(0) , nbDeLignes(1)
{
  Brique *tabB = new Brique [alloc];
  data = tabB;
}



tableauBriques::tableauBriques(size_t _taille , unsigned int _decalBriquesX, unsigned int _decalBriquesY,unsigned int _distanceInterBriques, unsigned int _nbDeLignes) : taille(_taille) , alloc(_taille) , decalBriquesX(_decalBriquesX) ,decalBriquesY(_decalBriquesY) , distanceInterBriques(_distanceInterBriques)
{
  if(_nbDeLignes>0){
    nbDeLignes=_nbDeLignes;
    //creer le tab dynamic
    Brique *tabB = new Brique [alloc];
    data = tabB;


    //ajuster les coordonnes des briques


    //------------------------------fait un rectangle de taille nbDeLignes -------------------//
    //longeur ligne, hauteur
    int longeurLignes = taille / nbDeLignes; // si le modulo != 0 le affichage ne marche pas
    int indice = 0;

    for(int ligne = 0 ; ligne<nbDeLignes ; ligne++)
      {
	for(int i = 0 ; i<longeurLignes; i++)
	  {
	    if(i==0)
	      {
		data[indice].setX(decalBriquesX);
		data[indice].setY(decalBriquesY * ligne);
	      }
	    else
	      {
		data[indice].setY(decalBriquesY*ligne);
		data[indice].setX(data[indice-1].getX() + data[indice-1].getl() + distanceInterBriques);

	      }
	    indice = indice + 1;
	  }
    }

    //---------------------------fin createur rectangle--------------------------------------//

  }
  else
    std::cerr<<"constructeur tableauBriques : nbDeLignes <= 0 \n";

}
//--------------------------fin constructeurs-------------------------------------------//
// supprimer une brique
void tableauBriques::supprimerBrique(int i)
{
  for(int j = i ; j < taille ; j++)
  {
    data[j]=data[j+1];
  }
  taille--;
}
//----------------------lecture------------------------//
size_t tableauBriques::getTaille() const{return taille;}

size_t tableauBriques::getAlloc() const{return alloc;}

Brique &tableauBriques::at(size_t i) {return data[i];}

unsigned int tableauBriques::getDecalBriquesX() const{return decalBriquesX;}

unsigned int tableauBriques::getDecalBriquesY() const{return decalBriquesY;}

unsigned int tableauBriques::getDistanceInterBriques() const{return distanceInterBriques;}

unsigned int tableauBriques::getNbDeLignes() const{return nbDeLignes;}

void tableauBriques::printTableauBriques(WINDOW *w) const
{
  for(int i = 0 ; i<taille ; i++)
    data[i].printBrique(w);
}

//--------------------fin lecture---------------------------//

 //-------modif briques---------------------------------------//
void tableauBriques::setCorpAt(size_t i , char c){data[i].setCorp(c);}
void tableauBriques::setResistanceAt(size_t i , unsigned int r){data[i].setResistance(r);}
void tableauBriques::setHauteurAt(size_t i , unsigned int H){data[i].setL(H);}
void tableauBriques::setLongeurAt(size_t i , unsigned int longr){data[i].setl(longr);}
void tableauBriques::setPosxAt(size_t i , unsigned int _x){data[i].setX(_x);}
void tableauBriques::setPosyAt(size_t i , unsigned int _y){data[i].setY(_y);}
void tableauBriques::setColorAt(size_t i, Color col){data[i].setColor(col);}

//-----------------------------fin modif briques------------------//
