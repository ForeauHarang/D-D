#include "RENDU_AnimatedTuile.hpp"


	/*taux;
	RENDU_Tuile* tuile;*/ 
	
/*
 * Constructeur 
 */
RENDU_AnimatedTuile::RENDU_AnimatedTuile(float taux=10){
	this->taux = taux;
}

/*
 * Destructeur 
 */
RENDU_AnimatedTuile::~RENDU_AnimatedTuile();

/*
 * Getters
 */
float const RENDU_AnimatedTuile::getRate(){
	return this->taux;
}

const RENDU_Tuile* const RENDU_AnimatedTuile::getTile(int64_t temps){
	//TODO
}
const RENDU_Tuile* const RENDU_AnimatedTuile::getTile(int i){
	//TODO
}
int const RENDU_AnimatedTuile::getTilecount(){
	//TODO
}

/*
 * Setters
 */
void RENDU_AnimatedTuile::setRate(float taux){
	this->taux=taux;
}
void RENDU_AnimatedTuile::setTile(int i, RENDU_Tuile* tuile){
	this->tuile=tuile;
	//TODO i?
}

/*
 * Methodes
 */  
 bool const RENDU_AnimatedTuile::isAnimated(){
	 return true;
 }
 void RENDU_AnimatedTuile::addTile(RENDU_Tuile* tuile){
	 //TODO
 }
