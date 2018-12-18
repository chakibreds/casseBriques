#include "bille.h"
#include "window.h"
#include <stdio.h>
#include <string>
#include "tableauBriques.h"



Bille::Bille() : posX(0), posY(0), directionX(0), directionY(0), icone('o'), maDirection(GAUCHE){
}

Bille::Bille(int x, int y, int dirX, int dirY, char icon, DirectionDepart dirDebut): posX(x), posY(y), directionX(dirX), directionY(dirY), icone(icon), maDirection(dirDebut){
}

    int Bille::getX() const{
        return posX;
    }
    int Bille::getY() const{
        return posY;
    }
    int Bille::getDirX() const{
        return directionX;
    }
    int Bille::getDirY() const{
        return directionY;
    }
    char Bille::getIcone() const{
        return icone;
    }
    Bille::DirectionDepart Bille::getDirDepart() const{
        return maDirection;
    }

    
    void Bille::setX(int x) {
        posX=x;
    }
    void Bille::setY(int y){
        posY=y;
    }
    void Bille::setDirX(int dirX){
        directionX=dirX;
    }
    void Bille::setDirY(int dirY){
        directionY=dirY;
    }
    void Bille::setIcone(char icon){
        icone=icon;
    }
    void Bille::setDirDepart(DirectionDepart dir){
        maDirection=dir;
    }
    
    
    void Bille::avancer(){
        posX=posX+directionX;
        posY=posY+directionY;
    }
    
    
    void Bille::changerTrajectoire(int angle){
        if (angle==0){
            directionY=(-1)*(this->getDirY());
        }
        if (angle==90){
            directionX=(-1)*(this->getDirX());
        }
        if (angle==45){
            directionY=(-1)*(this->getDirY());
            directionX=(-1)*(this->getDirX());
        }
    }
    
    
    void Bille::contactBords(int tailleX, int tailleY){
        if ((posX+directionX==tailleX)||(posX+directionX<0)){
            (this->changerTrajectoire(90));
        }
        if ((posY+directionY==tailleY)||(posY+directionY<0)){
            (this->changerTrajectoire(0));
        }
    }
    
    
    void Bille::contactRaquette(int debutRaquette, int finRaquette, int yRaquette){
        if((posX+directionX<=finRaquette && posX+directionX>=debutRaquette)&&(posY+directionY==yRaquette)){
            this->changerTrajectoire(0);
        }
    }
    
    
    bool Bille::billeDansBrique(Brique uneBrique) const{    // renvoie (bille sera dans brique)
        return(((posX+directionX>=uneBrique.getX() && posX+directionX<uneBrique.getX()+uneBrique.getl()) && (posY+directionY>=uneBrique.getY() && posY+directionY<uneBrique.getY()+uneBrique.getL())));
    }
    
    
    void Bille::contactBrique(tableauBriques *tabBriques){
        int nbrBriques=tabBriques->getTaille();
        for (int i=0;i<nbrBriques;i++){
            if (billeDansBrique(tabBriques->at(i))){
                if ((posX==tabBriques->at(i).getX()-1 && posY==tabBriques->at(i).getY()+tabBriques->at(i).getL()+1) || (posX==tabBriques->at(i).getX()+tabBriques->at(i).getl()+1 && posY==tabBriques->at(i).getY()-1) || (posX==tabBriques->at(i).getX()+tabBriques->at(i).getl()+1 && posY==tabBriques->at(i).getY()+tabBriques->at(i).getL()+1) || (posX==tabBriques->at(i).getX()-1 && posY==tabBriques->at(i).getY()-1)){
                    this->changerTrajectoire(45);
                }
                else if (posX==tabBriques->at(i).getX()+tabBriques->at(i).getl()+1 || posX==tabBriques->at(i).getX()-1){
                    this->changerTrajectoire(90);
                }
                else if (posY==tabBriques->at(i).getY()+tabBriques->at(i).getL()+1 || posY==tabBriques->at(i).getY()-1){
                    this->changerTrajectoire(0);
                }
            }
        }
    }
    
    
    void Bille::print(WINDOW* w) const{
        std::string x(1,icone);
        mvwprintw(w,posY,posX,x.c_str());
        wrefresh(w);
        refresh();
    }
