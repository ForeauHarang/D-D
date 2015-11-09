#include "MAP_Personnage.hpp"
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
 
MAP_Personnage::MAP_Personnage(int carac[NOMBRECARAC] , Race race, Profession profession, Groupe groupe, MAP_InventairePersonnage inventaire, string nom){
	this->caracteristiques=carac;
	this->race=race;
	this->profession=profession;
	this->groupe=groupe;
	this->inventaire=inventaire;
	this->idPersonnage=nom;
}
MAP_Personnage::MAP_Personnage(Race race, Profession profession, Groupe groupe, MAP_InventairePersonnage inventaire, string nom){
	int carac[NOMBRECARAC] ;
	carac[0]=10;
	carac[1]=10;
	carac[2]=10;
	carac[3]=1;
	carac[4]=0;
	carac[5]=100;
	carac[6]=0;
	carac[7]=0;
	carac[8]=0;
	
	this->caracteristiques=carac;
	this->race=race;
	this->profession=profession;
	this->groupe=groupe;
	this->inventaire=inventaire;
	this->idPersonnage=nom;
	
}
MAP_Personnage::MAP_Personnage(string nom){
	int carac[NOMBRECARAC] ;
	carac[0]=10;
	carac[1]=10;
	carac[2]=10;
	carac[3]=1;
	carac[4]=0;
	carac[5]=100;
	carac[6]=0;
	carac[7]=0;
	carac[8]=0;
	
	this->caracteristiques=carac;
	this->race=HUMAIN;
	this->profession=SOLDAT;
	this->groupe=NEUTRE;
	this->idPersonnage=nom;
	
}
 
/*
 * destructeurs
 * */
  
MAP_Personnage::~MAP_Personnage(){
	this->inventaire.~MAP_InventairePersonnage();
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
MAP_InventairePersonnage MAP_Personnage::getInventory(){
	return this->inventaire;
}

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

void MAP_Personnage::openInventory(){
	this->inventaire.openInventory();
}

void MAP_Personnage::closeInventory(){
	this->inventaire.closeInventory();
	
}
