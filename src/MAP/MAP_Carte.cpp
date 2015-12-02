#include "MAP_Carte.hpp"

/*
MAP_Personnage[NOMBREPERSOMAX] listePersonnages;
MAP_Quete* listeQuetes;
MAP_Coffre* listeCoffres;
int* listeElementsInfranchissables;
int nombrePersonnages;
int nombreQuetes;
int nombreCoffres;
int nombreElementsInfranchissables;
std::vector<int> level;
 */

/* C'est ici que se d�finit notre map : donc level doit �tre d�finit ici par exemple ainsi que le passage des coordonn�es du tableau 1D vers 2D*/

// 9 = herbe
// 54 = arbres
// 12 = terre claire
// 14 = terre fonc�e
// 0 = route grise
// 2 = route noire
// 15 = eau claire
// 17 = eau fonc�e

static int level1[] =
{
	9,9,9,9,0,0,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,14,15,15,17,17,17,17,17,15,15,14,54,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,
	9,9,9,9,0,0,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,14,14,15,15,17,17,17,15,15,14,14,54,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,
	9,9,9,9,0,0,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,54,14,14,15,15,15,15,15,14,14,54,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,15,9,9,9,9,14,2,14,2,15,9,9,9,9,9,9,9,
	9,9,9,9,0,0,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,54,54,14,14,14,14,14,54,54,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,2,2,2,2,2,9,9,9,9,9,9,9,
	9,9,9,9,0,0,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,
	9,9,9,9,0,0,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,
	14,14,14,14,0,0,14,14,14,14,14,14,14,14,14,14,14,14,14,14,14,14,14,14,14,14,14,14,14,14,14,14,14,14,14,14,14,14,14,14,14,14,14,14,14,14,14,14,14,14,14,14,14,14,14,14,14,14,14,14,14,14,14,14,14,14,14,
	0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
	2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,
	2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,
	0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,2,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
	14,14,14,14,14,14,14,14,14,14,14,14,14,14,14,14,14,14,14,14,14,14,14,14,14,14,14,14,14,14,14,14,14,14,14,14,2,14,14,14,14,14,14,14,14,14,14,14,14,14,14,14,14,14,14,14,14,14,14,14,14,14,14,14,14,14,14,
	9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,2,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,12,12,12,12,12,9,9,9,9,9,9,9,9,
	9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,2,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,
	9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,2,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,
	9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,2,2,2,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,
	9,9,9,9,9,9,9,9,9,9,9,9,9,12,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,2,15,2,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,
	9,9,9,9,9,9,9,9,9,9,9,9,12,12,12,9,9,9,9,9,54,54,54,9,9,9,9,9,9,9,9,9,9,9,9,2,15,2,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,
	9,9,9,9,9,9,9,9,9,9,9,9,12,12,12,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,2,2,2,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,
	9,9,9,9,9,9,9,9,9,9,9,9,9,12,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,2,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,
	9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,2,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,14,9,9,9,9,9,9,9,9,9,9,9,9,9,
	9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,2,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,14,14,14,14,14,14,14,14,9,9,9,9,9,9,
	9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,2,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,12,12,12,12,12,14,14,9,9,9,9,9,9
};


/*
* constructeurs
* */

MAP_Carte::MAP_Carte(int idCarte, int width, int height){
	int i=0;

	this->nombrePersonnages=0;
	this->nombreQuetes=0;
	this->nombreCoffres=0;
	this->nombreElementsInfranchissables=0;
	this->idCarte=idCarte;
	this->width = width;
	this->height = height;

	level.resize(width*height);
	for (i = 0; i < level.size(); i++) {
		level[i] = level1[i];
	}
	
}
MAP_Carte::MAP_Carte(){
	//string strtemp="none";
	/*for (i=0;i<NOMBREPERSOMAX;i++){
		this->listePersonnages[i]=new MAP_Personnage(strtemp);
	}*/
	this->nombrePersonnages=0;
	this->nombreQuetes=0;
	this->nombreCoffres=0;
	this->nombreElementsInfranchissables=0;
	this->idCarte=0;
	
}
/*
 * destructeurs
 * */
 
MAP_Carte::~MAP_Carte(){
	int i=0;
	MAP_Personnage* temp = 0;
	while(listePersonnages.size() != 0)
	delete listePersonnages[0];

	delete[] listeQuetes[NBQUETES];
	delete[] listeCoffres[NBCOFFRES];
	
}

/*
 * liste des getteurs
 * */

std::vector<MAP_Personnage*> MAP_Carte::getListCharacters(){
	return this->listePersonnages;
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

const std::vector<int>& MAP_Carte::getMap() const {
	return this->level;
}

int MAP_Carte::getLevelValue(int x,int y) const {
	if(y<0){
		throw std::invalid_argument("y<0");
	}
	if(y>=height){
		std::cerr << y << " et " << height << std::endl;
		throw std::invalid_argument("y>taille");
	}
	if(x<0){
		throw std::invalid_argument("x<0");
	}
	if(x>=width){
		throw std::invalid_argument("x>taille");
	}
	
	return this->level[x+width*y];

}

int MAP_Carte::getWidthMap() {
	return this->width;
}

int MAP_Carte::getHeightMap() {
	return this->height;

}

/*
 * liste des setteurs
 * */
 
void MAP_Carte::addCharacter(MAP_Personnage *perso){

	listePersonnages.push_back(perso);//new MAP_Personnage(perso.getCharacteristics(), perso.getRace(), perso.getJob(), perso.getGroup(), perso.getCharacterId());//perso.getInventory(), perso.getCharacterId());
	nombrePersonnages++;
}

void MAP_Carte::removeCharacter(MAP_Personnage perso){
	int i = listePersonnages.size();
	int temp=0;

	std::vector<MAP_Personnage*> listePersonnagesTemp;

	while (listePersonnages[listePersonnages.size()-1]->getCharacterId()!=perso.getCharacterId()) {
		listePersonnagesTemp.push_back(listePersonnages[listePersonnages.size() - 1]);
		listePersonnages.pop_back();
	}

	listePersonnages.pop_back();

	while (listePersonnagesTemp.size()!=0) {
		listePersonnages.push_back(listePersonnages[listePersonnagesTemp.size() - 1]);
		listePersonnagesTemp.pop_back();
	}
	/*for(i=0;i<nombrePersonnages;i++){
		if((*this->listePersonnages[i]).getCharacterId()==perso.getCharacterId()){
			temp=i;
		}
	}
	nombrePersonnages--;
	delete[] listePersonnages[temp];
	for(i=temp;i<nombrePersonnages;i++){
		listePersonnages[i]=listePersonnages[i+1];
	}
	delete[] listePersonnages[nombrePersonnages+1];*/
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

void MAP_Carte::setWidthMap(int width) {
	this->width = width;
}
void MAP_Carte::setHeightMap(int height) {
	this->height = height;
}
	

	
