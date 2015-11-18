#include "MOTEUR_Regle.hpp"

	
/*
 * Constructeur 
 */

MOTEUR_Regle::MOTEUR_Regle();

/*
 * Destructeur 
 */
 
MOTEUR_Regle::~MOTEUR_Regle();

/*
 * Getters
 */		

MAP_Carte* MOTEUR_Regle::getCARTE_Map();

/*
 * Setters
 */

void MOTEUR_Regle::setCARTE_Map(MAP_Carte*);

/*
 * Methodes
 */  

bool MOTEUR_Regle::MOTEUR_isAvailable(MOTEUR_DeplacementPersonnage commande,int numeroAction){
	if(commande.getCharacterPtr->getX()<48*TAILLEBLOC) // le personnage ne peut pas aller hors de l'ecran; par défaut, permission=false
				actions.setPermissionTrue(numeroAction);
}
