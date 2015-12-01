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
/*
bool MOTEUR_Regle::isAvailable(MOTEUR_DeplacementPersonnage* commande){
	if(commande->getX()+commande->getDX()<(42*TAILLEBLOC - TAILLEBLOC / 2) && commande->getX()+commande->getDX()>-1 && commande->getY()+commande->getDY()<(22*TAILLEBLOC) && commande->getY()+commande->getDY()>-1) // le personnage ne peut pas aller hors de l'ecran; par défaut, permission=false
		return true;
		
	return false;
}*/

bool MOTEUR_Regle::isAvailable(MOTEUR_DeplacementPersonnage* commande){
	int X=commande->getX() / TAILLEBLOC;
	int Y=commande->getY() / TAILLEBLOC;
	int DX=commande->getDX() / TAILLEBLOC;
	int DY=commande->getDY() / TAILLEBLOC;
	
	int incrementationDeLigne = 67;//CARTE_carte->getWidth();
	
	int caseDuPerso = X+Y*incrementationDeLigne;
	//std::vector<int> level = CARTE_carte->getMap();
	
	
	if(!((X+DX < 42) && (X+DX > -1) && +(Y+DY<22) && (Y+DY>-1))) // le personnage ne peut pas aller hors de l'ecran; par défaut, permission=false
		return false;
/*	if(DX<0){
		if(level[caseDuPerso-1] > 14)
			return false;
	}
	if(DX>0){
		if(level[caseDuPerso+1] > 14)
			return false;
	}
	if(DY<0){
		if(level[caseDuPerso-incrementationDeLigne] > 14)
			return false;
	}
	if(DY>0){
		if(level[caseDuPerso+incrementationDeLigne] > 14)
			return false;
	}*/
	return true;
}


/*
bool MOTEUR_Regle::isAvailable(MOTEUR_Action commande){	
	return false;
}

*/
