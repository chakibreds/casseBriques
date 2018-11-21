#ifndef BRIQUES_H_
#define BRIQUES_H_
#include"window.h"
class Brique
{
private: 
char corp; 
unsigned int resistance,L,l,x,y;
public:
	//largeur L=hauteur 
	//longueur l 
	Brique(); 
	Brique(char corp ,int y, int x , int L, int l,int resistance);
	Brique(const Brique &b);
	unsigned int getL()const; 
	unsigned int getl()const;
	unsigned int getX()const;
	unsigned int getY()const;
	void setL(unsigned int L);
	void setl(unsigned int l);
	void setX(unsigned int x);
	void setY(unsigned int y);
	void printBrique(WINDOW *w);
	void printvide(WINDOW *w);
};
#endif