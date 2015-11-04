#include "RENDU_StaticTuile.hpp"


/*int x;
int y;
int hauteur;
int largeur;*/
		
/*
 * Constructeur 
 */
 /*
RENDU_StaticTuile::RENDU_StaticTuile(){
	this->x=0;
	this->y=0;
	this->largeur=0;
	this->hauteur=0;
}
*/
/*
RENDU_StaticTuile::RENDU_StaticTuile(int x, int y, int largeur, int hauteur){
	this->x=x;
	this->y=y;
	this->largeur=largeur;
	this->hauteur=hauteur;
}*/


/*
 * Destructeur 
 */
/*
RENDU_StaticTuile::~RENDU_StaticTuile(){
	
}
*/
/*
 * Getters
 */
int const RENDU_StaticTuile::getX(){
	return this->x;
}

int const RENDU_StaticTuile::getY(){
	return this->y;
}

int const RENDU_StaticTuile::getWidth(){
	return this->largeur;
}

int const RENDU_StaticTuile::getHeight(){
	return this->hauteur;
}

/*
 * Setters
 */
void RENDU_StaticTuile::setX(int x){
	this->x=x;
} 
void RENDU_StaticTuile::setY(int y){
	this->y=y;	
}
void RENDU_StaticTuile::setWidth(int largeur){
	this->largeur=largeur;
}
void RENDU_StaticTuile::setHeight(int hauteur){
	this->hauteur=hauteur;
}

/*
 * Methodes
 */  
bool const RENDU_StaticTuile::isAnimated(){
	return false; 
}
