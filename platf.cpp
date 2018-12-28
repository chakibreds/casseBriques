#include "platf.h"
#include "window.h"
#include <string>
platf::platf(int longr, int pox,int poy, char cor,float vit) : longeur(longr),posx(pox),posy(poy),corp(cor),vitesse(vit){}

int platf::getlongr() const {return longeur;}
int platf::getx() const {return posx;}
int platf::gety() const {return posy;}
char platf::getcorp() const {return corp;}
float platf::getVitesse() const
{
  return vitesse;
}
bool platf::contactmurG(int w) const {
  //w = with window
  return posx>0 ;
}
bool platf::contactmurD(int w) const {
  //w = with window
  return (posx+longeur < w);
}

void platf::setlongeur(int longr){longeur = longr;}
void platf::setx(int x){posx = x;}
void platf::sety(int y){posy = y;}
void platf::setcorp(char cor){corp = cor;}
void platf::setVitesse(float vit)
{
  vitesse=vit;
}

void platf::print(WINDOW* w) const
{
int l=longeur - 2;
  std::string x(l,corp);
  mvwprintw(w,posy,posx,"/");
  mvwprintw(w,posy,posx+1,x.c_str());
  mvwprintw(w,posy,posx+longeur-1,"\\");
  wrefresh(w);
  refresh();
}
void platf::printVide(WINDOW* w) const
{

  std::string x(longeur,' ');
  mvwprintw(w,posy,posx,x.c_str());
  wrefresh(w);
  refresh();

}
