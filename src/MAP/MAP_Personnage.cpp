//#include "MAP_Personnage.hpp"
#include "MAP.hpp"
using namespace MAP;
/*
private :
	int[NOMBRECARAC] caracteristiques; 
	Race race;
	Profession profession;
	Groupe groupe;
	MAP_InventairePersonnage inventaire;
	
	string idPersonnage;
	
	public :
*/
		
/*
 * constructeurs
 * */
 
MAP_Personnage::MAP_Personnage(int carac[NOMBRECARAC] , Race race, Profession profession, Groupe groupe,string nom){// MAP_InventairePersonnage inventaire, string nom){

	this->race=race;
	this->profession=profession;
	this->groupe=groupe;
	//this->inventaire=inventaire;
	this->idPersonnage=nom;
}
MAP_Personnage::MAP_Personnage(Race race, Profession profession, Groupe groupe,string nom){// MAP_InventairePersonnage inventaire, string nom){
	caracteristiques[0]=10;
	caracteristiques[1]=10;
	caracteristiques[2]=10;
	caracteristiques[3]=1;
	caracteristiques[4]=0;
	caracteristiques[5]=100;
	caracteristiques[6]=0;
	caracteristiques[7]=0;
	caracteristiques[8]=0;
	
	this->race=race;
	this->profession=profession;
	this->groupe=groupe;
	//this->inventaire=inventaire;
	this->idPersonnage=nom;
	
}
MAP_Personnage::MAP_Personnage(string nom){
	caracteristiques[0]=10;
	caracteristiques[1]=10;
	caracteristiques[2]=10;
	caracteristiques[3]=1;
	caracteristiques[4]=0;
	caracteristiques[5]=100;
	caracteristiques[6]=0;
	caracteristiques[7]=0;
	caracteristiques[8]=0;
	
	this->race=HUMAIN;
	this->profession=SOLDAT;
	this->groupe=NEUTRE;
	this->idPersonnage=nom;
	//this->inventaire=MAP_InventairePersonnage();
	
}
 
/*
 * destructeurs
 * */
  
MAP_Personnage::~MAP_Personnage(){
	//this->inventaire.~MAP_InventairePersonnage();
}

/*
 * getteurs
 * */

int MAP_Personnage::getX(){
	return this->caracteristiques[7];
}
int MAP_Personnage::getY(){
	return this->caracteristiques[8];
}

int* MAP_Personnage::getCharacteristics(){
	return this->caracteristiques;
}

Race MAP_Personnage::getRace(){
	return race;
}

Profession MAP_Personnage::getJob(){
	return this->profession;
}

Groupe MAP_Personnage::getGroup(){
	return this->groupe;
}

string MAP_Personnage::getCharacterId(){
	return this->idPersonnage;
}
/*
MAP_InventairePersonnage MAP_Personnage::getInventory(){
	return this->inventaire;
}
*/
/*
 * setteurs
 * */
 
void MAP_Personnage::set1characteristicto(int numeroCarac, int nouvelleValeur){
	this->caracteristiques[numeroCarac]=nouvelleValeur;
}
void MAP_Personnage::setX(int x){
	this->caracteristiques[7]=x;
}
void MAP_Personnage::setY(int y){
	this->caracteristiques[8]=y;
}

/*
 * autres méthodes
 * */
/*
void MAP_Personnage::openInventory(){
	this->inventaire.openInventory();
}

void MAP_Personnage::closeInventory(){
	this->inventaire.closeInventory();
	
}
*/
