#include "RENDU_StaticTuile.hpp"


		/*int x;
		int y;
		int hauteur;
		int largeur;*/
		
		/*
		 * Constructeur 
		 */
StaticTuile::StaticTuile(int x=0, int y=0, int largeur=0, int hauteur=0){
	this->x=x;
	this->y=y;
	this->largeur=largeur;
	this->hauteur=hauteur;
}

/*
 * Destructeur 
 */
StaticTuile::~StaticTuile(){
	
}

/*
 * Getters
 */
int const StaticTuile::getX(){
	return this->x;
}

int const StaticTuile::getY(){
	return this->y;
}

int const StaticTuile::getWidth(){
	return this->largeur;
}

int const StaticTuile::getHeight(){
	this->hauteur;
}

/*
 * Setters
 */
void StaticTuile::setX(int x){
	this->x=x;
} 
void StaticTuile::setY(int y){
	this->y=y;	
}
void StaticTuile::setWidth(int largeur){
	this->largeur=largeur;
}
void StaticTuile::setHeight(int hauteur){
	this->hauteur=hauteur;
}

/*
 * Methodes
 */  
bool const isAnimated(){
	return false; 
}
