#ifndef __BILLE_H
#define __BILLE_H
#include <ncurses.h>
#include "window.h"
#include "briques.h"
#include "tableauBriques.h"

class Bille{

public:
    
    enum DirectionDepart {
    GAUCHE,
    DROITE,
    };
    
private:
    
    int posX;
    int posY;
    int directionX;
    int directionY;
    char icone;
    DirectionDepart maDirection;
    
    
public:
    
    Bille();
    Bille(int positionX, int positionY, int dirX, int dirY, char icon, DirectionDepart dirDebut);
    
    
    int getX() const;
    int getY() const;
    int getDirX() const;
    int getDirY() const;
    char getIcone() const;
    DirectionDepart getDirDepart() const;
    
    void setX(int x);
    void setY(int y);
    void setDirX(int dirX);
    void setDirY(int dirY);
    void setIcone(char icon);
    void setDirDepart(DirectionDepart dir);
    
    void avancer();
    void changerTrajectoire(int angle);                     // ne prend que l'angle de la surface sur laquelle le choc a lieu
    void contactBords(int tailleX, int tailleY);            // prend taille grille de jeu
    void contactRaquette(int debutRaquette, int finRaquette, int yRaquette); // prend taille raquette et sa pos en Y
    bool billeDansBrique(Brique uneBrique) const;
    void contactBrique(tableauBriques *tabBriques);
    void print(WINDOW* w) const;
    
};
#endif
