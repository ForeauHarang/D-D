//
// Created by gabriel on 03/12/15.
//

#include "IA_DeplacementCase.hpp"

/*
private :
int etage;
IA_DeplacementCase* pere;
int x;
int y;

public :
*/
/*
* constructeurs
* */

IA_DeplacementCase::IA_DeplacementCase(int etage, int x, int y, MAP_Carte* carte) {
    this->etage=etage;
    this->x=x;
    this->y=y;
    this->carte=carte;
}

IA_DeplacementCase::IA_DeplacementCase(int etage, int x, int y, IA_DeplacementCase* pere, MAP_Carte* carte) {
    this->etage=etage;
    this->x=x;
    this->y=y;
    this->pere=pere;
    this->carte=carte;
}

/*
* destructeurs
* */

IA_DeplacementCase::~IA_DeplacementCase(){

}

/*
* getteurs
* */

int IA_DeplacementCase::getX(){
    return this->x;
}

int IA_DeplacementCase::getY(){
    return this->y;
}
int IA_DeplacementCase::getSquareDistance(IA_DeplacementCase* cible){
    int d=0;

    if(carte->getLevelValue(this->x,this->y)>14) {
        d=-1;
        }else {
        d += (this->x - cible->getX()) * (this->x - cible->getX());
        d += (this->y - cible->getY()) * (this->y - cible->getY());
    }
    return d;
}

int IA_DeplacementCase::getStage(){
    return this->etage;
}

IA_DeplacementCase* IA_DeplacementCase::getFather(){
    return this->pere;
}


/*
* setteurs
* */

/*
* autres méthodes
* */

