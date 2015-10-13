#include "MAP_Coffre.hpp"

/*
private :
int idCoffre;
NomObjet nomObjetContenu;
TypeObjet typeObjetContenu;
MAP_Carte carte;

public :
*/

/*
* constructeurs
* */

MAP_Coffre::MAP_Coffre(int idCoffre, NomObjet nomObjet, TypeObjet typeObjet){
	this->idCoffre=idCoffre;
	this->nomObjet=nomObjet;
	this->typeObjet=typeObjet;

//	carte.addChest(this);
}

/*
* destructeurs
* */

MAP_Coffre::~MAP_Coffre(){
/*
	carte.removeChest(this);
	carte.removeImpassableElement(this->idCoffre/10000, this->idCoffre%10000);
*/
}

/*
* getteurs
* */

NomObjet MAP_Coffre::getNameItem(){
	return this->nomObjet;
}

TypeObjet MAP_Coffre::getTypeItem(){
	return this->typeObjet;
}

int MAP_Coffre::getChestId(){
	return this->idCoffre;
}
/*
* setteurs
* */

/*
* autres méthodes
* */

void MAP_Coffre::transfert(MAP_Personnage personnage){
	personnage.getInventory().addItemInBag(this->typeObjet,this->nomObjet);
	this->~MAP_Coffre();
}
