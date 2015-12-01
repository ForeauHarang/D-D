#include "RENDU_ListeElementPlan.hpp"

/*
RENDU_JeuDeTuile jeuDeTuile;
*/

/*
 * Constructeur 
 */
RENDU_ListeElementPlan::RENDU_ListeElementPlan(){
	this->jeuDeTuile = new RENDU_JeuDeTuile)();
}

/*
 * Destructeur 
 */
~RENDU_ListeElementPlan::RENDU_ListeElementPlan(){
	jeuDeTuile.~RENDU_JeuDeTuile();
}

		
/*
 * Getters
 */ 
MAP_Carte RENDU_ListeElementPlan::getCarteMap(){
	return this->carteMap;
}
FIGHT_Carte RENDU_ListeElementPlan::getCarteFight(){
	return this->carteFight;
}
 
/*
 * Setters
 */ 
void RENDU_ListeElementPlan::setCarteMap(MAP_Carte carte){
	this->carteMap=carte;
}
void RENDU_ListeElementPlan::setCarteFight(FIGHT_Carte carte){
	this->carteFight=carte;
}

/*
 * Methodes
 */  
//void RENDU_ListeElementPlan::stateChanged(const ETAT::ETATEvent& e){}
//void RENDU_ListeElementPlan::update(const ETAT::ListeElement& listElement, int i){}

