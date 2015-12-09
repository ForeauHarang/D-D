//#include "MAP_Quete.hpp"
#include "MAP.hpp"
using namespace MAP;
/*
private :
int idQuete;
MAP_Personnage donneur;
int but;
EtatQuete etat;

public :
*/

/*
* constructeurs
* */

MAP_Quete::MAP_Quete(int idQuete, string donneur, int but){
	this->idQuete=idQuete;
	this->donneur=donneur;
	this->but=but;
	this->etat=REPOS;
	
	//carte.addQuest(this);
}

/*
* destructeurs
* */

MAP_Quete::~MAP_Quete(){
//	carte.removeQuest(this);
}

/*
* getteurs
* */

EtatQuete MAP_Quete::getState(){
	return this->etat;
}

MAP_Personnage MAP_Quete::getGiver(){
	return this->donneur;
}

int MAP_Quete::getGoal(){
	return this->but;
}

int MAP_Quete::getQuestId(){
	return this->idQuete;
}

/*
* setteurs
* */

void MAP_Quete::setState(EtatQuete etat){
	this->etat=etat;
}

/*
* autres méthodes
* */
