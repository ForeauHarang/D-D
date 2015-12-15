#include "MOTEUR.hpp"
using namespace MOTEUR;
using namespace MAP;
	
/*
 * Constructeur 
 */

MOTEUR_Regle::MOTEUR_Regle(){
	
}

MOTEUR_Regle::MOTEUR_Regle(MAP_Carte *carte){
	this->CARTE_carte=carte;
}

/*
 * Destructeur 
 */
 
MOTEUR_Regle::~MOTEUR_Regle(){
	
}

/*
 * Methodes
 */

bool MOTEUR_Regle::isAvailable(MOTEUR_DeplacementPersonnage* commande){
	int X=commande->getX() / TAILLEBLOC;
	int Y=commande->getY() / TAILLEBLOC;
	int DX=commande->getDX() / TAILLEBLOC;
	int DY=commande->getDY() / TAILLEBLOC;
	
	
	if(!((X+DX < 42) && (X+DX > -1) && +(Y+DY<22) && (Y+DY>-1))) // le personnage ne peut pas aller hors de l'ecran; par défaut, permission=false
		return false;

	if(DX!=0){
		if(CARTE_carte->getLevelValue(X+DX,Y) > 14)
			return false;
	}

	if(DY!=0){
		if(CARTE_carte->getLevelValue(X,Y+DY) > 14)
			return false;
	}
	return true;
}

