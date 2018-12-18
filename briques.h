#ifndef BRIQUES_H_
#define BRIQUES_H_
#include"window.h"
class Brique
{
 private: 
  char corp; 
  unsigned int resistance;
  unsigned int L;            // L la hauteur de la brique (taille en y)
  unsigned int l;            // l la largeur de la brique (taille en x)
  unsigned int x;            // x et y position du coin EN HAUT A GAUCHE
  unsigned int y;
  
  Color couleur;
 public:
  //largeur L=hauteur 
  //longueur l 
  Brique(); 
  Brique(char corp , Color couleur,int y, int x , int L, int l,int resistance);
  Brique(const Brique &b);
  
  unsigned int getL()const; 
  unsigned int getl()const;
  unsigned int getX()const;
  unsigned int getY()const;
  unsigned int getResistance()const;

  void setResistance(unsigned int r);
  void setCorp(char c);
  void setColor(Color col);
  void setL(unsigned int L);
  void setl(unsigned int l);
  void setX(unsigned int x);
  void setY(unsigned int y);
  void printBrique(WINDOW *w);
  void printVide(WINDOW *w);
};
#endif
