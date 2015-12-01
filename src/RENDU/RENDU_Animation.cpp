#include "RENDU_Animation.hpp" 

		/*int x;
		int y;
		float vitesse;
		int64_t debut;
		const RENDU_Tuile* tuile;
		
		//direction;
		
		int i;*/	
		
/*
 * Constructeur 
 */
RENDU_Animation::RENDU_Animation(int i, int x, int y, const RENDU_Tuile* a){
	this->i=i;
	this->x=x;
	this->y=y;
	this->tuile=a;
}

/*
 * Destructeur 
 */
RENDU_Animation::~RENDU_Animation(){
	
}

/*
 * Setters
 */
void RENDU_Animation::setDirection(//){
	//TODO
}
void RENDU_Animation::setSpeed(float vitesse){
	this->vitesse=vitesse;
}

/*
* Méthodes
*/
void RENDU_Animation::sync(int64_t temps){
	//TODO
}
void RENDU_Animation::update(int64_t temps, RENDU_Surface* surface){
	//TODO
}
