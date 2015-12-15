#include "IA.hpp"

using namespace IA;
using namespace MOTEUR;
using namespace MAP;

/*
private :
int etage;
IA_DeplacementCase* pere;
int x;
int y;
*/

/*
* constructeurs
* */

IA_DeplacementCase::IA_DeplacementCase(int etage, int x, int y, MAP_Carte* carte) {
    this->etage=etage;
    this->x=x/TAILLEBLOC;
    this->y=y/TAILLEBLOC;

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

int IA_DeplacementCase::getSquareDistance(IA_DeplacementCase* cible, MAP_Carte* map){
    int d=0;


    if(map->getLevelValue(this->x,this->y)>14) {
        d=-1;
    }else {
        d += (this->x - cible->getX()) * (this->x - cible->getX());
        d += (this->y - cible->getY()) * (this->y - cible->getY());
    }
    return d;
}

int IA_DeplacementCase::getSquareDistance(int x, int y, MAP_Carte* map){
    int d=0;


    if(map->getLevelValue(this->x,this->y)>14) {
        d=-1;
    }else {
        d += (this->x - x) * (this->x - x);
        d += (this->y - y) * (this->y - y);
    }
    return d;
}

int IA_DeplacementCase::getStage(){
    return this->etage;
}

IA_DeplacementCase* IA_DeplacementCase::getFather(){
    return this->pere;
}


MAP_Carte* IA_DeplacementCase::getMap(){
	return this->carte;
}


