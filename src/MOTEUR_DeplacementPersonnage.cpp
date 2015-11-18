#include "MOTEUR_DeplacementPersonnage.hpp"

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
