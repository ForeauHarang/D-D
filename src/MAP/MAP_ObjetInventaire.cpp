#include "MAP.hpp"
using namespace MAP;
/*
private :
TypeObjet typeObjet;
NomObjet nomObjet;
int slot;
*/


/*
* constructeurs
* */

MAP_ObjetInventaire::MAP_ObjetInventaire(int slot){
	this->typeObjet=PASDETYPE;
	this->nomObjet=PASDENOM;
	this->slot=slot;
}

MAP_ObjetInventaire::MAP_ObjetInventaire(TypeObjet typeObjet, NomObjet nomObjet, int slot){
	this->typeObjet=typeObjet;
	this->nomObjet=nomObjet;
	this->slot=slot;
}

/*
* destructeurs
* */

MAP_ObjetInventaire::~MAP_ObjetInventaire(){
	
}

/*
* setteurs
* */

void MAP_ObjetInventaire::setSlot(int slot){
	this->slot=slot;
}

/*
* getters
* */

TypeObjet MAP_ObjetInventaire::getTypeItem(){
	return this->typeObjet;
}

NomObjet MAP_ObjetInventaire::getItemName(){
	return this->nomObjet;
}

int MAP_ObjetInventaire::getSlot(){
	return this->slot;
}
