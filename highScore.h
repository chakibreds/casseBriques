#ifndef HIGHSCORE_H
#define HIGHSCORE_H

#include "window.h"
#include <exception>
#include <fstream>
#include <string>

class highScore{

private:
unsigned int *TabDeScores;

public:


highScore();
//~highScore(); faut le faire
bool estUnHighScore(unsigned int x) const;
void MettrenouveauHighScore(std::string file , unsigned int score , std::string nom) const;



};

#endif
