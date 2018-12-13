#include "joueur.h"
#include <ncurses.h>
#include <string>
joueur::joueur() : nomJ("Anon") , nbVies(3) , lvl(1) , score(0) {}

joueur::joueur( std::string _nomJ,unsigned int _nbVies, unsigned int _lvl, unsigned int _score) : nomJ(_nomJ) , nbVies(_nbVies) , lvl(_lvl) , score(_score) {}

unsigned int joueur::getNbVies() const{return nbVies;}
unsigned int joueur::getlvl() const{return lvl;}
unsigned int joueur::getScore() const{return score;}
std::string joueur::getNomJ() const { return nomJ;}

   
void joueur::setNbVies(unsigned int x){nbVies = x;}
void joueur::setlvl(unsigned int x){lvl = x;}
void joueur::setScore(unsigned int x){score = x;}
void joueur::addScore(unsigned int x){score = score + x;}

void joueur::printStats(WINDOW *w)const{
  std::string Vies = std::to_string(nbVies);
  std::string Lvl = std::to_string(lvl);
  std::string Score = std::to_string(score);
  
  
  mvwprintw(w,2,1,"Nom Joueur : ");
  mvwprintw(w,2,14,nomJ.c_str());
  mvwprintw(w,3,1,"Vies restantes : ");
  mvwprintw(w,3,18,Vies.c_str());
  mvwprintw(w,4,1,"Level : ");
  mvwprintw(w,4,9,Lvl.c_str());
  mvwprintw(w,5,1,"Score : ");
  mvwprintw(w,5,9,Score.c_str());
  
  wrefresh(w);
  refresh();
}
