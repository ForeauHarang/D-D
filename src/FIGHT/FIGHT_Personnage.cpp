#include "FIGHT.hpp"
using namespace FIGHT;

/*
private :
FIGHT_Competence* listeCompetences[]; // cf fin du header
int* caracteristiques; // cf fin du header
Race race;
Groupe groupe;
Profession profession;
NomArme arme;
NomArmure armure;
NomPotion potion;
string idPersonnage;
bool vivant;
*/

/*
* constructeurs
* */

FIGHT_Personnage::FIGHT_Personnage(int niveau, int x, int y, FIGHT_Race race, 
					FIGHT_Groupe groupe, FIGHT_Profession profession, FIGHT_NomArme arme, FIGHT_NomArmure armure,
					FIGHT_NomPotion potion, string idPersonnage){
	
	this->caracteristiques[0]=10+niveau;
	this->caracteristiques[1]=10+niveau;
	this->caracteristiques[2]=10+niveau;
	this->caracteristiques[3]=niveau;
	this->caracteristiques[6]=x;
	this->caracteristiques[7]=y;
	
	this->race=race;
	this->groupe=groupe;
	this->profession=profession;
	this->arme=arme;
	this->armure=armure;
	this->potion=potion;
	this->idPersonnage=idPersonnage;
	
	this->vivant = true;
	
	if (race==FIGHT_LOUP_GAROU){
		this->caracteristiques[0]=this->caracteristiques[0]+4;
		this->caracteristiques[1]=this->caracteristiques[1]+2;
		this->caracteristiques[2]=this->caracteristiques[2]-4;
	}
	if (race==FIGHT_VAMPIRE){
		this->caracteristiques[0]=this->caracteristiques[0]-2;
		this->caracteristiques[1]=this->caracteristiques[1]+0;
		this->caracteristiques[2]=this->caracteristiques[2]+2;
	}
	
	if(profession==FIGHT_SOLDAT){
		this->caracteristiques[0]=this->caracteristiques[0]+2;
		this->caracteristiques[1]=this->caracteristiques[1]+1;
		this->caracteristiques[2]=this->caracteristiques[2]-2;
	}
	if(profession==FIGHT_VOLEUR){
		this->caracteristiques[0]=this->caracteristiques[0]-2;
		this->caracteristiques[1]=this->caracteristiques[1]+6;
		this->caracteristiques[2]=this->caracteristiques[2]+0;
	}
	if(profession==FIGHT_SORCIER){
		this->caracteristiques[0]=this->caracteristiques[0]-4;
		this->caracteristiques[1]=this->caracteristiques[1]-4;
		this->caracteristiques[2]=this->caracteristiques[2]+6;
	}
	
	this->caracteristiques[4]=100+30*niveau+20*(this->caracteristiques[0]-10);
	if(this->caracteristiques[4]<50){
		this->caracteristiques[4]=50;
	}
	this->caracteristiques[5]=100+20*niveau+10*(this->caracteristiques[2]-10);
	if(this->caracteristiques[5]<0){
		this->caracteristiques[5]=0;
	}
	
	listeCompetences[FIGHT_ATTAQUER]=new FIGHT_Competence(
		FIGHT_ATTAQUER, this->caracteristiques[0], this->caracteristiques[2],this->caracteristiques[3], this->race, this->profession, this->arme,
		this->potion
		 );
	
	listeCompetences[FIGHT_BOULEDEFEU]=new FIGHT_Competence(
		FIGHT_BOULEDEFEU, this->caracteristiques[0], this->caracteristiques[2],this->caracteristiques[3], this->race, this->profession, this->arme,
		this->potion
		 );
	
	listeCompetences[FIGHT_MORSURE]=new FIGHT_Competence(
		FIGHT_MORSURE, this->caracteristiques[0], this->caracteristiques[2],this->caracteristiques[3], this->race, this->profession, this->arme,
		this->potion
		 );
	
	listeCompetences[FIGHT_GRIFFE]=new FIGHT_Competence(
		FIGHT_GRIFFE, this->caracteristiques[0], this->caracteristiques[2],this->caracteristiques[3], this->race, this->profession, this->arme,
		this->potion
		 );
	
	listeCompetences[FIGHT_BOUCLIER]=new FIGHT_Competence(
		FIGHT_BOUCLIER, this->caracteristiques[0], this->caracteristiques[2],this->caracteristiques[3], this->race, this->profession, this->arme,
		this->potion
		 );
	
	listeCompetences[FIGHT_POTION]=new FIGHT_Competence(
		FIGHT_POTION, this->caracteristiques[0], this->caracteristiques[2],this->caracteristiques[3], this->race, this->profession, this->arme,
		this->potion
		 );
}

/*
* destructeurs
* */

FIGHT_Personnage::~FIGHT_Personnage(){
	delete[] listeCompetences[NOMBRECOMPETENCES];
}

/*
* getteurs
* */

int FIGHT_Personnage::getStr(){
	return this->caracteristiques[0];
}

int FIGHT_Personnage::getDex(){
	return this->caracteristiques[1];
}	

int FIGHT_Personnage::getIntel(){
	return this->caracteristiques[2];
}

int FIGHT_Personnage::getHp(){
	return this->caracteristiques[4];
}

int FIGHT_Personnage::getMana(){
	return this->caracteristiques[5];
}

int FIGHT_Personnage::getLevel(){
	return this->caracteristiques[3];
}

FIGHT_Profession FIGHT_Personnage::getJob(){
	return this->profession;
}

FIGHT_Groupe FIGHT_Personnage::getGroup(){
	return this->groupe;
}

FIGHT_Race FIGHT_Personnage::getRace(){
	return this->race;
}

FIGHT_NomArme FIGHT_Personnage::getWeapon(){
	return this->arme;
}

FIGHT_NomArmure FIGHT_Personnage::getArmor(){
	return this->armure;
}

FIGHT_NomPotion FIGHT_Personnage::getPotion(){
	return this->potion;
}

string FIGHT_Personnage::getCharacterId(){
	return this->idPersonnage;
}

int FIGHT_Personnage::getXpos(){
	return this->caracteristiques[6];
}

int FIGHT_Personnage::getYpos(){
	return this->caracteristiques[7];
}
bool FIGHT_Personnage::getAlive(){
	return this->vivant;
}

/*
* setteurs
* */

void FIGHT_Personnage::setHP(int pv){
	this->caracteristiques[4]=pv;
}

void FIGHT_Personnage::setMana(int mana){
	this->caracteristiques[5]=mana;
}

void FIGHT_Personnage::setPotion(){
	this->potion=FIGHT_PASDENOMPOTION;
}

void FIGHT_Personnage::setDeath(){
	this->vivant=false;
}

/*
* autres méthodes
* */

//void FIGHT_Personnage::useCompetence(FIGHT_Personnage cible, int numComp);
