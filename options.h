#ifndef __OPTIONS_H
#define __OPTIONS_H



class options{
 private :
  int hauteurJeu;
  int longeurJeu;
  int longeurPlatf;

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
};

#endif
