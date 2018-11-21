#include<iostream>
#include <cstdlib>
#include "briques.h"
using namespace std; 

Brique::Brique():corp(' '),L(2),l(10),x(0),y(0),resistance(0)
{

} 
Brique::Brique(char corp,int y, int x , int L, int l,int resistance):corp(corp),L(L),l(l),x(x),y(y),resistance(resistance)
{
cout<< "construction de brique par un constructeur par parametres"<<endl;
}
Brique::Brique(const Brique &b)
{
L=b.L;
l=b.l;
x=b.x;
y=b.y;
}
	unsigned int Brique::getL()const
	{
		return L; 
	}
	unsigned int Brique::getl()const
	{
		return l;
	}
	unsigned int Brique::getX()const
	{
		return x;
	}
	unsigned int Brique::getY()const
	{
		return y; 
	}
	void Brique::setL(unsigned int L)
	{
		this->L=L;
	}
	void Brique::setl(unsigned int l)
	{
		this->l=l; 
	}
	void Brique::setX(unsigned int x)
	{
		this->x=x;
	}
	void Brique::setY(unsigned int y)
	{
		this->y=y; 
	}

	void Brique::printBrique(WINDOW *w)
	{
		std::string s(l,corp);
		for(int i = 0 ; i<L ; i++){
		  wattron(w , A_REVERSE);
		  mvwprintw(w,y+i,x,s.c_str());
		  wattroff(w , A_REVERSE);
		}
  		wrefresh(w);
  		refresh();
	}
	void Brique::printvide(WINDOW *w)
	{
	  	std::string s(l,' ');
		for(int i = 0 ; i<L ; i++){
		 
		  mvwprintw(w,y+i,x,s.c_str());
		  
		}
  		wrefresh(w);
  		refresh();
	}
