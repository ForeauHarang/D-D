#include "MAP_Carte.hpp"
#include "MAP_Personnage.hpp"
/*
MAP_Personnage[NOMBREPERSOMAX] listePersonnages;
MAP_Quete* listeQuetes;
MAP_Coffre* listeCoffres;
int* listeElementsInfranchissables;
int nombrePersonnages;
int nombreQuetes;
int nombreCoffres;
int nombreElementsInfranchissables;
 */

/*
* constructeurs
* */

MAP_Carte::MAP_Carte(int idCarte){
	int i=0;
	//string strtemp="none";
	/*for (i=0;i<NOMBREPERSOMAX;i++){
		this->listePersonnages[i]=new MAP_Personnage(strtemp);
	}*/
	this->nombrePersonnages=0;
	this->nombreQuetes=0;
	this->nombreCoffres=0;
	this->nombreElementsInfranchissables=0;
	this->idCarte=idCarte;
	
}

/*
 * destructeurs
 * */
 
MAP_Carte::~MAP_Carte(){
	int i=0;
	MAP_Personnage* temp = 0;
	delete[] listePersonnages[nombrePersonnages];

	delete[] listeQuetes[nombreQuetes];
	delete[] listeCoffres[nombreCoffres];
	
}

/*
 * liste des getteurs
 * */

MAP_Personnage* MAP_Carte::getListCharacters(){
	return *this->listePersonnages;
}

MAP_Quete* MAP_Carte::getListQuests(){
	return *this->listeQuetes;
}

MAP_Coffre* MAP_Carte::getListChest(){
	return *this->listeCoffres;
}

int* MAP_Carte::getListImpassableElement(){
	return this->listeElementsInfranchissables;
}		

/*
 * liste des setteurs
 * */
 
void MAP_Carte::addCharacter(MAP_Personnage perso){
	listePersonnages[nombrePersonnages]=new MAP_Personnage(perso.getCharacteristics(), perso.getRace(), perso.getJob(), perso.getGroup(), perso.getInventory(), perso.getCharacterId());
	nombrePersonnages++;
}

void MAP_Carte::removeCharacter(MAP_Personnage perso){
	int i=0;
	int temp=0;
	for(i=0;i<nombrePersonnages;i++){
		if((*this->listePersonnages[i]).getCharacterId()==perso.getCharacterId()){
			temp=i;
		}
	}
	nombrePersonnages--;
	delete[] listePersonnages[temp];
	for(i=temp;i<nombrePersonnages;i++){
		listePersonnages[i]=listePersonnages[i+1];
	}
	delete[] listePersonnages[nombrePersonnages+1];
}


void MAP_Carte::addQuest(MAP_Quete quete){
	listeQuetes[nombreQuetes]=new MAP_Quete(quete.getQuestId(), quete.getGiver().getCharacterId(), quete.getGoal());
	(*this->listeQuetes[nombreQuetes]).setState(ENCOURS);
	nombreQuetes++;
}

void MAP_Carte::removeQuest(MAP_Quete quete){
	int i=0;
	int temp=0;
	for(i=0;i<nombreQuetes;i++){
		if((*this->listeQuetes[i]).getQuestId()==quete.getQuestId()) temp=i;
	}
	nombreQuetes--;
	delete[] listeQuetes[temp];
	for(i=temp;i<nombreQuetes;i++){
		listeQuetes[i]=listeQuetes[i+1];
	}
	delete[] listeQuetes[nombreQuetes+1];
}


void MAP_Carte::addChest(MAP_Coffre coffre){
	listeCoffres[nombreCoffres]=new MAP_Coffre(coffre.getChestId(),coffre.getX(), coffre.getY(), coffre.getNameItem(), coffre.getTypeItem());
	nombreCoffres++;
}

void MAP_Carte::removeChest(MAP_Coffre coffre){
	int i=0;
	int temp=0;
	for(i=0;i<nombreCoffres;i++){
		if((*this->listeCoffres[i]).getChestId()==coffre.getChestId()) temp=i;
	}
	nombreCoffres--;
	delete[] listeCoffres[temp];
	for(i=temp;i<nombreCoffres;i++){
		listeCoffres[i]=listeCoffres[i+1];
	}
	delete[] listeCoffres[nombreCoffres+1];
}


void MAP_Carte::addImpassableElement(int x, int y){
	listeElementsInfranchissables[nombreElementsInfranchissables]=x;
	nombreElementsInfranchissables++;
	listeElementsInfranchissables[nombreElementsInfranchissables]=y;
	nombreElementsInfranchissables++;
}

void MAP_Carte::removeImpassableElement(int x, int y){
	int i=0;
	int tempx=0;
	int tempy=0;
	
	for(i=0;i<nombreElementsInfranchissables/2;i++){
		if ((listeElementsInfranchissables[2*i]==x) && (listeElementsInfranchissables[2*i+1]==y)){
			tempx=2*i;
			tempy=2*i+1;
		}
	}
	
	nombreElementsInfranchissables=nombreElementsInfranchissables-2;
	
	listeElementsInfranchissables[tempx]=PTRNULL;
	listeElementsInfranchissables[tempy]=PTRNULL;
		
	for(i=tempx;i<nombreElementsInfranchissables;i++){
		listeElementsInfranchissables[i]=listeElementsInfranchissables[i+2];
	}
	listeElementsInfranchissables[nombreElementsInfranchissables+1]=PTRNULL;
	listeElementsInfranchissables[nombreElementsInfranchissables+2]=PTRNULL;
}
	

	
