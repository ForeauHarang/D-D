#include "MOTEUR_ListeAction.hpp"

/*private:
		MOTEUR_Action *listeAction[LISTEMAX];
		bool permission[LISTEMAX];
		int nombreAtion=0;
	
	public:
*/


/*
 * Constructeur 
 */
 
MOTEUR_ListeAction::MOTEUR_ListeAction(){
	nombreAction=0;
}

/*
 * Destructeur 
 */

MOTEUR_ListeAction::~MOTEUR_ListeAction(){
	
}

/*
 * Getters
 */
 
MOTEUR_Action* MOTEUR_ListeAction::getActionFromList(int placeDansListe){
	return this->listeAction[placeDansListe];
}

int MOTEUR_ListeAction::getActionNumber(){
	return this->nombreAction;
}

bool MOTEUR_ListeAction::getPermissionFromList(int pladeDansListe){
	return permission[pladeDansListe];
}

/*
 * Setters
 */

void MOTEUR_ListeAction::addAction(MOTEUR_Action *action){
	this->listeAction[nombreAction]=action;
	nombreAction++;
}

void MOTEUR_ListeAction::setPermissionTrue(int placeDansListe){
	this->permission[placeDansListe-1]=true;
}

void MOTEUR_ListeAction::setPermissionFalse(int placeDansListe){
	this->permission[placeDansListe-1]=false;
}

void MOTEUR_ListeAction::removeAction(int placeDansListe){
	if(nombreAction>0){
		int i=placeDansListe;
		for(i=placeDansListe;i<nombreAction-1;i++){
			this->listeAction[nombreAction]=this->listeAction[nombreAction+1];
			this->permission[nombreAction]=this->permission[nombreAction+1];
		}
		nombreAction--;
	}
	if(nombreAction==0){
		this->permission[nombreAction]=false;
	}
}

/*
 * Methodes
 */ 

void MOTEUR_ListeAction::apply(){

	for(int i=0;i<nombreAction;i++){
		
		if(permission[i]){

			listeAction[i]->apply();
		}
	}
	for(int i=0;i<nombreAction;i++){
		removeAction(i);
	}
	
	
	
}