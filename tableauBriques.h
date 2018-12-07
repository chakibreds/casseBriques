#ifndef TABLEAU_BRIQUES_H
#define TABLEAU_BRIQUES_H

#include <cstdlib>
#include "briques.h"
//A faire
//-destructeur


class tableauBriques{

 private:
  size_t taille;
  size_t alloc;
  Brique *data;

  //-------pour creer des niveaux automatiques en rectangles-------------------//
  unsigned int decalBriquesX;
  unsigned int decalBriquesY;
  unsigned int distanceInterBriques;
  //nbDeLignes > 0
  unsigned int nbDeLignes;
  //-------------------------------------------------------//
 public:

  //constructeur

  //constructeur 1
  //donne un tab avec 3 lignes de 4 briques
  tableauBriques();

  //constructeur 2
  //donne un tab avec taille briques et les Decals et nblignes = 0
  tableauBriques(size_t _taille);

  //constructeur 3
  //nbLignes > 0
  tableauBriques(size_t _taille , unsigned int _decalBriquesX, unsigned int _decalBriquesY,unsigned int _distanceInterBriques, unsigned int _nbDeLignes);





  
  //destructeur
  //~tableauBriques();

  
  //-------lecture
  size_t getTaille() const;
  size_t getAlloc() const;
  Brique at(size_t i) const;
  void printTableauBriques(WINDOW *w) const;
  unsigned int getDecalBriquesX() const;
  unsigned int getDecalBriquesY() const;
  unsigned int getDistanceInterBriques() const;
  unsigned int getNbDeLignes() const;

  //-------modif tab
  void setTaille(size_t i);
  void setAlloc(size_t i);
  

  //-------modif brique
  void setCorpAt(size_t i , char c);
  void setResistanceAt(size_t i, unsigned int r);
  void setHauteurAt(size_t i , unsigned int H);
  void setLongeurAt(size_t i , unsigned int longr);
  void setPosxAt(size_t i , unsigned int _x);
  void setPosyAt(size_t i , unsigned int _y);
  void setColorAt(size_t i , Color col);
  
  
  
  
};
#endif
