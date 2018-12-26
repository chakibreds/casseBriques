#ifndef __PLATF_H
#define __PLATF_H

extern "C" {
#include <ncurses.h>
}
#include <string>
#include "window.h"

class platf{
 private:
  int longeur;
  int posx;
  int posy;
  char corp;
  float vitesse;

 public:
  platf(int longr, int posx, int posy, char corp,float vit);


  int getlongr() const;
  int getx() const;
  int gety() const;
  char getcorp() const;
  bool contactmurG(int w ) const;
  bool contactmurD(int w ) const;
  float getVitesse() const;

  void print(WINDOW* w) const;

  //pour enlever l'ancien platf
  void printVide(WINDOW* w)const;

  void setx(int x);
  void sety(int x);
  void setlongeur(int longr);
  void setcorp(char corp);
  void setVitesse(float vit);
};
#endif
