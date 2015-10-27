#include "RENDU_Scene.hpp"

#include "RENDU_JeuDeTuile.hpp"
#include "RENDU_Animation.hpp" 
#include "RENDU_Surface.hpp"

/*
	//animations ?
	const RENDU_JeuDeTuile* jeuDeTuile;
	RENDU_Surface* surface;
*/

/*
 * Constructeur 
 */
RENDU_Plan::RENDU_Plan();

/*
 * Destructeur 
 */
~RENDU_Plan::RENDU_Plan();

/*
 * Getters
 */
const RENDU_JeuDeTuile* const RENDU_Plan::getTileSet(){
	return this->jeuDeTuile;
}

/*
 * Setters
 */
void RENDU_Plan::setTileSet(const RENDU_JeuDeTuile* jeuDeTuile){
	this->jeuDeTuile=jeuDeTuile;
} 
void RENDU_Plan::setSurface(RENDU_Surface* surface){
	this->surface=surface;
}
void RENDU_Plan::setAnimation(int i, RENDU_Animation* a){
	//TODO
}

/*
 * Methodes
 */  
void RENDU_Plan::printText(int x, int y, const char* msg, int spriteIdx, int w, int h){
	//TODO
}
void RENDU_Plan::sync(int64_t temps){
	//TODO
}
void RENDU_Plan::update(int64_t temps){
	//TODO
}