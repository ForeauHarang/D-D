//#include "MOTEUR_DeplacementPersonnage.hpp"
#include "MOTEUR.hpp"
using namespace MOTEUR;
using namespace MAP;

//MOTEUR_DeplacementPersonnage::MOTEUR_DeplacementPersonnage(){}//:MOTEUR_Action(){}
void MOTEUR_DeplacementPersonnage::initDeplacement(int dx, int dy, MAP_Personnage* ptrperso){
	this->dx=dx;
	this->dy=dy;
	this->ptrperso=ptrperso;
}

/*
 * Getters
 */

int MOTEUR_DeplacementPersonnage::getX(){
	return this->ptrperso->getX();
}

int MOTEUR_DeplacementPersonnage::getY(){
	return ptrperso->getY();
}

int MOTEUR_DeplacementPersonnage::getDX(){
	return this->dx;
}

int MOTEUR_DeplacementPersonnage::getDY(){
	return this->dy;
}
MAP_Personnage* MOTEUR_DeplacementPersonnage::getCharacterPtr(){
	return this->ptrperso;
}

void MOTEUR_DeplacementPersonnage::apply(){
	ptrperso->setX(ptrperso->getX()+dx);
	ptrperso->setY(ptrperso->getY()+dy);
}

string MOTEUR_DeplacementPersonnage::getActionId(){
	string tempstr="deplacementPersonnage";
	return tempstr;
}
