#ifndef __OPTIONS_H
#define __OPTIONS_H

#include <string>

class options{
 private :
  unsigned int hauteurJeu;
  unsigned int longeurJeu;
  unsigned int longeurPlatf;
  unsigned int vitesseJeu;//en milliseconds
  
  //methodes pour lire le fichier de config
  void nettoie(std::string &str);
  bool findCleVal(std::string &str , std::string &str1 , std::string &s2);
  void TraiteOption(const std::string &cle , const std::string &valeur, size_t num_ligne);
  
 public :
  options();
  options(unsigned int h, unsigned int l, unsigned int longp);
  
  unsigned int getH()const;
  unsigned int getL()const;
  unsigned int getLongPla()const;
  unsigned int getVitesse()const;

  
  void setVitesse(unsigned int x);  
  void setHauteurJeu(unsigned int x);
  void setLongPla(unsigned int x);
  void setLongJeu(unsigned int x);
  void menu();
  
  void loadConfig(std::string file);
  //config (attrb : valeur)
};

#endif
