#include "MOTEUR_Regle.hpp"

	
/*
 * Constructeur 
 */

MOTEUR_Regle::MOTEUR_Regle(){
	
}

/*
 * Destructeur 
 */
 
MOTEUR_Regle::~MOTEUR_Regle(){
	
}

/*
 * Getters
 */		

//MAP_Carte* MOTEUR_Regle::getCARTE_Map();

/*
 * Setters
 */

//void MOTEUR_Regle::setCARTE_Map(MAP_Carte*);

/*
 * Methodes
 */  

bool MOTEUR_Regle::isAvailable(MOTEUR_DeplacementPersonnage* commande){
	if(commande->getX()+commande->getDX()<(42*TAILLEBLOC - TAILLEBLOC / 2) && commande->getX()+commande->getDX()>-1 && commande->getY()+commande->getDY()<(22*TAILLEBLOC) && commande->getY()+commande->getDY()>-1) // le personnage ne peut pas aller hors de l'ecran; par défaut, permission=false
		return true;
		
	return false;
}
/*
bool MOTEUR_Regle::isAvailable(MOTEUR_Action commande){	
	return false;
}

*/
