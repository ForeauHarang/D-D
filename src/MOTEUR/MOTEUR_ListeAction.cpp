//#include "MOTEUR_ListeAction.hpp"

#include "MOTEUR.hpp"
using namespace MOTEUR;
using namespace MAP;

/*
 * Constructeur 
 */
MOTEUR_ListeAction::MOTEUR_ListeAction() {
}

MOTEUR_ListeAction::MOTEUR_ListeAction(MAP_Carte *carte){
	nombreAction=0;
	regles=MOTEUR_Regle(carte);
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

/*
 * Setters
 */

void MOTEUR_ListeAction::addAction(MOTEUR_Action *action){
	if(resterDansLaBoucle) {
		this->listeAction[nombreAction] = action;
		nombreAction++;
	}
}

void MOTEUR_ListeAction::removeAction(int placeDansListe){
	if(nombreAction>0){
		int i=placeDansListe;
		for(i=placeDansListe;i<nombreAction-1;i++){
			this->listeAction[nombreAction]=this->listeAction[nombreAction+1];
		}
		nombreAction--;

	}
}

/*
 * Methodes
&listeAction[i]
 */ 

void MOTEUR_ListeAction::apply(){
	int limite;
	while(resterDansLaBoucle){

		limite = nombreAction;
		for (int i = 0; i < limite; i++) {
			if (listeAction[i]->getActionId() == "deplacementPersonnage") {
				//std::cout<<dynamic_cast <MOTEUR_DeplacementPersonnage *>(listeAction[i])->getCharacterPtr()->getCharacterId()<<std::endl;


				if (regles.isAvailable(dynamic_cast <MOTEUR_DeplacementPersonnage *>(listeAction[i]))) {
					//std::cout<<dynamic_cast <MOTEUR_DeplacementPersonnage *>(listeAction[i])->getCharacterPtr()->getCharacterId()<<std::endl;
					listeAction[i]->apply();
				}
			}
			if (listeAction[i]->getActionId() == "QuitterProgramme") {
				std::cout<<"action exit"<<std::endl;
				//std::cout<<dynamic_cast <MOTEUR_DeplacementPersonnage *>(listeAction[i])->getCharacterPtr()->getCharacterId()<<std::endl;
				listeAction[i]->apply();
				resterDansLaBoucle=false;
				i=limite;
			}
		}
		for (int i = 0; i < limite; i++) {
			removeAction(0);
		}
	}
	while(nombreAction) {
		removeAction(0);
	}
	removeAction(0);

}
