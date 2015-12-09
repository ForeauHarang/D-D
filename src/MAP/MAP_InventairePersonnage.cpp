//#include "MAP_InventairePersonnage.hpp"

#include "MAP.hpp"
using namespace MAP;

/*
private :
MAP_ObjetInventaire[NOMBRESLOTS] tableauSlots;
//		MAP_ObjetInventaire slotTemporaire; 
bool inventaireOuvert=false;

public :
*/


/*
* constructeurs
* */

MAP_InventairePersonnage::MAP_InventairePersonnage(){
	int i=0;
	for(i=0;i<NOMBRESLOTS;i++){
		//MAP_ObjetInventaire slotTemp=new MAP_ObjetInventaire(i);
		this->tableauSlots[i]=new MAP_ObjetInventaire(i);
		//slotTemp.~MAP_ObjetInventaire(i);
	}
	this->inventaireOuvert=false;
}

MAP_InventairePersonnage::MAP_InventairePersonnage(MAP_ObjetInventaire *tableauSlots[NOMBRESLOTS] ){
	int i=0;
	for(i=0;i<NOMBRESLOTS;i++){
		this->tableauSlots[i]=tableauSlots[i];
	}
	this->inventaireOuvert=false;
}

/*
* destructeurs
* */

MAP_InventairePersonnage::~MAP_InventairePersonnage(){
	int i=0;
	for (i=0;i<NOMBRESLOTS;i++){
		delete[] tableauSlots[i];
	}

}

/*
* getteurs
* */

MAP_ObjetInventaire MAP_InventairePersonnage::getItemInSlot(int numeroSlot){
	return *this->tableauSlots[numeroSlot];
}

bool MAP_InventairePersonnage::isInventoryOpen(){
	return this->inventaireOuvert;
}

/*
* setteurs
* */

void MAP_InventairePersonnage::moveItemToSlot(int numeroSlot, int origine){
	
	if(this->isSlotFree(numeroSlot)){
		if(this->isSlotOK(*tableauSlots[origine], numeroSlot)){
			delete[]this->tableauSlots[numeroSlot];
			this->tableauSlots[numeroSlot]=new MAP_ObjetInventaire(tableauSlots[origine]->getTypeItem(),tableauSlots[origine]->getItemName(),numeroSlot );
			delete[]this->tableauSlots[origine];
		}else{
			std::cout << "il y a déja un objet present dans le slot\n" << std::endl;
		}
	}else{
		std::cout << "L'objet n'as pas la permission d'aller dans ce slot\n" << std::endl;
	}
}

void MAP_InventairePersonnage::addItemInBag(TypeObjet typeObjet, NomObjet nomObjet){
	delete[]this->tableauSlots[0];
	this->tableauSlots[0]=new MAP_ObjetInventaire(typeObjet, nomObjet,0);
	
}

void MAP_InventairePersonnage::closeInventory(){
	if(this->inventaireOuvert){
		if ((*this).isSlotFree(0)){
			delete[]this->tableauSlots[1];
			this->tableauSlots[1]=new MAP_ObjetInventaire(1);
			this->inventaireOuvert=false;
		}else{
			std::cout << "le slot de transition n'est pas vide\n" << std::endl;
		}
	}
}

void MAP_InventairePersonnage::openInventory(){
	if(!this->inventaireOuvert){
		inventaireOuvert=false;
	}
}

/*
* autres méthodes
* */

bool MAP_InventairePersonnage::isSlotFree(int numeroSlot){
	bool retour;
	if(tableauSlots[numeroSlot]->getItemName()==PASDENOM && tableauSlots[numeroSlot]->getTypeItem()==PASDETYPE){
		retour=true;
	}else{
		retour=false;
	}
	return retour;
}

bool MAP_InventairePersonnage::isSlotOK(MAP_ObjetInventaire objetInventaire,int numeroSlot){
	TypeObjet typeTemp=objetInventaire.getTypeItem();
	bool retour = true;
	if(typeTemp==ARME){
		if(numeroSlot==3 || numeroSlot==4) retour=false;
	}else if(typeTemp==ARMURE){
		if(numeroSlot==2 || numeroSlot==4) retour=false;
	}else if(typeTemp=POTION){
		if(numeroSlot==2 || numeroSlot==3) retour=false;
	}else if(typeTemp=QUETE){
		if(numeroSlot<5 && numeroSlot!=0) retour=false;
	}
	
	return retour;
	
}


