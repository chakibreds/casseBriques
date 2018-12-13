#ifndef JOUEUR_H
#define JOUEUR_H

#include <ncurses.h>
#include <string>
class joueur{

 private:
  std::string nomJ;
  unsigned int nbVies;
  unsigned int lvl;
  unsigned int score;

 public:

  joueur();
  joueur(std::string _nomJ, unsigned int _nbVies, unsigned int _lvl, unsigned int _score);
  
  std::string getNomJ() const;
  unsigned int getNbVies() const;
  unsigned int getlvl() const;unsigned int getScore() const;
  
  void setNbVies(unsigned int x);
  void setlvl(unsigned int x);
  void setScore(unsigned int x);
  void addScore(unsigned int x);
  
  void printStats(WINDOW *w)const;
};

#endif
