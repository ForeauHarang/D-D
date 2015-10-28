#include "RENDU_JeuDeTuile.hpp"

/* include ETAT */

/*
 * Constructeur 
 */
RENDU_JeuDeTuile::RENDU_JeuDeTuile(){
	
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
	return this->listeTuile[35];
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
	return this->listeTuile[37]; // a mettre
}
const RENDU_Tuile* const RENDU_JeuDeTuile::getElementTile( MAP_ObjetInventaire objetInventaireMap){
//	enum NomObjet {PASDENOM, COUTEAU, PISTOLET, FUSIL, VETEMENT, KELVAR, POTION_SOIN,
//		 POTION_MANA, POISON, LIVRE, POULET, BALLES_ARGENTS, SAC_SANG, PIEUX };
	if(objetInventaireMap.getItemName()==PASDENOM) return this->listeTuile[38];
	if(objetInventaireMap.getItemName()==COUTEAU) return this->listeTuile[16];
	if(objetInventaireMap.getItemName()==PISTOLET) return this->listeTuile[27];
	if(objetInventaireMap.getItemName()==FUSIL) return this->listeTuile[19];
	if(objetInventaireMap.getItemName()==VETEMENT) return this->listeTuile[41];//
	if(objetInventaireMap.getItemName()==KELVAR) return this->listeTuile[42];//
	if(objetInventaireMap.getItemName()==POTION_SOIN) return this->listeTuile[29];
	if(objetInventaireMap.getItemName()==POTION_MANA) return this->listeTuile[32];
	if(objetInventaireMap.getItemName()==POISON) return this->listeTuile[31];
	if(objetInventaireMap.getItemName()==LIVRE) return this->listeTuile[15];
	if(objetInventaireMap.getItemName()==POULET) return this->listeTuile[9];
	if(objetInventaireMap.getItemName()==BALLES_ARGENTS) return this->listeTuile[20];
	if(objetInventaireMap.getItemName()==SAC_SANG) return this->listeTuile[22];
	if(objetInventaireMap.getItemName()==PIEUX) return this->listeTuile[33];

}

const RENDU_Tuile* const RENDU_JeuDeTuile::getElementTile( FIGHT_Carte carteFight){
	return this->listeTuile[36];
}

const RENDU_Tuile* const RENDU_JeuDeTuile::getElementTile( FIGHT_Personnage personnageFight){
//enum FIGHT_Race { FIGHT_HUMAIN, FIGHT_LOUP_GAROU, FIGHT_VAMPIRE, FIGHT_MONSTRE };		
	if(personnageFight.getRace()==FIGHT_HUMAIN) return this->listeTuile[0];
	if(personnageFight.getRace()==FIGHT_LOUP_GAROU) return this->listeTuile[2];
	if(personnageFight.getRace()==FIGHT_VAMPIRE) return this->listeTuile[6];
	if(personnageFight.getRace()==FIGHT_MONSTRE) return this->listeTuile[3];
	
}

const RENDU_Tuile* const RENDU_JeuDeTuile::getElementTile( FIGHT_Competence competenceFight){
	if(competenceFight.getSkillName()==FIGHT_ATTAQUER) return this->listeTuile[16];
	if(competenceFight.getSkillName()==FIGHT_BOULEDEFEU) return this->listeTuile[34];
	if(competenceFight.getSkillName()==FIGHT_MORSURE) return this->listeTuile[39];
	if(competenceFight.getSkillName()==FIGHT_GRIFFE) return this->listeTuile[40];
	if(competenceFight.getSkillName()==FIGHT_BOUCLIER) return this->listeTuile[21];
	if(competenceFight.getSkillName()==FIGHT_POTION) return this->listeTuile[30];
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


/* Tableau de Tuiles :
tabtuile[0] = humain1
tabtuile[1] = humain2
tabtuile[2] = loup_garou
tabtuile[3] = monstre
tabtuile[4] = guerrier
tabtuile[5] = sorcier
tabtuile[6] = vampire
tabtuile[7] = voleur
tabtuile[8] = boule_de_feu_1
tabtuile[9] = poulet
tabtuile[10] = coffre
tabtuile[11] = montagne
tabtuile[12] = herbe
tabtuile[13] = chemin
tabtuile[14] = herbe
tabtuile[15] = livre
tabtuile[16] = poignard 
tabtuile[17] = sable
tabtuile[18] = roche
tabtuile[19] = fusil
tabtuile[20] = balle_argent
tabtuile[21] = bouclier
tabtuile[22] = poche_de_sang
tabtuile[23] = boule_de_feu_2
tabtuile[24] = route
tabtuile[25] = chemin
tabtuile[26] = arbre
tabtuile[27] = pistolet
tabtuile[28] = potion_rose
tabtuile[29] = potion_rouge
tabtuile[30] = potion_jaune
tabtuile[31] = potion_verte
tabtuile[32] = potion_bleue
tabtuile[33] = pieu
tabtuile[34] = boule_de_feu_3
tabtuile[35] = carte_map
tabtuile[36] = carte_fight
tabtuile[37] = inventairePersonnage
tabtuile[38] = itemnull
tabtuile[39] = dent
tabtuile[40] = griffe
tabtuile[41] = vetement
tabtuile[42] = kevlar
*/

