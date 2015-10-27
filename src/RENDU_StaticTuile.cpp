#include "RENDU_StaticTuile.hpp"
#include "RENDU_Tuile.hpp"

		/*int x;
		int y;
		int hauteur;
		int largeur;*/
		
/*
 * Constructeur 
 */
RENDU_StaticTuile::RENDU_StaticTuile(int x=0, int y=0, int largeur=0, int hauteur=0){
	this->x=x;
	this->y=y;
	this->largeur=largeur;
	this->hauteur=hauteur;
}

/*
 * Destructeur 
 */
~RENDU_StaticTuile::RENDU_StaticTuile(){
	
}

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
	this->hauteur;
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

/* Tableau de Tuiles :
tabtuile[0] = humain1
tabtuile[1] = humain2
tabtuile[2] = loup_garou
tabtuile[3] = monstre
tabtuile[4] = guerrier
tabtuile[5] = sorcier
tabtuile[6] = vampire
tabtuile[7] = voleur
tabtuile[8] = boule_de_feu_1
tabtuile[9] = poulet
tabtuile[10] = coffre
tabtuile[11] = montagne
tabtuile[12] = herbe
tabtuile[13] = chemin
tabtuile[14] = herbe
tabtuile[15] = livre
tabtuile[16] = poignard 
tabtuile[17] = sable
tabtuile[18] = roche
tabtuile[19] = fusil
tabtuile[20] = balle_argent
tabtuile[21] = bouclier
tabtuile[22] = poche_de_sang
tabtuile[23] = boule_de_feu_2
tabtuile[24] = route
tabtuile[25] = chemin
tabtuile[26] = arbre
tabtuile[27] = pistolet
tabtuile[28] = potion_rose
tabtuile[29] = potion_rouge
tabtuile[30] = potion_jaune
tabtuile[31] = potion_verte
tabtuile[32] = potion_bleue
tabtuile[33] = pieu
tabtuile[34] = boule_de_feu_3
tabtuile[35] = carte_map
tabtuile[36] = carte_fight
*/