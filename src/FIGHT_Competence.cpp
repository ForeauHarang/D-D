#include "FIGHT_Competence.hpp"
/* 
private :
int degats;
int soins;
int bouclier;
int coutMana;
bool utilisatble;
public :
*/

/*
* constructeurs
* */

FIGHT_Competence::FIGHT_Competence(FIGHT_NomCompetence nomComp,int force, int intel, int niveau, FIGHT_Race race, FIGHT_Profession profession, FIGHT_NomArme arme, FIGHT_NomPotion potion){
	this->utilisable=true;
	this->degats=0;
	this->soins=0;
	this->coutMana=0;
	this->bouclier=0;
	this->competence=nomComp;
	
	/* schéma : nom de compétence => profession/race(permission) => carac(modification) => objet(autre modif)*/
	if(nomComp==FIGHT_ATTAQUER){
		this->degats=20+(force-10);
		if(this->degats < 1) this->degats=1;
		this->degats=this->degats+niveau;
		
		if(arme==FIGHT_COUTEAU){
			this->degats=this->degats+5;
		}
		if(arme==FIGHT_PISTOLET){
			this->degats=this->degats+15;
		}
		if(arme==FIGHT_FUSIL){
			this->degats=this->degats+25;
		}
		
	}
	
	if(nomComp==FIGHT_BOULEDEFEU){
		if(profession==FIGHT_SORCIER){
			this->degats=50+(intel-10)*2+niveau;
			this->coutMana=50+2*niveau-(intel-10);
		}else{
			this->utilisable=false;
		}
	}
	
	if(nomComp==FIGHT_MORSURE){
		if(race==FIGHT_VAMPIRE){
			this->degats=25+niveau+intel-10;
			this->soins=25+niveau+intel-10;
			this->coutMana=40+2*niveau-(intel-10);;
		}else{
			this->utilisable=false;
		}
	}
	
	if(nomComp==FIGHT_GRIFFE){
		if(race==FIGHT_LOUP_GAROU){
			this->degats=40+force-10+niveau*2;
			this->soins=-10-niveau;
		}else{
			this->utilisable=false;
		}
	}
	
	if(nomComp==FIGHT_BOUCLIER){
		if(profession==FIGHT_SORCIER){
			this->coutMana=20+2*niveau+intel-10;
			this->bouclier=25+2*niveau+intel-10;
		}else{
			this->utilisable=true;
		}
	}
	
	if(nomComp==FIGHT_POTION ){
		if(potion==FIGHT_PASDENOMPOTION){
			this->utilisable=false;
		}
		if(potion==FIGHT_SOIN){
			this->soins=50;
		}
		if(potion==FIGHT_MANA){
			this->coutMana=-50;
		}
		if(potion==FIGHT_POISON){
			this->degats=60;
		}
	}

}
/*
enum NomCompetence { ATTAQUER, BOULEDEFEU, MORSURE, GRIFFE, BOUCLIER, POTION };
enum NomPotion { PASDENOM, SOIN, MANA, POISON };
enum Race { HUMAIN, LOUP_GAROU, VAMPIRE, MONSTRE };
enum Profession { SOLDAT, VOLEUR, SORCIER };
enum NomArme {  PASDENOM, COUTEAU, PISTOLET, FUSIL };
*/

/*
* destructeurs
* */

FIGHT_Competence::~FIGHT_Competence(){}

/*
* getteurs
* */

int FIGHT_Competence::getDamage(){
	return this->degats;
}

int FIGHT_Competence::getHeal(){
	return this->soins;
}

int FIGHT_Competence::getShield(){
	return this->bouclier;
}

int FIGHT_Competence::getManaCost(){
	return this->coutMana;
}

bool FIGHT_Competence::isAvailable(){
	return this->utilisable;
}

FIGHT_NomCompetence FIGHT_Competence::getSkillName(){
	return this->competence;
}

/*
* setteurs
* */

void FIGHT_Competence::SkillLevelUp(int niveauxAjoutes){
	if(competence==FIGHT_ATTAQUER){
		this->degats=this->degats+niveauxAjoutes;
	}
	
	if(competence==FIGHT_BOULEDEFEU){

		this->degats=this->degats+niveauxAjoutes;
		this->coutMana=this->coutMana+niveauxAjoutes*2;

	}
	
	if(competence==FIGHT_MORSURE){
		this->degats=this->degats+niveauxAjoutes;
		this->soins=this->soins+niveauxAjoutes;
		this->coutMana=this->coutMana+niveauxAjoutes*10;
	}
	
	if(competence==FIGHT_GRIFFE){
		this->degats=this->degats+2*niveauxAjoutes;
		this->soins=this->soins-1*niveauxAjoutes;
	}
	
	if(competence==FIGHT_BOUCLIER){
		this->coutMana=this->coutMana+2*niveauxAjoutes;
		this->bouclier=this->bouclier+2*niveauxAjoutes;
	}
}

/*
* autres méthodes
* */
