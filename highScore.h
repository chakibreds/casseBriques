#ifndef HIGHSCORE_H
#define HIGHSCORE_H

#include "window.h"
#include <exception>
#include <fstream>
#include <string>
#include <ncurses.h>
class highScore{
  
 private:
  unsigned int *TabDeScores;

 
 public:
  
 
  highScore();
  //~highScore(); faut le faire
  bool estUnHighScore(unsigned int x) const;
  void mettreNouveauHighScore(unsigned int score , std::string nom);

  void pop(const Window &w)const;
 
  
};

#endif
