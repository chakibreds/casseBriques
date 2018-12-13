#ifndef __OPTIONS_H
#define __OPTIONS_H

#include <string>

class options{
 private :
  int hauteurJeu;
  int longeurJeu;
  int longeurPlatf;
  
  //methodes pour lire le fichier de config
  void nettoie(std::string &str);
  bool findCleVal(std::string &str , std::string &str1 , std::string &s2);
  void TraiteOption(const std::string &cle , const std::string &valeur, size_t num_ligne);
  
 public :
  options();
  options(int h, int l, int longp);
  
  int getH()const;
  int getL()const;
  int getLongPla()const;

  void setHauteurJeu(int x);
  void setLongPla(int x);
  void setLongJeu(int x);
  void menu();
  
  void loadConfig(std::string file);
  //config (attrb : valeur)
};

#endif
