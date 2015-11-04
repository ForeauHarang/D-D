#include "FIGHT_Carte.hpp"
/*
private : 
int nombreGentils;
int nombreMechants;
FIGHT_Personnage* listePersonnages[];


public :
* 
* */

/*
* constructeurs
* */

FIGHT_Carte::FIGHT_Carte(int nbGentils, int nbMechants, FIGHT_Personnage* tableauPersonnage){
	int i=0;
	this->nombreGentils=nbGentils;
	this->nombreMechants=nbMechants;
	this->nombreTotal=nbGentils+nbMechants;
	for(i=0; i<nbGentils + nbMechants; i++){
		this->listePersonnages[i]=new FIGHT_Personnage(
			tableauPersonnage[i].getLevel(),tableauPersonnage[i].getXpos(),tableauPersonnage[i].getYpos(),
			tableauPersonnage[i].getRace(),tableauPersonnage[i].getGroup(), tableauPersonnage[i].getJob(),tableauPersonnage[i].getWeapon(),
			tableauPersonnage[i].getArmor(),tableauPersonnage[i].getPotion(),tableauPersonnage[i].getCharacterId());
			/*
			 * FIGHT_Personnage(int niveau, int x, int y, FIGHT_Race race, 
							FIGHT_Groupe groupe, FIGHT_Profession profession, FIGHT_NomArme arme, FIGHT_NomArmure armure,
							FIGHT_NomPotion potion, string idPersonnage);
							*/
	}	
}

/*
* destructeurs
* */

FIGHT_Carte::~FIGHT_Carte(){
	delete[] listePersonnages[NBPERSO];
}

/*
* getteurs
* */

int FIGHT_Carte::getNiceNumber(){
	return this->nombreGentils;
}

int FIGHT_Carte::getEvilNumber(){
	return this->nombreMechants;
}

FIGHT_Personnage* FIGHT_Carte::getListCharacters(){
	return *this->listePersonnages;
}

/*
* setteurs
* */

void FIGHT_Carte::setNiceNumber(int nombreGentils){
	this->nombreGentils=nombreGentils;
}

void FIGHT_Carte::setEvilNumber(int nombreMechants){
	this->nombreMechants=nombreMechants;
}

void FIGHT_Carte::removeCharacter(FIGHT_Personnage personnage){
	if(personnage.getAlive()){
		FIGHT_Groupe groupeTemp=personnage.getGroup();
		FIGHT_Groupe gentil=FIGHT_GENTIL;
		if(gentil==groupeTemp){
			this->nombreGentils--;
			if(nombreGentils==0){
				std::cout<<"Les gentils ont perdu\n"<<std::endl;
			}
		}else{
			this->nombreMechants--;
			if(nombreMechants==0){
				std::cout<<"Les gentils ont gagne\n"<<std::endl;
			}
		}
		personnage.setDeath();
	}else{
		std::cout<<"deja mort\n"<<std::endl;
	}
}

/*
* autres méthodes
* */
