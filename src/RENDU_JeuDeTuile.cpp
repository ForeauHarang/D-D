#include "RENDU_JeuDeTuile.hpp"

/* include ETAT */

/*
 * Constructeur 
 */
RENDU_JeuDeTuile::RENDU_JeuDeTuile(){
	listeTuile[0]= new RENDU_StaticTuile(0,0,32,32); // humain1 premiere image
}

/*
 * Destructeur 
 */
RENDU_JeuDeTuile::~RENDU_JeuDeTuile(){
	delete[] listeTuile[NOMBRETUILES];
}

/*
 * Getters
 */
 
const char* const RENDU_JeuDeTuile::getImageFile(){
	return "../res/images/IMAGE.JPEG";
}

const RENDU_Tuile* const RENDU_JeuDeTuile::getElementTile( MAP_Carte carteMap){
	return this->listeTuile[37];
}

const RENDU_Tuile* const RENDU_JeuDeTuile::getElementTile( MAP_Personnage personnageMap){
	//enum Race { HUMAIN, LOUP_GAROU, VAMPIRE, MONSTRE };
	
	if(personnageMap.getRace()==HUMAIN) return this->listeTuile[0];
	if(personnageMap.getRace()==LOUP_GAROU) return this->listeTuile[2];
	if(personnageMap.getRace()==VAMPIRE) return this->listeTuile[6];
	if(personnageMap.getRace()==MONSTRE) return this->listeTuile[3];
	
}

const RENDU_Tuile* const RENDU_JeuDeTuile::getElementTile( MAP_Coffre coffreMap){
	return this->listeTuile[10];
}

const RENDU_Tuile* const RENDU_JeuDeTuile::getElementTile( MAP_InventairePersonnage inventairePersonnageMap){
	return this->listeTuile[39]; // a mettre
}
const RENDU_Tuile* const RENDU_JeuDeTuile::getElementTile( MAP_ObjetInventaire objetInventaireMap){
//	enum NomObjet {PASDENOM, COUTEAU, PISTOLET, FUSIL, VETEMENT, KELVAR, POTION_SOIN,
//		 POTION_MANA, POISON, LIVRE, POULET, BALLES_ARGENTS, SAC_SANG, PIEUX };
	if(objetInventaireMap.getItemName()==PASDENOM) return this->listeTuile[40];
	if(objetInventaireMap.getItemName()==COUTEAU) return this->listeTuile[14];
	if(objetInventaireMap.getItemName()==PISTOLET) return this->listeTuile[25];
	if(objetInventaireMap.getItemName()==FUSIL) return this->listeTuile[17];
	if(objetInventaireMap.getItemName()==VETEMENT) return this->listeTuile[32];//
	if(objetInventaireMap.getItemName()==KELVAR) return this->listeTuile[36];//
	if(objetInventaireMap.getItemName()==POTION_SOIN) return this->listeTuile[27];
	if(objetInventaireMap.getItemName()==POTION_MANA) return this->listeTuile[30];
	if(objetInventaireMap.getItemName()==POISON) return this->listeTuile[29];
	if(objetInventaireMap.getItemName()==LIVRE) return this->listeTuile[13];
	if(objetInventaireMap.getItemName()==POULET) return this->listeTuile[9];
	if(objetInventaireMap.getItemName()==BALLES_ARGENTS) return this->listeTuile[18];
	if(objetInventaireMap.getItemName()==SAC_SANG) return this->listeTuile[20];
	if(objetInventaireMap.getItemName()==PIEUX) return this->listeTuile[31];

}

const RENDU_Tuile* const RENDU_JeuDeTuile::getElementTile( FIGHT_Carte carteFight){
	return this->listeTuile[38];
}

const RENDU_Tuile* const RENDU_JeuDeTuile::getElementTile( FIGHT_Personnage personnageFight){
//enum FIGHT_Race { FIGHT_HUMAIN, FIGHT_LOUP_GAROU, FIGHT_VAMPIRE, FIGHT_MONSTRE };		
	if(personnageFight.getRace()==FIGHT_HUMAIN) return this->listeTuile[0];
	if(personnageFight.getRace()==FIGHT_LOUP_GAROU) return this->listeTuile[2];
	if(personnageFight.getRace()==FIGHT_VAMPIRE) return this->listeTuile[6];
	if(personnageFight.getRace()==FIGHT_MONSTRE) return this->listeTuile[3];
	
}

const RENDU_Tuile* const RENDU_JeuDeTuile::getElementTile( FIGHT_Competence competenceFight){
	if(competenceFight.getSkillName()==FIGHT_ATTAQUER) return this->listeTuile[14];
	if(competenceFight.getSkillName()==FIGHT_BOULEDEFEU) return this->listeTuile[34];
	if(competenceFight.getSkillName()==FIGHT_MORSURE) return this->listeTuile[35];
	if(competenceFight.getSkillName()==FIGHT_GRIFFE) return this->listeTuile[33];
	if(competenceFight.getSkillName()==FIGHT_BOUCLIER) return this->listeTuile[19];
	if(competenceFight.getSkillName()==FIGHT_POTION) return this->listeTuile[28];
}
//enum FIGHT_NomCompetence {  FIGHT_ATTAQUER,  FIGHT_BOULEDEFEU,  FIGHT_MORSURE,  FIGHT_GRIFFE,  FIGHT_BOUCLIER,  FIGHT_POTION };

int const RENDU_JeuDeTuile::getCellWidth(int i){
	return (*this->listeTuile[i]).getWidth();
}

int const RENDU_JeuDeTuile::getCellHeight(int i){
	return (*this->listeTuile[i]).getHeight();
}

/*
const RENDU_Tuile* const RENDU_JeuDeTuile::getElementTile(const ETAT::Element* e){
	//TODO
}
*/
const RENDU_Tuile* const RENDU_JeuDeTuile::getIntTile(int i){
	return this->listeTuile[i];
}


